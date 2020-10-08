#include <stdio.h>

int main(void) {
  int n;

  printf("Informe o valor de n: ");
  scanf("%i",&n);

  printf("\nOs antecessores de %i são: %i e %i\n",n,n-1,n-2);
  printf("Os sucessores de %i são: %i e %i",n,n+1,n+2);

  return 0;

}