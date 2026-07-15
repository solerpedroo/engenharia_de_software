#ifndef FILA_H
#define FILA_H

typedef struct NoFila NoFila;

typedef struct Fila Fila;


Fila* criarFila();

void limparFila(Fila* fila) ;

void destruirFila(Fila* fila) ;

int filaVazia(const Fila* fila) ;

void enfileirar(Fila* fila, int valor) ;

void desenfileirar(Fila* fila, int* valorRemovido) ;

int obterInicio(const Fila* fila);

int obterTamanho(const Fila* fila) ;

bool buscarValor(const Fila* fila, int valor) ;

void atualizarValor(Fila* fila, int valorAntigo, int valorNovo);

void imprimirFila(const Fila* fila) ;

#endif // FILA_H