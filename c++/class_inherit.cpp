#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class VideoTutorial
{
  public:
    char S_name[20];
    char D_name[20];
  public:
    VideoTutorial()
    {
      strcpy(S_name, "SB");
      strcpy(D_name, "nihao");
      printf("%s,%s\n", S_name, D_name);
    }
  protected:
    int a = 123;
};

class Gos: public VideoTutorial
{
  public:
    void prin()
    {
      printf("%d\n", a);
    }
};

int main()
{
  Gos nihao;
  nihao.prin();

  return 0;
}