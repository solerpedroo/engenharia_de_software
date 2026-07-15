#include <stdio.h>

typedef struct {
int arestanula;
int maxvertices;
int n; // quantidade de vértices
int *v; // vetor de vértices
int **M; // matriz de adjacências
} Grafo;

// === EXERCÍCIOS DE CÓDIGO === 

// === Exercício 5

// Função auxiliar recursiva.
// Ela é quem realmente executa a Busca em Profundidade (DFS).
//
// Parâmetros:
// g -> ponteiro para o grafo
// atual -> vértice onde estamos neste momento
// visitado -> vetor que controla quais vértices já foram visitados
void dfs_aux(Grafo *g, int atual, int *visitado) {

    // Marca o vértice atual como visitado.
    //
    // Exemplo:
    // Se atual = 2
    //
    // Antes:
    // visitado = [0, 0, 0, 0, 0]
    //
    // Depois:
    // visitado = [0, 0, 1, 0, 0]
    //
    // 0 = não visitado
    // 1 = visitado
    visitado[atual] = 1;

    // Imprime o valor armazenado no vértice atual.
    //
    // Se atual = 2 e g->v[2] = 2
    //
    // Saída:
    // 2
    printf("%d ", g->v[atual]);

    // Percorre todos os possíveis vértices do grafo.
    //
    // Como estamos usando matriz de adjacência,
    // precisamos verificar toda a linha correspondente
    // ao vértice atual.
    //
    // Exemplo:
    // atual = 0
    //
    // Verifica:
    // M[0][0]
    // M[0][1]
    // M[0][2]
    // ...
    // M[0][n-1]
    for (int i = 0; i < g->n; i++) {

        // Primeira condição:
        //
        // g->M[atual][i] != g->arestanula
        //
        // Verifica se existe uma aresta ligando
        // o vértice atual ao vértice i.
        //
        // Segunda condição:
        //
        // !visitado[i]
        //
        // Verifica se o vértice i ainda não foi visitado.
        //
        // As duas condições precisam ser verdadeiras.
        if (g->M[atual][i] != g->arestanula && !visitado[i]) {

            // Aqui acontece a recursão.
            //
            // Encontramos um vizinho ainda não visitado.
            //
            // Então "mergulhamos" nele.
            //
            // Exemplo:
            //
            // Estamos no vértice 0
            // Encontramos ligação para o vértice 1
            //
            // Chamamos:
            //
            // dfs_aux(g, 1, visitado);
            //
            // Agora toda a execução passa a ocorrer
            // a partir do vértice 1.
            dfs_aux(g, i, visitado);
        }
    }

    // Quando o laço termina significa que:
    //
    // - Todos os vizinhos foram analisados
    // - Não há mais caminhos para seguir
    //
    // A função termina e retorna para a chamada anterior.
}

// Função que inicia a DFS.
//
// Parâmetros:
//
// g -> ponteiro para o grafo
// origem -> vértice onde a busca começará
void dfs_recursiva(Grafo *g, int origem) {

    // Cria dinamicamente o vetor de visitados.
    //
    // calloc faz duas coisas:
    //
    // 1) Reserva memória
    // 2) Inicializa tudo com zero
    //
    // Exemplo:
    //
    // g->n = 5
    //
    // Resultado:
    //
    // visitado = [0, 0, 0, 0, 0]
    //
    // Todos começam como "não visitados".
    int *visitado = calloc(g->n, sizeof(int));

    // Chama a função recursiva pela primeira vez.
    //
    // É aqui que a DFS começa.
    //
    // Exemplo:
    //
    // origem = 0
    //
    // Chamada:
    //
    // dfs_aux(g, 0, visitado);
    //
    // A partir desse ponto a função vai
    // visitando os vértices recursivamente.
    dfs_aux(g, origem, visitado);

    // Após terminar a busca,
    // liberamos a memória alocada.
    //
    // Boa prática para evitar vazamento de memória.
    free(visitado);
}

// === Exercício 6

