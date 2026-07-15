// GRAFOS DIRECIONADOS PONDERADOS
#ifndef GRAFOS_H
#define GRAFOS_H

// typedef char TipoItem[50]; //Modificação
typedef char TipoItem;

typedef struct Grafo Grafo;


Grafo* criarGrafo(int max, int valorarestanula);

void destruirGrafo(Grafo **grafo);

int obterindice(const Grafo *grafo, const TipoItem item);

int estacheio(const Grafo *grafo);

void inserevertice(Grafo *grafo, const TipoItem item);

void inserearesta(Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada, int peso);

int obterpeso(const Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada);

int obtergrau(const Grafo *grafo, const TipoItem item);

void removervertice(Grafo *grafo, const TipoItem item);

void removeraresta(Grafo *grafo, const TipoItem NoSaida, const TipoItem NoEntrada);

void imprimirmatriz(const Grafo *grafo);

void imprimirvertices(const Grafo *grafo);

void bfsCaminho(const Grafo *grafo, const TipoItem inicio, const TipoItem fim); 

void dfsCaminho(const Grafo *grafo, const TipoItem inicio, const TipoItem fim); 

int menorDistancia(int* distancias, bool* explorado, int n);

void dijkstra(const Grafo *grafo, const TipoItem inicio, int* distancias, int* pais); 

void imprimirCaminhoMinimo(const Grafo *grafo, TipoItem inicio, TipoItem fim, int *distancias, int *pais);

int obterNumeroVertices(const Grafo *grafo);

#endif