#include <stdio.h>
#include <sys/types.h>
#include <utmp.h>


int main(int ac, char **av)
{
  if (ac == 1)
    dumpfile(UTMP_FILE);
  else
    dumpfile(av[1]);
}

void dumpfile(char *fn)
{
  struct utmp utrec;
  int fd;

  if (strcmp(fn, "-size") == 0)
  {
    printf("%d\n", sizeof(utrec));
    return ;
  }
  fd = open(fn, 0);
  if (fd == -1)
  {
    perror(fn);
    return ;
  }
  
  while (read(fd, &utrec, sizeof(utrec)) == sizeof(utrec))
    show_utrec(&utrec);

  close(fd);
}

void show_utrec(struct utmp *rp)
{
  char *typename();

  printf("%-*s", UT_NAMESIZE, rp->ut_user);
  printf("%-*s", uT_NAMESIZE, rp->ut_line);
  printf("%12d", rp->ut_time);
  printf("%6d", rp->ut_pid);

  printf("54d %-12.12s", rp->ut_
}
