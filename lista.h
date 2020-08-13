#define ERRO_LDE_VAZIA -1
#define ERRO_POS_INVALIDA -2

typedef struct ele {
    void *info;
    struct ele *suc, *ant;
}EleDuplo;

typedef struct {
    EleDuplo *cabeca;
    int tamInfo, qtd;
}LDE;

void inicializa_LDE(LDE *l, int t);
int LDE_vazia(LDE *l);
int insereNoInicio(LDE *l, void *info);
int removeDoInicio(LDE *l, void *info);
int insereNoFim(LDE *l, void *info);
int removeDoFim(LDE *l, void *info);
int insereNaPos(LDE *l, void *info, int pos);
int removeDaPos(LDE *l, void *info, int pos);
int modificaNaPos(LDE *l, void *info, int pos);
int leNaPos(LDE *l, void *info, int pos);
int insereNaOrdem(LDE *l, void *info, int (*comp) (void *, void *));
void mostra_LDE(LDE l, void (*mostra) (void *));
void limpa_LDE(LDE *l);
