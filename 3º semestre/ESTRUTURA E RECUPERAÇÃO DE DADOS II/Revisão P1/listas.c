#include <stdio.h>;

typedef struct No{
    int valor;
    struct No* proximo
} No;

typedef struct Lista{
    struct No* inicio;
    int tamanho;
} Lista;

Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    if (lista){
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void inserirInicio(Lista* lista, int valor){
    No* novoNo = (No*)malloc(sizeof(No));

    if(novoNo){
        novoNo->valor = valor;
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
        lista->tamanho ++;
    }
}

void inserirFim (Lista* lista, int valor){
    No* novoNo = (No*)malloc(sizeof(No));

    if(novoNo){
        novoNo->valor = valor;
        novoNo->proximo = NULL;

        if (lista->inicio == NULL){
            lista->inicio = novoNo;
        }else{
            No* temp = lista->inicio;
            while (temp != NULL){
                temp = temp->proximo;
            }
            temp->proximo = novoNo;
        }
        lista->tamanho++;
    }
}

void buscar(const Lista* lista, int valor){
    No* temp = lista->inicio;
    while(temp != NULL){
        if (temp->valor == valor) return temp;
        temp = temp->proximo;
    }
    return NULL;
}

No* remover (Lista* lista, int valor){
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
            }
            lista->tamanho--;
            return remover;
        }
    }
    return NULL;
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

void buscar(const Lista* lista, int valor){
    No* temp = lista->inicio;
    while(lista->inicio != NULL){
        if(temp->valor == valor) return temp;
        temp = temp->proximo;
    }
    return NULL;
}

void inserirFim(Lista* lista, int valor){
    No* no = (No*)malloc(sizeof(No));
    if(no){
        no->valor = valor;
        no->proximo = NULL;
    }
    if(lista->inicio == NULL){
        lista->inicio = no;
    }else{
        No* temp = lista->inicio;
        while(temp->proximo != NULL){
            temp = temp->proximo;
        }
        temp->proximo = no;
    }
    lista->tamanho++;
}