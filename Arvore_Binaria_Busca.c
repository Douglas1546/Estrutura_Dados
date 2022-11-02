//Aluno: Douglas Veras
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir(raiz->esquerda, num);
        else
            raiz->direita = inserir(raiz->direita, num);
        return raiz;
    }
}

void imprimir(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

NoArv* buscar(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar(raiz->esquerda, num);
        else
            return buscar(raiz->direita, num);
    }
    return NULL;
}


int main(){
    system("cls");
    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n0 - Sair\n\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            raiz =inserir(raiz, valor);
            break;
        case 2:
            system("cls");
            printf("\n=====Elementos inseridos=====\n");
            imprimir(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n===========================================\n");
            printf("\nDigite o valor que deseja pesquisar: ");
            scanf("%d", &valor);
            busca = buscar(raiz, valor);
            if(busca)
                printf("\nValor encontrado: %d\n", busca->valor);
            else
                printf("\nValor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}