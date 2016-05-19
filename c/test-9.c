#include <stdio.h>

int main()
{
  int i=4,j=5,m,k;
  m=4+((i++>3)&&(i%2))+i/j;
  i=4,j=5;
  k=((i++>3)&&(i%2));
  printf("%d %d\n", m, k);
}
