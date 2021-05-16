#include "stdio.h"
#include "stdlib.h"
#include "lista.h"
#include "fila.h"

TFila *criarFila(){
  TFila *f = malloc(sizeof(TFila));
  f->str = criarLSE();
  return f;
}

void mostrarFila(TFila *f){
  imprimirLSE(f->str, "Minha Fila", "Final fila");
}

void enfileirarFila(TFila *f, void *carga){
    TLista *str = f->str;
    TNo *novo = criarNo(carga);
    inserirLSE(str, novo);
}


// remover do inicio da fila
void *desenfileirarFila(TFila *f){
    void *carga=NULL;
    TNo *cabeca = removerLSE(f->str);
    if (cabeca != NULL){
      carga = cabeca->carga;
      cabeca->carga = NULL;
      destroyNo(cabeca);
    }
    return carga;
}
