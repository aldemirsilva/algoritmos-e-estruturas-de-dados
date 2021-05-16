#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"

typedef struct prato{
  int profundidade; //1 - raso 2 - fundo
  int material; // 1 - porcelana 2- vidro; 3 - plastico;
  char uso[2]; // s - sobremesa, p - principal
}TPrato;

TPrato *criarPrato(int prof, int mat, char uso[]){
  TPrato *p = malloc(sizeof(TPrato));

  p->profundidade = prof;
  p->material = mat;
  sprintf(p->uso,"%s", uso);

  return p;
}
void imprimirPrato(TPrato *p){
  printf("%c %d %d\n", p->uso[0], p->material, p->profundidade);
}

int main(int argc, char const *argv[]) {

  TPilha *pratoSobremesa = criarPilha();
  int prof, mat;
  char uso[2];

  scanf("%s %d %d",uso, &prof, &mat);
  while (uso[0] == 's'){
    TPrato *novo = criarPrato(prof, mat, uso);

    empilharPilha(pratoSobremesa, novo);
    scanf("%s %d %d",uso, &prof, &mat);

  }

   TPrato *novo = desempilharPilha(pratoSobremesa);
   imprimirPrato(novo);

   return 0;
 }
