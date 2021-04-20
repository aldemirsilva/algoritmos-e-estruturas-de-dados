#include <stdio.h>
#include <stdlib.h>

struct tipoNo {
    int num;
    struct tipoNo* prox;
};
typedef struct tipoNo TipoNo;

TipoNo *criarNo(int num) {
    TipoNo *novo = malloc(sizeof(TipoNo));
    novo->num = num;
    novo->prox = NULL;
}

void imprimeLista(TipoNo *primeiroPtr) {
    TipoNo* cam = primeiroPtr;
    while (cam) {
        printf("%d ", cam->num);
        cam = cam->prox;
    }
    printf("\n");
}

// Função que recebe um endereço de ponteiro para nó e insere no início de uma lista encadeada sem cabeça
void insereNoInicioDalista(TipoNo **cabeca, int dado) {
    TipoNo * novo = malloc(sizeof(TipoNo));
    novo->num = dado;
    novo->num = *cabeca;

    *cabeca = novo;
}

// Função para inserir um novo nó no fim da lista encadeada
void insereNoFimDaLista(TipoNo **primeiroPtr, int num) {
    TipoNo* novo = criarNo(num);

    if (*primeiroPtr == NULL) {
        *primeiroPtr = novo;
    }
    else {
        TipoNo *cam = *primeiroPtr;
        while (cam->prox != NULL) {
            cam = cam->prox;
        }
        cam->prox = novo;
    }
}

 /*Função recursiva para inverter uma lista encadeada. Inverte a lista e aponta
 os nós do restante da lista na ordem inversa*/
void inverteListaRec(TipoNo* primeiroPtr, TipoNo** refPrimeiro) {
    TipoNo* primeiro;
    TipoNo* resto;

    // Caso base para lista vazia
    if (primeiroPtr == NULL) {
        return;
    }

    primeiro = primeiroPtr;           // Suponha primeiro = {1, 2, 3}
    resto = primeiro->prox;     // resto = {2, 3}

    // Caso base: a lista possui apenas um nó
    if (resto == NULL) {
        // Fixa o ponteiro para a cabeça da lista
        *refPrimeiro = primeiro;
        return;
    }
    //Inverte recursivamente o menor caso {2, 3} e depois o resto {3, 2}
    inverteListaRec(resto, refPrimeiro);

    // Coloca o primeiro nó no fim da lista
    resto->prox = primeiro;
    primeiro->prox = NULL;
}

// Inverte uma lista encadeada. A função usa um ponteiro (referência) para o ponteiro primeiroPtr
void inverte(TipoNo **primeiroPtr) {
    inverteListaRec(*primeiroPtr, primeiroPtr);
}

int main() {
    int num;
    TipoNo *primeiroPtr = NULL;

    scanf("%d", &num);

    while (num != 0) {
        insereNoFimDaLista(&primeiroPtr, num);
        scanf("%d", &num);
    }
    inverte(&primeiroPtr);
    imprimeLista(primeiroPtr);

    return 0;
}
