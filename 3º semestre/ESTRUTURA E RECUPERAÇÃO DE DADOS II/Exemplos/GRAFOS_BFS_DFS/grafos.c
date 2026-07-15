#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"
#include "fila.h"
#include "grafos.h"

typedef struct Grafo {
    int arestanula;              // valor usado para representar ausencia de aresta na matriz de adjacencias
    int maxvertices;             // quantidade maxima de vertices que o grafo pode conter
    int numvertices;             // quantidade atual de vertices cadastrados no grafo
    TipoItem *vertices;          // vetor de vertices, onde cada vertice e representado por um TipoItem (string)
    int **matrizadjacencias;     // matriz de adjacencias, onde o valor em matrizadjacencias[i][j] representa o peso da aresta entre os vertices i e j
} Grafo;

Grafo* criarGrafo(int max, int valorarestanula) {
    Grafo *grafo = malloc(sizeof(Grafo));

                        if (grafo == NULL) {
                            printf("Erro ao alocar memoria para o grafo.\n");
                            return NULL;
                        }

    grafo->numvertices = 0;
    grafo->maxvertices = max;
    grafo->arestanula = valorarestanula;

    grafo->vertices = malloc(max * sizeof(TipoItem));

                        if (grafo->vertices == NULL) {
                            printf("Erro ao alocar memoria para os vertices.\n");
                            free(grafo);
                            return NULL;
                        }

    grafo->matrizadjacencias = malloc(max * sizeof(int*)); //Primeiro aloca as linhas da matriz, que sao ponteiros para int

                        if (grafo->matrizadjacencias == NULL) {
                            printf("Erro ao alocar memoria para a matriz de adjacencias.\n");
                            free(grafo->vertices);
                            free(grafo);
                            return NULL;
                        }

    for (int i = 0; i < max; i++) { // Depois aloca as colunas da matriz, que sao os ints
        grafo->matrizadjacencias[i] = malloc(max * sizeof(int)); 

                        if (grafo->matrizadjacencias[i] == NULL) {
                            printf("Erro ao alocar memoria para uma linha da matriz.\n");
                        
                            for (int j = 0; j < i; j++) {
                                free(grafo->matrizadjacencias[j]);
                            }
                        
                            free(grafo->matrizadjacencias);
                            free(grafo->vertices);
                            free(grafo);
                            return NULL;
                        }
    }

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            grafo->matrizadjacencias[i][j] = valorarestanula;
        }
    }

    return grafo;
}

void destruirGrafo(Grafo **grafo) {
    if (grafo == NULL || *grafo == NULL) {
        return;
    }

    for (int i = 0; i < (*grafo)->maxvertices; i++) {
        free((*grafo)->matrizadjacencias[i]); // Liberar cada coluna da matriz
    }

    free((*grafo)->matrizadjacencias); // Liberar as linhas da matriz
    free((*grafo)->vertices); // Liberar o vetor de vertices
    free(*grafo); // Liberar a estrutura do grafo

    *grafo = NULL;
}

int obterindice(const Grafo *grafo, const TipoItem item) {
    if (grafo == NULL) {
        return -1;
    }

    for (int i = 0; i < grafo->numvertices; i++) {

        if(item == grafo->vertices[i]) {
            return i;
        }
    }

    return -1;
}

int estacheio(const Grafo *grafo) {
    if (grafo == NULL) {
        return 0;
    }

    return grafo->numvertices == grafo->maxvertices;
}

void inserevertice(Grafo *grafo, const TipoItem item) {
    if (grafo == NULL) {
        return;
    }

    if (estacheio(grafo)) {
        printf("O numero maximo de vertices foi alcancado!\n");
        return;
    }

    if (obterindice(grafo, item) != -1) {
        printf("Esse vertice ja existe no grafo!\n");
        return;
    }

    grafo->vertices[grafo->numvertices] = item;
    grafo->numvertices++;
}

