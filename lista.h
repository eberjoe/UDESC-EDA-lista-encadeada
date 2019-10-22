#define ERROLISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2

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
int insereNoFim(Lista *l, void *info);
int removeDoFim(Lista *l, void *info);
int insereNaPos(Lista *l, void *info, int pos);
int removeDaPos(Lista *l, void *info, int pos);
int modificaNaPos(Lista *l, void *info, int pos);
int leNaPos(Lista *l, void *info, int pos);
int insereNaOrdem(Lista *l, void *info, int (*comp) (void *, void *));
void mostra_lista(Lista l, void (*mostra) (void *));
void limpa_lista(Lista *l);
