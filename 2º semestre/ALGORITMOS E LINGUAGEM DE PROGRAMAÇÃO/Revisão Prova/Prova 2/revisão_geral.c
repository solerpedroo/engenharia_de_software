// --> Ponteiros 

// Exercício 1

/*#include <stdio.h>

int main(){
    int var1=10, var2=20;
    int *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    int temp;

    temp = *pt1;
    *pt1 = *pt2;
    *pt2 = temp;

    printf("Var1 = %d\n", var1);
    printf("Var2 = %d\n", var2);
    printf("Ponteiro 1 = %d\n", *pt1);
    printf("Ponteiro 2 = %d\n", *pt2);

    return 0;
}*/

// Exercício 2

/*#include <stdio.h>

int main(){
    
    int var1=10, var2=20, var3;
    int *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    var3 = *pt1 + *pt2;

    pt1 = &var3;
    *pt1 = 40;

    printf("Var1 = %d\n", var1);
    printf("Var2 = %d\n", var2);
    printf("Var3 = %d\n", var3);
    printf("Ponteiro 1 = %d\n", *pt1);
    printf("Ponteiro 2 = %d\n", *pt2);

    return 0;
}*/

// Exercício 3

/*#include <stdio.h>

int main(){

    double var1=10, var2=20;
    double *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    double var3 = *pt1 * *pt2;

    pt2 = &var3;
    *pt2 = *pt2/2;

    printf("Var1 = %lf\n", var1);
    printf("Var2 = %lf\n", var2);
    printf("Var3 = %lf\n", var3);
    printf("Ponteiro 1 = %lf\n", *pt1);
    printf("Ponteiro 2 = %lf\n", *pt2);

    return 0;

}*/

// Exercício 4

/*#include <stdio.h>

int main(){
    int var1=10, var2=20, var3=30;
    int *pt1, *pt2, *pt3;

    pt1 = &var1;
    pt2 = &var2;
    pt3 = &var3;

    *pt1 = 40;

    pt1 = pt2;
    *pt1 = 50;

    pt1 = pt3; 
    *pt1 = 60;

    printf("Var1 = %d\n", var1);
    printf("Var2 = %d\n", var2);
    printf("Var3 = %d\n", var3);
    printf("Ponteiro 1 = %d\n", *pt1);
    printf("Ponteiro 2 = %d\n", *pt2);
    printf("Ponteiro 3 = %d\n", *pt3);

    return 0;
}*/

// ====> EXERCÍCIOS GERADOS PELO CHATGPT PARA ESTUDOS <====

// PONTEIROS

/*Fácil: Crie duas variáveis inteiras, use ponteiros para trocar os valores entre elas.
Médio: Crie um vetor de inteiros e use ponteiros para percorrê-lo e calcular a soma dos elementos.
Difícil: Implemente uma função que recebe um ponteiro para um vetor e seu tamanho, e retorna (via ponteiros) o maior e o menor elemento do vetor.*/

//1
/*#include <stdio.h>

int main(){
    int var1=10, var2=20, temp;
    int *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    temp = *pt1;
    *pt1 = *pt2;
    *pt2 = temp;

    printf("Var1: %d\n", var1);
    printf("Var2: %d", var2);

    return 0;
}*/

//2
/*#include <stdio.h>

int main(){
    int vec[3], soma=0, i;

    for(i=0; i<3; i++){
        printf("V[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    int *pt1;

    for(i=0; i<3; i++){
        pt1 = &vec[i];
        soma += *pt1;
    }

    printf("Soma: %d", soma);

    return 0;
}*/

//3
/*#include <stdio.h>

int main(){

    int tamanho;

    printf("Digite o tamamho: ");
    scanf("%d", &tamanho);
    
    int *sz;
    
    sz = &tamanho;

    int vec[*sz];

    for (int i=0; i< *sz; i++){
        printf("V[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    int maior = vec[0];
    int menor = vec[0];
    int *pt1;
    int *pt2;

    pt1 = &maior;
    pt2 = &menor;

    for (int i=0; i< *sz; i++){
        if (vec[i] > maior){
            *pt1 = vec[i];
        }
        if (vec[i] < menor){
            *pt2 = vec[i];
        }
    }

    printf("Maior: %d\n", *pt1);
    printf("Menor: %d\n", *pt2);

    return 0;
}*/

// STRUCTS

