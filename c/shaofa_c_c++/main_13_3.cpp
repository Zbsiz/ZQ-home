
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

// 按顺序插入节点
int insert(Student* obj)
{
	Student* cur = m_head.next; // 当前节点current
	Student* pre = &m_head;  // 上一个节点previous
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
	return 0;
}

// 按id查找并删除节点
void remove(int id)
{
	Student* cur = m_head.next; // 当前节点current
	Student* pre = &m_head;  // 上一个节点previous
	while(cur)
	{		
		if(id == cur->id) // 找到这个位置
		{
			// 删除该节点
			pre->next = cur->next;
			free(cur);
			break;
		}
		pre = cur;
		cur = cur->next;  // 找到最后一个对象
	}
}

// 遍历
void show_all()
{
	Student* p = m_head.next; 
	while(p)
	{
		printf("ID: %d, name: %s\n", p->id, p->name);
		p = p->next; // 下一个对象
	}
}

int main()
{
	Student* obj = NULL;
	

	obj = (Student*)malloc (sizeof(Student));
	obj->id = 8;
	strcpy(obj->name, "888");
	insert(obj);

	obj = (Student*)malloc (sizeof(Student));
	obj->id = 1;
	strcpy(obj->name, "111");
	insert(obj);

	obj = (Student*)malloc (sizeof(Student));
	obj->id = 4;
	strcpy(obj->name, "444");
	insert(obj);

	obj = (Student*)malloc (sizeof(Student));
	obj->id = 3;
	strcpy(obj->name, "333");
	insert(obj);

	obj = (Student*)malloc (sizeof(Student));
	obj->id = 5;
	strcpy(obj->name, "555");
	insert(obj);

	remove(3);
	remove(2);
	show_all();
	return 0;
}