void inserearesta(Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada, int peso) {
    if (grafo == NULL) {
        return;
    }

    int linha = obterindice(grafo, NoSaida);
    int coluna = obterindice(grafo, NoEntrada);

    if (linha == -1 || coluna == -1) {
        printf("Um ou ambos os vertices nao existem no grafo!\n");
        return;
    }

    grafo->matrizadjacencias[linha][coluna] = peso;
    // grafo->matrizadjacencias[coluna][linha] = peso; // Apenas para grafos não direcionados
}

int obterpeso(const Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada) {
    if (grafo == NULL) {
        return -1;
    }

    int linha = obterindice(grafo, NoSaida);
    int coluna = obterindice(grafo, NoEntrada);

    if (linha == -1 || coluna == -1) {
        printf("Um ou ambos os vertices nao existem no grafo!\n");
        return -1;
    }

    if (grafo->matrizadjacencias[linha][coluna] == grafo->arestanula) {
        printf("Nao existe aresta entre os vertices!\n");
        return grafo->arestanula;
    }

    return grafo->matrizadjacencias[linha][coluna];
}

int obtergrau(const Grafo *grafo, const TipoItem item) {
    if (grafo == NULL) {
        return -1;
    }

    int linha = obterindice(grafo, item);

    if (linha == -1) {
        printf("Vertice nao encontrado!\n");
        return -1;
    }

    int grau = 0;

    for (int i = 0; i < grafo->numvertices; i++) {
        if (grafo->matrizadjacencias[linha][i] != grafo->arestanula) { // Se o valor for diferente do valor que representa ausencia de aresta, entao existe uma aresta
            grau++;
        }
    }

    return grau;
}

void imprimirmatriz(const Grafo *grafo) {
    if (grafo == NULL) {
        return;
    }

    printf("Matriz de adjacencias:\n");

    for (int i = 0; i < grafo->numvertices; i++) {
        for (int j = 0; j < grafo->numvertices; j++) {
            printf("%d ", grafo->matrizadjacencias[i][j]);
        }
        printf("\n");
    }
}

void imprimirvertices(const Grafo *grafo) {
    if (grafo == NULL) {
        return;
    }

    printf("Lista de vertices:\n");

    for (int i = 0; i < grafo->numvertices; i++) {
        printf("%d: %c\n", i, grafo->vertices[i]);
    }
}

void removeraresta(Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada) {
    if (grafo == NULL) {
        return;
    }

    int linha = obterindice(grafo, NoSaida);
    int coluna = obterindice(grafo, NoEntrada);

    if (linha == -1 || coluna == -1) {
        printf("Um ou ambos os vertices nao existem no grafo!\n");
        return;
    }

    grafo->matrizadjacencias[linha][coluna] = grafo->arestanula; 
    // grafo->matrizadjacencias[coluna][linha] = grafo->arestanula; // Apenas para grafos não direcionados
}

void removervertice(Grafo *grafo, const TipoItem item) {
    if (grafo == NULL) {
        return;
    }

    int indice = obterindice(grafo, item);

    if (indice == -1) {
        printf("Vertice nao encontrado!\n");
        return;
    }

    for (int i = indice; i < grafo->numvertices - 1; i++) {
        grafo->vertices[i] = grafo->vertices[i + 1];
    }

    grafo->numvertices--;

    for (int i = 0; i < grafo->numvertices; i++) {
        grafo->matrizadjacencias[indice][i] = grafo->arestanula;
        grafo->matrizadjacencias[i][indice] = grafo->arestanula;
    }
}


// Busca em Largura (BFS)

