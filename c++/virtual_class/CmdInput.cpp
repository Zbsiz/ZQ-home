
#include <stdio.h>
#include <string.h>
#include "CmdInput.h"


CmdInput::CmdInput()
{
	m_handler = NULL;
}

void CmdInput::SetHandler(CmdHandler* h)
{
	m_handler = h;
}

int CmdInput::Run()
{
	char cmdline[256];

	while(1)
	{
		// 输入
		printf("> "); 
		gets(cmdline);

		// 退出
		if(strcmp(cmdline, "exit") == 0)
		{
			break;
		}		

		// 解析与执行
		if(m_handler)
		{
			m_handler->OnCommand(cmdline);
		}
	}
	return 0;
}



