/*
 * cp1.c
 * version 1 of cp -- user read and write with tunable buffer size
 *
 * usage: cp1 src dest
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define BUFFERSIZE 4096
#define COPYMODE 0644


void oops(char *, char *);

int main(int ac, char **av)
{
  int in_fd, out_fd, n_chars;
  char buf[BUFFERSIZE];
  char *destfilename;
  char *make_destfilename(char *, char *);

  if (ac != 3) {
    fprintf(stderr, "usage: %s source destination\n", * av);
    exit(1);
  }

  destfilename = make_destfilename(av[1], av[2]);

  if ((in_fd = open(av[1], O_RDONLY)) == -1)
    oops("Cannot open", av[1]);
  if ((out_fd = creat(destfilename, COPYMODE)) == -1)
    oops("Cannot creat", av[2]);

  while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
    if (write(out_fd, buf, n_chars) != n_chars)
      oops("Write error to", av[2]);
  if (n_chars == -1)
    oops("Read error from", av[1]);

  if (close(in_fd) == -1 || close(out_fd) == -1)
    oops("Error closing files", "");
}

void oops(char *s1, char *s2)
{
  fprintf(stderr, "Error: %s", s1);
  perror(s2);
  exit(1);
}

char *make_destfilename(char *src, char *dest)
{
  struct stat info;
  char *srcfilename;
  char *rv;

  if ( (srcfilename = strrchr(src, '/')) != NULL )
    srcfilename++;
  else
    srcfilename = src;

  rv = (char *) malloc(strlen(srcfilename) + strlen(dest) + 2);

  if ( stat(dest, &info) == -1 )
    return dest;
  else
    if ( S_ISDIR(info.st_mode) )
      sprintf(rv, "%s/%s", dest, srcfilename);

  return rv;
}
