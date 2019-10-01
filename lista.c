#include <stdio.h>

void inicializa_lista(Lista *l, int t) {
  l->cabeca = NULL;
  l->tamInfo = t;
  l->qtd = 0;
}
