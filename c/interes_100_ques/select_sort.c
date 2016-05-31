#include <stdio.h>

int N=10;

int main()
{
  int s[N], i, j, k, t;
  printf("The original data:\n");

  for (i=0; i<N; i++)
    scanf("%d", &s[i]);
  printf("\n");

  for (i=0; i<N-1; i++)
  {
    for (j=i+1; j<N; j++)
      if (s[j] > s[i])
      {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
      }
  }

  printf("The data after sorted:\n");

  for (i=0; i<N; i++)
    printf("%4d", s[i]);
  printf("\n");
}
