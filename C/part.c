#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void linked()
{
  typedef struct island {
    char* name;
    char* opens;
    char* closes;
    struct island* next;
  } island;

  void display(island *start) {
    island *i = start;
    for (; i!=NULL; i=i->next) {
      printf("Name %s \n open:%s-%s\n", i->name, i->opens, i->closes);
    }
  }

  int show_print() {
    island amity = {"Amity", "09:00", "17:00", NULL};
    island craggy = {"Craggy", "09:00", "17:00", NULL};
    island isla_nublar = {"isla nublar", "09:00", "17:00", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    
    island skull = {"skull", "09:00", "17:00", NULL};
    isla_nublar.next = &skull;
    
    display(&amity);
  }

  show_print();
}

int main(int argc, char* argv[])
{
  linked();
  return 0;
}
