// FILA

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    No* primeiro;
    No* ultimo;
} Fila;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = valor;
    return novo_no;
}

void inserir(Fila* f, int valor){
    No* novo_no = criar_no(valor);
    if(f->ultimo == NULL){
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{
        f->ultimo = novo_no;
        f->ultimo->proximo = novo_no;
    }
}

void remover(Fila* f){
    if(f->ultimo == NULL) return;
    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    if(f->primeiro = NULL) f->ultimo = NULL;
    free(temp);   
}

// PILHA

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

// LISTA

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

void insert_front(No* head, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = head;
    head = novo_no;
}

void insert_back(No* head, int valor){
    No* novo_no = criar_no(valor);

    if(head == NULL) return;
    if(head->proximo == NULL){
        head = novo_no;
        return;
    }

    No* atual = head;
    while(atual->proximo != NULL) atual = atual->proximo;
    atual->proximo = novo_no;
}

void remove_front(No* head){
    if(head == NULL) return;
    No* temp = head;
    head = head->proximo;
    free(temp);
}

void remove_back(No* head){
    if(head == NULL) return;
    if(head->proximo == NULL){
        free(head);
        head = NULL;
        return;
    }

    No* atual = head;
    while(atual->proximo->proximo != NULL) atual = atual->proximo;
    free(atual->proximo);
    atual->proximo = NULL;
}

void inser_at(No* head, int valor, int pos){
    if(pos <= 0 || head == NULL) return (insert_front(head, valor));

    No* atual = head;
    int indice = 0;

    while(atual->proximo != NULL && indice < pos - 1){
        atual = atual->proximo;
        indice++;
    }

    No* novo_no = criar_no(atual);
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

// Fila 

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    No* primeiro;
    No* ultimo;
} Fila;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

void inserir(Fila* f, int valor){
    No* novo_no = criar_no(valor);
    if(f->ultimo == NULL){
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{
        f->ultimo = novo_no;
        f->ultimo->proximo = novo_no;
    }
}

void remover(Fila* f){
    if(f->ultimo == NULL) return;
    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    if(f->primeiro == NULL) f->ultimo = NULL;
    free(temp);
}