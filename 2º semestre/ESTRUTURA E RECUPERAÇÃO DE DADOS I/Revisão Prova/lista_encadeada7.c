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
    while (atual->proximo->proximo != NULL) atual = atual->proximo;
    free(atual->proximo);
    atual->proximo = NULL;    
}