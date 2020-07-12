#include <stdio.h>
#include "lista.h"

void mostra_float(void *x);
int compara_float(void *x, void *y);

int main() {
    LDE l1;
    float x = 123.91239, y;
    char r[2][11] = {"falhou!", "deu certo!"};

    inicializa_LDE(&l1, sizeof(float));

    printf("\nA insercao no inicio de %f %s\n", x, r[insereNoInicio(&l1, &x)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x = 3.12;

    printf("\nA insercao no inicio de %f %s\n", x, r[insereNoInicio(&l1, &x)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x=0.6;

    printf("\nA insercao no inicio de %f %s\n", x, r[insereNoInicio(&l1, &x)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x = 5;

    printf("\nA insercao no fim de %f %s\n", x, r[insereNoFim(&l1, &x)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    printf("\nA remocao do inicio de %f %s\n", y, r[removeDoInicio(&l1, &y)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    printf("\nA remocao do fim de %f %s\n", y, r[removeDoFim(&l1, &y)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x = 9;

    printf("\nA insercao no fim de %f %s\n", x, r[insereNoFim(&l1, &x)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x = 12;

    printf("\nA insercao na posicao 2 de %f %s\n", x, r[insereNaPos(&l1, &x, 2)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    printf("\nA remocao da posicao 1 de %f %s\n", y, r[removeDaPos(&l1, &y, 1)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x = 10000000;

    printf("\nA insercao ordenada de %f %s\n", x, r[insereNaOrdem(&l1, &x, compara_float)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x = 1.2;

    printf("\nA insercao ordenada de %f %s\n", x, r[insereNaOrdem(&l1, &x, compara_float)]);

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    x = 13;

    printf("\nA insercao ordenada de %f %s\n", x, r[insereNaOrdem(&l1, &x, compara_float)]);

    mostra_LDE(l1, mostra_float);

    x = 144000;

    printf("\nA sobrescrita de %f na posicao 1 %s\n", x, r[modificaNaPos(&l1, &x, 1)]);

    mostra_LDE(l1, mostra_float);

    printf("\nA leitura de %f na posicao 2 %s\n", y, r[leNaPos(&l1, &y, 2)]);

    limpa_LDE(&l1); // testa limpeza

    mostra_LDE(l1, mostra_float); // mostra toda a LDE

    return 0;
}

void mostra_float(void *x) {
    printf("%f\n", *(float*) x);
}

int compara_float(void *x, void *y) {
    float *a = x, *b = y;
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;
}

