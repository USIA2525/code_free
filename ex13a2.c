/***************************************
 * lec13-2b.c
 *
 * キューのデータ挿入・取り出し毎にキューの内容を表示して、
 * 動作が目に見えるようにした。
 ***************************************/
#include <stdio.h>
#include <stdlib.h>

#define QSIZE 5

int isFull(void);
int isEmpty(void);
void enqueue(int);
int dequeue(void);

int queue[QSIZE];
int head = 0;
int tail = 0;

int main(){
  int data, status, i;

  while (1) {
    printf("input>> ");
    status = scanf("%d", &data);
    if (status != 1) break;
    /* 入力値が0の場合はデータ取り出し、それ以外ならデータを
       キューに追加する */
    if (data == 0) printf("Data: %d\n", dequeue() );
    else enqueue(data);

    printf("  [Queue] ");   /* 処理後にキューの内容を表示してみる */
    for ( i=head; i!=tail; i=(i+1)%QSIZE ) printf("%d ", queue[i]);
    printf("\n");
  }

  return 0;
}

int isFull(void){
  return (tail + 1) % QSIZE == head;
}
int isEmpty(void){
  return head == tail;
}

void enqueue(int num){
  if (isFull()) {
    /* キューがいっぱいの場合のエラー処理 */
    printf("Queue overflow!\n");
    exit(1);
  }
  else{
    queue[tail] = num;
    tail = (tail + 1) % QSIZE;
  }
}

int dequeue(void){
  int val;

  if (isEmpty()) {
    /* キューが空の場合のエラー処理 */
    printf("Queue is empty!\n");
    exit(1);
  }
  val = queue[head++];
  head = (head + 1) % QSIZE;
  return val;
}
