#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "heap.h"

struct heap{
  void* *vetor;
  int tamanho;
  int ocupacao;
};

THeap *criarHeap(int tam){
  THeap *heap = malloc(sizeof(THeap));
  heap->tamanho=(int)pow(2,ceil(log2(tam)));
  heap->vetor = malloc(sizeof( void* ) * heap->tamanho);
  heap->ocupacao = 0;

  return heap;
}

static void trocarElementoHeap(void* vetor[], int imenor, int i){
  void *carga = vetor[imenor];
  vetor[imenor] = vetor[i];
  vetor[i] = carga;
}


void heapifica(THeap *heap, int i, TCompararElementoHeap comparar){
  void* *vetor = heap->vetor;
  int esq = 2*i + 1;
  int dir = 2*i + 2;

  int imenor = i;
  if (esq > heap->ocupacao)
    return ;
  else if (comparar(vetor[imenor], vetor[esq]) > 0)
    imenor = esq;
  if ( (dir < heap->ocupacao) && (comparar(vetor[imenor], vetor[dir])>0) )
    imenor = dir;

  if (imenor != i){
    trocarElementoHeap(vetor, imenor, i);
    heapifica(heap, imenor, comparar);
  }
}

void montarHeap(THeap *heap, TCompararElementoHeap comparar){
  int meio = (heap->ocupacao-1)/2;
  for(int i=meio;i>=0;i--){
    heapifica(heap,i,comparar);
  }
}

void *raizHeap(THeap *heap){

  return heap->vetor[0];

}

void *removerHeap(THeap *heap, TCompararElementoHeap comparar){

  if (heap->ocupacao == 0)
    return NULL;

  trocarElementoHeap(heap->vetor, 0, heap->ocupacao-1);
  heap->ocupacao--;
  heapifica(heap,0,comparar);

  void *carga = heap->vetor[heap->ocupacao];
  heap->vetor[heap->ocupacao] = NULL;

 return carga;
}


void mostrarHeap(THeap *heap){

    for(int i=0;i<heap->ocupacao;i++)
      printf("%p\n", heap->vetor[i]);

}

void inserirHeap(THeap *heap, void *carga, TCompararElementoHeap comparar){

    if (heap->ocupacao >= heap->tamanho){
      printf("Overflow do vetor\n");
      heap->tamanho*=2;
      int tamEmBytes = sizeof( void* ) * heap->tamanho;
      heap->vetor = realloc(heap->vetor,tamEmBytes);
//    printf("Erro na Insercao: Overflow do vetor. Precisa implementar VD\n");
//     exit(0);
    }
    heap->vetor[heap->ocupacao] =  carga;

    int i = heap->ocupacao;
    int pai =  (i - 1)/2;
    int continua = 1;

    while( (i>0) && (continua)){
      if (comparar(heap->vetor[pai], heap->vetor[i]) < 0){
          //printf("pai: %d  filho: %d\n", pai, i);
          trocarElementoHeap(heap->vetor, pai, i);
          heapifica(heap,i,comparar);
          i = pai;
          pai = (i-1)/2;
      }else{
        continua=0;
      }
    }
    heap->ocupacao++;
}

int ocupacaoHeap(THeap *heap){
  return heap->ocupacao;
}
