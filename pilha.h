typedef struct pilha Pilha;

Pilha * criar();
void destruir(Pilha * p);
int desempilhar(Pilha * p); // ou pop
void empilhar(Pilha * p, int x); // ou push
int tamanho(Pilha * p);
int topo(Pilha * p);

void imprimir(Pilha * p);
int eh_igual(Pilha * p1, Pilha * p2);


