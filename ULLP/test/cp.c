#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>
#include <sys/stat.h>




#define BUFFERSIZE  4096
#define COPYMODE  0644


void oops(char *, char *);
void set_times(struct stat *, char *, char *);

int main(int ac, char **av)
{
  int in_fd, out_fd, n_chars;
  struct stat fileinfo;
  char buf[BUFFERSIZE];

  if (ac != 3)
  {
    fprintf(stderr, "Usage: %s source destination\n", *av);
    exit(1);
  }

  if (stat(av[1], &fileinfo) == -1)
    oops("Cannot stat", av[1]);


  if ((in_fd = open(av[1], O_RDONLY)) == -1)
    oops("Cannot open", av[1]);
  
  if ((out_fd = creat(av[2], COPYMODE)) == -1)
    oops("Cannot creat", av[2]);

  while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
    if (write(out_fd, buf, n_chars) != n_chars)
      oops("Write error to", av[2]);
    else if (n_chars == -1)
      oops("Read error from", av[1]);

  if (close(in_fd) == -1 || close(out_fd) == -1)
    oops("Error closing files", "");

  set_times(&fileinfo, av[1], av[2]);
  
  return 0;
}


void oops(char *s1, char *s2)
{
  fprintf(stderr, "Error: %s", s1);
  perror(s2);
  exit(1);
}

void set_times(struct stat *finfop, char *f1, char *f2)
{
  struct utimbuf timeinfo;
  char *ctime(time_t);

  timeinfo.actime = finfop->st_atime;
  timeinfo.modtime = finfop->st_mtime;

  if (utime(f1, &timeinfo) == -1)
    oops("Cannot change times", f1);
  if (utime(f2, &timeinfo) == -1);
    oops("Cannot change times", f2);
}

