// Exercício 4 - lista 6 

/*#include <stdio.h>

int main(){

    int i, j, m[10][10], soma4=0;

    printf("\nDigite os elementos da matriz: ");
    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for (j=0; j<10; j++){
        soma4 += m[3][j];
    }

    int menor_coluna5 = m[0][4];

    for (i=0; i<10; i++){
        if (m[i][4] < menor_coluna5){
            menor_coluna5 = m[i][4];
        }
    }

    int maior_diag = m[0][0];
    int linha=0, coluna=0;

    for (i=0; i<10; i++){
        if (m[i][i] > maior_diag){
            maior_diag = m[i][i];
            linha = i;
            coluna = i;
        }
    }

    printf("\nA soma da linha 4 é: %d", soma4);
    printf("\nO menor da coluna 5 é: %d", menor_coluna5);
    printf("\nO maior da diagonal principal é: %d, sua linha: %d, sua coluna: %d", maior_diag, linha, coluna);

    return 0;
}*/

// Exercício 5 - lista aula 6

/*#include <stdio.h>

int main (){

    int i, j, k, linha_a, coluna_a, linha_b, coluna_b;

    printf("\nDigite a qtd de linha da matriz A: ");
    scanf("%d", &linha_a);
    printf("\nDigite a qtd de colunas da matriz A: ");
    scanf("%d", &coluna_a);
    printf("\nDigite a qtd de linha da matriz B: ");
    scanf("%d", &linha_b);
    printf("\nDigite a qtd de colunas da matriz B: ");
    scanf("%d", &coluna_b);

    if (coluna_a != linha_b){
        printf("A multiplicação não é válida");
    }
    else{


    }

}*/

/*preencher dois vetores max 20, assim que um numero negativo for digitado ele para, se um número negativo for digitado na pos3, o vetor vai até a posição da ultima posição, e por fim juntar os dois vetores*/

/*#include <stdio.h>

int main (){

    int i, x[20], y[20], cont1=0, cont2=0;

    for (i=0; i<20; i++){
            printf("X[%d]: ", i);
            scanf("%d", &x[i]);
            if (x[i] < 0){
                printf("\nNúmero negativo");
                break;
            }
            cont1 ++;
        }
    
        for (i=0; i<20; i++){
            printf("Y[%d]: ", i);
            scanf("%d", &y[i]);
            if (y[i] < 0){
                printf("\nNúmero negativo");
                break;
            }
            cont2 ++;
        }

        int z[cont1+cont2];

        for (i=0; i<cont1; i ++){
            z[i] = x[i];
        }

        for(i = cont1; i < cont2; i++){
            z[cont1 + i] = y[i];
        }
        
        printf("\nVetor Z (junção de X e Y):\n");
        for (i = 0; i < cont1 + cont2; i++) {
            printf("Z[%d] = %d\n", i, z[i]);
        }
    
        return 0;

}*/

/*matriz já preenchida e ordenar a coluna de forma crescente*/

#include <stdio.h>

int main() {
    int i, j;
    int linhas = 4;
    int colunas = 4;

    int matriz[4][4] = {
        {9,  4,  3,  8},
        {1,  7,  5,  2},
        {6,  0, 12, 10},
        {15, 14, 11, 13}
    };
    for (j = 0; j< 4; j ++){
        for(i = 0; i < 3; i++){
            if(matriz[i][j] > matriz[i+1][j]){
                int temp = matriz[i][j];
                matriz[i][j] = matriz[i + 1][j];
                matriz[i+1][j] = temp;
            }
        }
    }

    printf("\nMatriz após ordenar todas as colunas em ordem crescente:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}