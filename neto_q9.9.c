#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char item;
    struct No *prox;
} No;

void empilha(char x, No **P) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria.\n");
        exit(1);
    }

    novo->item = x;
    novo->prox = *P;
    *P = novo;
}

char desempilha(No **P) {
    No *aux;
    char x;

    if (*P == NULL) {
        printf("Pilha vazia.\n");
        exit(1);
    }

    aux = *P;
    x = aux->item;
    *P = aux->prox;

    free(aux);

    return x;
}

int main() {
    No *P = NULL;

    empilha('a', &P);
    empilha('b', &P);
    empilha('c', &P);

    printf("Desempilhando: %c\n", desempilha(&P));
    printf("Desempilhando: %c\n", desempilha(&P));
    printf("Desempilhando: %c\n", desempilha(&P));

    return 0;
}