/***************************************
 * lec13-1b.c
 *
 * スタックのデータ挿入・取り出し毎にスタック内容を表示して、
 * 動作が目に見えるようにした。
 ***************************************/
#include <stdio.h>
#include <stdlib.h>

#define STSIZE 100

void push(int);
int pop(void);
void detect(void);

int stack[STSIZE];
int top = 0;

int main(){
  int data, status, i;

  while (1) {
    printf("--- Input [+] to push, [-] to pop, [0] to detect --- >>  ");
    status = scanf("%d", &data);
    if (status != 1) break;
    /* 入力値が0の場合はデータ取り出し、それ以外ならデータを
       スタックに追加する */
    if (data > 0) {
      push(data);
    } else if (data < 0) {
      printf("Data: %d\n", pop());
    } else {
      detect();
    }

    printf("  [Stack] ");   /* 処理後にスタックの内容を表示してみる */
    for ( i=0; i<top; i++ ) printf("%d ", stack[i]);
    printf("\n");
  }

  return 0;
}


void push(int num){
  if (top == STSIZE) {
    /* スタックがいっぱいの場合、エラー処理を行う */
    printf("Stack overflow!\n");
    exit (2);
  }
  stack[top] = num;
  top++;
}

int pop(void){
  if (top == 0) {
    /* スタックが空の場合、エラー処理を行う */
    printf("Stack is empty!\n");
    exit (3);
  }
  top--;
  return stack[top];
}

void detect(void){
  int n,i;
  if (top == 0) {
  /* スタックが空の場合、エラー処理を行う */
  printf("Stack is empty!\n");
  exit (3);
  }
  printf("Detect what ? :");
  scanf("%d",&n);
  for (i = 0; i < top; i++) {
    if (stack[i] == n) {
      printf("%d exists at stack[%d]\n", n, i);
      return;
    }
  }
  printf("%d not in stack!\n",n);
  exit(4);
}
