#include <stdio.h>

void BubbleSort(int Aor[], int tamanho)
{ 
  int aux, i, j; 
 
  for(j=tamanho-1; j>=1; j--)
  { 
    for(i=0; i<j; i++)
    { 
      if(Aor[i] > Aor[i+1])
      { 
        aux=Aor[i]; 
        Aor[i]=Aor[i+1]; 
        Aor[i+1]=aux; 
      } 
    } 
  } 
}

int PesquisaBinaria (int A[], int chave, int tam)
{
  int achou = 0;
  int comeco = 0;
  int fim = tam-1;
  int meio = (comeco+fim)/2;
  while (comeco<=fim && achou == 0){
    if(chave==A[meio]){
      achou = 1;
    }else{
      if(chave<A[meio]){
        fim = meio-1;
      }else{
        comeco= meio+1;
      }
    }
    meio = (comeco+fim)/2;
  }
  if(achou==1){
    return meio;
  }else{
    return -1;
  }  
}

int main(void) {
  int tam = 30;
  int A[tam];
  int i,num,valor,chave;

  for (i=0;i<tam;i++){
    scanf("%i",&num);
    if (num%2==0){
      A[i] = 2*num;
    }else{
      A[i] = 5*num;
    }
  }

  BubbleSort(A, tam);

  printf("insira o valor a ser pesquisado: ");
  scanf("%i",&chave);

  int posicao = PesquisaBinaria(A,chave,tam);
  
  if(posicao ==-1){
    printf("valor não encontrado");
  }else{
    printf("%i foi localizado na posição %i",chave,posicao);
  } 
   
  return 0;
}