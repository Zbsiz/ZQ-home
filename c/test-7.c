/*
 * 还是链表结构，这个是看了邵发的视频的
 * 功能有插入节点，可以使开头也可以是结尾
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Student {
  int id;
  char *name;
  struct Student *next;
} Student;

Student first = {0};

void add_start(Student *obj)    /*  用于插入一个对象到链表中  */
{
  obj->next = first.next;
  first.next = obj;
}

void add_end(Student *obj)
{
  Student *p = &first;
  while (p->next)
    p = p->next;
  p->next = obj;
  obj->next = NULL;
}

void display(Student *msg)    /* 遍历链表  */
{
  while (msg)
  {
    printf("ID:%d, Name:%s\n", msg->id, msg->name);
    msg = msg->next;
  }
}

void user_input(Student *obj)
{
  printf("学号： ");
  scanf("%d", &obj->id);
  
  char name[14];
  printf("名字： ");
  scanf("%s", &name);
  obj->name = name;
}
  
int main()
{
//  Student *obj_start = NULL;
//  Student *obj_next = NULL;

  while (1)
  {
    int ma_select;
    printf("Select a number: "
        "\n1) Add node"
        "\n2) Show linked_list"
        "\n4) Exit"
        "\n\nEnter: ");
    scanf("%d", &ma_select);

    switch (ma_select)
    {
      case 1:
        while (1)
        {
          Student *obj_current = (Student *)malloc(sizeof(Student));
          user_input(obj_current);
          if (obj_current->id == 4)
            break;
          add_end(obj_current);
          printf("%s\n", obj_current->name);
        }
        break;
      case 2:
        display(first.next);
        break;
      case 4:
        printf("\nBye!\n");
        exit(0);
    }
  }

  return 0;
}
