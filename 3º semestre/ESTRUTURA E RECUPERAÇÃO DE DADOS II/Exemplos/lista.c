#include <stdlib.h> 
#include <stdio.h>

typedef struct No {
    int valorNo;
    struct No* proxNo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Lista;

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    if(lista){
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void inserirInicio(Lista* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
        novoNo->valorNo = valor;
        novoNo->proxNo = lista->inicio;
        lista->inicio = novoNo;
        lista->tamanho++;
    }
}

void inserirFim(Lista* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
        novoNo->valorNo = valor;
        novoNo->proxNo = NULL;

        if(lista->inicio == NULL) {
            lista->inicio = novoNo;
        } else {
            No* temp = lista->inicio;
            while(temp->proxNo != NULL) {
                temp = temp->proxNo;
            }
            temp->proxNo = novoNo;
        }
        lista->tamanho++;
    }
}

No* buscar(Lista* lista, int valor) {
    No* temp = lista->inicio;
    while(temp != NULL) {
        if(temp->valorNo == valor) {
            return temp;
        }
        temp = temp->proxNo;
    }
    return NULL; // Valor não encontrado
}


No *removerNo(Lista* lista, int valor) {
    No* anterior = NULL; 
    No* remover = lista->inicio; 

    if(lista->inicio) { 
        while(remover != NULL) { 
            if(remover->valorNo == valor) {
                if(anterior == NULL) { 
                    lista->inicio = remover->proxNo; 
                } else { 
                    anterior->proxNo = remover->proxNo; 
                }
                lista->tamanho--;
                return remover; 
            }
            anterior = remover;
            remover = remover->proxNo;
        }

    }
        return NULL;
}

void imprimirLista(Lista* lista) {
    No* temp = lista->inicio;
    while(temp) {
        printf("%d -> ", temp->valorNo);
        temp = temp->proxNo;
    }
    printf("NULL\n");
}

void removerPares(Lista* lista) {
    No* anterior = NULL;
    No* remover = lista->inicio;

    if (lista->inicio) {
        while (remover != NULL) {
            if (remover->valorNo % 2 == 0) {
                if (anterior == NULL) {
                    lista->inicio = remover->proxNo;
                } else {
                    anterior->proxNo = remover->proxNo;
                }
                No* temp = remover;
                remover = remover->proxNo;
                free(temp);
                temp = NULL;
                lista->tamanho--;
            } else {
                anterior = remover;
                remover = remover->proxNo;
            }
        }
    }
}

void remover(Lista* lista, int valor) {
    No* anterior = NULL; 
    No* removerNo = lista->inicio; 

    if(lista->inicio) { 
        while(removerNo != NULL) { 
            if(removerNo->valorNo == valor) {
                if(anterior == NULL) { 
                    lista->inicio = removerNo->proxNo; 
                } else { 
                    anterior->proxNo = removerNo->proxNo; 
                }
                free(removerNo); 
                removerNo = NULL; 
                lista->tamanho--;
                return; 
            }else {
            anterior = removerNo;
            removerNo = removerNo->proxNo;
            }
        }
    }
        printf("Valor %d não encontrado para remoção.\n",valor);
}


void liberarLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proxNo;
        free(temp);
    }
    free(lista);
}


int main(){

Lista *lista = criarLista();
int opcao, valor;

do{
    printf("1. Inserir no início\n");
    printf("2. Inserir no fim\n");
    printf("3. Buscar valor\n");
    printf("4. Remover valor\n");
    printf("5. Imprimir lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o valor para inserir no início: ");
            scanf("%d", &valor);
            inserirInicio(lista, valor);
            break;
        case 2:
            printf("Digite o valor para inserir no fim: ");
            scanf("%d", &valor);
            inserirFim(lista, valor);
            break;
        case 3:
            printf("Digite o valor para buscar: ");
            scanf("%d", &valor);
            No* encontrado = buscar(lista, valor);
            if(encontrado) {
                printf("Valor %d encontrado na lista.\n", valor);
            } else {
                printf("Valor %d não encontrado na lista.\n", valor);
            }
            break;
        case 4:
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);
            remover(lista, valor);
            break;
        case 5:
            imprimirLista(lista);
            break;
        case 0:
            liberarLista(lista);
            printf("Liberando memória e saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }

}while (opcao != 0);

return 0;

}