int existe_caminho_bfs(Grafo *g, int origem, int destino)
{
    // Cria um vetor para marcar os vértices já descobertos.
    //
    // calloc inicializa tudo com zero.
    //
    // Exemplo:
    // [0,0,0,0,0]
    // 0 = não descoberto
    // 1 = descoberto
    int *descoberto = calloc(g->n, sizeof(int));

    // Cria a fila utilizada pela BFS.
    // A fila é o coração da busca em largura.
    Fila *fila = criarFila();

    // Coloca o vértice inicial na fila.
    enfileirar(fila, origem);

    // Marca a origem como descoberta.
    descoberto[origem] = 1;

    // Enquanto existir alguém na fila...
    while (!filaVazia(fila)) {

        int atual;

        // Remove o primeiro elemento da fila.
        // Esse vértice será analisado agora.
        desenfileirar(fila, &atual);

        // Verifica se encontramos o destino.
        if (atual == destino) {

            // Libera memória antes de sair.
            free(descoberto);
            destruirFila(fila);

            // Caminho encontrado.
            return 1;
        }

        // Percorre todos os possíveis vizinhos
        // do vértice atual.
        for (int i = 0; i < g->n; i++) {

            // Existe aresta?
            //
            // E o vértice ainda não foi descoberto?
            if (g->M[atual][i] != g->arestanula && !descoberto[i]) {

                // Coloca o vizinho na fila.
                enfileirar(fila, i);

                // Marca como descoberto.
                descoberto[i] = 1;
            }
        }
    }

    // Se chegamos aqui,
    // toda a busca terminou e
    // o destino nunca foi encontrado.

    free(descoberto);
    destruirFila(fila);

    return 0;
}

// === Exercício 7

// Função auxiliar recursiva.
//
// Objetivo:
// Contar quantos vértices podem ser alcançados
// a partir do vértice atual.
//
// Parâmetros:
//
// g -> ponteiro para o grafo
// atual -> vértice que está sendo visitado agora
// descoberto -> vetor que controla quais vértices
//               já foram visitados
//
// Retorno:
// Quantidade de vértices alcançáveis a partir
// deste vértice.
int dfs_contar(Grafo *g, int atual, int *descoberto)
{
    // Marca o vértice atual como visitado.
    //
    // Exemplo:
    //
    // atual = 2
    //
    // Antes:
    // [0 0 0 0]
    //
    // Depois:
    // [0 0 1 0]
    //
    // Isso impede que o algoritmo visite
    // o mesmo vértice várias vezes.
    descoberto[atual] = 1;

    // Começamos a contagem com 1.
    //
    // Por quê?
    //
    // Porque o próprio vértice atual
    // deve ser contado.
    //
    // Exemplo:
    //
    // Se chegamos ao vértice 5,
    // já encontramos pelo menos
    // um vértice.
    int total = 1;

    // Percorre todos os vértices do grafo.
    //
    // Como estamos usando matriz de adjacência,
    // precisamos verificar toda a linha
    // correspondente ao vértice atual.
    for (int i = 0; i < g->n; i++)
    {
        // Verifica duas condições:
        //
        // 1) Existe aresta entre
        //    "atual" e "i" ?
        //
        // 2) O vértice "i" ainda não foi visitado?
        //
        // Somente se as duas forem verdadeiras
        // continuamos a busca.
        if (g->M[atual][i] != g->arestanula &&
            !descoberto[i])
        {
            // Chamada recursiva.
            //
            // Vamos explorar o vértice i.
            //
            // A função retornará quantos
            // vértices ela conseguiu alcançar.
            //
            // Esse valor é somado ao total.
            //
            // Exemplo:
            //
            // total = 1
            //
            // dfs_contar(...) retorna 3
            //
            // total = 1 + 3
            //
            // total = 4
            total += dfs_contar(g, i, descoberto);
        }
    }

    // Quando todos os vizinhos foram analisados,
    // retornamos a quantidade encontrada.
    //
    // Esse valor será utilizado pela chamada
    // anterior da recursão.
    return total;
}



