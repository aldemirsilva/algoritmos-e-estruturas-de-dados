/*Enunciado

Digamos que um texto é um vetor de bytes, todos com valor entre 32 e 126. (Cada um desses bytes representa um caractere ASCII.)

Digamos que uma palavra é um segmento maximal de texto que consiste apenas de letras.

Escreva uma função que receba um texto e imprima uma relação de todas as palavras que ocorrem no texto juntamente com o número de ocorrências de cada palavra.

Use uma lista encadeada para armazenar as palavras.

 Dicas

Observe se a entrada não é um texto vazio.

Desconsidere acentuações.

Considere todos as letras como sendo maiúsculas ou minúsculas.

Considere que o texto digital não tenha ocorrência de numerais.

Uma palavra é definida no espaço por estar:

1) No início da frase, seguida de um espaço em branco

2) No meio da frase, antecedida e suscedida de espaços em branco

3) No final da frase, antecedida de um espaço em branco; podendo ser precedida de uma pontuação (:,.-?!)


Exemplos de Entrada e Saída

 Entrada

a aranha arranha a ra a ra arranha a aranha nem a aranha arranha a ra nem a ra arranha a aranha

 Saída

a (8)
aranha (4)
arranha (4)
ra (4)
nem (2)
Total de palavras: 5
Maior incidencia: a - 8 vezes

 Entrada

.

Saída

Total de palavras: 0*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct no {
    int ocorre;
    struct no *prox;
    char *palavra;
} TNo;

typedef struct lista {
    TNo *inicio;
    int tam;
} TLista;

TNo *criarNo(char *palavra) {
        TNo *no = (TNo *) malloc(sizeof(TNo));
        no->palavra = (char *) malloc(TAM*sizeof(char));
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
    TLista *lst = (TLista *) malloc(sizeof(TLista));
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
    TNo *base = l->inicio, *anterior, *atual;
    while (base) {
        anterior = base;
        atual = base->prox;
        while (atual) {
            if (strcmp(base->palavra, atual->palavra) == 0) {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
                base->ocorre++;
                l->tam--;
            }
            else {
                anterior = anterior->prox;
                if (atual) atual = atual->prox;
            }
        }
        base = base->prox;
    }
}

void maiorIncidencia(TLista *l) {
    TNo *aux = l->inicio, *maior = NULL;
    int num = 0;

    while (aux) {
        if ((aux->ocorre) > num) {
            num = aux->ocorre;
            maior = aux;
        }
        aux = aux->prox;
    }
    if (l->inicio) {
        printf("Maior incidencia: %s - %d vezes\n", maior->palavra, maior->ocorre);
	 }
}

char lerpalavra(char *palavra){
    char pontuacao[] = "~^…¬¢£³²¹§#$%¨&@ªº\"():;.,<>?/'!+-_={}[] \\\n*|\t\r0123456789";
    char letra;
    int i = 0;
    while (1) {
        letra = getchar();
        if (strchr(pontuacao, letra) == NULL) palavra[i++] = letra;
        else break;
    }
    palavra[i] = '\0';
    return letra;
}

void destroiLista(TLista *l) {
    TNo *anterior = l->inicio, *atual = NULL;
    if (anterior) {
        atual = anterior->prox;
        while (anterior) {
            free(anterior->palavra);
            free(anterior);
            anterior = atual;
            if (atual) atual = atual->prox;
		  }
        free(l);
	 }
}

int main() {
    TLista *l1 = criarLista();
    char c = '\0', *palavra = (char *) malloc(TAM*sizeof(char));

    while (c != '\n') {
        c = lerpalavra(palavra);
        if (strlen(palavra) > 0) {
            TNo *novo = criarNo(palavra);
            inserirLista(l1, novo);
        }
    }
    removerDuplicados(l1);
    imprimirLista(l1);
    maiorIncidencia(l1);
    destroiLista(l1);
    free(palavra);
    return 0;
}
