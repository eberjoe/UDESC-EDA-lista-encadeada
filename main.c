#include "lista.h"

int main () {
    Lista l1;
    float c = 123.91239;
    inicializa_lista(&l1, sizeof(float));
    printf("%d", insereNoInicio(&l1, &c));
}
