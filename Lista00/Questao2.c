#include <stdio.h>

int main(void) {
  int a[5][3] = {{1,2,3},{4,5,6},{7,8,9},{9,8,7},{6,5,4}};
  int b[5][3] = {{3,2,1},{1,2,3},{4,5,6},{7,8,9},{9,8,7}};
  int c[2][15];
  int i = 0, j = 0;

  for (i=0;i<2;i++){
    for (j=0;j<15;j++){
      if (i==0){
        c[0][j] = a[j/3][j%3];
        c[1][j] = b[j/3][j%3];
        printf("%i, ",c[i][j]);
      }else{
        printf("%i, ",c[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}