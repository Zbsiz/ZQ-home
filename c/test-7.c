/*
 * 还是链表结构，这个是看了邵发的视频的
 * 功能有插入节点，可以使开头也可以是结尾
 *
 * 之后追加了删除插入功能
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

/*  用于插入一个对象到链表中  */
void add_start(Student *obj)    
{
  obj->next = first.next;
  first.next = obj;
}

/* 这个插入是向后追加的    */
void add_end(Student *obj)
{
  Student *p = &first;
  while (p->next)
    p = p->next;
  p->next = obj;
  obj->next = NULL;
}

/* 遍历链表  */
void display(Student *msg)    
{
  while (msg)
  {
    printf("ID:%d, Name:%s\n", msg->id, msg->name);
    msg = msg->next;
  }
}

void insert(Student* obj)
{
	Student* cur = first.next; // 当前节点current
	Student* pre = &first;  // 上一个节点previous
	while(cur)
	{		
		if(obj->id < cur->id) // 找到这个位置
			break;

		pre = cur;
		cur = cur->next;  // 找到最后一个对象
	}

	// 插入到pre节点的后面
	obj->next = pre->next;
	pre->next = obj;
}

void delete(Student *obj)
{
  Student *cur = first.next;
  Student *pre = &first;
  while (cur)
  {
    if (obj->id == cur->id)
      break;
    pre = cur;
    cur = cur->next;
  }
  pre->next = cur->next;
  free(cur->name);
  free(cur);
}


void user_input(Student *obj)
{
  printf("学号： ");
  scanf("%d", &obj->id);
  
  /* 这里是因为在机构体中，我们定义的是一个char型指针，所以赋值的时候不能直接scanf */
  char name[14];
  printf("名字： ");
  scanf("%s", &name);
  obj->name = strdup(name);
}

void release(Student *obj)
{
  Student *next = NULL;
  while (obj != NULL)
  {
    next = obj->next;
    free(obj->name);
    free(obj);
    obj = next;
  }
}
    
  
int main()
{
  while (1)
  {
    int ma_select;
    printf("\nSelect a number: "
        "\n1) Add node"
        "\n2) Show linked_list"
        "\n3) Insert node"
        "\n4) Delete node"
        "\n5) Exit"
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
          {
            free(obj_current->name);
            free(obj_current);
            break;
          }
          insert(obj_current);
        }
        break;
      case 2:
        display(first.next);
        break;
      case 3:
        for (int case_num=0; case_num<1; case_num++)
        {
        	Student *case_name = (Student*)malloc (sizeof(Student));
          user_input(case_name);
        	insert(case_name);
        }
        break;
      case 4:
        for (int case_num=0; case_num<1; case_num++)
        {
        	Student *case_name = (Student*)malloc (sizeof(Student));
          user_input(case_name);
          delete(case_name);
          free(case_name->name);
          free(case_name);
        }
        break;
      case 5:
        printf("\nBye!\n");
        release(first.next);
        exit(0);
    }
  }
}
