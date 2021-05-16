#include "senha.h"
#include "stdio.h"

typedef int (*TCompararElementoOrd)(void* s1, void* s2);

static void trocarElemento(void* vetor[], int i, int j){
  void *carga = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = carga;
}

void insercao(void* vetor[], int tam, TCompararElementoOrd comparar){
  int i,j;
  for(j=1;j<tam;j++){
    void* carga = vetor[j];
    i=j-1;
    while((i>=0) && (comparar(vetor[i], vetor[i+1]) > 0)){
        trocarElemento(vetor, i, i+1);
        i--;
    }
    //vetor[i+1] = carga;
  }
}

void bolha(void* vetor[], int tam, TCompararElementoOrd comparar){
  int j, i;

  for(j=0;j<=tam-2;j++){
    for(i=0;i<tam-1-j;i++){
      if (comparar(vetor[i], vetor[i+1]) > 0) // novo menor encontrado
        trocarElemento(vetor,i,i+1);
      }
    }
}

void selecao(void* vetor[], int tam, TCompararElementoOrd comparar){
  int j, i, imenor;

  for(j=0;j<tam-1;j++){
    imenor = j; // suposição
    for(i=j+1;i<tam;i++){
    //i=1...n-1; 2...n-1;...n-2...n-1 = (n-1)+(n-2)+...+2 = nˆ2 - n/2
      if (comparar(vetor[i], vetor[imenor]) <= 0) // novo menor encontrado
        imenor = i; // ajuste da suposição
    }
    trocarElemento(vetor,j,imenor);
  }
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

  //selecao(entrada, tam, compararSenha);
  //bolha(entrada, tam, compararSenha);
  //insercao(entrada, tam, compararSenha);

  for(i=0;i<tam;i++){
    imprimirSenha(entrada[i]);
  }

  return 0;
}
