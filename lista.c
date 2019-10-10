#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void inicializa_lista(Lista *l, int t) {
    l->cabeca = NULL;
    l->tamInfo = t;
    l->qtd = 0;
}

int lista_vazia(Lista *l) {
    return !l->qtd;
}

int insereNoInicio(Lista *l, void *info) {
    Elemento *p = malloc(sizeof(Elemento));
    if (!p)
        return 0; // falta memória
    p->info = malloc(l->tamInfo);
    if (!p->info) {
        free(p);
        return 0; // falta memória
    }
    memcpy(p->info, info, l->tamInfo);
    p->proximo = l->cabeca;
    l->cabeca = p;
    l->qtd++;
    return 1; // sucesso
}

int removeDoInicio(Lista *l, void *info) {
    if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    Elemento *p = l->cabeca;
    memcpy(info, p->info, l->tamInfo);
    l->cabeca = p->proximo;
    l->qtd--;
    free(p->info);
    free(p);
    return 1; // sucesso
}

int insereNoFim(Lista *l, void *info) {
    Elemento *p = malloc(sizeof(Elemento));
    if (!p)
        return 0; // falta memória
    p->info = malloc(l->tamInfo);
    if (!p->info) {
        free(p);
        return 0; // falta memória
    }
    memcpy(p->info, info, l->tamInfo);
    p->proximo = NULL;
    if (!l->cabeca) {
        insereNoInicio(l, info);
    } else {
        Elemento *q = l->cabeca;
        while (q->proximo) {
            q = q->proximo;
        }
        q->proximo = p;
        l->qtd++;
        return 1; // sucesso
    }
}

int removeDoFim(Lista *l, void *info) {
    if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    if (l->qtd == 1)
        return removeDoInicio(l, info);
    Elemento *p = l->cabeca;
    while (p->proximo->proximo) { // penúltimo
        p = p->proximo;
    }
    memcpy(info, p->proximo->info, l->tamInfo);
    free(p->proximo->info);
    free(p->proximo);
    p->proximo = NULL;
    l->qtd--;
    return 1; // sucesso
}

void mostra_lista(Lista l, void (*mostra) (void *)) {
    if (lista_vazia(&l))
        printf("\nLista vazia!\n");
    else {
        printf("\nDados da lista:\n");
        Elemento *p = l.cabeca;
        while (p) {
            mostra(p->info);
            p = p->proximo;
        }
    }
}
