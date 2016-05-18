#include <stdio.h>
#include "MyParser.h"

MyParser::MyParser()
{

}



void MyParser::OnCommand(char* cmdline)
{	
	char* argv[128];
	int argc = Split(cmdline,argv);

	if(argc > 0)
	{
		printf("命令: %s \n" , argv[0]);
		printf("参数: ");

		for(int i=1; i<argc; i++)
		{
			printf("%s ", argv[i]);
		}
		printf("\n\n");
	}

}

int MyParser::Split(char text[], char* parts[])
{	
	int count = 0; // 分段的个数
	int start = 0; // 每一分段的首地址
	int flag = 0; // 遍历text，标识当前是否处于有效字符

	int stop = 0; // 是否到达结束
	for(int i=0; !stop ; i++)
	{
		char ch = text[i];
		if(ch == 0) 
			stop = 1; // 结束循环

		if(ch == ',' || ch == '\0' || ch == ' ' || ch == '\t' )
		{
			if(flag) // 遇到分隔符，且当前状态为flag=1
			{
				flag = 0;

				text[i] = 0; // 修改为结束符,完成分段
				parts[count] = text + start; // 记录首地址
				count ++;				
			}
		}
		else
		{
			if(!flag) // 遇到有效字符，且当前状态为flag=0
			{
				flag = 1;
				start = i;
			}
		}
	}
	return count; // 返回分段个数
}