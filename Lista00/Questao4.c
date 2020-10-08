#include <stdio.h>

int main(void) {
  int a[5][4] = {{1,2,3,4},{5,6,7,8},{9,8,7,6},{5,4,3,2},{1,2,3,4}};
  int b[4][3] = {{1,2,3},{4,5,6},{7,8,9},{9,8,7}};
  int c[5][4];
  int i = 0, j = 0, k = 0, cC = 0;


  for(i=0;i<5;i++){
    for(j=0;j<3;j++){
      for (k=0;k<4;k++){
        cC+=a[i][k]*b[k][j];
      }
      c[i][j] = cC;
      cC = 0;

      printf("%i ",c[i][j]);
    }
    printf("\n");
  }
  return 0;
}