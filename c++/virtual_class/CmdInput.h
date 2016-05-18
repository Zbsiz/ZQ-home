
#ifndef _CMD_INPUT_H
#define _CMD_INPUT_H

#include "CmdHandler.h"

class CmdInput
{
public:
	CmdInput();
	void SetHandler(CmdHandler* h);

	// 开始运行
	int Run();
	
private:
	CmdHandler* m_handler;
};





#endif

