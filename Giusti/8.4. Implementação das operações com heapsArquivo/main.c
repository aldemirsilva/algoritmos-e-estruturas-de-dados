#include <stdio.h>
#include "heap.h"

int main(void)
{
	Heap *h;

	h = heap_criar(10);
	printf("Heap de tamanho %d criada\n", heap_tamanho(h));

	heap_inserir(h, 5);
	heap_inserir(h, 8);
	heap_inserir(h, 4);
	heap_inserir(h, 7);
	printf("Tamanho da heap: %d\n", heap_tamanho(h));

	printf("Primeiro elemento: %d\n", heap_acessar(h));
	printf("Removendo...\n");
	heap_remover(h);

	printf("Primeiro elemento: %d\n", heap_acessar(h));
	printf("Removendo...\n");
	heap_remover(h);

	printf("Primeiro elemento: %d\n", heap_acessar(h));
	printf("Removendo...\n");
	heap_remover(h);

	printf("Primeiro elemento: %d\n", heap_acessar(h));
	printf("Removendo...\n");
	heap_remover(h);

	heap_destruir(h);
}
