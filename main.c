#include "lista.h"

void mostra_float( void *x);

int main () {
    Lista l1;
    float x = 123.91239, y;

    inicializa_lista(&l1, sizeof(float));

    printf("%d\n", insereNoInicio(&l1, &x));

    mostra_lista(l1, mostra_float);

    printf("%d\n", removeDoInicio(&l1, &y));

    printf("%d\n", removeDoInicio(&l1, &y)); // erro por lista vazia

    printf("Valor %f", y);
}

void mostra_float( void *x) {
    printf("%f\n", *(float*) x);
}
