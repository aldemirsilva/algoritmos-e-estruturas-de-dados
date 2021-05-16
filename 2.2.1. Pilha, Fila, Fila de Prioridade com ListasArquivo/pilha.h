typedef struct pilha TPilha;

TPilha *criarPilha();
void empilharPilha(TPilha *p, void *novo);
void *desempilharPilha(TPilha *p);
void *topoPilha(TPilha *p);
int tavaziaPilha(TPilha *p);
int medirPilha(TPilha *p);
