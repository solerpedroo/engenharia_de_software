// VOID

/*#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    No* primeiro;
    No* ultimo;
} Fila;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return;
}

void inserir(Fila* f, int valor){
    No* novo_no = criar_no(valor);

    if(f->ultimo == NULL){
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{
        f->ultimo = novo_no;
        f->ultimo->proximo = novo_no;
    }
}

void remover(Fila* f){
    if(f->ultimo == NULL) return;

    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    if(f->primeiro == NULL) f->ultimo = NULL;
    free(temp);
}*/

// INT

/*#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    No* primeiro;
    No* ultimo;
} Fila;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return;
}

int inserir(Fila* f, int valor){
    No* novo_no = criar_no(valor);

    if(f->ultimo == NULL){
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{
        f->ultimo = novo_no;
        f->ultimo->proximo = novo_no;
    }

    return 0;
}

int remover(Fila* f){
    if(f->ultimo == NULL) return 1;

    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    if(f->primeiro == NULL) f->ultimo = NULL;
    free(temp);
    return 0;
}*/

// STRUCT 

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    No* primeiro;
    No* ultimo;
} Fila;

No* criar_no(int valor){
    No* novo_no = criar_no(valor);
    novo_no->proximo = NULL;
    novo_no->valor = valor;
    return novo_no;
}

Fila* inserir(Fila* f, int valor){
    No* novo_no = criar_no(valor);
    if(f->ultimo == NULL){
        f->primeiro = novo_no;
        f->ultimo = novo_no;
    }
    else{
        f->ultimo = novo_no;
        f->ultimo->proximo = novo_no;
    }

    return;
}

Fila* remover(Fila* f){
    if(f->ultimo == NULL) return;

    No* temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    if(f->primeiro == NULL) f->ultimo = NULL;
    free(temp);
    return;
}