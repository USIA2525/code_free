#include <stdio.h>
#include <stdlib.h>

# define NUMMAX 20

void histogram(int);

int main(){
   int num;
   int data[NUMMAX];
   int count = 0;
   int i; 

   while(1){
      scanf("%d",&num);
      if(num < 0){
         break;
      }
      if(count < NUMMAX){
         data[count] = num;
         count++;
      }
   }
   for(i = 0; i < count; i++){
      histogram(data[i]);
   }
 return 0;
}

void histogram(int num){
  int i;
 
  if(num > 70){
     fprintf(stderr,"illegal value!\n");
     exit(4);
  }

  printf("[%2d]:",num);
  for(i = 0; i <= num; i++){
        printf("#");
  }
  printf("\n");

}
