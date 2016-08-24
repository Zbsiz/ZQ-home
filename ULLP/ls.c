#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


void dump(char *);
void dump_mode(struct dirent *);

int main(int ac, char **av)
{
  if (ac == 1)
    dump(".");
  else
    while (--ac)
    {
      printf("%s :\n", av[1]);
      dump(av[1]);
    }
}

void dump(char *dirname)
{
  DIR *dir_ptr;
  struct dirent *direntp;

  if ((dir_ptr = opendir(dirname)) == NULL)
  {
    fprintf(stderr, "Error opendir %s", dirname);
    perror(dirname);
  }
  else
    while (direntp = readdir(dir_ptr))
    {
      printf("%d\n", direntp->d_name[0]);
      printf("%-8s\n", direntp->d_name);
    }
}

