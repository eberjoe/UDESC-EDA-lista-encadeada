#include "lista.h"

void mostra_float( void *x);

int main () {
    Lista l1;
    float x = 123.91239, y;

    inicializa_lista(&l1, sizeof(float));

    insereNoInicio(&l1, &x); // testa inserção no início

    x = 3.12;

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

    limpa_lista(&l1); // testa limpeza

    mostra_lista(l1, mostra_float); // mostra toda a lista

}

void mostra_float(void *x) {
    printf("%f\n", *(float*) x);
}
