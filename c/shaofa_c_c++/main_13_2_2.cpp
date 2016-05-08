
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
	int id;
	char name[16];
	Student* next;
};

// 定义了一个有头节点
Student m_head = {0};

// 插入一个对象到链表中
// void add(Student* obj)
// {
// 	obj->next = m_head.next;
// 	m_head.next = obj;
// }

void add(Student* obj)
{
	Student* p = &m_head;
	while(p->next)
		p = p->next;  // 找到最后一个对象
	p->next = obj;   //  把obj挂在最后一个对象后面
	obj->next = NULL;  // 现在obj作为最后一个对象
}

// 用户输入数据
// 返回值：0个成功；-1表示用户输入有误
int user_input(Student* obj)
{
	printf("学号: ");
	scanf("%d", &obj->id);
	printf("姓名: ");
	scanf("%s", obj->name);
	return 0;
}

void display(Student *msg)    /* 遍历链表  */
{
  while (msg)
  {
    printf("ID:%d, Name:%s\n", msg->id, msg->name);
    msg = msg->next;
  }
}

int main()
{
	while(1)
	{
		Student* obj_1 = (Student*)malloc (sizeof(Student));
// 		obj_1->id = 1;
// 		strcpy(obj_1->name, "X");
		if(user_input(obj_1) == 0)
		{
			add(obj_1);
		}
		else
		{
			free(obj_1);
		}
		
		printf("OK!\n");
    display(m_head.next);
	}


	return 0;
}


