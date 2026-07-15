#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Pilha{
    No* topo;
} Pilha;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

void push(Pilha* p, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = p->topo;
    p->topo = novo_no;
}

void pop(Pilha* p){
    if(p->topo == NULL) return;
    No* temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
}