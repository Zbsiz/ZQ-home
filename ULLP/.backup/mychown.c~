#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>



int main(int ac, char **av)
{
  uid_t userid;
  struct passwd *infop;
  int i;
  int rv;

  rv = 0;

  if (ac < 3)
  {
    fprintf(stderr, "chown: too few arguments\n");
    exit(1);
  }


  infop = getpwnam(av[1]);

  if (infop == NULL)
  {
    fprintf(stderr, "chown: %s: invalid user\n", av[1]);
    exit(2);
  }

  userid = infop->pw_uid;

  for (i=2; i<ac; i++)
    if (chown(av[i], userid, -1) == -1)
    {
      fprintf(stderr, "chown: ");
      perror(av[i]);
      rv = 3;
    }

  return rv;
}
