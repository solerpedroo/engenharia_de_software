#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"
#include "fila.h"
#include "grafos.h"

int main() {
    int max, valorarestanula;

    printf("Digite a quantidade maxima de vertices:\n");
    scanf("%d", &max);

    printf("Digite o valor para representar a ausencia de aresta:\n");
    scanf("%d", &valorarestanula);

    Grafo *grafo1 = criarGrafo(max, valorarestanula);

    if (grafo1 == NULL) {
        printf("Nao foi possivel criar o grafo.\n");
        return 1;
    }

    TipoItem item1, item2;
    int opcao, valor, peso;

    do {
        printf("\nDigite 0 para parar o algoritmo!\n");
        printf("Digite 1 para inserir um vertice!\n");
        printf("Digite 2 para inserir uma aresta!\n");
        printf("Digite 3 para remover um vertice!\n");
        printf("Digite 4 para remover uma aresta!\n");
        printf("Digite 5 para imprimir a matriz de adjacencias!\n");
        printf("Digite 6 para imprimir a lista de vertices!\n");
        printf("Digite 7 para Buscar em Largura (BFS)!\n");
        printf("Digite 8 para Buscar em Profundidade (DFS)!\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case 1:
                printf("Digite o elemento do vertice que sera inserido:\n");
                scanf(" %c", &item1);

                inserevertice(grafo1, item1);
                
                break;
            case 2:
                printf("Digite o vertice de saida:\n");
                scanf(" %c", &item1);

                printf("Digite o vertice de entrada:\n");
                scanf(" %c", &item2);

                printf("Digite o peso desta aresta:\n");
                scanf("%d", &peso);

                inserearesta(grafo1, item1, item2, peso);

                break;
            case 3:
                printf("Digite o elemento do vertice que sera removido:\n");
                scanf(" %c", &item1);

                removervertice(grafo1, item1);

                break;
            case 4:
                printf("Digite o vertice de saida:\n");
                scanf(" %c", &item1);
                printf("Digite o vertice de entrada:\n");
                scanf(" %c", &item2);

                removeraresta(grafo1, item1, item2);

                break;
            case 5:

                imprimirmatriz(grafo1);

                break;
            case 6:

                imprimirvertices(grafo1);

                break;
            case 7:
                char inicio, fim;
                printf("Digite o vertice de inicio para a busca em largura:\n");
                scanf(" %c", &inicio);
                printf("Digite o vertice de fim para a busca em largura:\n");
                scanf(" %c", &fim);

                bfsCaminho(grafo1, inicio, fim);

                break;
            case 8:
                printf("Digite o vertice de inicio para a busca em profundidade:\n");
                scanf(" %c", &inicio);
                printf("Digite o vertice de fim para a busca em profundidade:\n");
                scanf(" %c", &fim);

                dfsCaminho(grafo1, inicio, fim);

                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    destruirGrafo(&grafo1);

    return 0;
}
