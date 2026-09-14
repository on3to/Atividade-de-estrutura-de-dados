#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char item;
    struct No *prox;
} No;

void enfileira(char x, No **F) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria.\n");
        exit(1);
    }

    novo->item = x;

    if (*F == NULL) {
        novo->prox = novo;
        *F = novo;
    } else {
        novo->prox = (*F)->prox;
        (*F)->prox = novo;
        *F = novo;
    }
}

char desenfileira(No **F) {
    No *primeiro;
    char x;

    if (*F == NULL) {
        printf("Fila vazia.\n");
        exit(1);
    }

    primeiro = (*F)->prox;
    x = primeiro->item;

    if (primeiro == *F) {
        *F = NULL;
    } else {
        (*F)->prox = primeiro->prox;
    }

    free(primeiro);

    return x;
}

int main() {
    No *F = NULL;

    enfileira('a', &F);
    enfileira('b', &F);
    enfileira('c', &F);

    printf("Desenfileirando: %c\n", desenfileira(&F));
    printf("Desenfileirando: %c\n", desenfileira(&F));
    printf("Desenfileirando: %c\n", desenfileira(&F));

    return 0;
}