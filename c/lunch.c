/*
 * 测试数组初始化
 * 生词 午餐   lunch/[lʌntʃ]
 */

#include <stdio.h>

int main()
{
  char a[][80] = { 
    "nihao",
    "hehe",
    "haha",
    "qushi",
  };

  printf("%s\n", a[0]);
  printf("%c\n", a[0][0]);
}
