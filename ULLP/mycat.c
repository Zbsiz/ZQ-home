#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



int dump(FILE *);

int main(int ac, char **av)
{
  FILE *fp;

  if (ac == 1)
    dump(stdin);
  else
    while (--ac)
      if ((fp = fopen(*++av, "r")) != NULL)
      {
        dump(fp);
        fclose(fp);
      }
      else
        exit(1);

  return 0;
}

int dump(FILE *fp)
{
  char buf[512];
  int num;

  while (fgets(buf, 512, fp))
    if (fputs(buf, stdout) == -1)
      exit(1);
}
