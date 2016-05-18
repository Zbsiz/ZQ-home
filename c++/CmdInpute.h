#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CmdInput
{
  public:
    CmdInput();
    void SetHandler(CmdHandler *h);
    int Run();

  private:
    CmdHandler *m_handler;
};
      