// Função principal.
//
// Objetivo:
// Contar quantos vértices podem ser alcançados
// a partir de um vértice de origem.
//
// Parâmetros:
//
// g -> ponteiro para o grafo
// origem -> vértice inicial da busca
//
// Retorno:
// Quantidade total de vértices alcançáveis.
int contar_alcancaveis(Grafo *g, int origem)
{
    // Cria o vetor de vértices descobertos.
    //
    // calloc:
    //
    // 1) Aloca memória
    // 2) Inicializa tudo com zero
    //
    // Exemplo:
    //
    // g->n = 5
    //
    // Resultado:
    //
    // [0 0 0 0 0]
    //
    // Onde:
    //
    // 0 = não visitado
    // 1 = visitado
    int *descoberto = calloc(g->n, sizeof(int));

    // Inicia a DFS a partir da origem.
    //
    // Exemplo:
    //
    // origem = 0
    //
    // dfs_contar irá visitar todos os vértices
    // alcançáveis a partir do vértice 0.
    //
    // O valor retornado será a quantidade
    // de vértices encontrados.
    int total = dfs_contar(g, origem, descoberto);

    // Libera a memória utilizada pelo vetor.
    //
    // Boa prática para evitar vazamento
    // de memória.
    free(descoberto);

    // Retorna a quantidade total encontrada.
    return total;
}

/// === Exercício 8 

// Retorna todos os vértices adjacentes
// (vizinhos) de um determinado vértice.
//
// Parâmetros:
//
// g -> ponteiro para o grafo
// vertice -> vértice que queremos analisar
// quantidade -> variável onde será armazenada
//               a quantidade de vizinhos encontrados
//
// Retorno:
//
// Vetor contendo todos os vizinhos.
int* obter_adjacentes(Grafo *g,
                      int vertice,
                      int *quantidade)
{
    // Inicialmente não encontramos nenhum vizinho.
    //
    // Como quantidade é um ponteiro,
    // usamos *quantidade para acessar
    // a variável original.
    *quantidade = 0;

    // Primeiro percurso:
    //
    // Apenas contamos quantos vizinhos existem.
    //
    // Isso é necessário porque precisamos saber
    // quantas posições alocar no vetor.
    for (int i = 0; i < g->n; i++)
    {
        // Existe aresta entre
        // vertice e i ?
        if (g->M[vertice][i] != g->arestanula)
        {
            // Encontramos um vizinho.
            (*quantidade)++;
        }
    }

    // Agora já sabemos quantos vizinhos existem.
    //
    // Criamos um vetor exatamente do tamanho
    // necessário.
    int *adj = malloc((*quantidade) * sizeof(int));

    // Variável auxiliar que indica a próxima
    // posição livre do vetor adj.
    int pos = 0;

    // Segundo percurso:
    //
    // Agora copiamos os vizinhos para o vetor.
    for (int i = 0; i < g->n; i++)
    {
        // Existe ligação?
        if (g->M[vertice][i] != g->arestanula)
        {
            // Armazena o vértice adjacente.
            //
            // Exemplo:
            //
            // adj[0] = 1
            // adj[1] = 2
            // adj[2] = 5
            adj[pos++] = g->v[i];
        }
    }

    // Retorna o vetor contendo os vizinhos.
    return adj;
}

// === Exercício 9 

// Verifica se um vértice é isolado.
//
// Um vértice isolado é aquele que não possui
// nenhuma aresta ligada a ele.
//
// Retorno:
//
// 1 -> vértice isolado
// 0 -> vértice NÃO isolado
int eh_isolado(Grafo *g, int vertice)
{
    // Percorre toda a linha do vértice
    // na matriz de adjacência.
    //
    // Como estamos usando matriz de adjacência,
    // todos os possíveis vizinhos do vértice
    // estão nesta linha.
    for (int i = 0; i < g->n; i++)
    {
        // Verifica se existe uma aresta
        // entre o vértice analisado e o vértice i.
        if (g->M[vertice][i] != g->arestanula)
        {
            // Encontramos uma ligação.
            //
            // Portanto o vértice NÃO é isolado.
            return 0;
        }
    }

    // Se chegamos aqui,
    // significa que percorremos toda a linha
    // e não encontramos nenhuma aresta.
    //
    // Logo o vértice é isolado.
    return 1;
}

