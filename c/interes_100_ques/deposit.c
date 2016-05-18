/*
 * 假设某银行一年不取的月利息是0.63%，市民甲存入一笔钱，在之后的五年中，每年取出1000元，到第五点刚好取完
 * 问市民甲一开始存入了多少钱？
 *
 * 生词： deposit/[dɪˈpɒzɪt] n.存款;押金;订金
 *
 */

#include <stdio.h>

int main()
{
  int i;
  double money=0.0;
  
  for (i=0; i<5; i++)
    money=(money+1000.0)/(1+0.0063*12);

  printf("money: %0.2f\n", money);
}
