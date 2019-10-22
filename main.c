#include "lista.h"

void mostra_float( void *x);
int compara_float(void *x, void *y);

int main () {
    Lista l1;
    float x = 123.91239, y;

    inicializa_lista(&l1, sizeof(float));

    insereNoInicio(&l1, &x); // testa inserção no início

    x = 3.12;

    insereNoInicio(&l1, &x); // testa inserção no início

    x=0.6;

    insereNoInicio(&l1, &x); // testa inserção no início

    mostra_lista(l1, mostra_float); // mostra toda a lista

    x = 5;

    insereNoFim(&l1, &x); // testa inserção no final

    mostra_lista(l1, mostra_float); // mostra toda a lista

    removeDoInicio(&l1, &y); // testa remoção do início

    removeDoFim(&l1, &y); // testa remoção do fim

    mostra_lista(l1, mostra_float); // mostra toda a lista

    x = 9;

    insereNoFim(&l1, &x);

    mostra_lista(l1, mostra_float); // mostra toda a lista

    x = 12;

    insereNaPos(&l1, &x, 2);

    mostra_lista(l1, mostra_float); // mostra toda a lista

    removeDaPos(&l1, &y, 1);

    mostra_lista(l1, mostra_float); // mostra toda a lista

    x = 10000000;

    insereNaOrdem(&l1, &x, compara_float);

    x = 1.2;

    insereNaOrdem(&l1, &x, compara_float);

    x = 13;

    insereNaOrdem(&l1, &x, compara_float);

    mostra_lista(l1, mostra_float);

    x = 144000;

    printf("Modificando a posicao 1");

    modificaNaPos(&l1, &x, 1));

    mostra_lista(l1, mostra_float);

    leNaPos(&l1, &y, 2);

    printf("A posicao 2 tem %f", y);

    limpa_lista(&l1); // testa limpeza

    mostra_lista(l1, mostra_float); // mostra toda a lista

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

