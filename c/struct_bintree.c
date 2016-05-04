/*
 * 生词 bintree   二叉树
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  char *question;
  struct node *no;
  struct node *yes;
} node;

int yes_no(char *question)
{
  char answer[3];
  printf("%s? (y/n): ", question);
  fgets(answer, 3, stdin);
  return answer[0] == 'y';      /* 相等的话就返回 y, 否则返回0   */
}

node* create(char *question)
{
  node *n = malloc(sizeof(node));
  n->question = strdup(question);
  n->no = NULL;
  n->yes = NULL;
  return n;
}

void release(node *n)
{
  if (n) {
    if (n->no)
      release(n->no);
    if (n->yes)
      release(n->yes);
    if (n->question)
      free(n->question);
    free(n);
  }
}

int main()
{
  char question[80];
  char suspect[20];
  node *start_node = create("怀疑有胡子吗");
  start_node->no = create("嫌疑人二吗");
  start_node->yes = create("嫌疑人一吗");

  node *current;
  do {
    current = start_node;
    for (;;) {
      if (yes_no(current->question))     /* 在yes_no函数中，回应y就标识结果位 true     */
      {
        if (current->yes) {     /* 在第一次循环时，将 current变量等于它的分支yes，之后第二次循环就会问yes中的问题   */
          current = current->yes;   
        } else {
          printf("SUSPECT IDENTIFIED\n");
          break;
        }
      } else if (current->no) {    /* 如果回应n那结果为 false，那第二次循环就将会问no中的问题    */
        current = current->no;
      } else {    /* 如果第二次循环再次回应n ，那之后因为no分支中的no变量是NULL，所以结果为 false所以进入下面的问题 */

        /* Make the yes-node the new suspect name */
        printf("嫌疑人是谁? ");
        fgets(suspect, 20, stdin);
        node *yes_node = create(suspect);
        current->yes = yes_node;

        /* Make the no-node a copy of this question */
        node *no_node = create(current->question);
        current->no = no_node;

        /* Then replace this question with the new question */
        printf("给我一个问题去正确确认 %s 但不是 %s? ", suspect, current->question);
        fgets(question, 80, stdin);

        free(current->question);     /*  strudp 会调用malloc为复制字符串分配空间，需要free释放   */
        current->question = strdup(question);

        break;
      }
    }
  } while(yes_no("Run again"));
  release(start_node);

  return 0;
}
