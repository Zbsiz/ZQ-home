#include <stdio.h>


class obj{
  public:
    int x;
    int y;
    char *name;

    void Test(obj *that)
    {
      printf("x=%d, y=%d\n", that->x, that->y);
    }
};

int main()
{
  char name[] = "nihao";
  obj co = {1, 2, name};

  co.Test(&co);
  
  printf("%s\n", co.name);
  return 0;
}


