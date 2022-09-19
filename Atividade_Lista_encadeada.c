// By: Douglas Veras
// Aluno de Ciência de Dados e Inteligência Artificial

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_no_inicio(Lista *lista, int num)
{
    system("cls");
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_no_meio(Lista *lista, int num, int ant)
{
    system("cls");
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        if (lista->inicio == NULL) // verifica se a lista está vazia
        { 
            novo->proximo = NULL;
            lista->inicio = novo; // se estiver vazia, a gentep reenche com o primeiro elemento
        }
        else
        {
            aux = lista->inicio;
            while (aux->valor != ant && aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar de memoria!\n");
    }
}

void inserir_no_fim(Lista *lista, int num)
{
    system("cls");
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (lista->inicio == NULL)
            lista->inicio = novo;
        else
        {
            aux = lista->inicio;
            while (aux->proximo != NULL)
            {                       // quando o proximo for igual posição NULL, significa que ele chegou ao final da lista
                aux = aux->proximo; // essa variavel auxiliar serve so para percorrer a lista ate achar o NULL, que é o final da lista
            }
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

void imprimir(Lista lista)
{
    system("cls");
    No *no = lista.inicio;
    printf("\nLista tam %d: \n", lista.tam);
    while (no)
    {
        printf("%d    ", no->valor);
        no = no->proximo;
    }

    printf("\n\n");
}

No *remover(Lista *lista, int num)
{
    No *aux, *remover = NULL;
    if (lista->inicio != NULL)
    {
        if (lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo != NULL && aux->proximo->valor != num)
            {
                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }
    return remover;
}

No *buscar(Lista *lista, int num)
{
    No *aux, *no = NULL;

    aux = lista->inicio;
    while (aux != NULL && aux->valor != num)
    {
        aux = aux->proximo;
    }
    if (aux != NULL)
    {
        no = aux;
    }
    return no;
}

void modificar(Lista *lista, int new, int antigo)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = antigo;
        if (lista->inicio == NULL) // verifica se a lista está vazia
        { 
            novo->proximo = NULL;
            lista->inicio = novo; // se estiver vazia, preenche com o primeiro elemento
        }
        else
        {
            aux = lista->inicio;
            while (aux->valor != antigo && aux->proximo != NULL) // varre a lista do inicio ao fim com um aux, para n perder os dados da lista.
            {
                aux = aux->proximo;
            }
            aux->valor = new;
        }
    }
    else
    {
        printf("Erro ao alocar de memoria!\n");
    }
}

int main()
{
    system("cls");
    int op, valor, ant, antigo, new;
    Lista lista;
    No *removido, *buscando;

    criar_lista(&lista);

    do
    {
        printf("\n 1 - Inserir no inicio \n 2 - Inserir no fim \n 3 - Inserir em uma posicao especifica \n 4 - Remover elemento");
        printf("\n 5 - Exibir a lista \n 6 - Exibir tamanho da lista\n 7 - Buscar elemento\n 8 - Modificar \n 0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            printf("Digite apos qual valor voce deseja inserir: ");
            scanf("%d", &ant);
            inserir_no_meio(&lista, valor, ant);

            break;
        case 4:
            printf("\nDigite o valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if (removido)
            {
                printf("\nElemendo %d removido\n", removido->valor);
                free(removido);
            }
            else
                printf("\nO elemento digitado nao existe!\n");
            break;
        case 5:
            imprimir(lista);
            break;
        case 6:
            printf("\nO tamanho da lista e: %d \n", lista.tam);
            break;
        case 7:
            printf("Digite o valor que deseja buscar: ");
            scanf("%d", &valor);
            buscando = buscar(&lista, valor);
            if (buscando != NULL)
            {
                printf("\nValor encontrado: %d\n", buscando->valor);
            }
            else
                printf("\nValor nao encontrado!\n");
            break;
        case 8:
            printf("Digite o numero que deseja modificar: ");
            scanf("%d", &antigo);
            printf("Digite o novo valor: ");
            scanf("%d", &new);
            modificar(&lista, new, antigo);
            break;
        case 0:
            break;
        default:
            if (op != 0)
            {
                printf("\nOpcao invalida!\n");
            }

            break;
        }

    } while (op != 0);
}