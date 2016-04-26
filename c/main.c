#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rings.c"   /* Press any key to continue . . . */
#include "band.c"  /* 素数 */

int main(int argc, char* argv[])
{
  rings();
  band();

  printf("nihao!\n");  

  int a = 1;
  int b;

  b=-a-5;
  
  printf("%d\n", b);


  /* 输出转义符, 结果还是会自动换行  */
  putchar('\n');

  /*
  char bb;
  scanf("%c", &bb);
  printf("%c\\n", bb);
  */

  /*  使用不可打印字符时，需要用转义字符标识  */
  printf("note:\n  a  s\ti\b\bk\rp\n");

  /*  输入ascii 部分码表  */
  for (int i=0; i<26; i++)
  {
    printf("%c: %d   ", 'A'+i, 'A'+i);
    if (i%7 == 6)
      printf("\n");
  }
  printf("\n");

  return 0;
}
