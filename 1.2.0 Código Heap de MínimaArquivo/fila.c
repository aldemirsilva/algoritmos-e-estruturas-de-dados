#include "stdio.h"
#include "stdlib.h"
#include "lista.h"
#include "fila.h"

TFila *criarFila(){
  TFila *f = malloc(sizeof(TFila));
  f->str = criarLSE();
  //f->str->tamanho = 0;
  return f;
}

void mostrarFila(TFila *f){
  imprimirLSE(f->str, "Minha Fila", "Final fila");
}

void enfileirarFila(TFila *f, void *carga){
    TLista *str = f->str;
    inserirLSE(str, carga);
}


// remover do inicio da fila
void *desenfileirarFila(TFila *f){
    void *carga=NULL;
    carga = removerLSE(f->str);
    return carga;
}

void *cabecaFila(TFila *f){
    void *carga = primeiroLSE(f->str);
    return carga;
}

int tamanhoFila(TFila *f){
  return tamanhoLSE(f->str);
}

short vaziaFila(TFila *f){
  void *carga = primeiroLSE(f->str);
  return (carga == NULL);
}
