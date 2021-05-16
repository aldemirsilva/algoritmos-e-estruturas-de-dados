#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char identificador[3];
    int prioridade;
    struct no *prox;
} TNo;

typedef int(*TCompararElementoFilaPrioridade)(TNo *e1, TNo *e2);


typedef struct lista
{
    int tam;
    TNo *inicio;
} TLista;

typedef struct filaprioridade{
    TLista *str;
    //estatisticas da fila
} TFilaPrioridade;

TNo *criarNo(char identificador[], int prioridade)
{
    TNo *novo = malloc(sizeof(TNo));
    strcpy(novo->identificador,identificador);
    novo->prioridade = prioridade;
    novo->prox = NULL;

    return novo;
}

void imprimirNo(TNo *no)
{
    printf("%s %d\n", no->identificador, no->prioridade);
}

TLista *criarLSE()
{
    TLista *lst = malloc(sizeof(TLista));
    lst->tam = 0 ;
    lst->inicio = NULL;
    return lst;
}

TFilaPrioridade *criarFilaPrioridade()
{
    TFilaPrioridade *f = malloc(sizeof(TFilaPrioridade));
    f->str = criarLSE();
    return f;
}

int compararPrioridade(TNo *p1, TNo *p2)
{
    TNo *pp1 = p1;
    TNo *pp2 = p2;
    return (pp1->prioridade - pp2->prioridade);
}

void inserirOrdenadoLSE(TFilaPrioridade *lst, TNo *novo, TCompararElementoFilaPrioridade comparar)
{
    TNo *anterior = NULL;
    TNo *cam = lst->str->inicio;
    //busca do local de inserção
    while((cam != NULL) && (comparar(cam, novo) >= 0))
    {
        anterior = cam;
        cam = cam->prox;
    }
    
    // inserir no Inicio
    if (cam == lst->str->inicio)
    {
        novo->prox = lst->str->inicio;
        lst->str->inicio = novo;
    }
    
    // inserir no Final
    else if (cam == NULL)
    {
        anterior->prox = novo;
        novo->prox = NULL;
    }
    
    // inserir em posição intermediária
    else
    {
        anterior->prox = novo;
        novo->prox = cam;
    }
    lst->str->tam++;
}

void removerLSE(TFilaPrioridade *l)
{
    TNo *cabeca = l->str->inicio;

    if (cabeca)
    {
        l->str->inicio = l->str->inicio->prox;
        l->str->tam--;
    }
    free(cabeca);
}

void imprimirFilaPrioridade(TFilaPrioridade *lst)
{
    TNo *cam = lst->str->inicio;
    while(cam != NULL )
    {
        imprimirNo(cam);
        cam = cam->prox;
    }
}

int main(int argc, char const *argv[])
{
    TFilaPrioridade *filaAviao = criarFilaPrioridade();
    char operacao, identificador[3];
    int prioridade;

    scanf("%c %s %d", &operacao, identificador, &prioridade);
    printf("%c %s %d\n", operacao, identificador, prioridade);

/*     while (operacao != 'S')
    {
        if (operacao == 'Q')
        {
            return filaAviao->str->tam;
        }
        if (operacao == 'D')
        {
            removerLSE(filaAviao);
        }
        if (operacao == 'A')
        {
            TNo *novo = criarNo(identificador,prioridade);
            inserirOrdenadoLSE(filaAviao, novo, compararPrioridade);
        }
        if (operacao == 'L')
        {
            imprimirFilaPrioridade(filaAviao);
        }
        if (operacao == 'P')
        {
            printf("%s %d\n", filaAviao->str->inicio->identificador, filaAviao->str->inicio->prioridade);
        }
        scanf("%c %s %d", &operacao, identificador, &prioridade);
    } */
}