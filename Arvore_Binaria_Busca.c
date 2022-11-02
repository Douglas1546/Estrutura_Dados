#include <stdio.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

void inserir(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

void imprimir(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

int main(){

    NoArv *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            inserir(&raiz, valor);
            break;
        case 2:
            printf("\n=====Elementos inseridos=====\n");
            imprimir(raiz);
            printf("\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}