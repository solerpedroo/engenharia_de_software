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

static Fila* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserir(Fila* fila, int valor){
    No* novoNo = criarNo(valor);
    if(fila->inicio == NULL){
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }else{
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
    fila->tamanho++;
}

void remover(Fila* fila){
    No* temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(temp);
    fila->tamanho--;
    if(fila->inicio == NULL) fila->fim == NULL;
}

void limparFila(Fila* fila){
    while(fila->inicio != NULL){
        No* temp = fila->inicio;
        fila->inicio = temp->proximo;
        free(temp);
    }
    fila->fim = NULL;
    fila->tamanho = 0;
}

void enfileirar(Fila* f, int valor){
    No* novoNo = criarNo(valor);
    if(f->inicio == NULL){
        f->inicio = novoNo;
        f->fim = novoNo;
    }else{
        f->fim = novoNo;
        f->fim->proximo = novoNo;
    }
    f->tamanho++;
}

void desenfileirar(Fila* f, int valor){
    if(filaVazia(f)){
        printf("Fila sem nada");
    }
    No* temp = f->inicio;
    f->inicio = f->inicio->proximo;
    free(temp);
    f->tamanho--;
    if(filaVazia(f)) f->fim = NULL;
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