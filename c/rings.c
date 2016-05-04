/*
 * 该脚本的功能是实现 “用户按下任意键后继续”
 * 生词 n戒指 v响铃   rings/[rɪŋ]
 */

#include <stdio.h>
#include <stdlib.h>

void rings()
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

}


int main()
{
  rings();
}