void bfs(const Grafo *grafo, const TipoItem inicio, const TipoItem fim){

        int indiceInicio = obterindice(grafo, inicio);
        int indiceFim = obterindice(grafo, fim);
    
        if (indiceInicio == -1 || indiceFim == -1) {
            printf("Um ou ambos os vertices nao existem no grafo!\n");
            return;
        }
    
        bool *visitado = malloc(grafo->numvertices * sizeof(bool));
        for (int i = 0; i < grafo->numvertices; i++) {
            visitado[i] = false;
        }
    
        Fila *fila = criarFila();
        enfileirar(fila, indiceInicio);
        printf("Iniciando BFS a partir do vertice: %c\n", grafo->vertices[indiceInicio]);
        visitado[indiceInicio] = true;
        bool encontrou = false;

        while (!filaVazia(fila)) {
            int verticeAtual;
            desenfileirar(fila, &verticeAtual);
    
            printf("Visitando vertice (Desenfileirando): %c\n", grafo->vertices[verticeAtual]);
    
            if (verticeAtual == indiceFim) {
                printf("Existe caminho entre os vértices %c e %c!\n", inicio, fim);
                encontrou = true;
                break;
            }
    
            for (int i = 0; i < grafo->numvertices; i++) {
                if ((grafo->matrizadjacencias[verticeAtual][i] != grafo->arestanula) && !visitado[i]) {
                    printf("Enfileirando vertice adjacente: %c\n", grafo->vertices[i]);
                    enfileirar(fila, i);
                    visitado[i] = true;
                }
            }
        }

        if (!encontrou) {
            printf("Nao existe caminho entre os vertices %c e %c!\n", inicio, fim);
        }
    
        free(visitado);
        destruirFila(fila);
}

// Busca em Profundidade (DFS)
void dfs(const Grafo *grafo, const TipoItem inicio, const TipoItem fim){
    int indiceInicio = obterindice(grafo, inicio);
    int indiceFim = obterindice(grafo, fim);

    if (indiceInicio == -1 || indiceFim == -1) {
        printf("Um ou ambos os vertices nao existem no grafo!\n");
        return;
    }

    bool *visitado = malloc(grafo->numvertices * sizeof(bool));
    for (int i = 0; i < grafo->numvertices; i++) {
        visitado[i] = false;
    }

    Pilha *pilha = criarPilha();
    empilhar(pilha, indiceInicio);
    printf("Iniciando DFS a partir do vertice: %c\n", grafo->vertices[indiceInicio]);
    visitado[indiceInicio] = true;
    bool encontrou = false;

    while (!pilhaVazia(pilha)) {
        int verticeAtual;
        desempilhar(pilha, &verticeAtual);

        printf("Visitando vertice (Desempilhando): %c\n", grafo->vertices[verticeAtual]);

        if (verticeAtual == indiceFim) {
            printf("Existe caminho entre os vértices %c e %c!\n", inicio, fim);
            encontrou = true;
            break;
        }

        for (int i = 0; i < grafo->numvertices; i++) {
            if (grafo->matrizadjacencias[verticeAtual][i] != grafo->arestanula && !visitado[i]) {
                printf("Empilhando vertice adjacente: %c\n", grafo->vertices[i]);
                empilhar(pilha, i);
                visitado[i] = true;
            }
        }
    }

    if (!encontrou) {
        printf("Nao existe caminho entre os vertices %c e %c!\n", inicio, fim);
    }

    free(visitado);
    apagarPilha(pilha);
}

