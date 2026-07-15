/*#include <stdio.h>
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

No* inserir_em(No* head, int valor, int pos){
    if (pos<=0 || head == NULL) return(inserir_frente(head, valor));

    No* atual = head;
    int indice = 0;

    while(atual->proximo != NULL && indice != pos - 1){
        atual = atual->proximo;
        indice ++;
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

No* remover_atras(No* head){
    if (head == NULL) return NULL;
    if (head->proximo == NULL){
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

No* remover_em(No* head, int pos){
    if (head == NULL || pos < 0) return 0;
    if (pos == 0) return(remover_frente(head));

    No* atual = head;
    int indice = 0;
    
    while(atual->proximo != NULL && indice < pos - 1){
        atual = atual->proximo;
        indice++;
    }

    if (atual->proximo == NULL) return(remover_atras(head));

    No* temp = head;
    atual->proximo = temp->proximo;
    free(temp);
    return head;
}*/

// COM VOID

/*#include <stdio.h>
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

void inserir_frente(No* head, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = head;
}

void inserir_final(No* head, int valor){
    No* novo_no = criar_no(valor);

    if(head == NULL){
        head = novo_no;
        return;
    }

    No* atual = head;
    while(atual->proximo != NULL) atual = atual->proximo;
    atual->proximo = novo_no;
}

void inserir_em(No* head, int valor, int pos){

    if(pos<=0 || head == NULL){
        inserir_frente(head, valor);
        return;
    }

    No* atual = head;
    int indice = 0;

    while(atual->proximo != NULL && indice != pos - 1){
        atual = atual->proximo;
        indice++;
    }

    No* novo_no = criar_no(valor);
    novo_no->proximo = atual->proximo;
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
        head == NULL;
        return;
    }

    No* atual = head;
    while(atual->proximo->proximo != NULL){
        atual = atual->proximo;
    }

    free(atual->proximo);
    atual->proximo = NULL;
}

void remover_em(No* head, int pos){
    if (head == NULL || pos < 0) return;
    if (pos==0){
        remover_frente(head);
        return;
    }

    No* atual = head;
    int indice = 0;

    while(atual->proximo != NULL && indice < pos - 1){
        atual = atual->proximo;
        indice++;
    }

    if(atual->proximo == NULL){
        remover_atras(head);
        return;
    }

    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
}*/

// COM INT

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
    return;
}

int inserir_frente(No* head, int valor){
    No* novo_no = criar_no(valor);
    if(novo_no == NULL) return 1;
    novo_no->proximo = head;
    head = novo_no;
    return 0;
}

int inserir_atras(No* head, int valor){
    No* novo_no = criar(valor);
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

int inserir_em(No* head, int valor, int pos){
    if(head == NULL || pos<=0) return inserir_frente(head, valor);

    No* atual = head;
    int indice = 0;

    while(atual->proximo != NULL && indice != pos - 1){
        atual = atual->proximo;
        indice++;
    }

    No* novo_no = criar_no(valor);
    if(novo_no == NULL) return 1;

    novo_no->proximo = atual->proximo;
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
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }

    free(atual->proximo);
    atual->proximo = NULL;
    return 0;
}

int remover_em(No* head, int pos){
    if(head == NULL || pos < 0) return 1;
    if(pos == 0) return remover_frente(head);

    No* atual = head;
    int indice = 0;

    while(atual->proximo != NULL && indice < pos - 1){
        atual = atual->proximo;
        indice++;
    }

    if(atual->proximo == NULL) return remover_atras(head);

    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
    return 0;
}