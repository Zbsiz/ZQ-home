#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
  float lemon;
  int lime_pieces;
  short hel;
} lemon_lime;

int main()
{

  lemon_lime q;
  q.lime_pieces = 6;
  printf("%d\n", q.lime_pieces);
  printf("%d\n", q.hel);

  return 0;
}