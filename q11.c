#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializar_fila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void add_fila(Fila* f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    
    if (f->fim != NULL) {
        f->fim->prox = novo;
    }
    f->fim = novo;
    
    if (f->inicio == NULL) {
        f->inicio = novo;
    }
}

int remove_fila(Fila* f) {
    if (f->inicio == NULL) return -1; 
    
    No* temp = f->inicio;
    int valor = temp->valor;
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
    return valor;
}

int fila_vazia(Fila* f) {
    return f->inicio == NULL;
}

typedef struct {
    Fila f1;
    Fila f2;
} Pilha;

void inicializar_pilha(Pilha* p) {
    inicializar_fila(&p->f1);
    inicializar_fila(&p->f2);
}

void empilhar(Pilha* p, int valor) {
    add_fila(&p->f2, valor);
    
    while (!fila_vazia(&p->f1)) {
        add_fila(&p->f2, remove_fila(&p->f1));
    }
    
    Fila temp = p->f1;
    p->f1 = p->f2;
    p->f2 = temp;
}

int desempilhar(Pilha* p) {
    if (fila_vazia(&p->f1)) return -1;
    return remove_fila(&p->f1);
}
int main() {
    Pilha p;
    inicializar_pilha(&p);

    // Adicionar elementos à pilha
    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    // Remover e imprimir os elementos (LIFO: o último a entrar é o primeiro a sair)
    printf("Desempilhando: %d\n", desempilhar(&p)); // Deve imprimir 30
    printf("Desempilhando: %d\n", desempilhar(&p)); // Deve imprimir 20
    printf("Desempilhando: %d\n", desempilhar(&p)); // Deve imprimir 10

    return 0;
}