#include <stdio.h>

/* ここに必要な宣言を行うこと */
int count1 = 0;
int count2 = 0;
int countTotal = 0;
void function1(void);
void function2(void);

int main() {
    int n;
    while(1) {
        printf("Which function will you call? [1 or 2 (0: Stop)]: ");
        scanf("%d", &n);
        if ( n == 0 ) break;
        switch(n) {
            /* ここでnの値に応じた関数の呼び出しを行うこと */
            /* switch-case構文に関わる処理と、関数呼び出し処理以外は書いてはならない */
            /* つまり、呼び出し回数の加算をここで行ってはならない */
            case 1:
                function1();
                break;
            case 2:
                function2();
                break;
        }
  }
  printf("Function 1 was called %d times.\n", count1);
  printf("Function 2 was called %d times.\n", count2);
  printf("Functions 1 and 2 were called %d times in total.\n", countTotal);
  
  return 0;
}

void function1(void) {
    printf("Function 1 was called.\n");
    /* ここで関数呼び出し回数の加算を行うこと */
    count1++;
    countTotal++;
}

void function2(void) {
    printf("Function 2 was called.\n");
    /* ここで関数呼び出し回数の加算を行うこと */
    count2++;
    countTotal++;
}
