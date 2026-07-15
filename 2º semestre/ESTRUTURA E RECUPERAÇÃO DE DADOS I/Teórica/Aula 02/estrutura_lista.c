#include <stdio.h>
#include <stdlib.h>

// estrutura de nó
typedef struct No
{
    int valor;
    struct No* proximo;
} No;

// criar novo nó
No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

// inserir na frente
No* inserir_frente(No* head, int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = head;
    return novo_no;
}

// inserir atrás
No* inserir_atras(No* head, int valor){
    No* novo_no = criar_no(valor);
    if (head == NULL) return novo_no;

    No* atual = head;
    while(atual->proximo != NULL) atual = atual->proximo;
    atual->proximo = novo_no;
    return head;
}

// inserir em uma posição específica
No* inserir_em(No* head, int valor, int pos){
    if (pos <= 0 || head == NULL) return inserir_frente(head, valor);

    No* atual = head;
    int indice = 0;

    while (atual->proximo != NULL && indice != pos - 1){
        atual = atual->proximo;
        indice++;
    }

    No* novo_no = criar_no(valor);
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
    return head;
}

// Remover frente
No* remover_frente(No* head) {
    if (head == NULL) return NULL;
    No* temp = head;
    head = head->proximo;
    free(temp);
    return head;
}

// Remover atrás
No* remover_atras(No* head) {
    if (head == NULL) return NULL;
    if (head->proximo == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    No* atual = head;
    while (atual->proximo->proximo != NULL) atual = atual->proximo;
    free(atual->proximo);
    atual->proximo = NULL;
    return head;
}

// Remover em uma posição fornecida
No* remover_em(No* head, int pos) {
    if (head == NULL || pos < 0) return head;
    if (pos == 0) return remover_frente(head);

    No* atual = head;
    int index = 0;
    while (atual->proximo != NULL && index < pos - 1) {
        atual = atual->proximo;
        index++;
    }

    if (atual->proximo == NULL) return remover_atras(head);
    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
    return head;
}

// Buscar por um valor
No* buscar(No* head, int valor) {
    No* atual = head;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Limpar a lista
void free_lista(No* head) {
    No* atual = head;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// Imprimir a lista
void print(No* head) {
    No* atual = head;
    printf("List: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main(){
    No* head = NULL;

    // inserir na frente (inicio)
    /*head = inserir_frente(head, 10);
    head = inserir_frente(head, 20);
    head = inserir_frente(head, 30);*/

    // inserir atrás (final)
    /*head = inserir_atras(head, 10);
    head = inserir_atras(head, 20);
    head = inserir_atras(head, 30);*/

    // inserir em uma posição fornecida
    // primeiro criar uma lista e posterior inserir nas posições
    /*head = inserir_atras(head, 10);
    head = inserir_atras(head, 20);
    head = inserir_atras(head, 30);

    head = inserir_em(head, 15, 1);
    head = inserir_em(head, 50, 2);*/

    // remover da frente (inicio)
    /*head = inserir_atras(head, 10);
    head = inserir_atras(head, 20);
    head = inserir_atras(head, 30);

    head = remover_frente(head);
    head = remover_frente(head);*/

    // remover atrás (final)
    /*head = inserir_atras(head, 10);
    head = inserir_atras(head, 20);
    head = inserir_atras(head, 30);

    head = remover_atras(head);
    head = remover_atras(head);*/

    // remover em uma posição fornecida
    head = inserir_atras(head, 10);
    head = inserir_atras(head, 20);
    head = inserir_atras(head, 30);
    head = inserir_atras(head, 40);
    head = inserir_atras(head, 50);
    head = inserir_atras(head, 60);

    head = remover_em(head, 1);
    head = remover_em(head, 2);

    print(head);
    free_lista(head);
    return 0;
}