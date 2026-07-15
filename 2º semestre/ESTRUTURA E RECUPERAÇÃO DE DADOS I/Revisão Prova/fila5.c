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

void remover (Fila* f){
    if(f->primeiro == NULL) return;
    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    if(f->primeiro == NULL) f->ultimo = NULL;
    free(temp);
}