/* Interface do TAD. Declara o tipo da estrutura de dados e
 * os protótipo das funções públicas.
 */

#ifndef __HEAP_H__
#define __HEAP_H__

/* Declaração opaca de heap. Só permite que o usuário declare ponteiros
 * para a estrutura, sem ter conhecimento do seu conteúdo.
 */
typedef struct heap Heap;

/* Funções públcas para criar e destruir a heap.
 */
Heap *heap_criar(int capacidade);
void heap_destruir(Heap *heap);

/* Funções para obter informações sobre a heap.
 */
int heap_tamanho(Heap *heap);
int heap_capacidade(Heap *heap);
int heap_vazia(Heap *heap);
int heap_cheia(Heap *heap);

/* Funções para acessar e manipular o conteúdo da heap.
 */
int heap_acessar(Heap *heap);
void heap_inserir(Heap *heap, int elem);
void heap_remover(Heap *heap);

#endif
