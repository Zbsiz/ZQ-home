#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct Student {
  int ID;
  char *name;
  struct Student *next;
} Student;

Student first = {0};

Student ss[4] = {
  {201501, "John", NULL},
  {201502, "Jennifer", NULL},
  {201503, "AnXi", NULL},
  {201504, "Unnamed", NULL}
};

void add_start(Student *obj)
{
  obj->next = first.next;
  first.next = obj;
}

void add_end(Student *obj)
{
  Student *b = &first;
}

Student *find(Student *p, char find_argv[4])   /*  查找节点 */
{
  int id = atoi(find_argv);
  while (p)
  {
    if(p->ID == id)
    {
      return p;
      break;
    }
    p = p->next;
  }
};

void display(Student *msg)    /* 遍历链表  */
{
  while (msg)
  {
    printf("ID:%d, Name:%s\n", msg->ID, msg->name);
    msg = msg->next;
  }
}

int main(int argc, char *argv[])
{
  first.next = &ss[0];
  ss[0].next = &ss[1];
  ss[1].next = &ss[2];
  ss[2].next = &ss[3];
  ss[3].next = NULL;

  

  display(first.next);


  return 0;
}