/*Fácil: Defina uma struct Aluno com nome e idade. Leia os dados de 1 aluno e mostre na tela.
Médio: Crie um vetor de 5 alunos, cada um com nome e nota. Exiba o nome do aluno com a maior nota.
Difícil: Implemente uma agenda de contatos usando struct (nome, telefone, email) e permita buscar um contato pelo nome.*/

//1
/*#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nome[50];
    int idade;
} Aluno;

int main(){
    Aluno a;

    printf("Nome: ");
    scanf(" %[^\n]", a.nome);

    printf("Idade: ");
    scanf("%d", &a.idade);

    printf("Nome: %s.\nIdade: %d", a.nome, a.idade);

    return 0;
}*/

//2
/*#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nome[50];
    double nota;
} Aluno;

int main(){
    int i; 
    Aluno vec[5];

    for (i=0; i<5; i++){
        printf("POS[%d]\n", i);

        printf("Nome: ");
        scanf(" %[^\n]", vec[i].nome);

        printf("Nota: ");
        scanf("%lf", &vec[i].nota);
    }

    Aluno nota_maior = vec[0];

    for (i=0; i<5; i++){
        if (vec[i].nota > nota_maior.nota){
            nota_maior = vec[i];
        }
    }

    printf("O aluno é: %s\n", nota_maior.nome);
    printf("Nota é: %.2lf\n", nota_maior.nota);

    return 0;
}*/

// 3
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
    char telefone[50];
    char email[50];
} Agenda;

int buscar_contato_unico(Agenda contato[], const char* nome_busca){
    for (int i = 0; contato[i].nome[i] != '\0'; i++) {
        contato[i].nome[i] = toupper(contato[i].nome[i]);

    if (strcmp(contato[i].nome, nome_busca) == 0){
        return i; 
    }
    }
    return -1;
}

int main(){
    Agenda contato[3];
    int i=0;

    printf("Digite os contatos: \n");
    for (int i=0; i<3; i++){
        printf("Nome: ");
        scanf(" %[^\n]", contato[i].nome);
        printf("\n");

        printf("Telefone: ");
        scanf(" %[^\n]", contato[i].telefone);
        printf("\n");

        printf("Email: ");
        scanf(" %[^\n]", contato[i].email);
        printf("\n");
    }

    for (int j = 0; contato[i].nome[j] != '\0'; j++){
        contato[i].nome[j] = toupper(contato[i].nome[j]);
    }

    char buscar_contato[50];
    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", buscar_contato);

    while(buscar_contato[i] != '\0'){
        buscar_contato[i] = toupper(buscar_contato[i]);
        i++;
    }

    int indice = buscar_contato_unico(contato, buscar_contato);

    if (indice != -1){
        printf("Nome: %s\n", contato[indice].nome);
        printf("Email: %s\n", contato[indice].email);
        printf("Telefone: %s\n", contato[indice].telefone);
    }
    else printf("Contato não encontrado");

    return 0;
}*/

// FUNÇÕES

/*Fácil: Escreva uma função que recebe um número inteiro e retorna o seu fatorial.
Médio: Crie uma função que recebe dois números e retorna o máximo divisor comum (MDC) entre eles.
Difícil: Implemente uma função que receba um vetor de inteiros e seu tamanho e retorne um novo vetor apenas com os números primos.*/

//1
/*#include <stdio.h>

int fatorial(int num){
    int i, fatorado=1;
    for (i=num; i>1; i--){
        fatorado*=i;
    }
    return fatorado;
}

int main(){
    int num;

    printf("Digite o número para fatorar: ");
    scanf("%d", &num);

    int fatorado = fatorial(num);
    
    printf("O número %d fatorado é %d", num, fatorado);

    return 0;
}*/

//2
/*#include <stdio.h>

int mdc(int num1, int num2){
    int resto;
    while(num2 != 0){
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;
    }
    return num1;
}

int main(){
    int n1, n2;

    printf("Digite dois números para fatorar: ");
    scanf("%d%d", &n1, &n2);

    int calc_mdc = mdc(n1,n2);

    printf("O MDC é %d", calc_mdc);

    return 0;
}*/

