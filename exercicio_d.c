#include <stdio.h>
#include <stdlib.h>

struct no_lista {
    float valor;
    struct no_lista *prox;
};

typedef struct no_lista NoLista;

void inserir(float numero, NoLista **pLista) {
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
    novo->valor = numero;
    novo->prox = *pLista;
    *pLista = novo;
}

int main() {
    NoLista *inicio = NULL;

    inserir(3.5, &inicio);
    inserir(7.2, &inicio);
    inserir(9.8, &inicio);

    
    NoLista *atual = inicio;

    while (atual != NULL) {
        printf("%.2f ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
    
    atual = inicio;

    while (atual != NULL) {
        NoLista *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    return 0;
}
