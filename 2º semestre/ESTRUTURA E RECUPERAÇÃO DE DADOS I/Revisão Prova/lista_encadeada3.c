// VOID

/*#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->proximo = NULL;
    novo_no->valor = valor;
    return novo_no;
}

void inserir_frente(No* head, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = head;
    head = novo_no;
}

void inserir_atras(No* head, int valor){
    No* novo_no = criar_no(valor);

    if (head == NULL){
        head = novo_no;
        return;
    }

    No* atual = head;
    while(atual->proximo != NULL) atual = atual->proximo;
    atual->proximo = novo_no;
}

void remover_frente(No* head){
    if (head == NULL) return;

    No* temp = head;
    head = head->proximo;
    free(temp);
}

void remover_atras(No* head){
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
}*/

// INT 

/*#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->proximo = NULL;
    novo_no->valor = valor;
    return novo_no;
}

int inserir_frente(No* head, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = head;
    head = novo_no;
    return 0;
}

int inserir_atras(No* head, int valor){
    No* novo_no = criar_no(valor);

    if(novo_no == NULL) return 1;

    if(head == NULL){
        head = novo_no;
        return 0;
    }

    No* atual = head;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }

    atual->proximo = novo_no;
    return 0;
}

int remover_frente(No* head){
    if(head == NULL) return 1;

    No* temp = head;
    head = head->proximo;
    free(temp);
    return 0;
}

int remover_atras(No* head){
    if(head == NULL) return 1;

    if(head->proximo == NULL){
        free(head);
        head = NULL;
        return 0;
    }

    No* atual = head;
    while(atual->proximo->proximo != NULL){
        atual = atual->proximo;
    }
    free(atual->proximo);
    atual->proximo = NULL;
    return 0;
}*/

// STRUCT 

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->proximo = NULL;
    novo_no->valor = valor;
    return novo_no;
}

No* inserir_frente(No* head, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = head;
    return novo_no;
}

No* inserir_atras(No* head, int valor){
    No* novo_no = criar_no(valor);

    if(head == NULL) return novo_no;
    No* atual = head;
    while(atual->proximo != NULL) atual = atual->proximo;
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

No* remover_atras(No* head){
    if(head == NULL) return NULL;
    if(head->proximo == NULL){
        free(head);
        head = NULL;
        return head;
    }

    No* atual = head;
    while(atual->proximo->proximo != NULL) atual = atual->proximo;
    free(atual->proximo);
    atual->proximo = NULL;
    return head;
}