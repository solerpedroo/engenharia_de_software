#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct No {
    int vertice;             // Índice do vértice conectado
    int peso;                // Peso da aresta
    struct No *proximo;      // Ponteiro para o próximo nó na lista
} No;

typedef struct Lista {
    No *inicio;              // Ponteiro para o primeiro nó da lista
} Lista;

typedef struct GrafoListas {
    int numvertices;         // Quantidade de vértices
    int arestanula;          // Valor que representa ausência de aresta
    Lista *listasadjacencias;// Vetor de listas de adjacências
} GrafoListas;

typedef char TipoItem[50];

typedef struct Grafo {
    int arestanula;              // valor usado para representar ausencia de aresta na matriz de adjacencias
    int maxvertices;             // quantidade maxima de vertices que o grafo pode conter
    int numvertices;             // quantidade atual de vertices cadastrados no grafo
    TipoItem *vertices;          // vetor de vertices, onde cada vertice e representado por um TipoItem (string)
    int **matrizadjacencias;     // matriz de adjacencias, onde o valor em matrizadjacencias[i][j] representa o peso da aresta entre os vertices i e j
} Grafo;

/*
    Cria dinamicamente um grafo.

    max:
        quantidade maxima de vertices.

    valorarestanula:
        valor usado na matriz para representar ausencia de aresta.
        Exemplo: 0 ou -1.
*/
Grafo* criarGrafo(int max, int valorarestanula);

/*
    Libera toda a memoria alocada para o grafo.
    Recebe Grafo**, pois tambem coloca o ponteiro como NULL ao final.
*/
void destruirGrafo(Grafo **grafo);

/*
    Procura o indice de um vertice no vetor de vertices.

    Retorna:
        indice do vertice, se encontrar;
        -1, se nao encontrar.
*/
int obterindice(const Grafo *grafo, const TipoItem item);

/*
    Verifica se o grafo ja atingiu a quantidade maxima de vertices.

    Retorna:
        1, se estiver cheio;
        0, caso contrario.
*/
int estacheio(const Grafo *grafo);

/*
    Insere um novo vertice no grafo.
*/
void inserevertice(Grafo *grafo, const TipoItem item);

/*
    Insere uma aresta ponderada entre dois vertices.

    Como este grafo e nao direcionado, a matriz e preenchida nas duas posicoes:

        matriz[linha][coluna]
        matriz[coluna][linha]
*/
void inserearesta(Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada, int peso);

/*
    Retorna o peso da aresta entre dois vertices.
*/

int obterpeso(const Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada);

/*
    Retorna o grau de um vertice.
*/
int obtergrau(const Grafo *grafo, const TipoItem item);

/*
    Remove um vertice do grafo, e todas as arestas associadas a ele.
*/
void removervertice(Grafo *grafo, const TipoItem item);

/*
    Remove a aresta entre dois vertices, preenchendo a posicao correspondente na matriz com o valor que representa ausencia de aresta.
*/
void removeraresta(Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada);

/*
    Imprime a matriz de adjacencias.
*/
void imprimirmatriz(const Grafo *grafo);

/*
    Imprime a lista de vertices cadastrados.
*/
void imprimirvertices(const Grafo *grafo);

#endif