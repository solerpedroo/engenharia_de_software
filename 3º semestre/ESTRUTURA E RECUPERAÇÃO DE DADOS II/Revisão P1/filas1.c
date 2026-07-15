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
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

static No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->proximo = NULL;
    novoNo->valor = 0;
    return novoNo;
}

void enfileirar(Fila* f, int valor){
    No* novoNo = criarNo(valor);
    if(filaVazia(f)){
        f->inicio = novoNo;
        f->fim = novoNo;
    }else{
        f->fim = novoNo;
        f->fim->proximo = novoNo;
    }
    f->tamanho++;
}

void desenfileirar(Fila* f){
    No* temp = f->inicio;
    f->inicio = temp->proximo;
    free(temp);
    f->tamanho--;
}

void limparFila(Fila* f){
    while(f->inicio != NULL){
        No* temp = f->inicio;
        f->inicio = temp->proximo;
        free(temp);
    }
    f->fim = NULL;
    f->tamanho = 0;
}

void destruirFila(Fila* f){
    limparFila(f);
    free(f);
}