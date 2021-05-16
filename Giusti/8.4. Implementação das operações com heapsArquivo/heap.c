#include "heap.h"

#include <assert.h>
#include <stdlib.h>


/* Definição da estrutura de heap. Neste exemplo, usaremos um vetor fixo, que
 * uma vez criado não pode ser redimensionado. Para utilizar outro tipo de estrutura,
 * basta trocar o campo "dados"
 */
struct heap {
	int *dados;
	int tamanho;
	int capacidade;
};


/* Protótipos para as funções internas.
 */
void trocar(int *vetor, int a, int b);
void heapify(int *vetor, int pos, int tam);
void aumentar_chave(int *vetor, int pos);


/* Troca dois elementos em um vetor.
 */
void trocar(int *vetor, int a, int b)
{
	if (a != b) {
		int aux = vetor[a];
		vetor[a] = vetor[b];
		vetor[b] = aux;
	}
}


/* Função heapify. Corrige uma "quase-heap" fazendo um elemento incorretamente
 * posicionado "descer" até seu lugar correto na heap.
 */
void heapify(int *vetor, int pos, int tam)
{
	int maior = pos;
	int esq = 2 * pos + 1;
	int dir = esq + 1;

	if (esq < tam && vetor[esq] > vetor[maior]) maior = esq;
	if (dir < tam && vetor[dir] > vetor[maior]) maior = dir;

	if (maior != pos) {
		trocar(vetor, pos, maior);
		heapify(vetor, maior, tam);
	}
}


/* Corrige a posição de um elemento que teve sua chave trocada por uma chave de
 * valor maior ou igual.
 */
void aumentar_chave(int *vetor, int pos)
{
	if (pos != 0) {
		int pai = (pos - 1) / 2;
		if (vetor[pos] > vetor[pai]) {
			trocar(vetor, pos, pai);
			aumentar_chave(vetor, pai);
		}
	}
}


/* Aqui começam as funções públicas do TAD.
 */


/* Cria uma heap vazia com um vetor cuja capacidade máxima é especificada
 * pelo usuário.
 */
struct heap *heap_criar(int capacidade)
{
	struct heap *nova;

	nova = malloc(sizeof *nova);
	assert(nova != NULL);

	nova->dados = malloc(capacidade * sizeof *nova->dados);
	assert(nova->dados != NULL);

	nova->capacidade = capacidade;
	nova->tamanho = 0;

	return nova;
}


/* Libera toda a memória alocada para a heap.
 */
void heap_destruir(struct heap *heap)
{
	free(heap->dados);
	free(heap);
}


int heap_tamanho(struct heap *heap)
{
	return heap->tamanho;
}


int heap_capacidade(struct heap *heap)
{
	return heap->capacidade;
}


int heap_vazia(struct heap *heap)
{
	return heap->tamanho == 0;
}


int heap_cheia(struct heap *heap)
{
	return heap->tamanho == heap->capacidade;
}


/* Acessa um elemento da heap. A heap só permite acessar o primeiro
 * elemento e ele só pode ser lido.
 * Pré-condições: a heap não pode estar vazia
 */
int heap_acessar(struct heap *heap)
{
	assert(heap->tamanho > 0);
	return heap->dados[0];
}


/* Insere um elemento em uma posição válida da heap. Não há garantia de
 * qual será a posição resultante do elemento, apenas que ela irá
 * respeitar a propriedade de heap.
 * Pré-condições: a heap não pode estar cheia
 */
void heap_inserir(struct heap *heap, int elem)
{
	assert(heap->tamanho < heap->capacidade);

	heap->dados[heap->tamanho] = elem;
	aumentar_chave(heap->dados, heap->tamanho);
	heap->tamanho++;
}


/* Remove um elemento do início da heap, garantindo que a estrutura irá
 * respeitar a propriedade de heap máxima.
 * Pré-condições: a heap não pode estar vazia
 */
void heap_remover(struct heap *heap)
{
	assert(heap->tamanho != 0);

	heap->tamanho--;
	heap->dados[0] = heap->dados[heap->tamanho];
	heapify(heap->dados, 0, heap->tamanho);
}
