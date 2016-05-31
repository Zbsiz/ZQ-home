/*
 
 将十六进制的字符串转成unsigned int 


 例如，有字符串
 char  buf [ ] = "12AB3d";
 写一段代码，将字符串buf转成一个整数。（整数的值是0x12AB3d ，即十进制的1223485）

 */



#include <stdio.h>

int main()
{
  char buf[] = "12AB3d";


  printf("%x\n", buf);

  return 0;
}
