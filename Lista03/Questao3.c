#include<stdio.h>

void secao(){
  int i;
  printf("\n");
  for (i=0;i<40;i++){
    printf("~");
  }
  printf("\n");
}

struct registro{
  char nome[30];
  float nota[3];
}reg;

void registrar(struct registro *ptr){
  printf("Qual o nome: "); scanf("%s",ptr->nome);
  printf("AP1: "); scanf("%f",&ptr->nota[0]);
  printf("AP2: "); scanf("%f",&ptr->nota[1]);
  printf("Final: "); scanf("%f",&ptr->nota[2]);
}

void exibirRegistro(struct registro r){
  printf("Nome: %s\n",r.nome);
  printf("AP1: %.2f\n",r.nota[0]);
  printf("AP2: %.2f\n",r.nota[1]);
  printf("Final: %.2f\n",r.nota[2]);
}

int main(){
  int n_registros = 35;
  int i;

  struct registro r[n_registros];

  for(i = 0;i<n_registros;i++){
    registrar(&r[i]);
    puts("\n");  
  }
    
  secao();

  for(i = 0;i<n_registros;i++){
    exibirRegistro(r[i]);
    puts("\n");
    setbuf(stdin,NULL);
  }

  return 0;
}