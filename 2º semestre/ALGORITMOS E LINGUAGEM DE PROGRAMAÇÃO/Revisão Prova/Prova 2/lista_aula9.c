// Exercício 1

/*#include <stdio.h>
#include <stdbool.h>

bool par = true;

int consultar_par (int num){

    if (num % 2 == 0){
        par = true;
    }
    else{
        par = false;
    }

    return par;
}

int main(){
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    consultar_par(num);

    if (par==true){
        printf("\nNúmero par");
    }
    else{
        printf("\nNúmero não é par");
    }

    return 0;
}*/

// Exercício 2

/*#include <stdio.h>

double ler_num(){
    double a;
    printf("Digite um número fracionário: ");
    scanf("%lf", &a);
    return a;
}

int main(){
    double b = ler_num();
    int parte_inteira = (int) b;
    double parte_fracionaria = b - parte_inteira;

    printf("Parte inteira: %d", parte_inteira);
    printf("\nParte fracionária: %.2lf", parte_fracionaria);

    return 0;
}*/

// Exercício 3

/*#include <stdio.h>

int fatorial (int num){
    int i, fatorado=1;
    for (i=num; i>=1; i--){
        fatorado *= i;
    }
    return fatorado;
}

int main(){
    int num;

    printf("Digite um número para fatorar: ");
    scanf("%d", &num);

    int b = fatorial(num);

    printf("Fatorial: %d", b);

    return 0;
}*/

// Exercício 4

/*#include <stdio.h>

void pares(int a, int b){
    int inicio, fim;
    
    if (a<b){
        inicio = a;
        fim = b;
    }
    else{
        inicio = b;
        fim = a;
    }

    for (int i=inicio; i<=fim; i++){
        if (i%2==0){
            printf("%d ", i);
        }
    }
    printf ("\n");
}

int main(){
    int a, b;

    printf("Valor a e b: ");
    scanf("%d%d", &a, &b);

    pares(a,b);

    return 0;
}*/

// Exercício 5

/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

char tamanho_string (char x[]){
    int qtd = 0;
    while (x[qtd] != '\0'){
        qtd ++;
    }
    return qtd;
}

int main(){
    char texto[100];

    printf("Digite a string: ");
    scanf(" %[^\n]", texto);

    int a = tamanho_string(texto);

    printf("O tamanho da string é: %d", a);

    return 0;
}*/

// Exercício 6

/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cont_car (char texto[], char caractere){
    int i, cont=0;

    for (i=0; texto[i] != '\0'; i++){
        texto[i] = toupper(texto[i]);

        if (caractere == texto[i]){
            cont ++;
        }
    }

    return cont;
}

int main(){
    char c, texto[100];

    printf("Digite a string: ");
    scanf(" %[^\n]", texto);

    printf("Digite o caractere: ");
    scanf(" %c", &c);
    c = toupper(c);

    int a = cont_car(texto, c);

    printf("A qtd é: %d", a);

    return 0;
}*/

// Exercício 7

/*#include <stdio.h>
#include <ctype.h>
#include <string.h>

void copiar_conteudo (char origem[], char destino[]){

    int i=0;

    while (origem[i] != '\0'){
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';

}

int main (){
    char texto[100], copia[100];

    printf("Digite uma string (max 99): ");
    scanf(" %[^\n]", texto);

    copiar_conteudo(texto, copia);

    printf("O conteúdo copiado é %s", copia);

    return 0; 

}*/

// Exercício 8

/*#include <stdio.h>
#include <ctype.h>
#include <string.h>

char palindromo(char texto[]){
    int cont, i;
    char y[20];

    cont = strlen(texto);

    for (i=0; texto[i] != '\0'; i++){
        y[i] = texto[cont - 1 - i];
    }

    int resultado = strcmp(texto, y);
    if (resultado == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main (){
    char texto[20];

    printf("Digite a string: ");
    scanf(" %[^\n]", texto);

    int a =palindromo(texto);

    if (a == 1){
        printf("É");
    }
    else{
        printf("Não é");
    }

    return 0;
}*/

// Exercício 9

/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maiusculo(char texto[]){
    int i;
    while (texto[i] != '\0'){
        texto[i] = toupper(texto[i]);
        i++;
    }
   for (i=0; texto[i] != '\0'; i++){
        texto[i] = toupper(texto[i]);
   }
}

int main(){
    char texto[100];

    printf("Digite uma string: ");
    scanf(" %[^\n]", texto);

    maiusculo(texto);

    printf("String em maiusculo: %s", texto);

    return 0;
}*/

// Exercício 10

/*#include <stdio.h>

void PrintVector(int sz, int vec[sz]){
    int i;
    for (i=0; i<sz; i++){
        printf("X[%d]: %d\n", i, vec[i]);
    }
}
int main(){
    int sz;
    printf("Tamanho do vetor: ");
    scanf("%d", &sz);

    int vec[sz];
    for (int i=0; i<sz; i++){
        printf("X[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    PrintVector(sz, vec);

    return 0;
}*/

