#include <stdio.h>
#include <stdlib.h>

struct tipoDado {
    int numero;
};
typedef struct tipoDado TipoDado;

struct tipoNo {
    struct tipoNo *prox;
    TipoDado d;
};
typedef struct tipoNo TipoNo;

struct tipoLista {
    TipoNo *prim;
};
typedef struct tipoLista TipoLista;

void criaLista(TipoLista *l) {
    l->prim = NULL;
}

void insereNaLista(TipoLista *l, TipoDado d) {
    TipoNo *aux;
    aux = (TipoNo *) malloc(sizeof(TipoNo));
    aux->d = d;
    aux->prox = l->prim;
    l->prim = aux;
}

void insereNoFimDaLista(TipoLista *l, TipoDado d) {
    TipoNo *auxPtr;
    auxPtr = (TipoNo *) malloc(sizeof(TipoNo));
    auxPtr->d = d;
    auxPtr->prox = NULL;

    TipoNo *anteriorPtr;
    TipoNo *atualPtr = l->prim;

    if (atualPtr == NULL) {
        l->prim = auxPtr;
    }
    else {
        while (atualPtr != NULL) {
            anteriorPtr = atualPtr;
            atualPtr = atualPtr->prox;
        }
        anteriorPtr->prox = auxPtr;
    }
}

void imprimeLista(TipoLista l1) {
    TipoNo *aux = l1.prim;

    while (aux) {
        printf("%d ", aux->d.numero);
        aux = aux->prox;
    }

    printf("\n");
}

void concatenaListas(TipoLista *l1, TipoLista *l2, TipoLista *l3) {
    TipoNo *aux;
    aux = l1->prim;
    while (aux) {
        insereNoFimDaLista(l3, aux->d);
        aux = aux->prox;
    }
    aux = l2->prim;
    while (aux) {
        insereNoFimDaLista(l3, aux->d);
        aux = aux->prox;
    }
}

void removeRepetidos(TipoLista l) {
    TipoNo *aux = l.prim;
    TipoNo *anteriorPtr;
    TipoNo *atualPtr;

    if (l.prim) {
        while (aux) {
            anteriorPtr = aux;
            atualPtr = aux->prox;
            while(atualPtr) {
                if (aux->d.numero == atualPtr->d.numero) {
                    anteriorPtr->prox = atualPtr->prox;
                    free(atualPtr);
                    atualPtr = anteriorPtr->prox;
                }
                else {
                    anteriorPtr = atualPtr;
                    atualPtr = atualPtr->prox;
                }
            }
            aux = aux->prox;
        }
    }
}

void uniaoDeListas(TipoLista *l1, TipoLista *l2, TipoLista *l3) {
    TipoNo *aux;
    aux = l1->prim;
    while (aux) {
        insereNoFimDaLista(l3, aux->d);
        aux = aux->prox;
    }
    aux = l2->prim;
    while (aux) {
        insereNoFimDaLista(l3, aux->d);
        aux = aux->prox;
    }
    removeRepetidos(*l3);
}

int listaVazia(TipoLista *l) {
    return (l == NULL);
}

TipoNo *buscaNaLista(TipoLista *l, int chave) {
    TipoNo *aux;
    for (aux = l->prim; aux != NULL; aux = aux->prox) {
        if (aux->d.numero == chave)
            return aux;
    }
    return NULL;
}

void intersecao3(TipoLista *l1, TipoLista *l2, TipoLista *l3) {
    TipoNo *aux1 = l1->prim;
    TipoNo *aux2;

    while (aux1) {
        aux2 = l2->prim;
        while (aux2) {
            if (aux1->d.numero == aux2->d.numero) {
                if (listaVazia(l3)) {
                    insereNaLista(l3, aux2->d);
                }
                else {
                    if (buscaNaLista(l3, aux2->d.numero)) {
                        return;
                    }
                    else {
                        insereNoFimDaLista(l3, aux2->d);
                    }
                }
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
}

int main () {
    TipoLista l1, l2, uniao, intersecao;
    TipoDado dado;
    int num;

    criaLista(&l1);
    criaLista(&l2);
    criaLista(&uniao);
    criaLista(&intersecao);

    scanf("%dado", &num);

    while (num != 0) {
        dado.numero = num;
        insereNoFimDaLista(&l1, dado);
        scanf("%dado", &num);
    }

    scanf("%dado", &num);

    while (num != 0) {
        dado.numero = num;
        insereNoFimDaLista(&l2, dado);
        scanf("%dado", &num);
    }

    printf("Lista 1: "); imprimeLista(l1);

    printf("Lista 2: "); imprimeLista(l2);

    uniaoDeListas(&l1, &l2, &uniao);

    printf("Uniao: "); imprimeLista(uniao);

    intersecao3(&l1, &l2, &intersecao);

    printf("Intersecao: "); imprimeLista(intersecao);

    return 0;
}
