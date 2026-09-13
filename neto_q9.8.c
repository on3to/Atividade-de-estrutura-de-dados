#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char valor;
    struct No *prox;
} No;


char enesimo(int n, No *L) {

    
    if (n <= 0 || L == NULL) {
        printf("Erro fatal: elemento invalido.\n");
        exit(1);
    }

    
    if (n == 1) {
        return L->valor;
    }

    
    return enesimo(n - 1, L->prox);
}


int main() {

    
    No d = {'d', NULL};
    No c = {'c', &d};
    No b = {'b', &c};
    No a = {'a', &b};

    No *L = &a;

    printf("3o elemento: %c\n", enesimo(3, L));

    return 0;
}