#include <stdio.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Pilha{
    int tamanho;
    struct No* topo;
} Pilha;

Pilha* criarPilha(){
    No* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->proximo = NULL;
    pilha->valor = 0;
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

void pop(Pilha* p){
    if(p->topo == NULL) return p;
    No* temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
}

void apagarPilha(Pilha* p){
    No* atual = p->topo;
    while (atual != NULL){
        No* temp = atual;
        atual = temp->proximo;
        free(temp);
    }
    p->topo = NULL;
    p->tamanho = 0;
    free(p);
}