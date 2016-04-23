#include <stdio.h>
#include <stdlib.h>


int main()
{

  system( "stty raw -echo "); 
  printf( "Press any key to continue . . . "); 
  getchar(); 
  system( "stty -raw echo "); 
  printf( "\n"); 

  /*  上面这个是linux中的输入任意字符后继续    */

  /* 这个网上其它大牛的代码 

	#include <stdio.h>
	#include <stdlib.h>
	#include <termios.h>
	#include <unistd.h>
	 
	int getch();
	 
	void press_key();
	 
	int main()
	{
	   printf("Hello world!\n");
	   press_key();
	   return 0;
	}
	 
	void press_key()
	{
	   printf("Press any key to continue...\n");
	   getch();
	}
	 
	int getch()
	{
	   struct termios tm, tm_old;
	   int fd = STDIN_FILENO,c;
	 
	   if (tcgetattr(fd, &tm) < 0)
	   {
	      return -1;
	   }
	 
	   tm_old = tm;
	   cfmakeraw(&tm);
	 
	   if (tcsetattr(fd, TCSANOW, &tm) < 0)
	   {
	      return -1;
	   }
	 
	   c = fgetc(stdin);
	 
	   if (tcsetattr(fd,TCSANOW,&tm_old) < 0)
	   {
	      return -1;
	   }
	 
	   return c;
	}

*/


  float a, b;
  a = 123567.12;
  b = a + 1;

  printf("%f\n", a);
  printf("%f\n", b);


  int sos = 1;
  float ciel = 2;
  ciel = sos = 4;

  printf("%.2f\n", sos);


  /*
  while (1) {
   printf("%d\n", sos);
  }
  */

  /*
  int s,j,g;

  scanf("%d,%d,%d", &s, &j, &g);
  printf("%d %d %d\n", s, j, g);

  char test_1,test_2,test_3;
  scanf("%c %c %c", &test_1, &test_2, &test_3);
  printf("%d %d %d\n", test_1, test_2, test_3);
  */


  return 0;
}
