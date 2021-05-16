typedef struct no TNo;
struct no{
  void *carga;
  struct no *prox;
};

typedef struct lista TLista;
struct lista{
  int tam;
  TNo *inicio;
};

TNo *criarNo(void *novo);
void imprimirNo(TNo *no);
void destroyNo(TNo *no);

typedef int(*TCompararElementoLSE)(void *e1, void *e2);

TLista *criarLSE();
void inserirLSE(TLista *l, TNo *novo);
void inserirInicioLSE(TLista *l, TNo *novo);
void inserirOrdenadoLSE(TLista *l, TNo *novo, TCompararElementoLSE comparar);
TNo *removerLSE(TLista *l);
void imprimirLSE(TLista *lst, char *abertura, char *fechamento);
