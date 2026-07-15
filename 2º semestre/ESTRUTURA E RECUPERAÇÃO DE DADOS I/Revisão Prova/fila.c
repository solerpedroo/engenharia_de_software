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

Fila* inserir_no(Fila* f, int valor){
    No* novo_no = criar_no(valor);

    if(f->ultimo == NULL){
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{
        f->ultimo->proximo = novo_no;
        f->ultimo = novo_no;
    }

    return f;
}

Fila* remover_no(Fila* f){
    if (f->primeiro == NULL) return f;

    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;

    if(f->primeiro == NULL){
        f->ultimo = NULL;
    }

    free(temp);

    return f;
}