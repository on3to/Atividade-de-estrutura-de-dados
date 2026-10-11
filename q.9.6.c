#include <stdio.h>
#include <stdlib.h>
//#define fmt "%d"

typedef int Item;
typedef struct no{
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item=x;
    n->prox=p;
    return n;
}

Lista inverter_lista (Lista L) {
    Lista atual=L; //ponteiro que pega o end memoria do inicio da lista.
    Lista anterior=NULL;
    Lista proximo=NULL; 
    
    while (atual!=NULL) {
        proximo = atual->prox;
        atual->prox=anterior;
        anterior=atual;
        atual=proximo;
    }
    return anterior;
}

void exibe_lista(Lista L) {
    while(L!=NULL) {
        if (L->prox != NULL) {
            printf("%d, ", L->item);
        } else {
            printf("%d\n", L->item);
        }
        L=L->prox;
    }
}

int main() {
    Lista A = no(2, no(4, no(6, no(8, NULL))));
    Lista B = no(1, no(2, no(3, NULL)));

    printf("\n===Listas Normais===\n");
    exibe_lista(A);
    exibe_lista(B);
    
    printf("\n===Listas Invertidas===\n");
    Lista lista_inevertida;
    
    lista_inevertida = inverter_lista(A);
    exibe_lista(lista_inevertida);
    lista_inevertida = inverter_lista(B);
    exibe_lista(lista_inevertida);
    
    printf("\n");

    system("pause");
}