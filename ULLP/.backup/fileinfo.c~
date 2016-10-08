#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>


void show_stat_info(char *, struct stat *);
void dump_mode(int);

int main(int ac, char **av)
{
  struct stat buf;

  if (ac == 1)
    fprintf(stderr, "Usage: ./info.out [filename]\n");
  else
    if (ac > 1)
    {
      stat(av[1], &buf);
      show_stat_info(av[1], &buf);
    }
}

void show_stat_info(char *filename, struct stat *buf)
{
  dump_mode(buf->st_mode);
  printf(" ");
  printf("%d", buf->st_nlink);
  printf(" ");
  printf("%s", getpwuid(buf->st_uid)->pw_name);
  printf(" ");
  printf("%s", getgrgid(buf->st_gid)->gr_name);
}

void dump_mode(int mode)
{
  char str[11] = "----------";

  if (S_ISDIR(mode)) str[0] = 'd';
  if (S_ISCHR(mode)) str[0] = 'c';
  if (S_ISBLK(mode)) str[0] = 'b';

  if (mode & S_IRUSR) str[1] = 'r';
  if (mode & S_IWUSR) str[2] = 'w';
  if (mode & S_IXUSR) str[3] = 'x';

  if (mode & S_IRGRP) str[4] = 'r';
  if (mode & S_IWGRP) str[5] = 'w';
  if (mode & S_IXGRP) str[6] = 'x';

  if (mode & S_IROTH) str[7] = 'r';
  if (mode & S_IWOTH) str[8] = 'w';
  if (mode & S_IXOTH) str[9] = 'x';

  printf("%s", str);
}
