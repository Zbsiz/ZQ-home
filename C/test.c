#include <stdio.h>
#include <stdlib.h>


int main()
{


  float a, b;
  a = 123567.12;
  b = a + 1;

  printf("%f\n", a);
  printf("%f\n", b);


  int sos = 1;
  float ciel = 2;
  ciel = sos = 4;

  printf("%.2f\n", sos);


  /*
  while (1) {
   printf("%d\n", sos);
  }
  */

  /*
  int s,j,g;

  scanf("%d,%d,%d", &s, &j, &g);
  printf("%d %d %d\n", s, j, g);

  char test_1,test_2,test_3;
  scanf("%c %c %c", &test_1, &test_2, &test_3);
  printf("%d %d %d\n", test_1, test_2, test_3);
  */


  return 0;
}
