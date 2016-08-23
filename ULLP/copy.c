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
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


#define BUFFERSIZE 4096
#define COPYMODE 0644


void oops(char *, char *);
int make_object(char *);
char *file_fullpath(char *, char *);
void copy_to_dest(char *, char *);

int main(int ac, char **av)
{
  int arg;

  arg = ac - 1;

  if (ac == 1) {
    fprintf(stderr, "usage: %s [source] [source] ... [destination]\n", * av);
    exit(1);
  }
  else
    while (--arg)
    {
      char *srcfullpath, *destfullpath;
      DIR *dir_ptr;
      struct dirent *direntp;

      if (make_object(av[arg]) == 4)
      {
        if ((dir_ptr = opendir(av[arg])) == NULL)
          oops("Cannot open", av[arg]);

        while (direntp = readdir(dir_ptr))
        {
          if ((strcmp(direntp->d_name, ".") != 0) &&
              (strcmp(direntp->d_name, "..") != 0))
          {
            srcfullpath = file_fullpath(direntp->d_name, av[arg]);
            destfullpath = file_fullpath(av[arg], av[ac-1]);
            mkdir(destfullpath, 0755);
            destfullpath = file_fullpath(srcfullpath, destfullpath);
            copy_to_dest(srcfullpath, destfullpath);
            free(srcfullpath);
            free(destfullpath);
          }
        }
        
        closedir(dir_ptr);
      }
      else
      {
        destfullpath = file_fullpath(av[arg], av[ac-1]);
        copy_to_dest(av[arg], destfullpath);
        free(destfullpath);
      }
    }
}

void oops(char *s1, char *s2)
{
  fprintf(stderr, "Error: %s ", s1);
  perror(s2);
  exit(1);
}

int make_object(char *mkob)
{
  struct stat mkob_info;

  if (stat(mkob, &mkob_info) == -1)
    oops("Object error", mkob);
  else
    if (S_ISDIR(mkob_info.st_mode))
      return 4;
    else
      return 1;
}

char *file_fullpath(char *src, char *dest)
{
  char src2[strlen(src)+1];
  char *srcfilename;
  char *rv;

  strcpy(src2, src);

  if ((srcfilename = strrchr(src2, '/')) != NULL)
  {
    if (strcmp(srcfilename, "/") == 0)
    {
      src2[strlen(src2)-1] = '\0';
      srcfilename = strrchr(src2, '/');
      srcfilename++;
    }
  }
  else
    srcfilename = src;

  rv = (char *) malloc(strlen(srcfilename) + strlen(dest) + 2);

  if (make_object(dest) == 4)
    sprintf(rv, "%s/%s", dest, srcfilename);

  return rv;
}


void copy_to_dest(char *src, char *dest)
{
  int in_fd, out_fd, n_chars;
  char buf[BUFFERSIZE];

  if ((in_fd = open(src, O_RDONLY)) == -1)
    oops("Cannot open", src);

  if ((out_fd = creat(dest, COPYMODE)) == -1)
    oops("Cannot creat", dest);

  while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
    if (write(out_fd, buf, n_chars) != n_chars)
      oops("Write error to", dest);

  if (n_chars == -1)
    oops("Read error from", src);

  close(in_fd);
}
