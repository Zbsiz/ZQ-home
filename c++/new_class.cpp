#include <stdio.h>
#include <stdlib.h>

 class obj 
 {
   public:
     int x;
     int y;
   public:
     int add()
     {   
       return x + y;  // 相当于 this->x + this->y
     }   
     int Test()
     {   
       printf("sum: %d\n", add());
       return 0;
     }   
		 obj()
		 {
		   printf("Nihao!");
     }
 };
 
 int main()
 {
   obj co = {1, 2}; 
   printf("%d\n", co.Test());
 }
