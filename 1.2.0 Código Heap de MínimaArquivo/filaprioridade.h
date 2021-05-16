typedef struct filaprioridade TFilaPrioridade;
typedef int(*TCompararElementoFilaPrioridade)(void *s1, void *s2);

TFilaPrioridade *criarFilaPrioridade();
void mostrarFilaPrioridade(TFilaPrioridade *f);
void enfileirarFilaPrioridade(TFilaPrioridade *f, void *carga, TCompararElementoFilaPrioridade comparar);
void *desenfileirarFilaPrioridade(TFilaPrioridade *f, TCompararElementoFilaPrioridade comparar);
void *cabecaFilaPrioridade(TFilaPrioridade *fp);
int tamanhoFilaPrioridade(TFilaPrioridade *fp);
void vaziaFilaPrioridade(TFilaPrioridade *fp);
