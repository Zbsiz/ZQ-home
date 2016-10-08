/* more02.c -- version 0.2 of more
 * read and print 24 lines then pause for a few speical commands
 * feature of version 0.2: reads from /dev/tty for commands
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 512
#define LINENUM 24


void do_more(FILE *);
int see_more(FILE *);


int main(int ac, char *av[])
{
  FILE * fp;
  if (ac == 1)
    do_more(stdin);
  else
    while (--ac)
      if ((fp = fopen(*++av, "r")) != NULL) {
        do_more(fp);
        fclose(fp);
      }
      else
        exit(1);

  return 0;
}

void do_more(FILE *fp)
/*
 * read LINENUM lines, then call see_more() for further instructions
 */
{
  char line[LINESIZE];
  int num_of_lines = 0;
  int see_more(FILE *), reply;

  FILE *fp_tty;
  fp_tty = fopen("/dev/tty", "r");    /* NEW: cmd stream */

  if (fp_tty == NULL)    /* if open fails */
    exit(1);   /* no use in running */
  
  while (fgets(line, LINESIZE, fp)) {   /* more input */
    if (num_of_lines == LINENUM) {     /* full screen?  */
      printf("\033[7m more? \033[m");    /* reverse on a vt100 */
      reply = see_more(fp_tty);   /* NEW: pass FILE *   */
      if (reply == 0)    /* n: done  */
        break;
      num_of_lines -= reply;     /* reset count  */
    }

    if (fputs(line, stdout) == EOF)   /* show line */
      exit(1);
    num_of_lines++;     /* count it */
  }
}


int see_more(FILE *cmd)
/*
 * print message, wait for response, return # of lines to advance
 * q means no, space means yes, CR means one line
 */
{
  int c;

  while ((c = getc(cmd)) != EOF)   /* NEW: reads from tty  */
  {
    if (c == 'q')     /* q -> N */
      return 0;
    if (c == ' ')    /* ' ' => next page  */
      return LINENUM;    /* how many to show */
    if (c == '\n')   /* Enter key => 1 line  */
      return 1;
  }

  return 0;
}

