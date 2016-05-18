/*
 * 不懂，以后再看吧
 * 牛顿迭代求平方根
 * 生词： 牛顿迭代发的英文名称
 *
 */

#include <stdio.h>
#include <math.h>

int main()
{
  /* 函数功能是用牛顿迭代法求方程的根
   * a,b,c,d 代表所有方程的系数， x用来记录求得的方程根 */
  float solution(float a, float b, float c, float d);
  float a, b, c, d, x;

  printf("Pkease enter: ");
  scanf("%f %f %f %f", &a, &b, &c, &d);
  x=solution(a,b,c,d);
  printf("x=%f", x);
}

float solution(float a, float b, float c, float d)
{
  /* f 用来描述方程的值，fd 用来描述方程求导之后的值 */
  float x0, x=1.5, f, fd, h;
  do
  {
    /* 用所求得的 x 的值代替 x0 原来的值 */
    x0=x;
    f=a*x0*x0*x0+b*x0*x0+c*x0+d;
    fd=3*a*x0*x0+2*b*x0+c;
    h=f/fd;
    /* 求得更接近方程根的 x 的值 */
    x=x0-h;
  } while (fabs(x-x0)>=1e-5);

  return x;
}
