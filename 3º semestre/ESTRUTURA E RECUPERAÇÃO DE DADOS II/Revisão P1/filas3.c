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
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->tamanho = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
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
}

void desenfileirar(Fila* f){
    No* temp = f->inicio;
    f->inicio = temp->proximo;
    free(temp);
    f->tamanho--;
    if(f->inicio == NULL) f->fim = NULL;
}