#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct Pilha
{
    int dados[TAM];
    int topo;
    int tam;
} Pilha;

void criar_pilha(Pilha *p)
{
    for (int i = 0; i < TAM; i++)
    {
        p->dados[i] = 0;
    }
    p->topo = 0;
}

void empilhar(int dado, Pilha *p)
{
    system("cls");
    if (p->topo == TAM)
    {
        printf("Pilha cheia! \n");
        return;
    }
    else
    {
        p->dados[p->topo] = dado;
        p->topo++;
        return;
    }
}

int desempilhar(Pilha *p)
{
    system("cls");
    int aux;
    if (p->topo == 0)
    {
        printf("Pilha vazia!\n");
        return;
    }
    else
    {
        p->topo--;
        aux = p->dados[p->topo];

        printf("Saiu: %d", aux);
        printf("\nDesempilhado com sucesso!\n");
        return aux;
    }
}

void imprimir_pilha(Pilha *p)
{
    system("cls");
    printf("\nxxxxxxxxxxxxxxx PILHA Tam: %d xxxxxxxxxxxxxxx\n\n", p->topo);
    for (int i = 0; i < p->topo; i++)
    {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main()
{
    Pilha p;
    int op, valor, aux;

    criar_pilha(&p);

    do
    {
        printf("\n 1 - Empilhar\n 2 - Desempilhar\n 3 - Imprimir\n 0 - Sair\n\n");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            empilhar(valor, &p);
            break;
        case 2:
            desempilhar(&p);
            break;
        case 3:
            printf("\n");
            imprimir_pilha(&p);

            break;
        default:
            if (op != 0)
                printf("\nOpcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}