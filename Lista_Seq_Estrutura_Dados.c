#include <stdio.h>
#include <stdlib.h>

struct L_seq{
 int num;
 struct L_seq *prox;
}; 
typedef struct L_seq Elem;

int tam;

void inicia(Elem *LISTA);
int menu(void);
void opcao(Elem *LISTA, int op);
Elem *criaNo();
void insereFim(Elem *LISTA);
void insereInicio(Elem *LISTA);
void exibe(Elem *LISTA);
void libera(Elem *LISTA);
void insere (Elem *LISTA);
Elem *retiraInicio(Elem *LISTA);
Elem *retiraFim(Elem *LISTA);
Elem *retira(Elem *LISTA);


int main(void)
{
 Elem *LISTA = (Elem *) malloc(sizeof(Elem));
 if(!LISTA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(LISTA);
 int opt;
 
 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
 }
}

void inicia(Elem *LISTA)
{
 LISTA->prox = NULL;
 tam=0;
}

int menu(void)
{
 int opt;
 
 printf("\n----Escolha uma opcao----\n\n");
 printf("0. Sair\n");
 printf("1. Zerar lista\n");
 printf("2. Exibir lista\n");
 printf("3. Adicionar elemnto no inicio\n");
 printf("4. Adicionar elemento no final\n");
 printf("5. Escolher onde inserir\n");
 printf("6. Retirar elemento do inicio\n");
 printf("7. Retirar elemento do fim\n");
 printf("8. Escolher de onde tirar\n");
 printf("\nOpcao: "); scanf("%d", &opt);
 
 return opt;
}

void opcao(Elem *LISTA, int op)
{
 Elem *tmp;
 switch(op){
  case 0:
   libera(LISTA);
   break;
   
  case 1:
   libera(LISTA);
   inicia(LISTA);
   break;
  
  case 2:
   exibe(LISTA);
   break;
  
  case 3:
   insereInicio(LISTA);
   break;  
   
  case 4:
   insereFim(LISTA);
   break;
   
  case 5:
   insere(LISTA);
   break;
  
  case 6:
   tmp= retiraInicio(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
   
  case 7:
   tmp= retiraFim(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
  
  case 8:
   tmp= retira(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
  
  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(Elem *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

Elem *aloca()
{
 Elem *novo=(Elem *) malloc(sizeof(Elem));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}


void insereFim(Elem *LISTA)
{
 Elem *novo=aloca();
 novo->prox = NULL;
 
 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  Elem *tmp = LISTA->prox;
  
  while(tmp->prox != NULL)
   tmp = tmp->prox;
  
  tmp->prox = novo;
 }
 tam++;
}

void insereInicio(Elem *LISTA)
{
 Elem *novo=aloca(); 
 Elem *oldHead = LISTA->prox;
 
 LISTA->prox = novo;
 novo->prox = oldHead;
 
 tam++;
}

void exibe(Elem *LISTA)
{
 system("clear");
 if(vazia(LISTA)){
  printf("\n\nLista vazia!\n\n");
  return ;
 }
 
 Elem *tmp;
 tmp = LISTA->prox;
 printf("Lista:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);
 
  
 printf("\n\n");
}

void libera(Elem *LISTA)
{
 if(!vazia(LISTA)){
  Elem *proxNode,
     *atual;
  
  atual = LISTA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void insere(Elem *LISTA)
{
 int pos,
  count;
 printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
 scanf("%d", &pos);
 
 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA);
  else{
   Elem *atual = LISTA->prox,
     *anterior=LISTA; 
   Elem *novo=aloca();
     
   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   tam++;
  }
   
 }else
  printf("Elemento invalido\n\n");  
}

Elem *retiraInicio(Elem *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja esta vazia\n");
  return NULL;
 }else{
  Elem *tmp = LISTA->prox;
  LISTA->prox = tmp->prox;
  tam--;
  return tmp;
 }
    
}

Elem *retiraFim(Elem *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja vazia\n\n");
  return NULL;
 }else{
  Elem *ultimo = LISTA->prox,
    *penultimo = LISTA;
    
  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }
    
  penultimo->prox = NULL;
  tam--;
  return ultimo;  
 }
}

Elem *retira(Elem *LISTA)
{
 int opt,
  count;
 printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
 scanf("%d", &opt);
 
 if(opt>0 && opt <= tam){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
   Elem *atual = LISTA->prox,
     *anterior=LISTA; 
     
   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->prox;
   }
   
  anterior->prox=atual->prox;
  tam--;
  return atual;
  }
   
 }else{
  printf("Elemento invalido\n\n");
  return NULL;
 }
}