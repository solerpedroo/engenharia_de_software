// Exercício 1

/*#include <stdio.h>
#include <stdbool.h>

bool e_par = true;

int par (int num){
    if (num % 2 == 0){
        e_par = true;
    }
    else{
        e_par = false;
    }
    return e_par;
}

int main(){

    int n;
    printf("Digite um número: ");
    scanf("%d", &n);

    par(n);

    if (e_par){
        printf("O número %d é par", n);
    }
    else{
        printf("O número %d não é par", n);
    }

    return 0;
}*/

// Exercício 2

/*#include <stdio.h>

double lernum(){
    double a;
    printf("Digite um número real: ");
    scanf("%lf", &a);
    return a;
}

int main(){

    double b = lernum();
    int parteinteira = (int) b;
    double partefracionada = b - parteinteira;

    printf("Número digitado: %.2lf\n", b);
    printf("Parte fracionária: %.2lf\n", partefracionada);

    return 0;

}*/

// Exercício 3
/*#include <stdio.h>

int fatorial(int num){
    int fatorial=1;
    for (int i=num; i>=1; i--){
        fatorial *= i;
    }
    return fatorial;
}

int main (){
    int a;
    printf("Digite um número inteiro e positivo: ");
    scanf("%d", &a);

    if (a < 0){
        printf("Número digitado é 0 ou negativo\n");
        printf("Fim de programa");
        return 1;
    }
    else{
        int b= fatorial(a);
        printf("O número %d fatorado é: %d", a, b);
    }
    return 0;
}*/

// Exercício 4
/*#include <stdio.h>

void escreverpares(int a, int b){
    int inicio, fim;

    if (a<b){
        inicio = a;
        fim = b;
    }
    else{
        inicio = b;
        fim = a;
    }

    printf("Números pares entre %d e %d\n", inicio, fim);
    for (int i = inicio; i <= fim; i++){
        if (i%2==0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    int a, b;
    printf("Digite dois números inteiros: ");
    scanf("%d" "%d", &a, &b);

    escreverpares(a,b);

    return 0;
}*/

// Exercício 5
/*#include <stdio.h>
#include <ctype.h>
#include <string.h>

char tamanho_string(char x[]){
    int qtd_letras=0;
    while (x[qtd_letras] != '\0'){
        qtd_letras ++;
    }
    return qtd_letras;
}

int main (){

    char texto[100];

    printf("Digite uma string (max 99 caractéres): ");
    scanf(" %[^\n]", texto);

    int tamanho = tamanho_string(texto);

    printf("O tamanho da string é %d\n", tamanho);

    return 0;

}*/

// Exercício 6

/*#include <stdio.h>
#include <ctype.h>
#include <string.h>

char cont_caractere(char text[], char c){
    int i, cont=0;
        
    for (i=0; text[i] != '\0'; i++){

        text[i] = toupper(text[i]);

        if (c == text[i]){
            cont++;
        }
    }

    return cont;
}

int main (){
        
    char c, text[21];
    
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    c = toupper(c);

    printf("Digite um texto (máximo 20 caracteres): ");
    scanf(" %[^\n]", text);

    int a = cont_caractere(text, c);

    printf("A quantidade de vezes que o caractere aparece é %d", a);

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

char palindromo (char texto[]){

    int i, qtd_letras;
    char y[20];

    qtd_letras = strlen(texto);

    for (i=0; texto[i] != '\0'; i++){
        y[i] = texto[qtd_letras - 1 - i];
    }

    y[qtd_letras] = '\0';

    int resultado = strcmp(texto, y);
    if (resultado == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    char text[20];

    printf("Digite uma string: ");
    scanf(" %[^\n]", text);

    int a = palindromo(text);

    printf("\n0 diferente | 1 igual\n");
    printf("\nO retorno é %d", a);

    return 0;

}*/

// Exercício 9

