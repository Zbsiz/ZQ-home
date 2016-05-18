#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class flower
{
  private:
    int a;
    int b;
    a = 1;
    b = 2;
  public:
    void give_me()
    {
      printf("%d\n", a);
      printf("%d\n", b);
    }
};

int main()
{
  flower a;
  a.give_me();
}
