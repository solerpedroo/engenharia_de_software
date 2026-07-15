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
    lista->inicio = NULL;
    lista->tamanho++;
    return lista;
}

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->proximo = NULL;
    novoNo->valor = valor;
    return novoNo;
}

void inserInicio(Lista* lista, int valor){
    No* novoNo = criarNo(valor);
    if(novoNo){
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
        lista->tamanho++;
    }
}

void inserirFim(Lista* lista, int valor){
    No* novoNo = criarNo(valor);
    if (lista->inicio == NULL){
        lista->inicio = novoNo;
    }else{
        No* temp = lista->inicio;
        while(temp->proximo != NULL){
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
    lista->tamanho++;
}

void remover(Lista* lista, int valor){
    No* remover = lista->inicio;
    No* anterior = NULL;
    if (lista->inicio){
        while(remover != NULL){
            if(remover->valor == valor){
                if(anterior == NULL){
                    lista->inicio = remover->proximo;
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
}