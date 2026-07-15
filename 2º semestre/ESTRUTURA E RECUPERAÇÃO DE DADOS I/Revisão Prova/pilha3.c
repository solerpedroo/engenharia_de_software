/*#include <stdio.h>
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
    return;
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
}*/

// INT

/*#include <stdio.h>
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
    return;
}

int push(Pilha* p, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = p->topo;
    p->topo = novo_no;
    return 0;
}

int pop(Pilha* p){
    if(p->topo == NULL) return 1;

    No* temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    return 0;
}*/

// STRUCT

/*#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Pilha
{
    No* topo;
} Pilha;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->proximo = NULL;
    novo_no->valor = valor;
    return;
}

Pilha* push(Pilha* p, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = p->topo;
    p->topo = novo_no;
    return;
}

Pilha* pop(Pilha* p, int valor){
    if(p->topo == NULL) return;

    No* temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    return;
}*/