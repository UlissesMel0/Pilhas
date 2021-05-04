#include <stdio.h>
#include <stdlib.h>

FILE *fl;

typedef struct pilha
{
 int elem;
 struct pilha* prox;
};

typedef struct pilha Pilha;
Pilha* topo = NULL; 
Pilha* base = NULL;

Pilha* CriaNo()
{
   Pilha* pt = (Pilha*)malloc(sizeof(Pilha));
   if(pt != NULL)
       return pt;
   return NULL;
}

int PilhaVazia()
{
  if (topo == NULL)
   return 1;
  else
   return 0;
}



void insereElemPilha()
{
int elem;
Pilha* x;
 if (PilhaVazia()) /* insere o primeiro elemento */
 {
   x = CriaNo();
   printf("Digite o valor a ser inserido\n");
   scanf("%d",&elem);
   x->elem = elem;
   x->prox = NULL;
   topo = x;
   base = x;
 }
 else
 {
   x = CriaNo();
   printf("Digite o valor a ser inserido\n");
   scanf("%d",&elem);
   x->elem = elem;
   x->prox = topo;
   topo = x;
 }
}

void removeElemPilha()
{
  int elem;
  Pilha* x;
  Pilha* y;
  if (PilhaVazia())
   {
   	printf("Pilha Vazia\n");
   	return;
   } 
   // pega o elemento do topo 
   x=topo;
   
   if (x->prox == NULL) /* Pilha com um único elemento */
   {
   	 printf("Elemento %d removido\n",x->elem);
	 topo = NULL;
	 free(x);
   } 
   else
   {
   	y = x->prox;
	printf("Elemento %d removido\n",x->elem);
	topo = y;
	free(x);
   } 
  return;
}



void consultaElemPilha()
{
  Pilha* x = topo;
  int num, cont = 0;
  
  printf("Qual elemento deseja procurar?\nElemento: ");
  scanf("%d",&num);
  
  if(x != NULL){
  	
  	while(x != NULL){
  		if(x->elem == num){
  			printf("\nElemento encontrado!\n");
  			cont++;
		  }

		  x = x->prox;
		  
	  }
	  if(cont == 0){
	  	printf("\nElemento mmão encontrado!\n\n");
	  }
	  
  	
  }else{
  	printf("\nA pilha está vazia!\n");
  }
  
}

int retornaQuantidaElementos()
{
  Pilha* x = topo;
  int qtd = 0;
  
  while(x != NULL){
  	qtd++;
  	x = x->prox;
  }

  printf("\nQuantidade de elementos na pilha: %d\n\n",qtd);
}


void somaElemPilha()
{
  Pilha* x = topo;
  int soma;
  
  if(x != NULL){
  	while(x != NULL){
  	soma += x->elem;
  	
  	x = x->prox;
  }
  
  printf("\nSoma dos elementos da pilha: %d \n\n",soma);
  }else{
  	printf("\nA pilha está vazia!\n");
  }
  
}
void retornaMaiorElemPilha()
{
  Pilha* x = topo;
  int maior_valor;
  
  if(x != NULL){
  	
  	maior_valor = x->elem;
  	
  	while(x != NULL){
  		if((x->elem) > maior_valor ){
  			maior_valor = x->elem;
		  }
		  
		  x = x->prox;
		  
	  }
	  
	  printf("\nMaior elemento da pilha: %d\n\n",maior_valor);
  	
  }else{
  	printf("\nA pilha está vazia!\n");
  	
  }
  
}

void imprimePilha()
{
  int i;
  Pilha* x;
  x = topo;
  if (PilhaVazia())
    printf("Pilha Vazia\n");
  else
  {
   while(x!= NULL)
   {
  	 printf("%d -",x->elem);
  	 x = x->prox;
   }	
  printf("\n\n");
}
}

int main() {
int opc;
Pilha* no;
topo = NULL; /* inicialização */
while (1)
{
  printf("1- Inserir elemento na pilha\n");
  printf("2- Retornar tamanho da pilha\n");
  printf("3- Remover elemento da pilha\n");
  printf("4- Consultar elemento da pilha\n");
  printf("5- Somar elementos da pilha\n");
  printf("6- Retornar o maior elemento da pilha\n");
  printf("7- Imprimir pilha\n");
  printf("8 - FIM\n");
  printf("Digite a opção desejada\n");
  scanf("%d", &opc);
  switch (opc)
  {
  	case 1: insereElemPilha();
  	         break;
  	case 2: retornaQuantidaElementos();
  	         break;
  	case 3: removeElemPilha();
  	         break;  
	case 4: consultaElemPilha();
  	         break; 
  	case 5: somaElemPilha();
  	         break;
  	case 6: retornaMaiorElemPilha();
  	         break;
	case 7: imprimePilha();
	        break;
	case 8: exit(0);
  }
}	
	return 0;
}
