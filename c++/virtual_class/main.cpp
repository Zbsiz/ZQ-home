
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CmdInput.h"
#include "MyParser.h"

int main()
{
	CmdInput input;
	MyParser parser;

	input.SetHandler(&parser);
	input.Run();

	return 0;
}


