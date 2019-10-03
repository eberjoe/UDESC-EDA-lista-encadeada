#define ERROLISTA_VAZIA -1

typedef struct ele {
    void *info;
    struct ele *proximo;
}Elemento;

typedef struct {
    Elemento *cabeca;
    int tamInfo, qtd;
}Lista;

void inicializa_lista(Lista *l, int t);
int lista_vazia(Lista *l);
int insereNoInicio(Lista *l, void *info);
int removeDoInicio(Lista *l, void *info);
void mostra_lista(Lista l, void (*mostra) (void *));
