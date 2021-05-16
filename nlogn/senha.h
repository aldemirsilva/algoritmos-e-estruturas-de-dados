typedef struct senha TSenha;
TSenha *criarSenha(int num, int hora, int min);
void imprimirSenha(TSenha *senha);
void destroySenha(TSenha *s);
int compararSenha(void *s1, void *s2);
