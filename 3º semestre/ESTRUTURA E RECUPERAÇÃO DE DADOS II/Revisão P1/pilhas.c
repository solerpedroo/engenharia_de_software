#include <stdio.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Pilha{
    No* topo;
    int tamanho;
} Pilha;

Pilha* criarPilha(){
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void push(Pilha* p, int valor){
    No* novoNo = criarNo(valor);
    novoNo->proximo = p->topo;
    p->topo = novoNo;
    p->tamanho++;
}

Pilha* pop(Pilha* p){
    if (p->topo == NULL) return p;
    No* temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    return p;
}

void apagarPilha(Pilha* p){
    No* atual = p->topo;
    while(atual != NULL){
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    p->tamanho = 0;
    p->topo = NULL;
    free(p);
}

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Pilha{
    int tamanho;
    struct No* topo;
} Pilha;

void empilhar(Pilha* pilha, int valor){
    No* novoNo = criarNo(valor);
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;
}