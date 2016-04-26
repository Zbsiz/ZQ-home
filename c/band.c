/*
 * 哥德巴赫猜想 c实现
 * 生词 乐队   band/[bænd]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void band()
{
  int i,j,num;
  int p,q,flagp,flagq;

  printf("Place input a even number: ");
  scanf("%d", &num);

  if (((num%2)!=0) || (num<=4))
    printf("data error \n");
  else
  {
    p=1;
    do
    {
      p=p+1;
      q=num-p;
      flagp=1;
      flagq=1;
      for (i=2; i<=(int)(floor(sqrt((double)(p)))); i++)
      {
        if ((p%i) == 0)
        {
          flagp=0;
          break;
        }
      }

      j=2;
      while (j<=(int)(floor(sqrt((double)(q)))))
      {
        if ((q%j) == 0)
        {
          flagq=0;
          break;
        }
        j++;
      }
    } while (flagp*flagq == 0);

    printf("%d = %d + %d \n", num, p, q);
  }
}
