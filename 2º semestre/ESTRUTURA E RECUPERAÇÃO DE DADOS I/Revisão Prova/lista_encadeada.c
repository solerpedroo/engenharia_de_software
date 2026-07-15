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

No* inserir_frente(No* head, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = head;
    return novo_no;
}

No* inserir_atras(No* head, int valor){
    No* novo_no = criar_no(valor);
    if (head == NULL) return novo_no;

    No* atual = head;
    while(atual->proximo != NULL) atual = atual->proximo;
    atual->proximo = novo_no;
    return head;
}

No* inserir_pos(No* head, int valor, int pos){
    if(pos <= 0 || head == NULL) return(inserir_frente(head, valor));

    No* atual = head;
    int indice = 0;

    while(atual->proximo != NULL && indice != pos - 1){
        atual = atual->proximo;
        indice++;
    }

    No* novo_no = criar_no(valor);
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
    return head;
}

No* remover_frente(No* head){
    if(head == NULL) return NULL;

    No* temp = head;
    head = head->proximo;
    free(temp);
    return head;
}