#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha NoPilha;

typedef struct Pilha Pilha;


Pilha *criarPilha() ;

void apagarPilha(Pilha* pilha);

int pilhaVazia(const Pilha* pilha);

void empilhar(Pilha* pilha, int valor);

void desempilhar(Pilha* pilha, int* valorDesempilhado);

int topoPilha(const Pilha* pilha) ;

void atualizarTopo(Pilha* pilha, int novoValor);

void imprimirPilha(const Pilha* pilha);


#endif // PILHA_H
