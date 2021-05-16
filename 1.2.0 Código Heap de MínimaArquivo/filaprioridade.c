#include "stdio.h"
#include "stdlib.h"
//#include "lista.h"
//#include "fila.h"
#include "heap.h"
#include "filaprioridade.h"

struct filaprioridade{
  THeap *str;
  //TLista *str;
  //estatisticas da fila
};

TFilaPrioridade *criarFilaPrioridade(){

  TFilaPrioridade *fp = malloc(sizeof(TFilaPrioridade));

  fp->str = criarHeap(5);

  return fp;
}

void mostrarFilaPrioridade(TFilaPrioridade *fp){
  mostrarHeap(fp->str);
}

void enfileirarFilaPrioridade(TFilaPrioridade *fp, void *carga, TCompararElementoFilaPrioridade comparar){
    //TLista *str = f->str;
    THeap *str = fp->str;
    //TNo *novo = criarNo(carga);
    //inserirOrdenadoLSE(str, novo, comparar);
    //printf("carga: %p\n", carga);
    inserirHeap(str, carga, comparar);

}

// remover do inicio da fila
void *desenfileirarFilaPrioridade(TFilaPrioridade *fp, TCompararElementoFilaPrioridade comparar){

//    void *carga = desenfileirarFila((TFila*)f;

  void *carga = removerHeap(fp->str, comparar);

  return carga;

}

void *cabecaFilaPrioridade(TFilaPrioridade *fp){
  void *carga = raizHeap(fp->str);

  return carga;
}

int tamanhoFilaPrioridade(TFilaPrioridade *fp){

    return ocupacaoHeap(fp->heap);
}

short vaziaFilaPrioridade(TFilaPrioridade *fp){

  return (ocupacaoHeap(fp->heap)==0);
}
