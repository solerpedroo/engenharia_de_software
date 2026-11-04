// --> Exercício 1

/*#include <stdio.h>

int main() {
    int i, j, n;

    printf("Digite o valor de N (máximo 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Número digitado inválido");
        return 1;
    }
    else {
        int matriz[n][n];
        
        printf("Digite todos os valores da matriz %dx%d:\n", n, n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("Elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("\nMatriz digitada:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }

        int soma_diagonal = 0;
        for (i = 0; i < n; i++) {
            soma_diagonal += matriz[i][i];
        }
        printf("Soma da diagonal principal: %d\n", soma_diagonal);
    }
    
    return 0;
}*/

// --> Exercício 2

/*#include <stdio.h>

int main (){

    int i, j, m[5][5], linha_maior=0, coluna_maior=0;

    printf("Digite os valores da matriz: \n");
    
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%d", &m[i][j]);
        }
    }

    int maior=m[0][0];

    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            if (m[i][j] > maior){
                maior = m[i][j];
                linha_maior = i;
                coluna_maior = j;
            }
        }
    }

    printf("O maior valor digitado foi: %d\n", maior);
    printf("A posição dele é m[%d][%d]", linha_maior, coluna_maior);

    return 0;

}*/

// Exercício 3

/*#include <stdio.h>

int main (){

    int i, j, m[5][3];

    printf("Digite os valores da matriz 5x3: \n");
    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%d", &m[i][j]);
        }
    }

    int mt[3][5];

    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            mt[j][i] = m[i][j];
        }
    }

    printf("Matriz original: \n");
    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("Matriz transposta: \n");
    for (i=0; i<3; i++){
        for (j=0; j<5; j++){
            printf("%d\t", mt[i][j]);
        }
        printf("\n");
    }

    return 0;

}*/

// Exercício 4

/*#include <stdio.h>

int main (){

    int i, j;
    float m[10][10];

    printf("Digite os valores da matriz 10x10: \n");
    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%f", &m[i][j]);
        }
    }

    float soma_linha4=0;

    for (j=0; j<10; j++){
        soma_linha4 += m[3][j];
    }

    float menor_col5 = m[0][4];

    for (i=1; i<10; i++){
        if (m[i][4] < menor_col5){
            menor_col5 = m[i][4];
        }
    }

    float maior_diag = m[0][0];
    int linhaMaior = 0, colunaMaior = 0;
    for (i = 1; i < 10; i++) {
        if (m[i][i] > maior_diag) {
            maior_diag = m[i][i];
            linhaMaior = i;
            colunaMaior = i;
        }
    }

    printf("\nResultados:\n");
    printf("a) Soma da linha 4 = %.2f\n", soma_linha4);
    printf("b) Menor elemento da coluna 5 = %.2f\n", menor_col5);
    printf("c) Maior elemento da diagonal principal = %.2f (posicao [%d][%d])\n", maior_diag, linhaMaior, colunaMaior);

    return 0;

}*/

// Exerício 5

#include <stdio.h>

int main (){
    
    int i, j, k, linha_mat1, linha_mat2, coluna_mat1, coluna_mat2;

    printf("Digite a quantidade de linhas da primeira matriz: ");
    scanf("%d", &linha_mat1);

    printf("Digite a quantidade de colunas da primeira matriz: ");
    scanf("%d", &coluna_mat1);

    printf("Digite a quantidade de linhas da segunda matriz: ");
    scanf("%d", &linha_mat2);

    printf("Digite a quantidade de colunas da segunda matriz: ");
    scanf("%d", &coluna_mat2);
    
    int matriz1[linha_mat1][coluna_mat1];
    int matriz2[linha_mat2][coluna_mat2];
    
    int matriz3[linha_mat1][coluna_mat2];

    if (coluna_mat1 == linha_mat2){
        
        for (i=0; i<linha_mat1; i++){
            for (j=0; j<coluna_mat1; j++){
                printf("Digite o elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz1[i][j]);
            }
        }
        
        for (i=0; i<linha_mat2; i++){
            for (j=0; j<coluna_mat2; j++){
                printf("Digite o elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz2[i][j]);
            }
        }
        
        for (i=0; i<linha_mat1; i++){
            for (j=0; j<coluna_mat2; j++){
                matriz3[i][j] = 0;
                for (k=0; k<coluna_mat1; k++){
                    matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
                    
                }
                
            }
        }
        
        for (i=0; i<linha_mat1; i++)
        {
            for (j=0; j<coluna_mat2; j++)
            {
                printf("%d\t", matriz3[i][j]);
            }
            printf("\n");
        }
    }
    
    else {
        printf("Multiplicação não é possível");
    }
    
    return 0;

}