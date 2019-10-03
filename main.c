#include "lista.h"

int main () {
    Lista l1;
    float x = 123.91239, y;

    inicializa_lista(&l1, sizeof(float));

    printf("%d\n", insereNoInicio(&l1, &x));

    printf("%d\n", removeDoInicio(&l1, &y));

    printf("%d\n", removeDoInicio(&l1, &y));

    printf("%f", y);
}
