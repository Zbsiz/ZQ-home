#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>


#define BUFFERSIZE 4096
#define COPYMODE 0644

void oops(char *, char *);
void *emalloc(size_t);
int isadir(char *);
char *make_destfilename(char *, char *);
void do_copy(char *, char *);
void copydir(char *, char *);


int main(int ac, char **av)
{
  if (ac != 3)
  {
    fprintf(stderr, "usage: %s [source] [destination]\n", *av);
    exit(1);
  }
  
  if (isadir(av[1]))
  {
    if (isadir(av[2]))
      copydir(av[1], av[2]);
    else
    {
      fprintf(stderr, "cp1: %s is not a directory\n", av[2]);
      exit(1);
    }
  }
  else
    do_copy(av[1], av[2]);

  return 0;
}


void copydir(char *srcdir, char *destdir)
{
  char *srcpath, *destpath;
  DIR *dir_ptr;
  struct dirent *direntp;

  srcpath = (char *) emalloc(strlen(srcdir) + 1 + 255 + 1);
  destpath = (char *) emalloc(strlen(srcdir) + 1 + 255 + 1);

  if ((dir_ptr = opendir(srcdir)) == NULL)
    oops("Cannot open directory", srcdir);

  while ((direntp = readdir(dir_ptr)) != NULL)
  {
    sprintf(srcpath, "%s/%s", srcdir, direntp->d_name);

    if (isadir(srcpath))
    {
      if (strcmp(direntp->d_name, ".") != 0 &&
          strcmp(direntp->d_name, "..") != 0)
        printf("skipping directory %s\n", srcpath);
      continue;
    }

    sprintf(destpath, "%s/%s", destdir, direntp->d_name);
    do_copy(srcpath, destpath);
  }

  closedir(dir_ptr);
  free(srcpath);
  free(destpath);
}


void do_copy(char *src, char *dest)
{
  int in_fd, out_fd, n_chars;
  char buf[BUFFERSIZE];
  char *destfilename;
  char *make_destfilename(char *, char *);

  destfilename = make_destfilename(src, dest);

  if ((in_fd = open(src, O_RDONLY)) == -1)
    oops("Cannot open", src);

  if ((out_fd = creat(destfilename, COPYMODE)) == -1)
    oops("Cannot creat", destfilename);

  while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
    if (write(out_fd, buf, n_chars) != n_chars)
      oops("Write error to", destfilename);

  if (n_chars == -1)
    oops("Read error from", src);

  if (close(in_fd) == -1 || close(out_fd) == -1)
    oops("Error closing files", "");
}

void oops(char *s1, char *s2)
{
  fprintf(stderr, "Error: %s ", s1);
  perror(s2);
  exit(1);
}

char *make_destfilename(char *src, char *dest)
{
  struct stat info;
  char *srcfilename;
  char *rv;

  if (stat(dest, &info) == -1)
    return dest;

  if (!S_ISDIR(info.st_mode))
    return dest;

  if ((srcfilename = strrchr(src, '/')) != NULL)
    srcfilename++;
  else
    srcfilename = src;

  rv = emalloc(strlen(srcfilename) + strlen(dest) + 2);
  sprintf(rv, "%s/%s", dest, srcfilename);

  return rv;
}

void *emalloc(size_t n)
{
  void *rv = malloc(n);

  if (rv == NULL)
    oops("Out of memory", "");
  
  return rv;
}

int isadir(char *str)
{
  struct stat info;

  return (stat(str, &info) != -1 && S_ISDIR(info.st_mode));
}
