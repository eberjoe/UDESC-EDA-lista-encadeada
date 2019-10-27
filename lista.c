#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

void inicializa_LDE(LDE *l, int t) {
    l->cabeca = NULL;
    l->tamInfo = t;
    l->qtd = 0;
}

int LDE_vazia(LDE *l) {
    return !l->qtd;
}

EleDuplo* aloca_ele(void *x, int t){
	EleDuplo *p = malloc(sizeof(EleDuplo));
	if (!p)
		return NULL; // falta memória
	p->info = malloc(t);
	if (!p->info){
		free(p);
		return NULL; // falta memória
	}
	memcpy(p->info, x, t);
	return p;
}

int insereNoInicio(LDE *l, void *info) {
    EleDuplo *p = aloca_ele(info, l->tamInfo);
    if ((p->suc = l->cabeca))
        p->suc->ant = p;
    l->cabeca = p;
    p->ant = NULL;
    l->qtd++;
    return 1; // sucesso
}

int removeDoInicio(LDE *l, void *info) {
    if (LDE_vazia(l))
        return ERROLDE_VAZIA;
    EleDuplo *p = l->cabeca;
    memcpy(info, p->info, l->tamInfo);
    l->cabeca = p->suc;
    p->suc->ant = NULL;
    l->qtd--;
    free(p->info);
    free(p);
    return 1; // sucesso
}

int insereNoFim(LDE *l, void *info) {
    EleDuplo *p = aloca_ele(info, l->tamInfo);
    p->suc = NULL;
    if (!l->cabeca) {
        insereNoInicio(l, info);
    } else {
        EleDuplo *q = l->cabeca;
        while (q->suc) {
            q = q->suc;
        }
        q->suc = p;
        p->ant = q;
    }
    l->qtd++;
    return 1; // sucesso
}

int removeDoFim(LDE *l, void *info) {
    if (LDE_vazia(l))
        return ERROLDE_VAZIA;
    if (l->qtd == 1)
        return removeDoInicio(l, info);
    EleDuplo *p = l->cabeca;
    while (p->suc->suc) { // penúltimo
        p = p->suc;
    }
    memcpy(info, p->suc->info, l->tamInfo);
    free(p->suc->info);
    free(p->suc);
    p->suc = NULL;
    l->qtd--;
    return 1; // sucesso
}

int insereNaPos(LDE *l, void *info, int pos) {
    if (pos < 0 || pos > l->qtd)
        return ERRO_POS_INVALIDA;
    if (!pos)
        return insereNoInicio(l, info);
    EleDuplo *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos-1; cont++)
        p = p->suc;
    EleDuplo *novo = aloca_ele(info, l->tamInfo);
    novo->suc = p->suc;
    novo->ant = p;
    p->suc = novo;
    l->qtd++;
    return 1; // sucesso
}

int removeDaPos(LDE *l, void *info, int pos) {
    if (LDE_vazia(l))
        return ERROLDE_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    if (!pos)
        return removeDoInicio(l, info);
    EleDuplo *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos-1; cont++)
        p = p->suc;
    EleDuplo *x = p->suc;
    p->suc = x->suc;
    p->suc->ant = p;
    memcpy(info, x->info, l->tamInfo);
    free(x->info);
    free(x);
    l->qtd--;
    return 1; // sucesso
}

int modificaNaPos(LDE *l, void *info, int pos) {
    if (LDE_vazia(l))
        return ERROLDE_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    EleDuplo *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++)
        p = p->suc;
    memcpy(p->info, info, l->tamInfo);
    return 1; // sucesso
}

int leNaPos(LDE *l, void *info, int pos) {
    if (LDE_vazia(l))
        return ERROLDE_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    EleDuplo *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++)
        p = p->suc;
    memcpy(info, p->info, l->tamInfo);
    return 1; // sucesso
}

int insereNaOrdem(LDE *l, void *info, int (*comp) (void *, void *)) {
    EleDuplo *p = l->cabeca;
    int cont = 0;
    while (p && comp(info, p->info) > 0) {
        p = p->suc;
        cont++;
    }
    return insereNaPos(l, info, cont);
}

void mostra_LDE(LDE l, void (*mostra) (void *)) {
    if (LDE_vazia(&l))
        printf("\nLDE vazia!\n");
    else {
        printf("\nDados da LDE:\n");
        EleDuplo *p = l.cabeca;
        int count =0;
        while (p) {
            printf("%d\t", count);
            mostra(p->info);
            p = p->suc;
            count++;
        }
    }
}

void limpa_LDE(LDE *l) {
    EleDuplo *p = l->cabeca, *q;
    while (p) {
        q = p;
        p = p->suc;
        free(q->info);
        free(q);
    }
    l->cabeca = NULL;
    l->qtd = 0;
}
