
#ifndef _MY_PARSER_H
#define _MY_PARSER_H

#include "CmdHandler.h"

/* MyParser:
    一个遵循了CmdHandler接口的类
*/

class MyParser : public CmdHandler
{
public:
	MyParser();

public:
	// 函数接口集
	virtual void OnCommand(char* cmdline);

private:
	// 解析命令
	int Split(char text[], char* parts[]);
};

#endif


