#include <stdio.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    int tamanho;
    struct No* inicio;
    struct No* fim;
} Fila;

Fila* criarFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void enfileirar(Fila* f, int valor){
    No* novoNo = criarNo(valor);
    if(f->inicio == NULL){
        f->inicio = novoNo;
        f->fim = novoNo;
    }else{
        f->fim->proximo = novoNo;
        f->fim = novoNo;
    }
    f->tamanho++;
}

void desenfileirar(Fila* f){
    No* temp = f->inicio;
    f->inicio = temp->proximo;
    free(temp);
    f->tamanho--;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
}