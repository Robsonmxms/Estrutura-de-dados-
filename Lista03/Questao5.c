#include<stdio.h>
#include <string.h>

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
  printf("\nQual o nome: "); scanf("%s",ptr->nome);
  printf("endereco: "); scanf("%s",ptr->endereco);
  printf("telefone: "); scanf("%ld",&ptr->telefone); 
  printf("situacao: "); scanf("%s",ptr->situacao);
}

void exibirContato(struct contato c){
  printf("\nNome: %s\n",c.nome);
  printf("Endereco: %s\n",c.endereco);
  printf("Telefone: %ld\n",c.telefone);
  printf("Situacao: %s\n",c.situacao);
}

int main(){
  int op=1, i;
  int numRegistros = 5;

  struct contato c[numRegistros];
  
  secao();
  printf("\t\t\t\tMenu");
  secao();

  printf("\n0 - Sair do programa de cadastro.\n");
  printf("1 - Inserir os 5 registros.\n");
  printf("2 - Pesquisar um dos 5 registros de cada vez pelo campo nome.\n");
  printf("3 - Alterar campos de um registro.\n");
  
  secao();
  while(op!=0){
    printf("Informe o número do que deseja: ");
    scanf("%i",&op);

    switch(op){
      struct contato escolhaNome;
      int aux,numReg;

      case 1:
        for(i=0;i<numRegistros;i++){
          criarContato(&c[i]);
        }
        secao();
      break;
      case 2: 
        printf("\nDigite o nome: ");
        scanf("%s",escolhaNome.nome);
        
        for(i=0;i<numRegistros;i++){
          if( strcmp(escolhaNome.nome,c[i].nome) == 0){
            exibirContato(c[i]);
            break;
          }
        }
        secao();
      break;
      case 3:
        printf("\nInforme o número do registro [0-%i]: ",numRegistros-1); scanf("%i",&numReg);

        printf("\n\tO que você deseja alterar?\n");
        
        printf("\n0 - Nome.\n");
        printf("1 - Endereço.\n");
        printf("2 - Telefone.\n");
        printf("3 - Situação.\n");
        
        printf("\nInforme: "); scanf("%i", &aux);

        switch(aux){
          case 0:
            printf("\nDigite o nome: ");
            scanf("%s",c[numReg].nome);
          break;
          case 1:
            printf("\nDigite o endereço: ");
            scanf("%s",c[numReg].endereco);
          break;
          case 2:
            printf("\nDigite o telefone: ");
            scanf("%ld",&c[numReg].telefone);
          break;
          case 3:
            printf("\nDigite a situação: ");
            scanf("%s",c[numReg].situacao);
          break;
        }

        exibirContato(c[numReg]);
        secao();  
      break;
    }
  }

  return 0;
}