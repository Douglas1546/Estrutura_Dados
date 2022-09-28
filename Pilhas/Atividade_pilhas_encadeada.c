#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char dados[30];
}tdados;

typedef struct no{
    tdados p;
    struct no *proximo;
}No;

typedef struct{
    No *topo;
    int tam;
}Pilha;

tdados ler_tdados(){
    tdados p;
    printf("\nDigite um nome ou numero para empilhar: ");
    scanf("%s", p.dados);
    return p;
}

void imprimir_tdados(tdados p){
    printf("\nNome / Numero: %s\n", p.dados);
}

void criar_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

void empilhar(Pilha *p){
    system("cls");
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_tdados();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
    else
        printf("\nErro ao alocar memoria...\n");
}

No* desempilhar(Pilha *p){
    system("cls");
    if(p->topo){
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}

void imprimir_pilha(Pilha *p){
    system("cls");
    No *aux = p->topo;
    printf("\nxxxxxxxxxxxxxxx PILHA Tam: %d xxxxxxxxxxxxxxx\n", p->tam);
    while(aux){
        imprimir_tdados(aux->p);
        aux = aux->proximo;
    }
    printf("\nxxxxxxxxxxxxxxx FIM PILHA xxxxxxxxxxxxxxxxxx\n");
}

int main(){

    No *remover;
    Pilha p;
    int op;

    criar_pilha(&p);

    do{
        printf("\n 1 - Empilhar\n 2 - Desempilhar\n 3 - Imprimir\n 0 - Sair\n");
        scanf("%d", &op);
        getchar();

        switch(op){
        case 1:
            empilhar(&p);
            break;
        case 2:
            remover = desempilhar(&p);
            if(remover){
                imprimir_tdados(remover->p);
                printf("\nDesempilhado com sucesso!\n");

                free(remover);
            }
            else
                printf("\nSem no a remover.\n");
            break;
        case 3:
            imprimir_pilha(&p);
            break;
        default:
            if(op != 0)
                printf("\nOpcao invalida!\n");
        }
    }while(op != 0);

    return 0;
}