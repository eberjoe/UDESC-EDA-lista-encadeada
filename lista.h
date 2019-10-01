typedef struct ele {
    void *info;
    struct ele *proximo;
}Elemento;

typedef struct {
    Elemento *cabeca;
    int tamInfo, qtd;
}Lista;
