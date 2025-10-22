/*#include <stdio.h>

int main() {
    int v[5] = {50, 40, 30, 20, 10};
    int soma = 0, m;

    for (int i = 0; i < 5; i++) {
        soma += v[i];
    }

    m = soma / 5;

    printf("A média dos vetores é igual a: %d\n", m);

    return 0;
}*/

/*#include <stdio.h>

int main (){

    int v[5] = {50, 40, 30, 20, 10};
    int i, s=0;

    for (i = 0; i < 5; i++){
        s += v[i];
    }

    printf("A média dos elementos é: %d", s/5);

    return 0;

}*/

/*#include <stdio.h>

int main (){

    int v[5], i;

    for (i=0; i<5; i++){
        printf("\nDigite um número inteiro: ");
        scanf("%d", &v[i]);
    }

    for (i=0; i<5; i++){
        printf("\nOs números digitados foram: %d\n", v[i]);
    }

    return 0;

}*/

/*#include <stdio.h>

int main (){

    int n, i;
    float x[20], y[20], z[20];

    printf("Digite o valor de N (máximo 20): ");
    scanf("%d", &n);

    if (n <= 0 || n > 20){
        printf("Número digitado inválido.\n");
        printf("Fim do programa.");
    }

    printf("Digite os valores do vetor X:\n");
    for ( i=0; i < n; i++){
        printf("X[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("Digite os valores do vetor Y:\n");
    for ( i=0; i < n; i++){
        printf("Y[%d]: ", i);
        scanf("%f", &y[i]);
    }
    
    for (i=0; i < n; i++){
        z[i] = x[i] * y[i];
    }

    printf("Vetores de X: \n");
    for (i=0; i < n; i++){
        printf("X[%f]: \n", x[i]);
    }

    printf("Vetores de Y: \n");
    for (i=0; i < n; i++){
        printf("Y[%f]: \n", y[i]);
    }

    printf("Vetores de Z: \n");
    for (i=0; i < n; i++){
        printf("Z[%f]: \n", z[i]);
    }

    return 0;

}*/

/*#include <stdio.h>

int main (){

    int v[20], n, i, menor, maior;

    printf("Digite um valor para N (máximo 20): ");
    scanf("%d", &n);

    if (n <= 0 || n > 20){
        printf("Valor digitado inválido");
    }

    printf("Digite os valores do vetor");
    for (i=0; i<n; i++){
        printf("\nX[%d]: ", i);
        scanf("%d", &v[i]);
    }

    maior = v[0];
    menor = v[0];

    for (i=0; i<n; i++){
        if (v[i] < menor) menor = v[i];
        if (v[i] > maior) maior = v[i];
    }

    printf("\nO maior valor encontrado foi %d", maior);
    printf("\nO menor valor encontrado foi %d", menor);

    return 0;

}*/

/*#include <stdio.h>

int main (){

    int v[20], n, i, menor, maior, ind_menor, ind_maior;

    printf("Digite um valor para N (máximo 20): ");
    scanf("%d", &n);

    if (n <= 0 || n > 20){
        printf("Valor digitado inválido");
    }

    printf("Digite os valores do vetor");
    for (i=0; i<n; i++){
        printf("\nX[%d]: ", i);
        scanf("%d", &v[i]);
    }

    maior = v[0];
    menor = v[0];
    ind_maior = 0;
    ind_menor = 0;

    for (i=0; i<n; i++){
        if (v[i] < menor){
            menor = v[i];
            ind_menor = i;
        } 
        if (v[i] > maior){
            maior = v[i];
            ind_maior = i;
        } 
    }

    printf("\nO maior valor encontrado foi %d e o seu índice é %d", maior, ind_maior);
    printf("\nO menor valor encontrado foi %d e o seu índice é %d", menor, ind_menor);
    printf("\nO vetor completo é:");
    for (i=0; i <n; i++){
        printf("\nVetor [%d]", v[i]);
    }

    return 0;

}*/

/*#include <stdio.h>

int main (){

    int x[20], y[20], i, n;

    printf("Digite o valor de N (máximo 20): ");
    scanf("%d", &n);

    if ( n <= 0 || n > 20){
        printf("Número inserido inválido");
    }

    for ( i=0 ; i < n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i=0; i<n; i++){
        y[i] = x [n-1-i];
    }

    printf("\nVetor digitado (X): ");
    for (i=0; i<n; i++){
        printf("\n%d", x[i]);
    }

    printf("\nVetor inverso (Y): ");
    for (i=0; i<n; i++){
        printf("\n%d", y[i]);
    }

    return 0;

}*/

/*#include <stdio.h>

int main (){

    int x[20], qtd5=0, qtd_par=0, i, n=5;

    printf("Digite os números do vetor: \n");
    for (i=0; i < n; i++){
        printf("X[%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i=0; i<n; i++){
        if (x[i] % 5 == 0){
            qtd5 ++;
        }
        if (x[i] % 2 ==0){
            qtd_par ++;
        }
    }

    printf("\nQuantidade mult 5: %d", qtd5);
    printf("\nQuantidade par: %d", qtd_par);

    return 0;

}*/

/*#include <stdio.h>

int main (){

    int v[20], n=5, media=0, soma=0, menor_media=0, i;

    printf("Digite os elementos do vetor: \n");
    for (i=0; i<n; i++){
        printf("V[%d]: ", i);
        scanf("%d", &v[i]);
    }

    for (i=0; i<n; i++){
        soma += v[i];
    }

    media = soma / n;

    for (i=0; i<n; i++){
        if (v[i] < media){
            menor_media ++;
        }
    }

    printf("A média é igual a: %d", media);
    printf("\nQuantidade menor que a média é: %d", menor_media);

    return 0;

}*/

#include <stdio.h>

int main (){

    int ;

}