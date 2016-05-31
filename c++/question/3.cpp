/*

 求圆柱体的体积。已经底半径r和高h，求圆柱体的体积。


 #include <stdio.h>
 
 int main()
 {
 	double r = 1.0;
 	double h = 2.0;
 
 	scanf("%lf,%lf", &r, &h);
 
 	double v = 3.1415 * r * r * h;
 	printf("体积: %.4lf \n", v);
 
 	return 0;
 }
  
 */


#include <stdio.h>

int main()
{
  double r = 1.0;
  double h = 2.0;

  scanf("%lf,%lf", &r, &h);

  double v = 3.1415 * r * r * h;
  printf("V: %4lf \n", v);

  return 0;
}
