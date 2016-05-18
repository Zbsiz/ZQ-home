
#include <stdio.h>
#include <string.h>

struct Student
{
	int id;
	char name[16];
	Student* next;
};


Student* find(Student* head, int id)
{
	Student* p = head;
	while(p)
	{
		if(p->id == id) // 符合条件
			return p;

		p = p->next;
	}
	return NULL; // 没有找到符合条件的对象
}

int main()
{
	// 链表的构造
	ss[0].next = &ss[1];
	ss[1].next = &ss[2];
	ss[2].next = &ss[3];
	ss[3].next = 0;

	// 链表的遍历
	Student* p = &ss[0];
	while(p)
	{
		printf("ID: %d, name: %s\n", p->id, p->name);
		p = p->next; // 下一个对象
	}

	Student* result = find(&ss[0], 201503);

	return 0;
}


