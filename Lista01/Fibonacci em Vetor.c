#include <stdio.h>

int main() {
    int T;
    int N;
    unsigned long long int fib[61];
    int cont;

    fib[0] = 0;
    fib[1] = 1;

    for (cont = 2;cont<=60;cont++){
        fib[cont] = fib[cont-1]+fib[cont-2];
    }

    scanf("%d",&T);

    for (cont = 0;cont<T;cont++){
        scanf("%d",&N);
        printf("Fib(%d) = %llu\n",N,fib[N]);
    }


    return 0;
}