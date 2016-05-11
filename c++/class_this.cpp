#include <stdio.h>
#include <stdlib.h>
#include <string>

class obj
{
  public:
    int x;
  public:
    int Test(int x)
    {
      printf("sum: %d\n", x);
    }
};

int main()
{
  obj co = {1};
  co.Test(2);

  return 0;
}
