/*
 * 冒泡排序，随意输入定义数量的数，程序会自动从小到大排序
 *
 * 生词：    bubble/['bʌb(ə)l] n.冒牌
 */

#include <stdio.h>

int N = 10;

int main()
{
  int i, j, a[N], t, count=0;
  printf("Please enter(%d): \n", N);
  
  for (i=0; i<N; i++)
    scanf("%d", &a[i]);

  for (i=1; i<=N-1; i++)   // 控制比较的轮数
    for (j=0; j<N-i; j++)    // 控制每轮比较的次数
      if (a[j]>a[j+1])     // 数组相邻两个元素进行交换
      {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }

  /*
   * 冒泡排序的核心是在第一轮将所有数字中最大的给交换到最后
   * 之后第二轮在交换第二大的到第二后
   * ...
   * 所以它只需要N-1次
   *
   */
  
  printf("va: \n");

  for (i=0; i<N; i++)
  {
    count++;
    printf("%d ", a[i]);
  }

  printf("\n");
  return 0;
}
