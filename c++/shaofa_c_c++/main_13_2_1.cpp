
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


int main()
{
	Student* obj_1 = (Student*)malloc (sizeof(Student));
	obj_1->id = 1;
	strcpy(obj_1->name, "X");
	add(obj_1);

	Student* obj_2 = (Student*)malloc (sizeof(Student));
	obj_2->id = 2;
	strcpy(obj_2->name, "Y");
	add(obj_2);
	return 0;
}


