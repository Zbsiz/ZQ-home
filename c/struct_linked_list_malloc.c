/*
 * 用户自动可以插入，删除，遍历链表
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
  int id;
  char *name;
  struct island *next;
} island;

void display(island *start);
island* create(char *name, int cr_id);
void release(island *i);

int main()
{
  island *start   = NULL;
  island *current = NULL;
  island *next    = NULL;

  char name[80], ma_next[4];
  int ma_select, ma_id;

  while (1)
  {
    printf("\nSelect a option: "
        "\n1) Add a node"
        "\n2) Show linked table"
        "\n4) Exit\n");
    printf("\nEnter select: ");
    scanf("%d", &ma_select);
  
    switch (ma_select)
    {
      case 1:
        while (1) {
          printf("Enter: ");
          scanf("%d %s", &ma_id, &name);
          next = create(name, ma_id);
          if (start == NULL)
            start = next;
          if (current != NULL)
            current->next = next;
          current=next;
          printf("Next or exit: ");
          scanf("%s", &ma_next);
          if (!strncasecmp("end", ma_next, 3))
            break;
        }
        break;
      case 2:
        display(start);
        break;
      case 4:
        release(start);
        printf("\nBye!\n");
        exit(0);
    }
  }

  return 0;
}

island* create(char *name, int cr_id)
{
  island *i = malloc(sizeof(island));
  i->name   = strdup(name);
  i->id   = cr_id;
  i->next   = NULL;

  return i;
}

void release(island *i)
{
  island *next = NULL;
  while (i != NULL) {
    next = i->next;
    free(i->name);
    free(i);
    i = next;
  }
}

void display(island *start)
{
  island *i = start;
  for (;i != NULL; i = i->next) {
    printf("\n");
    printf("ID: %d  Name: %s \n", i->id, i->name);
  }
}
