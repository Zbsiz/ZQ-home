#include <stdio.h>
#define N 10

int main()
{
  int i, j, a[N], t, count=0;
  printf("Please ener: \n");
  
  for (i=0; i<N; i++)
    scanf("%d", &a[i]);
  for (i=1; i<=N-1; i++)
    for (j=0; j<N-i; j++)
      if (a[j]>a[j+1])
      {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
  
  printf("va: \n");

  for (i=0; i<N; i++)
  {
    count++;
    printf("%d ", a[i]);
  }

  printf("\n");
  return 0;
}
