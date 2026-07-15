#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fila.h"

typedef struct NoFila {
    int valor;
    struct NoFila* prox;
} NoFila;

typedef struct Fila {
    NoFila* inicio;
    NoFila* fim;
    int tamanho;
} Fila;


Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

static NoFila* criarNo(int valor) {
    NoFila* novoNo = (NoFila*)malloc(sizeof(NoFila));
    if(!novoNo){
        printf("Erro ao alocar memória para o nó da fila.\n");
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void limparFila(Fila* fila) {
    while (fila->inicio != NULL) {
        NoFila* temp = fila->inicio;
        fila->inicio = temp->prox;
        free(temp);
    }
    fila->fim = NULL;
    fila->tamanho = 0;
}
void destruirFila(Fila* fila) {
    limparFila(fila);
    free(fila);
}

int filaVazia(const Fila* fila) {
    return (fila->tamanho == 0);
}

void enfileirar(Fila* fila, int valor) {
    NoFila* novoNo = criarNo(valor);
    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
    fila->tamanho++;
}

void desenfileirar(Fila* fila, int* valorRemovido) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não é possível desenfileirar.\n");
        *valorRemovido = 0; // Retorna um valor inválido para indicar erro
        return;
    }
    NoFila* temp = fila->inicio;
    *valorRemovido = temp->valor; // Armazena o valor do elemento removido
    fila->inicio = temp->prox;
    free(temp);
    fila->tamanho--;
    if (filaVazia(fila)) {
        fila->fim = NULL;
    }
}

int obterInicio(const Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não há elemento na frente.\n");
        return -1; // Retorna um valor inválido para indicar erro
    }
    return fila->inicio->valor;
}

int obterTamanho(const Fila* fila) {
    return fila->tamanho;
}

bool buscarValor(const Fila* fila, int valor) {
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return true; 
        }
        atual = atual->prox;
    }
    return false; 
}

void atualizarValor(Fila* fila, int valorAntigo, int valorNovo) {
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        if (atual->valor == valorAntigo) {
            atual->valor = valorNovo;
            return; 
        }
        atual = atual->prox;
    }
    printf("Valor %d não encontrado na fila.\n", valorAntigo);
}

void imprimirFila(const Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    NoFila* atual = fila->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

