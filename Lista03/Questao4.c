#include<stdio.h>

void secao(){
  int i;
  printf("\n");
  for (i=0;i<40;i++){
    printf("~");
  }
  printf("\n");
}

struct contato{
  char nome[30];
  char endereco[50];
  long int telefone;
  char situacao[1]; //L – Livre; X – Ocupado e * - Apagado)
}reg;

void criarContato(struct contato *ptr){
  printf("Qual o nome: "); scanf("%s",ptr->nome);
  printf("endereco: "); scanf("%s",ptr->endereco);
  printf("telefone: "); scanf("%ld",&ptr->telefone); 
  printf("situacao: "); scanf("%s",ptr->situacao);
}

void exibirContato(struct contato c){
  printf("Nome: %s\n",c.nome);
  printf("Endereco: %s\n",c.endereco);
  printf("Telefone: %ld\n",c.telefone);
  printf("Situacao: %s\n",c.situacao);
}

int main(){
  struct contato c;
  criarContato(&c);
  secao();
  exibirContato(c);
  return 0;
}