// Exercício 11

/*#include <stdio.h>

void Swap(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

    printf("O valor do ponteiro A é: %d\n", *a);
    printf("O valor do ponteiro B é: %d\n", *b);
}

int main(){
    int v1, v2;

    printf("Digite o v1 e v2: ");
    scanf("%d%d", &v1, &v2);

    Swap(&v1, &v2);

    return 0;
}*/

// Exercício 12

/*#include <stdio.h>

void OrdenarCrescente(int sz, int vec[sz]){
    int aux, i, j;

    for (i=0; i<sz-1; i++){
        for (j=0; j<sz-1-i; j++){
            if (vec[j] > vec[j+1]){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }

    for (i=0; i<sz; i++){
        printf("V[%d]: %d\n", i, vec[i]);
    }
}

int main(){
    int sz;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    int vec[sz];
    for (int i=0; i<sz; i++){
        printf("V[%d]: ", i);
        scanf("%d", &vec[i]);
    }
    printf("\n\n");

    OrdenarCrescente(sz, vec);

    return 0;
}*/

// Exercício 13

/*#include <stdio.h>

void SeparaParImpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar){
    int i; 
    *szPar=0; 
    *szImpar=0;

    for (i=0; i<sz; i++){
        if (vec[i] % 2 == 0){
            vPar[*szPar] = vec[i];
            (*szPar) ++;
        }
        else{
            vImpar[*szImpar] = vec[i];
            (*szImpar) ++;
        }
    }

    printf("Vetor completo:\n");
    for (i=0; i<sz; i++){
        printf("V.C[%d]: %d ", i, vec[i]);
    }
    printf("\n\n");

    printf("Vetor de pares:\n");
    for (i=0; i<*szPar; i++){
        printf("V.P[%d]: %d ", i, vPar[i]);
    }
    printf("\n\n");

    printf("Vetor de ímpares: ");
    for (i=0; i<*szImpar; i++){
        printf("V.I[%d]: %d ", i, vImpar[i]);
    }
}

int main(){
    int i, sz, szP, szI;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sz);

    int v[sz], vPar[sz], vImpar[sz];

    printf("Preencha o vetor:\n");
    for (i=0; i<sz; i++){
        printf("V[%d]: ", i);
        scanf("%d", &v[i]);
    }
    printf("\n\n");

    SeparaParImpar(sz, v, vPar, vImpar, &szP, &szI);

    return 0;
}*/

// Exercício 14

/*#include <stdio.h>

void PrintMatrix(int nRows, int nCols, int matrix[nRows][nCols]){
    int i, j;
    for (i=0; i<nRows; i++){
        for (j=0; j<nCols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i, j, nRows, nCols;

    printf("Digite o tamanho de linhas da matriz: ");
    scanf("%d", &nRows);
    printf("Digite o tamanho de colunas da matriz: ");
    scanf("%d", &nCols);

    int m[nRows][nCols];

    for (i=0; i<nRows; i++){
        for (j=0; j<nCols; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    printf("\n\n");

    printf("Impressão da matriz:\n");
    PrintMatrix(nRows, nCols, m);

    return 0;
}*/

// Exercício 15

/*#include <stdio.h>
#include <stdbool.h>

bool MultMatrix(int linhasA, int colunasA, int A[linhasA][colunasA],
                int linhasB, int colunasB, int B[linhasB][colunasB],
                int Mult[linhasA][colunasB]) {
    if (colunasA != linhasB) {
        printf("Nao e possivel multiplicar: colunas de A (%d) != linhas de B (%d)\n", colunasA, linhasB);
        return false;
    }

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            Mult[i][j] = 0;
        }
    }

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            for (int k = 0; k < colunasA; k++) {
                Mult[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return true;
}

void PrintMatrix(int nRows, int nCols, int matrix[nRows][nCols]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhasA, colunasA, linhasB, colunasB;

    printf("Digite as dimensoes da matriz A (linhas colunas): ");
    scanf("%d %d", &linhasA, &colunasA);
    printf("Digite as dimensoes da matriz B (linhas colunas): ");
    scanf("%d %d", &linhasB, &colunasB);

    int A[linhasA][colunasA];
    int B[linhasB][colunasB];
    int Mult[linhasA][colunasB];

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasA; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < linhasB; i++) {
        for (int j = 0; j < colunasB; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    if (MultMatrix(linhasA, colunasA, A, linhasB, colunasB, B, Mult)) {
        printf("\nResultado da multiplicacao AxB:\n");
        PrintMatrix(linhasA, colunasB, Mult);
    }

    return 0;
}*/