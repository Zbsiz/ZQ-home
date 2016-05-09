/*
 * 测试在结构体中，如何给char型指针变量赋值
 *
 */

#include <stdio.h>

typedef struct Stest
{
  int id;
  char *name;
} Stest;

int main()
{
  Stest first = {0};

  scanf("%d", &(first.id));
  scanf("%s", &(first.name));
  printf("%d,%s\n", first.id, first.name);

  return 0;
}