/*#include <stdio.h>
#include <ctype.h>
#include <string.h>

void maiusculo (char texto[]){

    int i=0;
    while (texto[i] != '\0'){
        texto[i] = toupper(texto[i]);
        i++;
    }
}

int main (){

    char texto[100];

    printf("Digite uma string: ");
    scanf(" %[^\n]", texto);

    maiusculo(texto);

    printf("String em maiúsculas: %s", texto);

    return 0;

}*/

// Exercício 10

/*#include <stdio.h>

void PrintVector(int sz, int vec[sz]){

    int i;
    
    for (i=0; i<sz; i++){
        printf("V[%d]: %d\n", i, vec[i]);
    }

}

int main(){
    
    int n, i;
    
    printf("Digite a quantidade de valores do vetor: ");
    scanf("%d", &n);
    
    int vec[n];
    
    printf("Digite os elementos do vetor:\n");
    for (i=0; i<n; i++){
        printf("Vec[%d]: ", i);
        scanf("%d", &vec[i]);
    }
    
    printf("\n\n");
    
    PrintVector(n, vec);
    
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

    int valor1, valor2;

    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);
    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);

    printf("\n\n");

    Swap(&valor1, &valor2);

    return 0;

}*/

// Exercício 12

/*#include <stdio.h>

void OrdenarCrescente(int sz, int vec[sz]){

    int i, j, aux;
    
    for (i=0; i<sz-1; i++){
        for (j=0; j<sz-1-i; j++){
                if (vec[j] > vec[j + 1]) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
                }
        }
    }
    
    printf("\nVetor ordenado em ordem crescente:\n");
    for (i = 0; i < sz; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");

}

int main (){
    
    int n, i;
    
    printf("Digite a quantidade de valores do vetor: ");
    scanf("%d", &n);
    
    int vec[n];
    
    printf("Digite os elementos do vetor:\n");
    for (i=0; i<n; i++){
        printf("Vec[%d]: ", i);
        scanf("%d", &vec[i]);
    }
    
    printf("\n\n");
    
    OrdenarCrescente(n, vec);
    
    return 0;
    
}*/

// Exercício 13

/*#include <stdio.h>

void SeparaParImpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar) {
    int i;
    *szPar = 0;
    *szImpar = 0;

    for (i = 0; i < sz; i++) {
        if (vec[i] % 2 == 0) {
            vPar[*szPar] = vec[i];
            (*szPar)++;
        } else {
            vImpar[*szImpar] = vec[i];
            (*szImpar)++;
        }
    }
}

int main() {
    int n, i;

    printf("Digite a quantidade de valores do vetor: ");
    scanf("%d", &n);

    int vec[n];
    int vPar[n], vImpar[n];
    int szPar, szImpar;

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        printf("Vec[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    SeparaParImpar(n, vec, vPar, vImpar, &szPar, &szImpar);

    printf("\nValores pares (%d): ", szPar);
    for (i = 0; i < szPar; i++) {
        printf("%d ", vPar[i]);
    }
    printf("\n");

    printf("Valores ímpares (%d): ", szImpar);
    for (i = 0; i < szImpar; i++) {
        printf("%d ", vImpar[i]);
    }
    printf("\n");

    return 0;
}*/

// Exercício 14

