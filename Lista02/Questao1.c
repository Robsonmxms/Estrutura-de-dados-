#include <stdio.h>

int main(void) {
  int A[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
  int B[25] = {51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75};
  int C[50];
  int i,num;

  for (i=0;i<50;i++){
    if(i<25){
      C[i]=A[i];
    }else{
      C[i]=B[i-25];
    }
  }

  scanf("%i",&num);

  for (i=0;i<50;i++){
    if(C[i]==num){
      printf("número encontrado na posição: %i",i);
      break;
    }else if(i==49){
      printf("número não encontrado no array");
    }
  }
  return 0;
}