#include "senha.h"
#include "../casodeuso/heap.h"
#include "stdio.h"

typedef int (*TCompararElementoOrd)(void* s1, void* s2);

static void trocarElementoOrd(void *vetor[], int m, int n){
  void *carga = vetor[m];
  vetor[m]= vetor[n];
  vetor[n] = carga;
}

static int pivotarQS(void* vetor[], int prim, int ult, TCompararElementoOrd comparar ){

  int i = prim;
  int j = ult;
  int meio = (i+j)/2;
  void *pivo = vetor[meio];

  trocarElementoOrd(vetor,meio,ult);

  j=j-1;

  do{
    while(comparar(vetor[i],pivo)<0){
      i++;
    }
    while( (j>=0) && (comparar(vetor[j],pivo)>=0) ){
      j--;
    }
    if (i<j){
      trocarElementoOrd(vetor,i,j);
    }
  }while(i<j);

  trocarElementoOrd(vetor,i,ult);

  return i;
}

static void QS(void* vetor[], int prim, int ult, TCompararElementoOrd comparar){

  if ((ult-prim) < 1)
    return;

  int meio = pivotarQS(vetor, prim, ult,comparar);
  QS(vetor,prim,meio-1,comparar);
  QS(vetor,meio+1,ult,comparar);

}

void quicksort(void* vetor[], int tam, TCompararElementoOrd comparar){

  QS(vetor, 0, tam-1, comparar);

}

void heapsort(void* vetor[], int tam, TCompararElementoOrd comparar){
    THeap *heap = criarHeap(tam);

    transferParaHeap(heap, vetor, tam);
    montarHeap(heap, comparar);
    int ocupacao = ocupacaoHeap(heap);
    int i=0;
    while(i < ocupacao){
      vetor[i] = removerHeap(heap, comparar);
      i++;
    }

    destroyHeap(heap);
}



int main(int argc, char const *argv[]) {

  int i, tam;
  int num, hora, min;

  scanf("%d", &tam);

  void* entrada[tam];

  for(i=0;i<tam;i++){
    scanf("%d %d %d", &num, &hora, &min);
    TSenha *senha = criarSenha(num, hora, min);
    entrada[i] = senha;
  }

  //heapsort(entrada, tam, compararSenha);
  quicksort(entrada, tam, compararSenha);

  printf("Ordenado======\n");
  for(i=0;i<tam;i++){
    imprimirSenha(entrada[i]);
  }

  return 0;
}