/*#include <stdio.h>

void PrintMatrix(int nRows, int nCols, int matrix[nRows][nCols]) {
    int i, j;
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int nRows, nCols, i, j;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &nRows);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &nCols);

    int matrix[nRows][nCols];

    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatriz digitada:\n");
    PrintMatrix(nRows, nCols, matrix);

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

// Exercício 16

// ====================================================
// Exercício 1
/*#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool e_par = true;

bool par (int num){
    if (num % 2 == 0){
        e_par = true;
    }
    else{
        e_par = false;
    }
    return e_par;
}

// ====================================================
// Exercício 2
double lernum(){
    double a;
    printf("Digite um número real: ");
    scanf("%lf", &a);
    return a;
}

// ====================================================
// Exercício 3
int fatorial(int num){
    int fatorial=1;
    for (int i=num; i>=1; i--){
        fatorial *= i;
    }
    return fatorial;
}

// ====================================================
// Exercício 4
void escreverpares(int a, int b){
    int inicio, fim;

    if (a<b){
        inicio = a;
        fim = b;
    }
    else{
        inicio = b;
        fim = a;
    }

    printf("Números pares entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++){
        if (i%2==0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

// ====================================================
// Exercício 5
int tamanho_string(char x[]){
    int qtd_letras=0;
    while (x[qtd_letras] != '\0'){
        qtd_letras ++;
    }
    return qtd_letras;
}

// ====================================================
// Exercício 6
int cont_caractere(char text[], char c){
    int i, cont=0;
        
    for (i=0; text[i] != '\0'; i++){
        if (c == text[i]){
            cont++;
        }
    }

    return cont;
}

// ====================================================
// Exercício 7
void copiar_conteudo (char origem[], char destino[]){
    int i=0;
    while (origem[i] != '\0'){
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

// ====================================================
// Exercício 8
int palindromo (char texto[]){
    int qtd_letras = strlen(texto);
    char y[100];

    for (int i=0; texto[i] != '\0'; i++){
        y[i] = texto[qtd_letras - 1 - i];
    }
    y[qtd_letras] = '\0';

    int resultado = strcmp(texto, y);
    if (resultado == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// ====================================================
// Exercício 9
void maiusculo (char texto[]){
    int i=0;
    while (texto[i] != '\0'){
        texto[i] = toupper(texto[i]);
        i++;
    }
}

// ====================================================
// Exercício 10
void PrintVector(int sz, int vec[sz]){
    for (int i=0; i<sz; i++){
        printf("V[%d]: %d\n", i, vec[i]);
    }
}

// ====================================================
// Exercício 11
void Swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// ====================================================
// Exercício 12
void OrdenarCrescente(int sz, int vec[sz]){
    int i, j, aux;
    for (i=0; i<sz-1; i++){
        for (j=0; j<sz-1-i; j++){
            if (vec[j] > vec[j + 1]) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

// ====================================================
// Exercício 13
void SeparaParImpar(int sz, int vec[sz], int vPar[], int vImpar[], int *szPar, int *szImpar) {
    *szPar = 0;
    *szImpar = 0;
    for (int i = 0; i < sz; i++) {
        if (vec[i] % 2 == 0) {
            vPar[*szPar] = vec[i];
            (*szPar)++;
        } else {
            vImpar[*szImpar] = vec[i];
            (*szImpar)++;
        }
    }
}

// ====================================================
// Exercício 14
void PrintMatrix(int nRows, int nCols, int matrix[nRows][nCols]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ====================================================
// Exercício 15
bool MultMatrix(int linhasA, int colunasA, int A[linhasA][colunasA],
                int linhasB, int colunasB, int B[linhasB][colunasB],
                int Mult[linhasA][colunasB]) {
    if (colunasA != linhasB) {
        printf("Nao e possivel multiplicar\n");
        return false;
    }

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            Mult[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                Mult[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return true;
}

// ====================================================
// Exercício 16 - Menu
void EscolherExercicio(){
    int opcao;
    do {
        printf("\n================ MENU ================\n");
        printf("1 - Numero par\n");
        printf("2 - Parte fracionaria\n");
        printf("3 - Fatorial\n");
        printf("4 - Pares entre a e b\n");
        printf("5 - Tamanho da string\n");
        printf("6 - Contar caractere\n");
        printf("7 - Copiar string\n");
        printf("8 - Palindromo\n");
        printf("9 - Maiusculo\n");
        printf("10 - Imprimir vetor\n");
        printf("11 - Swap\n");
        printf("12 - Ordenacao crescente\n");
        printf("13 - Separar pares e impares\n");
        printf("14 - Imprimir matriz\n");
        printf("15 - Multiplicar matrizes\n");
        printf("0 - Sair\n");
        printf("======================================\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:{
                int n;
                printf("Digite um numero: ");
                scanf("%d", &n);
                if (par(n)) printf("%d eh par\n", n);
                else printf("%d nao eh par\n", n);
                break;
            }
            case 2:{
                double num = lernum();
                int parteint = (int)num;
                double partefrac = num - parteint;
                printf("Parte fracionaria: %.2lf\n", partefrac);
                break;
            }
            case 3:{
                int n;
                printf("Digite um inteiro positivo: ");
                scanf("%d", &n);
                printf("Fatorial = %d\n", fatorial(n));
                break;
            }
            case 4:{
                int a,b;
                printf("Digite dois numeros: ");
                scanf("%d %d", &a,&b);
                escreverpares(a,b);
                break;
            }
            case 5:{
                char texto[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", texto);
                printf("Tamanho = %d\n", tamanho_string(texto));
                break;
            }
            case 6:{
                char texto[100], c;
                printf("Digite um caractere: ");
                scanf(" %c", &c);
                printf("Digite uma string: ");
                scanf(" %[^\n]", texto);
                printf("Qtd = %d\n", cont_caractere(texto, c));
                break;
            }
            case 7:{
                char origem[100], destino[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", origem);
                copiar_conteudo(origem, destino);
                printf("Copia: %s\n", destino);
                break;
            }
            case 8:{
                char texto[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", texto);
                if (palindromo(texto)) printf("Eh palindromo\n");
                else printf("Nao eh palindromo\n");
                break;
            }
            case 9:{
                char texto[100];
                printf("Digite uma string: ");
                scanf(" %[^\n]", texto);
                maiusculo(texto);
                printf("Maiuscula: %s\n", texto);
                break;
            }
            case 10:{
                int n;
                printf("Digite o tamanho do vetor: ");
                scanf("%d", &n);
                int vec[n];
                for (int i=0; i<n; i++) scanf("%d", &vec[i]);
                PrintVector(n, vec);
                break;
            }
            case 11:{
                int a,b;
                printf("Digite dois valores: ");
                scanf("%d %d", &a,&b);
                Swap(&a,&b);
                printf("Swap -> A=%d, B=%d\n", a,b);
                break;
            }
            case 12:{
                int n;
                printf("Digite o tamanho do vetor: ");
                scanf("%d", &n);
                int vec[n];
                for (int i=0; i<n; i++) scanf("%d", &vec[i]);
                OrdenarCrescente(n, vec);
                for (int i=0; i<n; i++) printf("%d ", vec[i]);
                printf("\n");
                break;
            }
            case 13:{
                int n;
                printf("Digite o tamanho do vetor: ");
                scanf("%d", &n);
                int vec[n], vPar[n], vImpar[n], szPar, szImpar;
                for (int i=0; i<n; i++) scanf("%d", &vec[i]);
                SeparaParImpar(n, vec, vPar, vImpar, &szPar, &szImpar);
                printf("Pares: ");
                for (int i=0; i<szPar; i++) printf("%d ", vPar[i]);
                printf("\nImpares: ");
                for (int i=0; i<szImpar; i++) printf("%d ", vImpar[i]);
                printf("\n");
                break;
            }
            case 14:{
                int l,c;
                printf("Digite linhas e colunas: ");
                scanf("%d %d", &l,&c);
                int mat[l][c];
                for (int i=0; i<l; i++)
                    for (int j=0; j<c; j++) scanf("%d", &mat[i][j]);
                PrintMatrix(l,c,mat);
                break;
            }
            case 15:{
                int lA,cA,lB,cB;
                printf("Digite dimensoes A (lin col): ");
                scanf("%d %d", &lA,&cA);
                printf("Digite dimensoes B (lin col): ");
                scanf("%d %d", &lB,&cB);
                int A[lA][cA], B[lB][cB], M[lA][cB];
                for (int i=0; i<lA; i++)
                    for (int j=0; j<cA; j++) scanf("%d", &A[i][j]);
                for (int i=0; i<lB; i++)
                    for (int j=0; j<cB; j++) scanf("%d", &B[i][j]);
                if (MultMatrix(lA,cA,A,lB,cB,B,M)){
                    PrintMatrix(lA,cB,M);
                }
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao!=0);
}

int main(){
    EscolherExercicio();
    return 0;
}*/

