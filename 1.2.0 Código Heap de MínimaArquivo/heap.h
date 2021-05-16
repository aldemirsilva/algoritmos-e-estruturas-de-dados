typedef struct heap THeap;
typedef int(*TCompararElementoHeap)(void *s1, void *s2);

THeap *criarHeap(int tam);
void heapifica(THeap *heap, int i, TCompararElementoHeap comparar);
void montarHeap(THeap *heap, TCompararElementoHeap comparar);
void *raizHeap(THeap *heap);
void *removerHeap(THeap *heap, TCompararElementoHeap comparar);

//
void mostrarHeap(THeap *heap);
void inserirHeap(THeap *heap, void *carga, TCompararElementoHeap comparar);
int ocupacaoHeap(THeap *heap);
