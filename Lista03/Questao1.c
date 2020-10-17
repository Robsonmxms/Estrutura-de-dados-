#include <stdio.h>

void secao(){
  int i;
  printf("\n");
  for (i=0;i<40;i++){
    printf("~");
  }
  printf("\n");
}

struct registro{
    char funcionario[36];
    char sexo;
    int pecas;
};

void registrar(struct registro *ptr){
    printf("\nnome: "); scanf("%s",ptr->funcionario);
    printf("sexo: "); scanf("%s",&ptr->sexo);
    printf("pecas: "); scanf("%d",&ptr->pecas);
}


int main(void) {
  
  int qtdFunc, i;
  printf("Informe a quantidade de funcionários: ");
  scanf("%i",&qtdFunc);

  secao();
  struct registro registroGeral[qtdFunc];
  
  int somaMas = 0; 
  int somaFem = 0;
  int maior = 0;

  for (i=0;i<qtdFunc;i++){
    registrar(&registroGeral[i]);
    
    if (registroGeral[i].pecas>maior){
      maior = i; 
    }

    if (registroGeral[i].sexo == 'F'){
      somaFem += registroGeral[i].pecas;
    }else{
      somaMas += registroGeral[i].pecas;
    }
  }
  
  secao();
  printf("\nQuantidade de peças produzidas por pessoas do sexo masculino: %i",somaMas);
  printf("\nQuantidade de peças produzidas por pessoas do sexo feminino: %i\n",somaFem);
  
  secao();
  printf("\nO funcionário com maior prudução registrada foi: %s",registroGeral[maior].funcionario);
  return 0;
}