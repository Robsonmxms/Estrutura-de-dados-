#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

struct Fila {

	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int n_Itens;
  int n_atendentes;
  double n_max_pessoas;
  double n_pessoas;
  double soma_tempo; 

};
typedef struct Fila Fila;

void criarFila(Fila *f, int c ) { 

	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->n_Itens = 0;
  scanf("%i",&f->n_atendentes); 
  f->n_max_pessoas=0;

}

void inserir(Fila *f, int v) {

	if(f->ultimo == f->capacidade-1){f->ultimo = -1;}

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->n_Itens++; // mais um item inserido

}

int remover(Fila *f) { // pega o item do começo da fila

  int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->n_Itens--;  // um item retirado
	return temp;

}

int escolha_aleatoria(int a){
  srand( (unsigned)time(NULL) );
  int result=0;
  int valor = rand()%1;
  if(valor==0){
    result -= rand()%a; 
  }else{
    result += rand()%a;
  }
  return result;
}

int construtor(int s,int fc,int valor, Fila *f){
  int chegou = escolha_aleatoria(valor);
  fc += chegou;
  s += fc;
  if(s<3300){inserir(f,s);}
  return s;//retorna o tempo de chegada do novo aluno
}

void atendimento(Fila* f,int dif,int s){
  for(int i=0;i<dif;i++){//atendimentos por segundo
    for(int j=0;j<f->n_atendentes;j++){
      if(f->n_Itens>0){
        if(f->n_Itens>f->n_max_pessoas){
          f->n_max_pessoas = f->n_Itens;
        }
        f->n_pessoas+=1;
        f->soma_tempo+=s-f->primeiro;
        remover(f);
      }
    }
  }
}


int main(){ 
  int s = 0;
  Fila *f;
  criarFila(f, 500);
  inserir(f,s);

  while (s<3300){
    int aux=s;
    int dif;//diferença de tempo entre a chegada do anterior e do posterior
    

    if(s<900){ //30 a 15min antes

      s = construtor(s,20,5,f);
      
    }else if(s<1200){//15 a 5 min antes

      s = construtor(s,10,6,f);
      
    }else if(s<1500){//5min ao inicio
      s = construtor(s,5,3,f);
      
      
    }else if(s<2100){//inicio a 10min depois
      s = construtor(s,10,8,f);
      dif = s-aux;
      atendimento(f,dif,s);
    
    }else if(s<2700){//10 a 20 min depois
      s = construtor(s,20,15,f);
      dif = s-aux;
      atendimento(f,dif,s);
      
    }else if(s<3300){//20 a 30 min depois
      s = construtor(s,30,5,f);
      dif= s-aux;
      atendimento(f,dif,s);
    }
  }
  
  printf("\nTempo médio de espera: %0.f segundos",f->soma_tempo/f->n_pessoas);
  printf("\nNúmero total de atendimentos: %0.f",f->n_pessoas);
  printf("\nNúmero máximo de alunos na fila: %0.f",f->n_max_pessoas);
  

 return 0;
}