// --> EXERCÍCIOS EXTRAS <--

/*Fazer um exercício que uma função recebe um vetor e ordene ele de forma crescente e de forma descrescente*/

/*void vec_crescente(int sz, int vec[]){
    int i, j, aux;

    for (i=0; i<sz-1; i++){
        for (j=0; j<sz-1-i; j++){
            if (vec[j] > vec[j+1]){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }

    printf("\nVetor ordenado de forma crescente: ");
    for (i=0; i<sz; i++){
        printf("%d ", vec[i]);
    }
    printf("\n\n");

}

void vec_decrescente(int sz, int vec[]){
    int i, j, aux;

    for (i = 0; i < sz-1; i++) {
        for (j = 0; j < sz-1 - i; j++) {
            if (vec[j] < vec[j + 1]) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    printf("\nVetor ordenado de forma decrescente: ");
    for (i=0; i<sz; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");

}

int main (){
    int i, n;

    printf("\nQuantos elementos quer inserir no vetor? ");
    scanf("%d", &n);

    int vec[n];

    for (i=0; i<n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    vec_crescente(n, vec);
    vec_decrescente(n, vec);

    return 0;
}*/

/*fazer 4 funções que recebem uma matriz NxN, uma que ordene uma coluna da matriz de forma crescente, outra que ordene a linha de forma crescente, outra que ordene a coluna de forma decrescente, outra que ordene a linmha de forma decrescente*/

