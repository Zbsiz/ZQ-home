/*
 * 矩阵转置
 * 生词 ajd.伟大的   great/[ɡreɪt]
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,j,b[3][3];
  int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

  printf("这是原来的矩阵:\n");

  for (i=0; i<3; i++)
  {
    for (j=0;j<3;j++)
    {
      b[j][i] = a[i][j];
      printf("%d  ", a[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  printf("这是转置后的矩阵:\n");

  for (i=0; i<3; i++)
  {
    for (j=0;j<3;j++)
    {
      printf("%d  ", b[i][j]);
    }
    printf("\n");
  }

  return 0;
}