// === Exercício 10

// Conta quantas arestas existem no grafo.
//
// O grafo é NÃO DIRECIONADO.
//
// Em grafos não direcionados,
// cada aresta aparece duas vezes
// na matriz:
//
// M[i][j]
// M[j][i]
//
// Por isso percorremos apenas metade
// da matriz.
int contar_arestas(Grafo *g)
{
    // Armazena a quantidade total de arestas.
    int total = 0;

    // Percorre todas as linhas.
    for (int i = 0; i < g->n; i++)
    {
        // Percorre apenas a parte superior
        // da matriz.
        //
        // Começamos em i+1 para evitar:
        //
        // M[0][0]
        // M[1][1]
        // M[2][2]
        //
        // e também para não contar
        // a mesma aresta duas vezes.
        for (int j = i + 1; j < g->n; j++)
        {
            // Existe uma aresta entre
            // os vértices i e j?
            if (g->M[i][j] != g->arestanula)
            {
                // Encontramos uma aresta.
                total++;
            }
        }
    }

    // Retorna a quantidade encontrada.
    return total;
}

// Exercício 11

// Calcula o grau de entrada de um vértice.
//
// Grau de entrada:
//
// Quantidade de arestas que chegam
// ao vértice informado.
int grau_entrada(Grafo *g, int vertice)
{
    // Contador de arestas que chegam
    // ao vértice.
    int grau = 0;

    // Percorre todos os vértices do grafo.
    for (int i = 0; i < g->n; i++)
    {
        // Verifica se existe uma aresta
        // saindo de i e chegando em vertice.
        //
        // Estamos analisando a coluna
        // correspondente ao vértice.
        if (g->M[i][vertice] != g->arestanula)
        {
            // Encontramos uma aresta
            // chegando ao vértice.
            grau++;
        }
    }

    // Retorna o grau de entrada.
    return grau;
}

// === Exercício 12

// Calcula o grau de saída de um vértice.
//
// Grau de saída:
//
// Quantidade de arestas que SAEM
// do vértice informado.
int grau_saida(Grafo *g, int vertice)
{
    // Contador de arestas de saída.
    int grau = 0;

    // Percorre todos os vértices do grafo.
    for (int j = 0; j < g->n; j++)
    {
        // Verifica se existe uma aresta
        // saindo de "vertice" e chegando em j.
        //
        // Estamos percorrendo a linha
        // correspondente ao vértice.
        if (g->M[vertice][j] != g->arestanula)
        {
            // Encontramos uma aresta de saída.
            grau++;
        }
    }

    // Retorna o grau de saída.
    return grau;
}

// === Exercício 13

// DFS recursiva.
//
// Marca todos os vértices pertencentes
// à mesma componente conexa.
void marcar_componente(Grafo *g,
                       int atual,
                       int *visitado)
{
    // Marca o vértice atual.
    visitado[atual] = 1;

    // Procura todos os vizinhos.
    for (int i = 0; i < g->n; i++)
    {
        // Existe ligação?
        // Ainda não foi visitado?
        if (g->M[atual][i] != g->arestanula &&
            !visitado[i])
        {
            // Visita o vizinho.
            marcar_componente(g, i, visitado);
        }
    }
}


// Conta quantas componentes conexas
// existem no grafo.
int contar_componentes(Grafo *g)
{
    // Vetor de controle dos vértices visitados.
    int *visitado = calloc(g->n, sizeof(int));

    // Quantidade de componentes.
    int componentes = 0;

    // Percorre todos os vértices.
    for (int i = 0; i < g->n; i++)
    {
        // Se ainda não foi visitado,
        // encontramos uma nova componente.
        if (!visitado[i])
        {
            // Conta a componente.
            componentes++;

            // Marca todos os vértices
            // pertencentes a essa componente.
            marcar_componente(g, i, visitado);
        }
    }

    // Libera memória.
    free(visitado);

    // Retorna a quantidade encontrada.
    return componentes;
}