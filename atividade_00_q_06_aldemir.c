#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    unsigned int prioridade;
    char palavra[31];
} TElemento;

TElemento *criarElemento(unsigned int proridade, char palavra[]) {
    TElemento *elemento = malloc(sizeof(TElemento));
    elemento->prioridade = proridade;
    strcpy(elemento->palavra, palavra);
    return elemento;
}

typedef int(*TCompararElementoHeap) (TElemento *e1, TElemento *e2);

typedef struct heap {
    TElemento **vetor;
    int tamanho;
    unsigned int ocupacao;
} THeap;

THeap *criarHeap(unsigned int tam) {
    THeap *heap = malloc(sizeof(THeap));
    heap->tamanho = tam;
    heap->vetor = malloc(heap->tamanho * sizeof(TElemento));
    heap->ocupacao = 0;
    return heap;
}

void trocarElementoHeap(THeap *heap, int imaior, int i) {
    TElemento *aux = heap->vetor[imaior];
    heap->vetor[imaior] = heap->vetor[i];
    heap->vetor[i] = aux;
}

int compararPrioridade(TElemento *e1, TElemento *e2){
    if(e1->prioridade != e2->prioridade) return (e1->prioridade - e2->prioridade);
    else return strcmp(e2->palavra, e1->palavra);
}

void heapifica(THeap *heap, int i, TCompararElementoHeap comparar) {
    TElemento **vetor = heap->vetor;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    int imaior = i;
    if (esq >= heap->ocupacao) return;
    else if (comparar(heap->vetor[imaior], heap->vetor[esq]) < 0) imaior = esq;
    if ((dir < heap->ocupacao) && (comparar(vetor[imaior], vetor[dir]) < 0)) imaior = dir;

    if (imaior != i) {
        trocarElementoHeap(heap, imaior, i);
        heapifica(heap, imaior, comparar);
    }
}

void removerHeap(THeap *heap, TCompararElementoHeap comparar) {
    if (heap->ocupacao == 0) return;
    printf("%s\n", heap->vetor[0]->palavra);
    trocarElementoHeap(heap, 0, heap->ocupacao-1);
    heap->ocupacao--;
    heap->vetor[heap->ocupacao] = NULL;
    heapifica(heap, 0, comparar);
}

void inserirHeap(THeap *heap, TElemento *carga, TCompararElementoHeap comparar) {
    if (heap->ocupacao >= heap->tamanho) {
        heap->tamanho *= 2;
        int tamEmBytes = heap->tamanho * sizeof(TElemento);
        heap->vetor = realloc(heap->vetor, tamEmBytes);
    }

    heap->vetor[heap->ocupacao] = carga;

    int i = heap->ocupacao;
    int pai = (i - 1) / 2;
    int continua = 1;

    while((i > 0) && (continua)) {
        if (comparar (heap->vetor[pai], heap->vetor[i]) < 0) {
            trocarElementoHeap(heap, pai, i);
            heapifica(heap, i, comparar);
            i = pai;
            pai = (i - 1) / 2;
        }
        else {
            continua = 0;
        }
    }
    heap->ocupacao++;
}

void destroiHeap(THeap *heap) {
    for(int i = 0; i < heap->ocupacao; i++) free(heap->vetor[i]);
    free(heap->vetor);
    free(heap);
}

int main(void) {
    char palavra[31], operacao;
    unsigned int prioridade;
    THeap *heapFila = criarHeap(10);

    operacao = getchar();
    while (operacao != '0') {
        if (operacao == '1') {
            scanf("%d %s", &prioridade, palavra);
            TElemento *elemento = criarElemento(prioridade, palavra);
            elemento->prioridade = prioridade;
            strcpy(elemento->palavra, palavra);
            inserirHeap(heapFila, elemento, compararPrioridade);
        }

        if (operacao == '2') {
            removerHeap(heapFila, compararPrioridade);
        }
        operacao = getchar();
    }
    destroiHeap(heapFila);
    return EXIT_SUCCESS;
}