//3
/*#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int n){
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int* filtraPrimos(int *vet, int tamanho, int *novoTamanho){
    int count = 0;

    for (int i = 0; i < tamanho; i++){
        if (ehPrimo(vet[i])){
            count++;
        }
    }

    int *primos = (int*) malloc(count * sizeof(int));
    if (primos == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < tamanho; i++){
        if (ehPrimo(vet[i])){
            primos[j] = vet[i];
            j++;
        }
    }

    *novoTamanho = count;
    return primos;
}

int main(){
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    printf("Digite os %d elementos: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    int novoTamanho;
    int *primos = filtraPrimos(vet, n, &novoTamanho);

    printf("Vetor de primos: ");
    for (int i = 0; i < novoTamanho; i++){
        printf("%d ", primos[i]);
    }

    free(primos);
    return 0;
}*/

// STRINGS 

/*Fácil: Leia uma string e exiba o seu comprimento (sem usar strlen).
Médio: Leia duas strings e diga se são iguais (sem usar strcmp).
Difícil: Leia uma string e retorne uma nova string sem vogais.*/

//1
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int i, cont=0;
    char texto[50];

    printf("Digite uma palavra: ");
    scanf(" %[^\n]", texto);

    for (i=0; texto[i] != '\0'; i++){
        cont++;
    }

    printf("O tamanho é %d", cont);

    return 0;
}*/

//2 
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
    bool igual = true;
    int i;
    char txt1[50], txt2[50];

    printf("Digite a primeira palavra: ");
    scanf(" %[^\n]", txt1);

    printf("Digite a segunda palavra: ");
    scanf(" %[^\n]", txt2);

    int qtd1 = strlen(txt1);
    int qtd2 = strlen(txt2);

    if (qtd1 == qtd2){
        for (i=0; txt1[i] != '\0'; i++){
            if (txt1[i] == txt2[i]){
                igual = true;
                break;
            }
            else{
                igual = false;
            }
        }
    }
    else{
        igual = false;
    }

    if (igual == true){
        printf("São iguais\n");
    }
    else{
        printf("São diferentes\n");
    }

    return 0;
}*/

//3
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int i;
    int j = 0; 
    char txt[50], sem_vogal[50];

    printf("Digite a string: ");
    scanf(" %[^\n]", txt); 

    for (i = 0; txt[i] != '\0'; i++){
        txt[i] = toupper(txt[i]);
    }

    for (i = 0; txt[i] != '\0'; i++){
        if (txt[i] != 'A' && txt[i] != 'E' && txt[i] != 'I' && txt[i] != 'O' && txt[i] != 'U'){
            
            sem_vogal[j] = txt[i];
            
            j++; 
        }
    }

    sem_vogal[j] = '\0'; 

    printf("String original (maiúscula): %s\n", txt);
    printf("String sem vogais: %s\n", sem_vogal);

    return 0;
}*/

// MATRIZES 

/*Fácil: Leia uma matriz 3x3 e exiba a soma dos elementos da diagonal principal.
Médio: Leia uma matriz 3x3 e exiba a transposta.
Difícil: Leia uma matriz NxN e verifique se ela é simétrica.*/

//1
/*#include <stdio.h>

int main(){
    int m[3][3];
    int i, j, soma=0;

    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("M[%d][%d]: ", i,j);
            scanf("%d", &m[i][j]);
        }
    }

    for (i=0; i<3; i++){
        soma += m[i][i];
    }

    printf("Matriz: \n");
    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("Soma diagonal principal: %d", soma);

    return 0;
}*/

//2 
/*#include <stdio.h>

int main(){
    int m[3][3], mt[3][3], i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            mt[i][j] = m[j][i];
        }
    }

    printf("Matriz Original: \n");
    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("Matriz Transposta: \n");
    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d\t", mt[i][j]);
        }
        printf("\n");
    }

    return 0;
}*/

//3
/*#include <stdio.h>
#include <stdbool.h>

int main(){
    int qtd_linhas=0, qtd_colunas=0, i, j;
    bool simetrica = true;

    printf("Digite a quantidade de linhas e colunas: ");
    scanf("%d%d", &qtd_linhas, &qtd_colunas);

    if (qtd_colunas == qtd_linhas){
        int m[qtd_linhas][qtd_colunas];

        printf("Digite a matriz: \n");
        for(i=0; i<qtd_linhas; i++){
            for(j=0; j<qtd_colunas; j++){
                printf("M[%d][%d]: ",i,j);
                scanf("%d", &m[i][j]);
            }
        }

        for(i=0; i<qtd_linhas; i++){
            for(j=0; j<qtd_colunas; j++){
                if (m[i][j] != m[j][i]) simetrica = false;
                break;
            }
        }
        
        if(simetrica == true) printf("É simétrica\n");
        else printf("Não é simétrica\n");

    }
    else{
        printf("Matriz não é simétrica, qtd linhas e qtd de colunas diferentes\n");
    }

    return 0;
}*/

