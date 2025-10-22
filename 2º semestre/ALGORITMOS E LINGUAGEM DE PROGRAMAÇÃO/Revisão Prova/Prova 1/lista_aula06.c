// Exercício 1

/*#include <stdio.h>

int main (){

    int i, j, n;

    printf("Digite o tamanho da matriz (max 20): ");
    scanf("%d", &n);

    if (n>20 || n<0){
        printf("Número digitado é inválido");
    }
    else{
        int matriz[n][n];
        int soma=0;
        
        for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                printf("M[%d][%d]: ", i,j);
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
        
        for (i=0; i<n; i++){
            soma += matriz[i][i];
        }
        
        printf("\nA soma da diagonal principal é: %d", soma);
    }

    return 0;
}*/

// Exercício 2 

/*#include <stdio.h>

int main (){

    int i, j, matriz[5][5], linha_maior=0, coluna_maior=0;

    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int maior=matriz[0][0];

    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            if (matriz[i][j] > maior){
                maior = matriz[i][j];
                linha_maior = i;
                coluna_maior = j;
            }
        }
    }

    printf("\nMatriz digitada: \n");
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nO maior número digitado foi: %d", maior);
    printf("\nA linha é: %d", linha_maior);
    printf("\nA coluna é: %d", coluna_maior);

    return 0;

}*/

// Exercício 3

/*#include <stdio.h>

int main (){

    int i, j, m[5][3], mt[3][5];

    printf("Digite a matriz 5x3: ");
    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

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

    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%f", &m[i][j]);
        }
    }

    float soma_linha4=0;

    for (j=0; j<10; j++){
        soma_linha4 += m[3][j];
    }

    float menor_coluna5 = m[0][4];

    for (i=0; i<10; i++){
        if (menor_coluna5 < m[i][4]){
            menor_coluna5 = m[i][4];
        }
    }

    float maior_diag_principal = m[0][0];
    int linha_diag_principal = 0, coluna_diag_principal = 0;

    for (i=0; i<10; i++){
        if (m[i][i] > maior_diag_principal){
            maior_diag_principal = m[i][i];
            coluna_diag_principal = linha_diag_principal = i;
        }
    }

    printf("\nA soma da linha 4 é: %f\n", soma_linha4);
    printf("O menor elemento da coluna 5 é: %f\n", menor_coluna5);
    printf("O maior elemento da diagonal principal é: %f, sua linha é: %d, sua coluna é: %d", maior_diag_principal, linha_diag_principal, coluna_diag_principal);

    return 0;

}*/

// Exercício 5

#include <stdio.h>

int main (){

    int i, j, k, linha_mat1, coluna_mat1, linha_mat2, coluna_mat2;

    printf("Digite a quantidade de linhas da primeira matriz: ");
    scanf("%d", &linha_mat1);

    printf("Digite a quantidade de colunas da primeira matriz: ");
    scanf("%d", &coluna_mat1);

    printf("Digite a quantidade de linhas da segunda matriz: ");
    scanf("%d", &linha_mat2);

    printf("Digite a quantidade de colunas da segunda matriz: ");
    scanf("%d", &coluna_mat2);

    int m1[linha_mat1][coluna_mat1], m2[linha_mat2][coluna_mat2];
    int m3[linha_mat1][coluna_mat2];

    if (linha_mat1 != coluna_mat2){
        printf("\nA multiplicação não é possível\n");
        return 0;
    }
    else{
        for (i=0; i<linha_mat1; i++){
            for (j=0; j<coluna_mat1; j++){
                printf("M1[%d][%d]: ", i, j);
                scanf("%d", &m1[i][j]);
            }
        }

        for (i=0; i<linha_mat2; i++){
            for (j=0; j<coluna_mat2; j++){
                printf("M2[%d][%d]: ", i, j);
                scanf("%d", &m2[i][j]);
            }
        }

        for (i=0; i<linha_mat1; i++){
            for (j=0; j<coluna_mat2; j++){
                m3[i][j] = 0;
                for (k=0; k<coluna_mat1; k++){
                    m3[i][j] += m1[i][k] * m2[k][j];
                } 
            }    
        }

        for (i=0; i<linha_mat1; i++){
            for (j=0; j<coluna_mat2; j++){
                printf("%d\t", m3[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
    
}