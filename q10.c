#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, int x) {
    if (p->topo < MAX - 1) {
        p->dados[++(p->topo)] = x;
    }
}

int desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[(p->topo)--];
    }
    return -1;
}

typedef struct {
    Pilha p1;
    Pilha p2;
} Fila;

void inicializarFila(Fila *f) {
    inicializar(&f->p1);
    inicializar(&f->p2);
}

void entrarFila(Fila *f, int x) {
    empilhar(&f->p1, x);
}

int sairFila(Fila *f) {
    if (vazia(&f->p2)) {
        while (!vazia(&f->p1)) {
            empilhar(&f->p2, desempilhar(&f->p1));
        }
    }
    return desempilhar(&f->p2);
}

int main() {
    Fila f;
    inicializarFila(&f);

    entrarFila(&f, 10);
    entrarFila(&f, 20);
    entrarFila(&f, 30);

    printf("%d\n", sairFila(&f));
    printf("%d\n", sairFila(&f));

    entrarFila(&f, 40);

    printf("%d\n", sairFila(&f));
    printf("%d\n", sairFila(&f));

    return 0;
}