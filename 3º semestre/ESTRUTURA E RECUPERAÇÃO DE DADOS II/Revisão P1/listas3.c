#include <stdio.h>

typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Lista{
    int tamanho;
    struct No* inicio;
} Lista;

Lista* lista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if(lista){
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void inserirInicio(Lista* l, int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
        novoNo->valor = valor;
        novoNo->proximo = l->inicio;
        l->inicio = novoNo;
        l->tamanho++;
    }
}

void inserirFim(Lista* l, int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
        novoNo->valor = valor;
        novoNo->proximo = NULL;
        
        if(l->inicio == NULL){
            l->inicio = novoNo;
        }else{
            No* temp = l->inicio;
            while(temp->proximo != NULL){
                temp = temp->proximo;
            }
            temp->proximo = novoNo;
        }
        l->tamanho++;
    }
}

No* remover(Lista* lista, int valor){
    No* anterior = NULL;
    No* remover = lista->inicio;

    if(lista->inicio){
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