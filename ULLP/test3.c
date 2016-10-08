#include <stdio.h>
#include <getopt.h>


char *l_opt_arg;
char *const short_options = "nbl:";

struct option long_options[] =
{
  { "name", 0, NULL, 'n' },
  { "bf_name", 0, NULL, 'b' },
  { "love", 1 , NULL, 'l' },
};


int main(int ac, char **av)
{
  int c;
  while ((c=getopt_long(ac, av, short_options, long_options, NULL)) != -1)
  {
    switch (c)
    {
      case 'n':
        printf("My name is XL.\n");
        break;
      
      case 'b':
        printf("His name is ST.\n");
        break;

      case 'l':
        l_opt_arg = optarg;
        printf("Our love is %s!\n", l_opt_arg);
        break;
    }
  }

  return 0;
}
