#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *prox;
} TNo;

void imprimirNo(TNo *no){
    printf("%d ", no->num);
}

TNo *criarNo(int num) {
    TNo *no = malloc(sizeof(TNo));
    no->num = num;
    no->prox = NULL;
    return no;
}

typedef struct lista {
    TNo *inicio;
    int tam;
} TLista;

TLista *criarLista() {
    TLista *lst = malloc(sizeof(TLista));
    lst->inicio = NULL;
    lst->tam = 0;

    return lst;
}

void imprimirLista(TLista *lst) {
    TNo *cam = lst->inicio;
    while (cam != NULL) {
        imprimirNo(cam);
        cam = cam->prox;
    }
    printf("\n");
}

void inserirLista(TLista *lst, TNo *novo) {
    if (lst->inicio == NULL) {
        lst->inicio = novo;
        lst->tam++;
    }
    else {
        TNo *cam = lst->inicio;
        while (cam->prox != NULL) {
            cam = cam->prox;
        }
        cam->prox = novo;
        lst->tam++;
    }
}

int buscarLista(TLista *lst, int buscado) {
    TNo *cam = lst->inicio;
    int status = 0;
    while ((cam != NULL) && (cam->num != buscado)) {
        cam = cam->prox;
    }
    if (cam == NULL) {
        status = 0;
    } else {
        status = 1;
    }
    return status;
}

TLista *uniaoLista(TLista *l1, TLista *l2) {
    TLista *l3 = criarLista();

    TNo *cam = l1->inicio;

    while (cam) {
        if (buscarLista(l3, cam->num) == 0) {
            TNo *novo = criarNo(cam->num);
            inserirLista(l3, novo);
        }
        cam = cam->prox;
    }
    cam = l2->inicio;
    while (cam) {
        if (buscarLista(l3, cam->num) == 0) {
            TNo *novo = criarNo(cam->num);
            inserirLista(l3, novo);
        }
        cam = cam->prox;
    }
    return l3;
}

TLista *intersecaoLista(TLista *l1, TLista *l2) {
    TLista *l3 = criarLista();
    TNo *cam = l2->inicio;

    while (cam) {
        if (buscarLista(l1, cam->num) == 1) {
            if (buscarLista(l3, cam->num) == 0) {
                TNo *novo = criarNo(cam->num);
                inserirLista(l3, novo);
            }
        }
        cam = cam->prox;
    }
    return l3;
}

int main() {
    TLista *lst1 = criarLista();
    TLista *lst2 = criarLista();
    TLista *l3, *l4;

    int num;

    scanf("%d", &num);

    while(num != 0) {
        TNo *novo = criarNo(num);
        inserirLista(lst1, novo);
        scanf("%d", &num);
    }

    scanf("%d", &num);

    while(num != 0) {
        TNo *novo = criarNo(num);
        inserirLista(lst2, novo);
        scanf("%d", &num);
    }
    printf("Lista 1: ");
    imprimirLista(lst1);
    printf("Lista 2: ");
    imprimirLista(lst2);

    l3 = uniaoLista(lst1, lst2);
    printf("Uniao: ");
    imprimirLista(l3);

    l4 = intersecaoLista(lst1, lst2);
    printf("Intersecao: ");
    imprimirLista(l4);

    return 0;
}