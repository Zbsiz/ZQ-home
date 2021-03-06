/*
 * 测试链表的使用
 * 可以插入，删除节点
 * 生词 链表    linked_list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
  int id;
  char *name;
  char *describe;
  int years_old;
  struct Student *next;
} Student;


Student *create(int cr_id, char *cr_name, char *cr_desc, int cr_year)
{
  Student *i = malloc(sizeof(Student));
  i->id = cr_id;
  i->name = strdup(cr_name);
  i->describe = strdup(cr_desc);
  i->years_old = cr_year;
  i->next = NULL;
  return i;
}

void happy_small(Student *sos)
{
  for (; sos!=NULL; sos=sos->next)
    printf("ID=[%d]\t%s,%s,%d\n", sos->id, sos->name, sos->describe, sos->years_old);
}
  
void release(Student *start)
{
  Student *i = start;
  Student *next = NULL;
  for (; i!=NULL; i=next)
  {
    next = i->next;
    free(i->name);
    free(i);
  }
}

int main()
{

  int ma_select;

  int ma_id;
  char ma_name[80];
  char ma_desc[320];
  int ma_year;

  /*
  do {
    */
    printf("\nSelect one of: \n"
        "1)add a node\n");
    printf("\nEnter select: ");
    scanf("%d", &ma_select);

    switch (ma_select)
    {
      case 1:
        printf("\nEnter ID: ");
        scanf("%d", &ma_id);
        printf("Enter name: ");
        scanf("%s", &ma_name);
        printf("Enter describe: ");
        scanf("%s", &ma_desc);
        printf("Enter year_old: ");
        scanf("%d", &ma_year);
  
        Student *so = create(ma_id,ma_name,ma_desc,ma_year);
  
        /*
        char name_1[80] = "nihao";
        int year_1 = 2;
        Student *ao = create(name_1,year_1);
  
        so->next = ao;
        */
  
        happy_small(so);
        release(so);
        break;
        //continue;
      default:
        printf("\nError option!\nBye!\n");
        exit(1);
    }
    /*
  } while (0<ma_select<5);
  */

  return 0;

}
