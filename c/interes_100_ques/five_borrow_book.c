/*
 * 小明有5本书，要借给A,B,C三个人，若每人每次只能借一本，问有多少种借法？
 * 生词     borrow/['bɒrəʊ] v.借
 */

#include <stdio.h>

int main()
{
  int A, B, C;
  int count=0;

  for (A=1; A<=5; A++)
  {
    for (B=1; B<=5; B++)
    {
      for (C=1; C<=5; C++)
      {
        if ((A!=B) && (A!=C) && (C!=B))
        {
          //printf("A: %d; B: %d; C: %d\n", A, B, C);
          count++;
        }
      }
    }
  }

  printf("Return: %d\n", count);
  return 0;
}
