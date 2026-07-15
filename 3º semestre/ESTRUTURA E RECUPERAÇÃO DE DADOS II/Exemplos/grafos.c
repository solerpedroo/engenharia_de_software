#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

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

    //Alocacao dinamica da matriz de adjacencias - 
    grafo->matrizadjacencias = (int**) malloc(max * sizeof(int*)); //Primeiro aloca as linhas da matriz, que sao ponteiros para int

                        if (grafo->matrizadjacencias == NULL) {
                            printf("Erro ao alocar memoria para a matriz de adjacencias.\n");
                            free(grafo->vertices);
                            free(grafo);
                            return NULL;
                        }

    for (int i = 0; i < max; i++) { // Depois aloca as colunas da matriz, que sao os ints
        grafo->matrizadjacencias[i] = (int*) malloc(max * sizeof(int)); 

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

// Obtem o indice de um vertice no vetor de vertices do grafo
//Retorna o indice do vertice, se encontrar; -1, se nao encontrar
int obterindice(const Grafo *grafo, const TipoItem item) {
    if (grafo == NULL) {
        return -1;
    }

    for (int i = 0; i < grafo->numvertices; i++) {
        if (strcmp(item, grafo->vertices[i]) == 0) {
            return i;
        }
    }

    return -1;
}

// Verifica se o grafo ja atingiu a quantidade maxima de vertices
int estacheio(const Grafo *grafo) {
    if (grafo == NULL) {
        return 0;
    }

    return grafo->numvertices == grafo->maxvertices;
}

// Insere um novo vertice no grafo
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

    //Adicionamos o vertice no vetor de vertices do grafo, e incrementamos a quantidade de vertices cadastrados
    strcpy(grafo->vertices[grafo->numvertices], item);
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

    /*
        Como o enunciado considera grafo simples, nao permitimos laco.
        Ou seja, nao pode existir aresta de um vertice para ele mesmo.
    */
    if (linha == coluna) {
        printf("Grafo simples nao permite laco!\n");
        return;
    }

    /*
        O peso nao pode ser igual ao valor que representa ausencia de aresta.
        Exemplo: se arestanula = 0, entao uma aresta nao pode ter peso 0.
    */
    if (peso == grafo->arestanula) {
        printf("O peso nao pode ser igual ao valor que representa ausencia de aresta!\n");
        return;
    }

    grafo->matrizadjacencias[linha][coluna] = peso;
    grafo->matrizadjacencias[coluna][linha] = peso;
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

    /*
        Percorremos apenas os vertices cadastrados, e nao maxvertices.
        Assim, a matriz impressa e analisada considera somente vertices existentes.
    */
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
        printf("%d: %s\n", i, grafo->vertices[i]);
    }
}

// Remove a aresta entre dois vertices, preenchendo a posicao correspondente na matriz com o valor que representa ausencia de aresta
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
    grafo->matrizadjacencias[coluna][linha] = grafo->arestanula;
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

    // Remove o vertice do vetor de vertices, e decrementa a quantidade de vertices cadastrados
    for (int i = indice; i < grafo->numvertices - 1; i++) {
        strcpy(grafo->vertices[i], grafo->vertices[i + 1]);
    }
    // Limpa a última posição do vetor, que agora contém "lixo" após o deslocamento dos vértices
    memset(grafo->vertices[grafo->numvertices - 1], 0, sizeof(TipoItem));

    grafo->numvertices--;

    // Remove as arestas associadas ao vertice removido, preenchendo a linha e coluna correspondentes com o valor que representa ausencia de aresta
    for (int i = 0; i < grafo->numvertices; i++) {
        grafo->matrizadjacencias[indice][i] = grafo->arestanula;
        grafo->matrizadjacencias[i][indice] = grafo->arestanula;
    }
}