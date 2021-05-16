typedef struct fila{
  TLista *str;
  // estatisticas da fila
}TFila;

TFila *criarFila();
void mostrarFila(TFila *f);
void enfileirarFila(TFila *f, void *carga);
void *desenfileirarFila(TFila *f);
