#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

No* criar(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

void inserir_frente(No* head, int valor){
    No* novo_no = criar(valor);
    novo_no->proximo = head;
    head = novo_no;
}

void inserir_final(No* head, int valor){
    No* novo_no = criar(valor);
    if (head == NULL){
        head = novo_no;
        return;
    }

    No* atual = head;
    while(atual->proximo != NULL) atual = atual->proximo;
    atual->proximo = novo_no;
}

void remover_frente(No* head){
    if(head == NULL) return;
    No* temp = head;
    head = head->proximo;
    free(temp);
}

void remover_final(No* head){
    if(head == NULL) return;

    if(head->proximo == NULL){
        free(head);
        head = NULL;
        return;
    }

    No* atual = head;
    while(atual->proximo->proximo != NULL){
        atual = atual->proximo;
    }
    free(atual->proximo);
    atual->proximo = NULL;
}