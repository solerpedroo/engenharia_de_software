#include <stdio.h>

typedef struct {
int arestanula;
int maxvertices;
int n; // quantidade de vértices
int *v; // vetor de vértices
int **M; // matriz de adjacências
} Grafo;

// === EXERCÍCIOS DE CÓDIGO ===

// Ex 5:

/*void dfs_aux(Grafo *g, int atual, int *visitado){

    visitado[atual] = 1;

    print("%d ", g->v[atual]);

    for (int i = 0; i<g->n; i++){
        if(g->M[atual][i] != g->arestanula && !visitado[i]){
            dfs_aux(g, i, visitado);
        }
    }

}

void dfs_recursiva(Grafo *g, int origem){

    int *visitado = calloc(g->n, sizeof(int));

    dfs_aux(g, origem, visitado);

    free(visitado);

}*/

// Ex 6: 

/*int existe_caminho_bfs(Grafo *g, int origem, int destino){

    int *descoberto = calloc(g->n, sizeof(int));

    Fila *f = criarFila();

    enfileirar(f, origem);

    descoberto[origem] = 1;

    while(!filaVazia(f)){

        int atual;

        desenfileirar(f, &atual);

        if(atual == destino){
            free(descoberto);
            destruirFila(f);
            return 1;
        }

        for (int i = 0; i<g->n; i++){
            if(g->M[atual][i] != g->arestanula && !descoberto[i]){
                enfileirar(f, i);
                descoberto[i] = 1;
            }
        }
    }

    free(descoberto);
    destruirFila(f);
    return 0;
}*/

// Ex 7:

/*int dfs_contar(Grafo *g, int atual, int *descoberto){

    descoberto[atual] = 1;

    int total = 1;

    for (int i = 0; i<g->n; i++){
        if(g->M[atual][i] != g->arestanula && !descoberto[i]){
            total += dfs_contar(g, i, descoberto);
        }
    }
    return total;
}

int contar_alcancaveis(Grafo *g, int origem){

    int *descoberto = calloc(g->n, sizeof(int));

    int total = dfs_contar(g, origem, descoberto);

    free(descoberto);

    return total;
}*/

// Ex 8:

/*int* obter_adjacentes(Grafo *g, int vertice, int *quantidade){

    *quantidade = 0;

    for (int i = 0; i <g->n; i++){
        if(g->M[vertice][i] != g->arestanula){
            (*quantidade)++;
        }
    }

    int *adj = malloc((*quantidade) * sizeof(int));

    int pos = 0;

    for (int i = 0; i<g->n; i++){
        if(g->M[vertice][i] != g->arestanula){
            adj[pos++] = g->v[i];
        }
    }
    return adj;
}*/

// Ex 9:

/*int eh_isolado(Grafo *g, int vertice){

    for (int i = 0; i<g->n; i++){
        if(g->M[vertice][i] != g->arestanula){
            return 0;
        }
    }
    return 1;
}*/

// Ex 10:

/*int contar_arestas(Grafo *g){
    int total = 0;

    for (int i = 0; i<g->n; i++){
        for(int j = i+1; j<g->n; j++){
            if(g->M[i][j] != g->arestanula){
                total++;
            }
        }
    }
    return total;
}*/

// Ex 11:

/*int grau_entrada(Grafo *g, int vertice){
    int grau = 0;

    for (int i = 0; i<g->n; i++){
        if(g->M[i][vertice] != g->arestanula){
            grau++;
        }
    }
    return grau;
}*/

// Ex 12:

/*int grau_saida(Grafo *g, int vertice){
    int grau = 0;

    for (int j = 0; j<g->n; j++){
        if(g->M[vertice][j] != g->arestanula){
            grau++;
        }
    }
    return grau;
}*/

// Ex 13:

void marcar_componentes(Grafo *g, int atual, int *visitado){

    visitado[atual] = 1;

    for (int i = 0; i<g->n; i++){
        if(g->M[atual][i] != g->arestanula && !visitado[i]){
            marcar_componentes(g, i, visitado);
        }
    }

}

int contar_componentes(Grafo *g){
    
    int *visitado = calloc(g->n, sizeof(int));

    int componentes = 0;

    for(int i = 0; i<g->n; i++){
        if(!visitado[i]){
            componentes++;
            marcar_componentes(g, i, visitado);
        }
    }
    free(visitado);
    return componentes;
} 