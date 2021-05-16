#include "stdio.h"
#include "stdlib.h"
#include "filaprioridade.h"

typedef struct senha{
  int num;
  int hora;
  int min;
}TSenha;

TSenha *criarSenha(int num, int hora, int min){
    TSenha *senha = malloc(sizeof(TSenha));
    senha->num = num;
    senha->hora = hora;
    senha->min = min;

    return senha;
}

void imprimirSenha(TSenha *senha){
  printf("%d %d %d\n", senha->num, senha->hora, senha->min);
}

void destroySenha(TSenha *s){
  if (s!=NULL)
    free(s);
}

int compararSenha(void *s1, void *s2){
    TSenha *ss1 = s1;
    TSenha *ss2 = s2;

//    printf("Chamou a CompararSenha\n");

    // if (ss1->num == ss2->num){
    //   return 0;
    // }else if(ss1->num < ss2->num){
    //   return 1;
    // }else{
    //   return -1;
    // }
    return (ss1->num - ss2->num);
}

int main(int argc, char const *argv[]) {
  TFilaPrioridade *filaBanco = criarFilaPrioridade();
  TFilaPrioridade *filaId = criarFilaPrioridade();
  int servico;

  // 2 servicos
  scanf("%d", &servico);
  while(servico != 0){
    if (servico == 1){
      int num, hora, min;
      scanf("%d%d%d",&num, &hora, &min);
      TSenha *senha = criarSenha(num,hora,min);
      enfileirarFilaPrioridade(filaBanco, senha, compararSenha);
    }else if(servico == 2){
      int num, hora, min;
      scanf("%d%d%d",&num, &hora, &min);
      TSenha *senha = criarSenha(num,hora,min);
      enfileirarFilaPrioridade(filaId, senha, compararSenha);
    }
    scanf("%d", &servico);
  }
  // int num, hora, min;
  // scanf("%d",&num);
  // while(num > 0){
  //   scanf("%d%d",&hora, &min);
  //   TSenha *senha = criarSenha(num,hora,min);
  //   enfileirarFilaPrioridade(filaBanco, senha, compararSenha);
  //   scanf("%d",&num);
  // }
  mostrarFilaPrioridade(filaBanco);
  TSenha *senha = desenfileirarFilaPrioridade(filaBanco);
  imprimirSenha(senha);

  mostrarFilaPrioridade(filaId);
  senha = desenfileirarFilaPrioridade(filaId);
  imprimirSenha(senha);


  return 0;
}
