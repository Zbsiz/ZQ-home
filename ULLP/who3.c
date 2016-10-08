/*
 * who3.c -- who with buffered reads
 *    -- surpresses empty records
 *    -- formats time nicely
 *    -- buffers input (using utmplib)
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include "utmplib.c"


void show_info(struct utmp *);
void showtime(time_t);

int main()
{
  struct utmp *utbufp,  /* holds pointer to next rec */
              *utmp_next();   /* returns pointer to next */

  if (utmp_open(UTMP_FILE) == -1) {
    perror(UTMP_FILE);
    exit(1);
  }

  while ((utbufp = utmp_next()) != ((struct utmp *)NULL))
    show_info(utbufp);
  utmp_close();
  return 0;
}

void show_info(struct utmp *utbuf)
{
  if (utbuf->ut_type != USER_PROCESS)
    return ;

  printf("% -8.8s", utbuf->ut_name);
  printf(" ");
  printf("% -8.8s", utbuf->ut_line);
  printf(" ");
  showtime(utbuf->ut_time);
  printf(" ");
  printf("(%s)", utbuf->ut_host);
  printf("\n");
}

void showtime(time_t timeval)
{
  char *utime;
  utime = ctime(&timeval); 
  printf("% 12.12s", utime+4);
}
