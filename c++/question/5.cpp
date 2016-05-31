/*
 
 输入5字符串，将它们排序后输出。


 例如，输入了5个字符串：  "dead", "alex",  "can", "best", "effort"
 则程序最终输出为:  alex,  best,  can, dead, effort

 */


#include <stdio.h>
#include <string.h>

// 选择排序法, 见《C/C++学习指南》特别篇 - “选择排序法”
void select_sort(char* arr[], int n) // 1.参数的类型
{
	for(int i=0; i<n-1; i++)
	{
		int pos = i;
		for(int j=i+1; j<n; j++)
		{
			//if(arr[j] < arr[pos]) // 2. 比较两个元素的大小
			if( strcmp(arr[j] ,arr[pos]) < 0)
			{
				pos = j;
			}
		}
		// 交换 index 与 i
		if(pos != i)
		{
			char* temp = arr[pos]; // 3. 修改元素类型
			arr[pos] = arr[i];
			arr[i] = temp;
		}
	}
}

struct Object
{
	char value[32];
};


int main()
{
	////////////////////
	int i;
	Object objs[5];
	for(i = 0; i<5; i++)
	{
		printf("> ");
		scanf("%s", objs[i].value);
	}
	printf("输入完毕 ......\n");



	/////////////////////
	char* names[5];
	// 	names[0] = "done";
	// 	names[1] = "alex";
	// 	names[2] = "can";
	// 	names[3] = "best";
	// 	names[4] = "effort";

	for(i=0; i<5; i++)
	{
		names[i] = objs[i].value;
	}

	select_sort(names, 5);

	for(i=0; i<5; i++)
	{
		printf("%s \n", names[i]);
	}

	return 0;
}





/*
 * 这个题目的考点就是选择排序
 *
 * 邵发使用了 strcmp 这个函数，原来这个函数不知可以比较字符串是否相等，还可以比较大小
 * 若str1==str2，则返回零；
 * 若str1>str2，则返回正数；
 * 若str1<str2，则返回负数。
 *
 * 我自己写的时候，遇到的问题就是比较了字符的大小但是重新排序的时候只替换了第一个字符
 *
 */



