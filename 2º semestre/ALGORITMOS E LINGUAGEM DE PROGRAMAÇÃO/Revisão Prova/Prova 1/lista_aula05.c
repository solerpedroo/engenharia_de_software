// Exercício 1

/*#include <stdio.h>

int main (){

    float x[20], y[20], z[20];
    int n, i;

    printf("Digite quantos números você deseja inserir (max 20): ");
    scanf("%d", &n);

    if (n>20 || n <0){
        printf("Número digitado inválido");
    }

    printf("Digite os vetores:\n");
    for (i=0; i < n; i++){
        printf("X[%d]: ", i);
        scanf("%f", &x[i]);

        printf("Y[%d]: ", i);
        scanf("%f", &y[i]);

        z[i] = x[i] * y[i];
    }

    printf("\nVetor X: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }

    printf("\nVetor Y: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", y[i]);
    }

    printf("\nVetor Z (X*Y): ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", z[i]);
    }

    printf("\n");
    return 0;
}*/

// Exercício 2

/*#include <stdio.h>

int main (){

    int i, n, x[20], maior, menor;

    printf("\nDigite o tamanho do vetor (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n < 0){
        printf("\nNúmero digitado inválido");
    }
    else{
        for (i=0; i<n; i++){
            printf("X[%d]: ", i);
            scanf("%d", &x[i]);
        }

        maior = x[0];
        menor = x[0];

        for (i=0; i<n; i++){
            if (x[i] > maior){
                maior = x[i];
            }
            if (x[i] < menor){
                menor = x[i];
            }
        }

        printf("\nMaior: %d", maior);
        printf("\nMenor: %d", menor);
    }    

    return 0;
}*/

// Exercício 3

/*#include <stdio.h>

int main (){

    int i, n, x[20], maior, menor, pos_maior, pos_menor;

    printf("\nDigite o tamanho do vetor (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n < 0){
        printf("\nNúmero digitado inválido");
    }

    for (i=0; i<n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);
    }

    maior = x[0];
    menor = x[0];
    pos_maior = 0;
    pos_menor = 0;

    for (i=0; i<n; i++){
        if (x[i] > maior){
            maior = x[i];
            pos_maior = i;
        }
        if (x[i] < menor){
            menor = x[i];
            pos_menor = i;
        }
    }

    printf("\nMaior: %d, na posição %d", maior, pos_maior);
    printf("\nMenor: %d, na posição %d", menor, pos_menor);

    return 0;
}*/

// Exercício 4

/*#include <stdio.h>

int main (){

    int n, i, x[20], y[20];

    printf("Digite o tamanho do vetor (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n < 0){
        printf("Número inválido");
    }

    for (i=0; i<n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i=0; i<n; i++){
        y[i] = x[n - 1 - i];
    }

    printf("\nVetor X: ");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    printf("\nVetor Y: ");
    for (i = 0; i < n; i++) {
        printf("%d ", y[i]);
    }    

    return 0;
}*/

// Exercício 5

/*#include <stdio.h>

int main (){

    int i, n, x[20], cont_5=0, cont_par=0;

    printf("Digite a quantidade de números do vetor (max 20): ");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i=0; i<n; i++){
        if (x[i] % 5 == 0){
            cont_5 ++;
        }
        if (x[i] % 2 == 0){
            cont_par ++;
        }
    }

    printf("\nVetor X: ");
    for (i=0; i<n; i++){
        printf("%d ", x[i]);
    }

    printf("\nQtd pares: %d", cont_par);
    printf("\nQtd mult 5: %d", cont_5);

    return 0;

}*/

// Exercício 6

/*#include <stdio.h>

int main (){

    int n, i, soma=0, media=0, x[20], menor_media=0;

    printf("Digite o valor de N (max 20): ");
    scanf("%d", &n);

    if (n >20 || n<0){
        printf("Número inválido");
    }

    for (i=0; i<n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);

        soma += x[i];
    }

    media = soma / n;

    for (i=0; i<n; i++){
        if (x[i] < media){
            menor_media ++;
        }
    }

    printf("Média: %d\n", media);
    printf("Menores que a média: %d\n", menor_media);

    printf("Vetor: ");
    for (i=0; i<n; i++){
        printf("%d ", x[i]);
    }

    return 0;
}*/

// Exercício 7

/*#include <stdio.h>

int main (){

    int i, j, aux, n, x[20];

    printf("Digite o valor de N (max 20): ");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i=0; i<n-1; i++){
        for (j=0; j<n-1-i; j++){
                if (x[j] > x[j + 1]) {
                aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;
                }
        }
    }

    printf("\nVetor ordenado em ordem crescente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}*/   

// Exercício 8

/*#include <stdio.h>

int main (){

    int i, j, aux, n, x[20];

    printf("Digite o valor de N (max 20): ");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i=0; i<n-1; i++){
        for (j=0; j<n-1-i; j++){
                if (x[j] < x[j + 1]) {
                aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;
                }
        }
    }

    printf("\nVetor ordenado em ordem crescente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}*/

// Exercício 9

/*#include <stdio.h>

int main (){

    int i, cont=0, v[10];

    printf("Digite 10 números (negativo para parar)\n");
    while (cont < 10){

        printf("V[%d]: ", cont);
        scanf("%d", &v[cont]);

        if (v[cont] < 0){
            printf("\nNúmero negativo digitado");
            printf("\nFim de programa");
            break;
        }

        cont ++;
    }

    printf("\nVetor digitado:\n");
    for (i=0; i<cont; i++){
        printf("%d ", v[i]);
    }

    return 0;

}*/

// Exercício 10

// --> Inserir elemento
/*
#include <stdio.h>

int main (){

    int vetor[10] = {1, 2, 3, 4, 5, 6};
    int n = 6, inserir = 22, i;

    for (i =n; i >3; i--){

        vetor[i] = vetor[i -1];

    }

    vetor[3] = inserir;
    n ++;

    printf("Vetor após inserir novo valor na pos3:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;

}*/

// --> Remover elemento

#include <stdio.h>

int main (){

    int vetor[10] = {1, 2, 3, 4, 5, 6};
    int n=6, i;

    for (i=2; i<n-1; i++){
        vetor[i] = vetor[i+1];

    }
    n--;

    printf("Vetor após remover a pos2:\n");
    for (i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;

}