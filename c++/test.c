#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *p1 = (int *)malloc(sizeof(int));
  *p1 = 123;
  printf("%d\n", *p1);
}
