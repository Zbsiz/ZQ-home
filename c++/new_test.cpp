#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *st = new int [500];
  for (int a=0; a<500; a++)
  {
    st[a] = a;
    printf("%d\n", st[a]);
  }
  
  
  delete [] st;
  st = NULL;
  printf("%d\n", st[30]);
}
