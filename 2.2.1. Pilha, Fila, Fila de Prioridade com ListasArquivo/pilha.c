#include "stdio.h"
#include "stdlib.h"
#include "lista.h"
#include "pilha.h"
/*
criarPilha()
empilharPilha()
desempilharPilha()
Barbara -> topoPilha() // retonar o topo pilha mas mantém elemento empilhado
Richard -> medirPilha()  //retornar altura da pilha
Aldemir -> tavaziaPilha() // 0 ou 1 -- falso ou verdade
desmobilizarPilha()
*/
struct pilha{
  TLista *lst;
  // altura maxima

  //estatisticas
  //    altura máxima alcançada
  //    nro elementos passados pela pilha
};

TPilha *criarPilha(){
    TPilha *p = malloc(sizeof(TPilha));
    p->lst = criarLSE();

    return p;
}

void empilharPilha(TPilha *p, void *novo){
      TLista *lst = p->lst;

      TNo *no = criarNo(novo);

      inserirInicioLSE(lst, no);

}

void *desempilharPilha(TPilha *p){
  TLista *lst = p->lst;
  void *carga = NULL;

  TNo *topo = removerLSE(lst);

  if (topo !=NULL){
    carga = topo->carga;
    free(topo);
  }

  return carga;
}

void *topoPilha(TPilha *p){
  TLista *lst = p->lst;
  TNo *no = lst->inicio;

  void *carga = NULL;
  if (no !=NULL)
    carga = no->carga;

  return carga;
}

int tavaziaPilha(TPilha *p){
  TLista *lst = p->lst;

  return (lst->inicio == NULL);
}

int medirPilha(TPilha *p){
  TLista *lst = p->lst;
  return lst->tam;
}

// int main(int argc, char const *argv[]) {
//
//   TPilha *p = criarPilha();
//   int num;
//   scanf("%d",&num);
//   while (num > 0){
//     TNo *novo = criarNo(num);
//
//     empilharPilha(p, novo);
//     scanf("%d",&num);
//
//   }
//
//   TNo *novo = desempilharPilha(p);
//    imprimirNo(novo);
//   //
//   novo = desempilharPilha(p);
//   imprimirNo(novo);
//
//   novo = desempilharPilha(p);
//   imprimirNo(novo);
//
//   printf("===============\n");
//   if (!tavaziaPilha(p)){
//     imprimirNo(topoPilha(p));
//     printf("Altura da pilha: %d\n", medirPilha(p));
//   }else{
//     printf("Pilha Vazia, Altura da pilha: %d\n", medirPilha(p));
//
//   }
//
//   return 0;
// }