// VETORES

/*Fácil: Leia 5 números e exiba a média deles.
Médio: Leia 10 números, remova os números repetidos e exiba o vetor resultante.
Difícil: Ordene um vetor de inteiros em ordem crescente (não use funções prontas como qsort).*/

//1
/*#include <stdio.h>

int main(){
    int v[5], i, soma=0, media=0;

    for (i=0; i<5; i++){
        printf("V[%d]: ", i);
        scanf("%d", &v[i]);
        soma += v[i];
    }

    media = soma / 5;

    printf("\n");

    printf("Média: %d\n\n", media);
    printf("Vetor: ");
    for(i=0; i<5; i++){
        printf("V[%d]: %d ", i, v[i]);
    } 

    return 0;
}*/

//2
/*#include <stdio.h>

int main() {
    int original[10];
    int resultado[10];
    int i, j, k = 0;
    int duplicado;

    printf("Digite 10 numeros:\n");

    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &original[i]);
    }

    for (i = 0; i < 10; i++) {
        duplicado = 0; 
        for (j = 0; j < k; j++) { 
            if (original[i] == resultado[j]) {
                duplicado = 1;
                break;
            }
        }
        if (duplicado == 0) {
            resultado[k] = original[i];
            k++;
        }
    }

    printf("\nNumeros sem repeticao:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}*/

//3
/*#include <stdio.h>

int main(){
    int i, j, v[5], aux;

    for(i=0; i<5; i++){
        printf("V[%d]: ", i);
        scanf("%d", &v[i]);
    }

    for(i=0; i<4; i++){
        for(j=0; j<4-i; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

    printf("Vetor ordenado: \n");
    for(i=0; i<5; i++){
        printf("%d ", v[i]);
    }

    return 0;
}*/

// LAÇOS

/*Fácil: Imprima os números de 1 a 10 usando for.
Médio: Leia números até o usuário digitar 0. Exiba a soma deles.
Difícil: Gere a sequência de Fibonacci até o n-ésimo termo usando do while.*/

//1 
/*#include <stdio.h>

int main(){
    int i;

    for (i=1; i<11; i++){
        printf("%d ", i);
    }

    return 0;
}*/

//2 
/*#include <stdio.h>

int main(){
    int num, soma=0;

    printf("Digite um número (0 parar): ");
    scanf("%d", &num);

    while(num != 0){
        soma += num;

        printf("Digite um número (0 parar): ");
        scanf("%d", &num);
    }

    printf("Soma: %d", soma);

    return 0;
}*/

//3 
/*#include <stdio.h>

int main(){
    int i, qtd=0, t1=0, t2=1, t_n;

    printf("Digite quantos números da sequência você quer: ");
    scanf("%d", &qtd);

    printf("%d %d ", t1,t2);
    for(i=2; i<qtd; i++){
        t_n = t1 + t2;
        printf("%d ", t_n);
        t1 = t2;
        t2 = t_n;
    }

    return 0;
}*/

// CONDICIONAIS

/**Fácil: Leia um número e diga se ele é par ou ímpar.
Médio: Leia a nota de um aluno e imprima o conceito: A (≥9), B (≥7), C (≥5), D (<5).
Difícil: Faça uma calculadora simples usando switch-case que some, subtraia, multiplique ou divida dois números.*/

//1 
/*#include <stdio.h>

int main(){
    int n;

    printf("Num: ");
    scanf("%d", &n);

    if(n % 2 == 0){
        printf("\nPar");
    }
    else{
        printf("\nÍmpar");
    }

    return 0;
}*/

//2 
/*#include <stdio.h>

int main(){
    double nota;

    printf("Nota: ");
    scanf("%lf", &nota);

    if(nota > 10 || nota < 0){
        printf("Nota inválida");
    }
    else if(nota < 5){
        printf("Conceito D");
    }
    else if (nota < 7){
        printf("Conceito C");
    }
    else if (nota < 9){
        printf("Conceito B");
    }
    else{
        printf("Conceito A");
    }

    return 0;
}*/

