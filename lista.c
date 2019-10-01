#include <stdstring.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void inicializa_lista(Lista *l, int t) {
    l->cabeca = NULL;
    l->tamInfo = t;
    l->qtd = 0;
}

int insereNoInicio(Lista *l, void *info) {
    Elemento *p = malloc(sizeof(Elemento));
    if (p == NULL)
        return 0; //falta memória
    p->info = malloc(l->tamInfo);
    if (p->info == NULL) {
        free(p);
        return 0; //falta memória
    }
    memcpy(p->info, info, l->tamInfo);
}
