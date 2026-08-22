#include <stdio.h>
#include <stdlib.h>

#define QSIZE 5

void enqueue(int);
int dequeue(void);

int queue[QSIZE];
int head = 0;
int dnum = 0;   /* データ数 */

int main(){
  int data, status, i; /* もし必要なら変数宣言を追加してもよい */

  while (1) {
    printf("input>> ");
    status = scanf("%d", &data);
    if (status != 1) break;
    
    if (data == 0) {
        printf("  Data: %d\n", dequeue() );
    } else {
        enqueue(data);
    }

    /* ここキューの内容表示処理を追加すること（変数tailは使わない） */
    printf("  [Queue]");
    for (i = 0; i < dnum; i++) {
        printf(" %d", queue[(head + i) % QSIZE]);
    }
    printf("\n");
  }
  return 0;
}

/* 続けて、問題に合わせて修正した enqueue関数、dequeue関数を書く */

void enqueue(int num){
  if (dnum == QSIZE) {
     printf("Queue overflow!\n");
     exit(1);
  }
  else {
    int insert_pos = (head + dnum) % QSIZE;
    queue[insert_pos] = num;
    dnum++; 
  }
}

int dequeue(void){
  int val;



  if (dnum == 0) {
    printf("Queue is empty!\n");
    exit(1);
  }
  val = queue[head];
  head = (head + 1) % QSIZE;
  dnum--;
  
  return val;
}
