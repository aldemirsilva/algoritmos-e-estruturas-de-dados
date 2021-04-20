#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int ocorre;
    struct no *prox;
    char palavra[];
}TNo;

typedef struct lista {
    TNo *inicio;
    int tam;
}TLista;

TNo *criarNo(char palavra[]) {
    TNo *no = malloc(sizeof(TNo));
    strcpy(no->palavra, palavra);
    no->ocorre = 1;
    no->prox = NULL;
    return no;
}

void imprimirNo(TNo *no){
    printf("%s (%d)\n", no->palavra, no->ocorre);
}

void imprimirLista(TLista *lst) {
    TNo *cam = lst->inicio;
    while (cam != NULL) {
        imprimirNo(cam);
        cam = cam->prox;
    }
    printf("Total de palavras: %d\n", lst->tam);
}

TLista *criarLista() {
    TLista *lst = malloc(sizeof(TLista));
    lst->inicio = NULL;
    lst->tam = 0;
    return lst;
}

void inserirLista(TLista *lst, TNo *novo) {
    if (lst->inicio == NULL) {
        lst->inicio = novo;
        lst->tam++;
    }
    else {
        TNo *cam;
        cam = lst->inicio;
        while (cam->prox != NULL) {
            cam = cam->prox;
        }
        cam->prox = novo;
        lst->tam++;
    }
}

void removerDuplicados(TLista *l) {
    TNo *base = l->inicio;

    while (base) {
        TNo *anterior = base;
        TNo *atual = anterior->prox;
        while (atual) {
            if (strcmp(base->palavra, atual->palavra) == 0) {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
                base->ocorre++;
                l->tam--;
            }
            else {
                anterior = atual;
                atual = atual->prox;
            }
        }
        base = base->prox;
    }
}

void maiorIncidencia(TLista *l) {
    TNo *aux = l->inicio;
    TNo *maior = NULL;
    int num = 0;

    while (aux) {
        if (aux->ocorre > num) {
            num = aux->ocorre;
            maior = aux;
        }
        aux = aux->prox;
    }
    printf("Maior incidencia: %s - %d vezes\n", maior->palavra, maior->ocorre);
}

//** realiza a leitura de uma palavra do texto
//retornando (implicitamente) a palavra lida (se houver)
// e o último caracter lido.
//
char lerpalavra(char palavra[]){
    char pontuacao[] = ".,<>?/''!+-_={}[] \\\n|";
    char *p, letra;
    int i = 0, sai = 0;
    palavra[i] = '\0';
    do {
        letra = getchar();
        if ((p = strchr(pontuacao, letra)) == NULL){
            palavra[i++]=letra;
            palavra[i]='\0';
        }
        else if ((letra == ' ') || (letra == '\n') ){
            sai = 1;
        }
    } while(!sai);
    return letra;
}

int main() {
    TLista *l1 = criarLista();
    char palavra[1000], c = '\0';

    while (c != '\n') {
        c = lerpalavra(palavra);
        TNo *novo = criarNo(palavra);
        inserirLista(l1, novo);
    }
    removerDuplicados(l1);
    imprimirLista(l1);
    maiorIncidencia(l1);
}