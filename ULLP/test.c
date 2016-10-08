#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>



void showtime(char *);
void show_info(struct utmp *);


int main()
{
  struct utmp *utbuf;

  setutent();

  while (utbufp = getutent())
    show_info(utbufp);

  return 0;
}


void show_info(struct utmp *utbufp)
{
  if (utbufp->ut_type != USER_PROCESS)
    return;

  printf("%-8.8s", utbufp->ut_name);
  printf(" ");
  printf("%-8.8s", utbufp->ut_line);
  printf(" ");
  showmodtime(utbufp->ut_line);
#ifdef SHOWHOST
  if (utbufp->ut_host[0] != '\0')
    printf("(%s)", uutbufp->ut_host);
#endif
  printf("\n");
}


void showmodtime(char *linename)
{
  char *devname;
  struct stat info;
  char *cp;
  time_t now;

  if ((devname = (char *) malloc(strlen(linename) + strlen("/dev/") + 1)) == NULL)
  {
    perror("out of memory
  }
}
