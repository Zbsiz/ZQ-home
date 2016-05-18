/*
 * 百鸡百钱问题，一只公鸡值五钱，一只母鸡值三钱，三只小鸡值一钱，问百钱买百鸡，三种鸡各有多少只？
 * 生词 chicken/['tʃɪkɪn] 小鸡    cock/[kɒk] 公鸡   hen/[hen] 母鸡
 */

#include <stdio.h>

int main()
{
  int chicken, cock, hen;

  for (cock=0; cock<=20; cock++)
  {
    for (hen=0; hen<=33; hen++)
    {
      chicken=100-cock-hen;
      if ((cock*5 + hen*3 + chicken/3.0) == 100)     // 3.0 表示限定chicken 能被3整除
        printf("chicken = %d; cock = %d; hen = %d\n", chicken, cock, hen);
    }
  }

  return 0;
}