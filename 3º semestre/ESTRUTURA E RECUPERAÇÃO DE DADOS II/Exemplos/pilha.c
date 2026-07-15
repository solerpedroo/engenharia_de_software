#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct NoPilha{
    int valor;
    struct NoPilha* prox;
} NoPilha;

typedef struct Pilha{
    NoPilha* topo;
    int tamanho;
} Pilha;

Pilha *criarPilha() {
    Pilha *novaPilha = (Pilha*)malloc(sizeof(Pilha));
    if (!novaPilha) {
        printf("Erro ao alocar memória para a pilha.\n");
    }
    novaPilha->topo = NULL;
    novaPilha->tamanho = 0;
    return novaPilha;
}


void apagarPilha(Pilha* pilha) {
    if(!pilha) {
        printf("Pilha nula. Não é possível apagar.\n");
        return;
    }
    NoPilha* atual = pilha->topo;
    while (atual != NULL) {
        NoPilha* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    free(pilha);
}

void esvaziarPilha(Pilha* pilha) {
    if(!pilha) {
        printf("Pilha nula. Não é possível esvaziar.\n");
        return;
    }
    NoPilha* atual = pilha->topo;
    while (atual != NULL) {
        NoPilha* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

static NoPilha* criarNo(int valor) {
    NoPilha* novoNo = (NoPilha*)malloc(sizeof(NoPilha));
    if (!novoNo) {
        printf("Erro ao alocar memória para o nó da pilha.\n");
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

int pilhaVazia(const Pilha* pilha) { //Retorna 1 se a pilha estiver vazia, 0 caso contrário
    return (pilha->tamanho == 0);
}

void empilhar(Pilha* pilha, int valor) {
    NoPilha* novoNo = criarNo(valor);
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;
}

void desempilhar(Pilha* pilha, int* valorDesempilhado) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Não é possível desempilhar.\n");
        return;
    }
    NoPilha* temp = pilha->topo;
    *valorDesempilhado = temp->valor;
    pilha->topo = temp->prox;
    free(temp);
    pilha->tamanho--;
}

int topoPilha(const Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Não há topo para retornar.\n");
        return -1;
    }
    return pilha->topo->valor;
}

void atualizarTopo(Pilha* pilha, int novoValor) { //Atualiza o valor do elemento no topo da pilha
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Não é possível atualizar o topo.\n");
        return;
    }
    pilha->topo->valor = novoValor;
}

  

void imprimirPilha(const Pilha* pilha) {
    NoPilha* atual = pilha->topo;
    printf("Pilha (topo para base): ");
    while (atual != NULL) {
        printf("\n%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\nNULL\n");
}