//3
/*#include <stdio.h>

int main(){
    int a, b, operacao=0;

    printf("\n\n===CALCULADORA===\n\n");
    printf("1. Soma\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n\n");
    printf("Digite a opção que você quer: ");
    scanf("%d", &operacao);

    printf("Valor de A e B: ");
    scanf("%d%d", &a, &b);

    switch (operacao)
    {
    case 1:
        printf("Soma: %d", a+b);
        break;

    case 2:
    printf("Subtração: %d", a-b);
    break;

    case 3:
    printf("Multiplicação: %d", a*b);
    break;

    case 4:
    if (b==0){
        printf("Não é possível dividir por 0");
    }
    else{
        printf("Divisão: %.2lf", (double)a/b);
    }
    break;

    default:
        printf("Fim do programa");
        break;
    }

    return 0;
}*/

// MAIS EXERCÍCIOS 

// PONTEIROS

/*-- Troca de Valores

Crie duas variáveis inteiras e use ponteiros para trocar os valores entre elas, sem utilizar uma variável auxiliar comum.

Exemplo: a = 10, b = 20 → a = 20, b = 10.

-- Imprimir Endereços e Valores

Declare um vetor de 5 inteiros e imprima, usando aritmética de ponteiros, o endereço e o valor de cada posição.

Exemplo de saída: Endereço: 0x... Valor: 7.

-- Strings e Ponteiros

Crie um programa que leia uma string (máx. 50 caracteres) e, usando ponteiros, conte quantas vogais existem nela.

-- Alocação Dinâmica para Lista de Números

O usuário informa n. Aloque dinamicamente um vetor de n inteiros, preencha com valores digitados pelo usuário e calcule a média usando ponteiros.

Após imprimir, libere a memória.

-- Struct com Ponteiros

Crie uma struct Pessoa com nome e idade. Aloque dinamicamente memória para 3 pessoas e preencha os dados. Depois, percorra e imprima usando ponteiros para struct.

-- Inversão de String

Escreva um programa que receba uma string e a inverta sem criar outro vetor, apenas manipulando os ponteiros para trocar as posições inicial e final.*/

//1
/*#include <stdio.h>
int main(){
    int var1=10, var2=20;
    int *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    *pt1 = 20;
    *pt2 =10;

    printf("Var1: %d\n", var1);
    printf("Var2: %d", var2);

    return 0;
}*/

//2
/*#include <stdio.h>
int main(){
    int i, v[5]={1, 2, 3, 4, 5};
    for(i=0; i<5; i++){
        int *pt1;
        pt1 = &v[i];
        printf("Endereço: %p, Valor: %d\n", pt1, *pt1);
    }
    return 0;
}*/

//3
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char string[50];
    int cont=0, *pt;
    pt = &cont;

    printf("Digite a string: ");
    scanf(" %[^\n]", string);

    int sz = strlen(string);

    for (int i=0; i<sz; i++){
        string[i] = toupper(string[i]);

        if (string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U'){
            (*pt)++;
        }
    }

    printf("QTD Vogais: %d", *pt);
    
    return 0;
}*/

//4
/*#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("N: ");
    scanf("%d", &n);

    int v[n];
    int *pt = (int*)malloc(sizeof(int));
    int soma = 0;
    pt = &soma;

    for (int i=0; i<n; i++){
        printf("V[%d]: ", i);
        scanf("%d", &v[i]);
        (*pt)+=v[i];
    }

    printf("A média é: %d", *pt/n);

    return 0;
}*/

//5
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_PESSOAS 3

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa *ptr_pessoas = (struct Pessoa *)malloc(NUM_PESSOAS * sizeof(struct Pessoa));

    if (ptr_pessoas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("--- Preenchimento de Dados ---\n");
    for (int i = 0; i < NUM_PESSOAS; i++) {
        
        printf("Pessoa %d - Nome: ", i + 1);
        scanf(" %[^\n]", (ptr_pessoas + i)->nome);

        printf("Pessoa %d - Idade: ", i + 1);
        scanf("%d", &(ptr_pessoas + i)->idade);
    }
    
    printf("\n");

    printf("--- Dados Cadastrados ---\n");

    for (struct Pessoa *p = ptr_pessoas; p < ptr_pessoas + NUM_PESSOAS; p++) {
        
        printf("Nome: %s\n", p->nome);
        printf("Idade: %d\n", p->idade);
        printf("--------------------------\n");
    }
    
    free(ptr_pessoas);
    
    return 0;
}*/