#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>
#include <sys/types.h>


void oops(char *, char *);


int main(int ac, char **av)
{
  struct passwd *infop;
  int userid;

  if (ac < 3)
    oops("Usage: ./a.out [user] [filename]", "");

  if ((infop = getpwnam(av[1])) == NULL)
    oops("chown: user invalid", "");

  userid = infop->pw_uid;

  for (int i=2; i<ac; i++)
    if (chown(av[i], userid, -1) == -1)
      oops("chown: error ", av[i]);
  
  return 0;
}

void oops(char *s1, char *s2)
{
  fprintf(stderr, s1);
  perror(s2);
  exit(1);
}
