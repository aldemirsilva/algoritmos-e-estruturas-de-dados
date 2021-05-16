#include "stdio.h"
#include "stdlib.h"

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
  if (senha)
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
    //   return -1;
    // }else{
    //   return 1;
    // }
    return (ss1->num - ss2->num);
}
