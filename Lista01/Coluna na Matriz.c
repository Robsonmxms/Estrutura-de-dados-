#include <stdio.h>

int main() {
    int tamanho = 12;
    double M[tamanho][tamanho];
    int C,i,j;
    char T;
    double soma = 0.0;

    scanf("%d",&C);
    scanf("%s",&T);

    for (i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            scanf("%lf",&M[i][j]);
        }
    }
    for (i=0;i<tamanho;i++){
        soma+=M[i][C];
    }
    if (T == 'M'){
        soma = soma/tamanho;
    }
    printf("%.1lf\n",soma);

    return 0;
}