// Busca em Largura (BFS)
void bfsCaminho(const Grafo *grafo, const TipoItem inicio, const TipoItem fim){

    int indiceInicio = obterindice(grafo, inicio);
    int indiceFim = obterindice(grafo, fim);

    if (indiceInicio == -1 || indiceFim == -1) {
        printf("Um ou ambos os vertices nao existem no grafo!\n");
        return;
    }

    bool *visitado = malloc(grafo->numvertices * sizeof(bool));
    int *pai = malloc(grafo->numvertices * sizeof(int));//MODIFICADO

    for (int i = 0; i < grafo->numvertices; i++) {
        visitado[i] = false;
        pai[i] = -1;//MODIFICADO
    }

    Fila *fila = criarFila();
    enfileirar(fila, indiceInicio);
    printf("Iniciando BFS a partir do vertice: %c\n", grafo->vertices[indiceInicio]);
    visitado[indiceInicio] = true;
    bool encontrou = false;

    while (!filaVazia(fila)) {
        int verticeAtual;
        desenfileirar(fila, &verticeAtual);

        printf("Visitando vertice (Desenfileirando): %c\n", grafo->vertices[verticeAtual]);

        if (verticeAtual == indiceFim) {
            printf("Existe caminho entre os vértices %c e %c!\n", inicio, fim);
            encontrou = true;
            printf("O caminho encontrado é: FIM <- ");//MODIFICADO

            int atual = indiceFim;//MODIFICADO
            while(atual!= -1)//MODIFICADO
            {
                printf("%c <- ",grafo->vertices[atual]);//MODIFICADO
                atual = pai[atual];//MODIFICADO
            }
            printf("INICIO");//MODIFICADO

            break;
        }

        for (int i = 0; i < grafo->numvertices; i++) {
            if ((grafo->matrizadjacencias[verticeAtual][i] != grafo->arestanula) && !visitado[i]) {
                printf("Enfileirando vertice adjacente: %c\n", grafo->vertices[i]);
                enfileirar(fila, i);
                visitado[i] = true;

                pai[i] = verticeAtual; //MODIFICADO
            }
        }
    }

    if (!encontrou) {
        printf("Nao existe caminho entre os vertices %c e %c!\n", inicio, fim);
    }

    free(visitado);
    free(pai);
    destruirFila(fila);
}

// Busca em Profundidade (DFS)
void dfsCaminho(const Grafo *grafo, const TipoItem inicio, const TipoItem fim){
int indiceInicio = obterindice(grafo, inicio);
int indiceFim = obterindice(grafo, fim);

if (indiceInicio == -1 || indiceFim == -1) {
    printf("Um ou ambos os vertices nao existem no grafo!\n");
    return;
}

bool *visitado = malloc(grafo->numvertices * sizeof(bool));
int *pai = malloc(grafo->numvertices * sizeof(int));//MODIFICADO

for (int i = 0; i < grafo->numvertices; i++) {
    visitado[i] = false;
    pai[i] = -1;//MODIFICADO
}

Pilha *pilha = criarPilha();
empilhar(pilha, indiceInicio);
printf("Iniciando DFS a partir do vertice: %c\n", grafo->vertices[indiceInicio]);
visitado[indiceInicio] = true;
bool encontrou = false;

while (!pilhaVazia(pilha)) {
    int verticeAtual;
    desempilhar(pilha, &verticeAtual);

    printf("Visitando vertice (Desempilhando): %c\n", grafo->vertices[verticeAtual]);

    if (verticeAtual == indiceFim) {
        printf("Existe caminho entre os vértices %c e %c!\n", inicio, fim);
        encontrou = true;
        printf("O caminho encontrado é: FIM <- ");//MODIFICADO

        int atual = indiceFim;//MODIFICADO
        while(atual!= -1)//MODIFICADO
        {
            printf("%c <- ",grafo->vertices[atual]);//MODIFICADO
            atual = pai[atual];//MODIFICADO
        }
        printf("INICIO");//MODIFICADO

        break;
    }

    for (int i = 0; i < grafo->numvertices; i++) {
        if (grafo->matrizadjacencias[verticeAtual][i] != grafo->arestanula && !visitado[i]) {
            printf("Empilhando vertice adjacente: %c\n", grafo->vertices[i]);
            empilhar(pilha, i);
            visitado[i] = true;

            pai[i] = verticeAtual;
        }
    }
}

if (!encontrou) {
    printf("Nao existe caminho entre os vertices %c e %c!\n", inicio, fim);
}

free(visitado);
free(pai);
apagarPilha(pilha);
}