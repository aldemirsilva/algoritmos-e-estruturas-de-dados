#include "stdio.h"
#include "stdlib.h"

typedef void (*TImprimirELSC)(void *);
//
typedef struct elem {
  void *carga;
  struct elem *prox;
} TElemLSE;

typedef struct dados {
  TElemLSE *prim;
} TDadosLSE;

typedef struct{
  void *dados;
} TListaSE;

TListaSE *criarLSE(){

  TDadosLSE *dados = malloc(sizeof(TDadosLSE));
  dados->prim=NULL;

  TListaSE *lse = malloc(sizeof(TListaSE));
  lse->dados = dados;

  return lse;
}

//inserir inicio
int inserirLSE(TListaSE *lse, void *carga){
  TDadosLSE *d = lse->dados;

  TElemLSE *e = malloc(sizeof(TElemLSE));
  e->prox = NULL;
  e->carga = carga;

  if (d->prim == NULL){
    d->prim = e;
  }else{
    e->prox = d->prim;
    d->prim = e;
  }

  return 1;
}


void imprimirLSE(TListaSE *lst, TImprimirELSC imprimir){
  TDadosLSE *d = lst->dados;
  TElemLSE *cam = d->prim;

  while (cam != NULL){
      imprimir(cam->carga);
      cam = cam->prox;
  }

}

typedef struct aviao{
  int nroTurbina;
  double nivelCombustivel;
  int prioridade;
} TAviao;

void *criarInstanciaAviao(int nroTurbina, double nivelCombustivel, int prioridade){

  TAviao *carga = malloc(sizeof(TAviao));
  carga->nroTurbina = nroTurbina;
  carga->nivelCombustivel = nivelCombustivel;
  carga->prioridade = prioridade;

  return carga;
}


void imprimirTipoAviao(void *pa){
  TAviao *a = pa;
  if (a!=NULL){
    printf("Prior: %d\n", a->prioridade);
    printf("turbinas: %d\n", a->nroTurbina);
    printf("nivelCombustivel: %.3lf\n", a->nivelCombustivel);
  }

}

typedef struct carro{
  int qtdeEixo;
  int qtdePorta;
  int qtdeMarcha;
} TCarro;

void *criarInstanciaCarro(int qtdeEixo,  int qtdePorta, int qtdeMarcha){

  TCarro *carga = malloc(sizeof(TCarro));
  carga->qtdeEixo = qtdeEixo;
  carga->qtdePorta = qtdePorta;
  carga->qtdeMarcha = qtdeMarcha;

  return carga;
}

void imprimirTipoCarro(void *pa){
  TCarro *a = pa;
  if (a!=NULL){
    printf("eixos: %d\n", a->qtdeEixo);
    printf("marchas: %d\n", a->qtdeMarcha);
    printf("portas: %d\n", a->qtdePorta);
  }

}



int main(int argc, char const *argv[]) {
  TListaSE *lst = criarLSE();
  void *carga;
  int qtde, tipo;
  scanf("%d %d", &qtde, &tipo);
  while ( qtde-- > 0){

    if (tipo == 1){ // complete o codigo
      int qtdeEixo, qtdeMarcha, qtdePorta;
      scanf("%d %d %d", &qtdeEixo, &qtdePorta, &qtdeMarcha);
      carga = criarInstanciaCarro(qtdeEixo, qtdePorta, qtdeMarcha);
    }else{ // complete o codigo
      int nroTurbina, prioridade;
      double nivelCombustivel;
      scanf("%d %lf %d", &nroTurbina, &nivelCombustivel, &prioridade);
      carga = criarInstanciaAviao(nroTurbina, nivelCombustivel, prioridade);
    }
    //complete o codigo 
  inserirLSE(lst, carga);
  }

  if (tipo == 1) // complete o codigo
    imprimirLSE(lst, imprimirTipoCarro);
  else
    imprimirLSE(lst, imprimirTipoAviao);

  return 0;
}
