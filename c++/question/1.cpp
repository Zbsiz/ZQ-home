/*

 【抽签问题】从10个数中随机抽5个数。

 例如，用数组给定10个数
 int data[10] = { 12, 98, 9, 89, 8,  878, 87, 23, 45, 235 };

 现在，从中任意取5个数，并打印出来。

 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));      // 这个要看是不是先了解 time()，再看 srand()

	int data[10] = { 12, 98, 9, 89, 8, 878, 87, 23, 45, 235 }; 
	char flags[10] = {0}; //0: 未取  ， 1已取

	for(int i=0; i<5 ; )
	{
		int r = rand() % 10;

		if(flags[r])
		{
			// 重复
			continue;
		}
		else
		{
			flags[r] = 1; // 已经取了
			i ++; // 计数增加
			printf("r: %d , %d \n", r, data[r]);
		}

	}

	return 0;
}