/*#include <stdio.h>

void ordenarColunaCrescente(int n, int matriz[n][n], int col) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matriz[i][col] > matriz[j][col]) {
                int temp = matriz[i][col];
                matriz[i][col] = matriz[j][col];
                matriz[j][col] = temp;
            }
        }
    }
}

void ordenarColunaDecrescente(int n, int matriz[n][n], int col) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matriz[i][col] < matriz[j][col]) {
                int temp = matriz[i][col];
                matriz[i][col] = matriz[j][col];
                matriz[j][col] = temp;
            }
        }
    }
}

void ordenarLinhaCrescente(int n, int matriz[n][n], int linha) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matriz[linha][i] > matriz[linha][j]) {
                int temp = matriz[linha][i];
                matriz[linha][i] = matriz[linha][j];
                matriz[linha][j] = temp;
            }
        }
    }
}

void ordenarLinhaDecrescente(int n, int matriz[n][n], int linha) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matriz[linha][i] < matriz[linha][j]) {
                int temp = matriz[linha][i];
                matriz[linha][i] = matriz[linha][j];
                matriz[linha][j] = temp;
            }
        }
    }
}

void imprimirMatriz(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite o tamanho da matriz NxN: ");
    scanf("%d", &n);

    int matriz[n][n];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz original:\n");
    imprimirMatriz(n, matriz);

    ordenarColunaCrescente(n, matriz, 0);  
    printf("Coluna 0 ordenada crescente:\n");
    imprimirMatriz(n, matriz);

    ordenarLinhaDecrescente(n, matriz, 1); 
    printf("Linha 1 ordenada decrescente:\n");
    imprimirMatriz(n, matriz);

    ordenarColunaDecrescente(n, matriz, 2 % n); 
    printf("Coluna 2 ordenada decrescente:\n");
    imprimirMatriz(n, matriz);

    ordenarLinhaCrescente(n, matriz, n-1); 
    printf("Última linha ordenada crescente:\n");
    imprimirMatriz(n, matriz);

    return 0;
}*/