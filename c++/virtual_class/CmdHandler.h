
#ifndef _CMD_HANDLER_H
#define _CMD_HANDLER_H

/* CmdHandler:
  接口类

*/

class CmdHandler
{
public:
	~CmdHandler() {} // 析构函数声明为 virtual

	virtual void OnCommand(char* cmdline) = 0; // 纯虚函数
};


#endif

