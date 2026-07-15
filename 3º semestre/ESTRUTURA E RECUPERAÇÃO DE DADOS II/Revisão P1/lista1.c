#include <stdio.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Lista{
    int tamanho;
    struct No* inicio;
} Lista;

Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if(lista){
        lista->inicio = NULL;
        lista-> tamanho = 0;
    }
    return lista;
}

void inserirInicio(Lista* lista, int valor){
    No* novoNo = (No*)malloc(sizeof(No));

    if(novoNo){
        novoNo->valor = valor;
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
        lista->tamanho++;
    }
}

void inserirFim (Lista* lista, int valor){
    No* novoNo = (No*)malloc(sizeof(No));

    if(novoNo){
        novoNo->valor = valor;
        novoNo->proximo = NULL;

        if(lista->inicio == NULL){
            lista->inicio = novoNo;
        }else{
            No* temp = lista->inicio;
            while (temp->proximo != NULL){
                temp = temp->proximo;
            }
            temp->proximo = novoNo;
        }
        lista->tamanho++;
    }
}

No* remover (Lista* lista, int valor){
    No* anterior = NULL;
    No* remover = lista->inicio;

    if(lista->inicio){
        while(remover != NULL){
            if(remover->valor == valor){
                if(anterior == NULL){
                    lista->inicio = remover->proximo;
                }
            }else{
                anterior->proximo = remover->proximo;
            }
            lista->tamanho--;
            return remover;
        }
        anterior = remover;
        remover = remover->proximo;
    }
    return NULL;
}