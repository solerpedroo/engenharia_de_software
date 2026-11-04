// Exercício 1
/*
#include <stdio.h>

int main ()
{
    int N, i;

    float X[20], Y[20], Z[20];

    printf("Digite o valor de N (max 20): ");
    scanf("%d", &N);

    if (N > 20 || N <= 0) 
    {
        printf("Valor inválido.\n");
        return 1;
    }

    printf("\nDigite os elementos do vetor X:\n");
    for (i = 0; i < N; i++) 
    {
        printf("X[%d] = ", i);
        scanf("%f", &X[i]);
    }

    printf("\nDigite os elementos do vetor Y:\n");
    for (i = 0; i < N; i++) {
        printf("Y[%d] = ", i);
        scanf("%f", &Y[i]);
    }

    for (i = 0; i < N; i++) {
        Z[i] = X[i] * Y[i];
    }

    printf("\nVetor X: ");
    for (i = 0; i < N; i++) {
        printf("%.2f ", X[i]);
    }

    printf("\nVetor Y: ");
    for (i = 0; i < N; i++) {
        printf("%.2f ", Y[i]);
    }

    printf("\nVetor Z (X*Y): ");
    for (i = 0; i < N; i++) {
        printf("%.2f ", Z[i]);
    }

    printf("\n");

    return 0;

}*/

// Exercício 2
/*
#include <stdio.h>

int main() {
    int n, i;
    float x[20], maior, menor;

    printf("Digite o valor de N (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Valor inválido\n");
        return 1;
    }

    printf("\nDigite os elementos do vetor X:\n");
    for (i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        scanf("%f", &x[i]);
    }

    maior = menor = x[0];

    for (i = 1; i < n; i++) {
        if (x[i] > maior) maior = x[i];
        if (x[i] < menor) menor = x[i];
    }

    printf("\nO maior número digitado foi %f", maior);
    printf("\nO menor número digitado foi %f", menor);

    return 0;
}*/

// Exercício 3
/*
#include <stdio.h>

int main() {
    int n, i;
    int x[20];
    int maior, menor;
    int idxMaior, idxMenor;

    printf("Digite o valor de N (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Valor inválido.\n");
        return 1;
    }

    printf("\nDigite os elementos do vetor X:\n");
    for (i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        scanf("%d", &x[i]);
    }

    maior = menor = x[0];
    idxMaior = idxMenor = 0;

    for (i = 1; i < n; i++) {
        if (x[i] > maior) {
            maior = x[i];
            idxMaior = i;
        }
        if (x[i] < menor) {
            menor = x[i];
            idxMenor = i;
        }
    }

    printf("\nVetor lido: ");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    printf("\n\nMaior valor: %d na posição %d", maior, idxMaior);
    printf("\nMenor valor: %d na posição %d\n", menor, idxMenor);

    return 0;
}*/


// Exercício 4
/*
#include <stdio.h>

int main ()
{

    int n, i;
    float x[20], y[20];

    printf("Digite o valor de N (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Valor inválido.\n");
        return 1;
    }

    printf("\nDigite os elementos do vetor X:\n");
    for (i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        scanf("%f", &x[i]);
    }

    for (i = 0; i < n; i++)
    {
        y[i] = x[ n - 1 - i];
    }

    printf("\nVetor X: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }

    printf("\nVetor Y (inverso): ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", y[i]);
    }

    printf("\n");
    return 0;

}*/

// Exercício 5
/*
#include <stdio.h>

int main ()
{

    int i, x[20], n=20;
    int qtd_par =0, qtd_mult5 = 0;

    printf("\nDigite os elementos do vetor X:\n");
    for (i = 1; i < n+1; i++) {
        printf("X[%d] = ", i);
        scanf("%i", &x[i]);

        if (i % 2 == 0)
        {
            qtd_par ++;
        }

        if (i % 5 == 0)
        {
            qtd_mult5 ++;
        }
    }

    printf("A quantidade de números pares digitados foi: %d", qtd_par);
    printf("\nA quantidade de números múltiplos de 5 digitados foi: %d", qtd_mult5);

    return 0;


}*/

// Exercício 6
/*
#include <stdio.h>

int main() {
    int i, x[5], n = 5;
    int soma = 0, qtd_menor_media = 0;
    int media;

    printf("\nDigite os elementos do vetor X:\n");
    for (i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        scanf("%d", &x[i]);
        soma += x[i];
    }

    media = soma / n;

    for (i = 0; i < n; i++) {
        if (x[i] < media) {
            qtd_menor_media++;
        }
    }

    printf("\nA média dos números digitados é: %d", media);
    printf("\nA quantidade de números menores que a média é: %d\n", qtd_menor_media);

    return 0;
}*/

// Exerício 7
/*
#include <stdio.h>

int main (){

    int x[20];
    int i, j, aux;

    printf("Digite 20 números inteiros:\n");
    for (i = 0; i < 20; i++) {
        printf("X[%d] = ", i);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < 19; i++) {
        for (j = 0; j < 19 - i; j++) {
            if (x[j] > x[j + 1]) {
                aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;
            }
        }
    }

    printf("\nVetor ordenado em ordem crescente:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;

}*/

// Exercício 8
/*
#include <stdio.h>

int main() {
    int x[20];
    int i, j, aux;

    printf("Digite 20 números inteiros:\n");

    for (i = 0; i < 20; i++) {
        printf("X[%d] = ", i);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < 19; i++) {
        for (j = 0; j < 19 - i; j++) {
            if (x[j] < x[j + 1]) {
                aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;
            }
        }
    }

    printf("\nVetor ordenado em ordem decrescente:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}*/

// Exercício 9 
/*
#include <stdio.h>

int main() {
    int x[10], cont = 0;
    int num, i;

    printf("Digite até 10 números inteiros (número negativo para parar):\n");

    while (cont < 10) {
        printf("X[%d] = ", cont);
        scanf("%d", &num);

        if (num < 0) {
            break;
        }

        x[cont] = num;
        cont++;
    }

    printf("\nVetor preenchido:\n");
    for (i = 0; i < cont; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

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