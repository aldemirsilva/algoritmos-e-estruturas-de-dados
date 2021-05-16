typedef struct no TNo;

TNo *criarNo(void *novo);
void imprimirNo(TNo *no);
void destroyNo(TNo *no);
void* acessarNo(TNo *no);
void nullifyNo(TNo *no);

typedef struct lista TLista;
typedef int(*TCompararElementoLSE)(void *e1, void *e2);

TLista *criarLSE();
void inserirLSE(TLista *l, TNo *novo);
void inserirInicioLSE(TLista *l, TNo *novo);
void inserirOrdenadoLSE(TLista *l, TNo *novo, TCompararElementoLSE comparar);
void *removerLSE(TLista *l);
void imprimirLSE(TLista *lst, char *abertura, char *fechamento);
void *primeiroLSE(TLista *lst);
int tamanhoLSE(TLista *lst);
