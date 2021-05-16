#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include "lista.h"

struct no{
  void *carga;
  struct no *prox;
};

TNo *criarNo(void *carga){
  TNo *novo = malloc(sizeof(TNo));
  novo->carga=carga;
  novo->prox = NULL;

  return novo;
}

void* acessarNo(TNo *no){
  return no->carga;
}

void nullifyNo(TNo *no){
  no->carga = NULL;
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

struct lista{
  int tamanho;
  TNo *inicio;
};

TLista *criarLSE(){
  TLista *lst = malloc(sizeof(TLista));
  lst->tamanho=0;
  lst->inicio=NULL;
  return lst;
}

// inserir no final da lse.
void inserirLSE(TLista *l, void *carga){
  TNo *novo = criarNo(carga);

  TNo *cam = l->inicio;
  l->tamanho++;
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
  l->tamanho++;

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

  lst->tamanho++;

}


void *removerLSE(TLista *l){
    TNo *cabeca = l->inicio;
    void *carga = NULL;

    if (l->inicio !=NULL){
      l->inicio = l->inicio->prox;
      l->tamanho--;
      carga = acessarNo(cabeca);
      nullifyNo(cabeca);
      destroyNo(cabeca);
    }

    return carga;
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

void *primeiroLSE(TLista *lst){
  TNo *cam = lst->inicio;
  void *carga = NULL;
  if (cam!=NULL){
    carga = cam->carga;
  }
  return carga;
}


int tamanhoLSE(TLista *lst){
  return lst->tamanho;
}
