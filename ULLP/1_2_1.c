/*
 *  这个程序也是模拟 cat ，不过，这不是根据参数的，只能通过 STDIN 和 STDOUT 
 *
 */


#include <stdio.h>

int main()
{
  int c;

  while ((c=getchar()) != EOF)
    putchar(c);
}
