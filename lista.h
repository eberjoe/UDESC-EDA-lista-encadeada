typedef struct ele {
    void *info;
    struct ele *proximo;
}Elemento;

typedef struct {
    Elemento *cabeca;
    int tamInfo, qtd;
}Lista;

void inicializa_lista(Lista *l, int t);
int insereNoInicio(Lista *l, void *info);
