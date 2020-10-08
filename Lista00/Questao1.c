#include <stdio.h>

int main(void) {
  int a[5] = {1,2,3,4,5};
  int b[5] = {6,7,8,9,10};
  int c[10];
  int i = 0;

  for (i=0;i<10;i++){
    if(i<5){
      c[i] = a[i];
      printf("%i ,",c[i]);
    }else{
      c[i] = b[i-5];
      printf("%i ,",c[i]);
    }
  }
  return 0;
}