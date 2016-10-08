#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/ioctl.h>


void do_ls(char *);

int main(int ac, char **av)
{
  if (ac == 1)
    do_ls(".");
  else
    while (--ac)
      do_ls(*++av);
}

void list_init();
void list_append(char *);
void list_show();
void list_finish();
void fatal(char *, char *);

void do_ls(char *dirname)
{
  DIR *dir_ptr;
  struct dirent *direntp;

//  list_init();

  dir_ptr = opendir(dirname);
  while (direntp = readdir(dir_ptr))
    printf("%s\n", direntp->d_name);
//    list_append(direntp->d_name);

  closedir(dir_ptr);

// list_show();
// list_finish();
}

#define CHUNKLEN 100

void *emalloc(unsigned), *erealloc(void *, unsigned);
char **namelist = NULL;
int listlen, taken, chunksize;

void list_init()
{
  namelist = (char **) emalloc(CHUNKLEN * sizeof(char *));
  listlen = CHUNKLEN - 1;
  taken = 0;
  chunksize = (CHUNKLEN * sizeof(char *));
}

void list_append(char *str)
{
  int i;
  char *newstring(char *);
  char *name = newstring(str);

  if (taken == listlen)
  {
    listlen += CHUNKLEN;
    chunksize += chunksize;
    namelist = (char **)erealloc(namelist, chunksize);
  }

  namelist[taken++] = name;
}


int get_screen_width();

void list_show()
{
  int i, cols, maxlen;
  int col = 0;

  for (i=0; i<taken; i++)
    if (strlen(namelist[i]) >= maxlen)
      maxlen = strlen(namelist[i]) + 1;

  cols = get_screen_width() / maxlen;

  for (i=0; i<taken; i++)
  {
    if (col == cols)
    {
      printf("\n");
      col = 0;
    }

    printf("%-*s", maxlen, namelist[i]);
    col++;
  }

  printf("\n");
}

void list_finish()
{
  int i;

  for (i=0; i<taken; i++)
    free(namelist[i]);
  free(namelist);
}

void fatal(char *s1, char *s2)
{
  fprintf(stderr, "ls1:c: %s %s\n", s1, s2);
  exit(1);
}

void *emalloc(unsigned n)
{
  void *rv = malloc(n);
  return rv;
}

void *erealloc(void *er_str, unsigned er_n)
{
  void *rv = realloc(er_str, er_n);
  return rv;
}

int get_screen_width()
{
  struct winsize size;

  if (isatty(STDOUT_FILENO) != 0)
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  
  return size.ws_col;
}

char *newstring(char *s)
{
  void *rv = emalloc(1 + strlen(s));
  strcpy(rv, s);
  return rv;
}
