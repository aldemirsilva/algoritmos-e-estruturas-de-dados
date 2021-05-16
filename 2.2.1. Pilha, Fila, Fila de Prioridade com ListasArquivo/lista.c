#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include "lista.h"

TNo *criarNo(void *carga){
  TNo *novo = malloc(sizeof(TNo));
  novo->carga=carga;
  novo->prox = NULL;

  return novo;
}

void destroyNo(TNo *no){
  if (no->carga!=NULL){
    printf("WARNING: Carga do nó foi liberada da memória\n");
    printf("mas havia um endereço válido associado\n");
  }
  free(no);
}

void imprimirNo(TNo *no){
  printf("%p %p %p\n", no, no->carga, no->prox );

}

TLista *criarLSE(){
  TLista *lst = malloc(sizeof(TLista));
  lst->tam=0;
  lst->inicio=NULL;
  return lst;
}

// inserir no final da lse.
void inserirLSE(TLista *l, TNo *novo){
  TNo *cam = l->inicio;
  l->tam++;
  if (cam == NULL){ // inserir no inicio
    l->inicio = novo;
  }else{
    while(cam->prox!=NULL){
      cam = cam->prox;
    }
    cam->prox = novo;
  }
}

// inserir no inicio da lse.
void inserirInicioLSE(TLista *l, TNo *novo){
  //TNo *cam = l->inicio;
  l->tam++;
  // if (cam == NULL){ // inserir em lista vazia
  //   l->inicio = novo;
  // }else{
  //   novo->prox = l->inicio;
  //   l->inicio = novo;
  // }
  novo->prox = l->inicio;
  l->inicio = novo;
}
//(1carga < 2carga) => menor que zero
//1carga == 2carga) => igual a zero
//1carga > 2carga)  => maior que zero

void inserirOrdenadoLSE(TLista *lst, TNo *novo, TCompararElementoLSE comparar ){
  TNo *anterior = NULL;
  TNo *cam = lst->inicio;
  //busca do local de inserção
  while( (cam != NULL) && (comparar(cam->carga,novo->carga)<=0) ){
    anterior = cam;
    cam = cam->prox;
  }

  // inserir no Inicio
  if (cam == lst->inicio){
    novo->prox = lst->inicio;
    lst->inicio = novo;
    // inserir no Final
  } else if (cam == NULL){
    anterior->prox = novo;
    novo->prox = NULL;
    // inserir em posição intermediária
  } else{
    anterior->prox = novo;
    novo->prox = cam;
  }

}


TNo *removerLSE(TLista *l){
    TNo *cabeca = l->inicio;

    if (l->inicio !=NULL){
      l->inicio = l->inicio->prox;
      l->tam--;
    }
    return cabeca;
}

void imprimirLSE(TLista *lst, char *abertura, char *fechamento){
  TNo *cam = lst->inicio;
  printf("%s\n", abertura);

  while(cam != NULL ){

    imprimirNo(cam);
    // printf("%d ", cam->num);
    cam = cam->prox;
  }
  printf("%s\n", fechamento);

}
