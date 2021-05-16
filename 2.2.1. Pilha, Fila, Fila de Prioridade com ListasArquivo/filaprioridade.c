#include "stdio.h"
#include "stdlib.h"
#include "lista.h"
#include "fila.h"
#include "filaprioridade.h"

struct filaprioridade{
  TLista *str;
  //estatisticas da fila
};

TFilaPrioridade *criarFilaPrioridade(){

  TFila *f = criarFila();

  return (TFilaPrioridade*) f;
}

void mostrarFilaPrioridade(TFilaPrioridade *f){
  mostrarFila((TFila*)f);
}

void enfileirarFilaPrioridade(TFilaPrioridade *f, void *carga, TCompararElementoFilaPrioridade comparar){
    TLista *str = f->str;
    TNo *novo = criarNo(carga);
    inserirOrdenadoLSE(str, novo, comparar);
}

// remover do inicio da fila
void *desenfileirarFilaPrioridade(TFilaPrioridade *f){

    void *carga = desenfileirarFila((TFila*)f);
    return carga;

}
