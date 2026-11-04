// Refazendo exercícios aula 6

// --> Exercício 1

/*#include <stdio.h>

int main()
{
    int i, j, n;
    
    printf("Digite o valor de N (máximo 20): ");
    scanf("%d", &n);
    
    if (n>20 || n<= 0){
        printf("Número de N inválido");
    }
    else{
        int matriz[n][n];
        
        printf("Digite os números da matriz: \n");
        for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                printf("Digite o elemento [%d][%d]: ", i,j);
                scanf("%d", &matriz[i][j]);
            }
        }
        
        int soma_diag=0;
        for (i=0; i<n; i++){
            soma_diag += matriz[i][i];
        }
        
        printf("A matriz digitada é: \n");
        for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
        printf("A soma da diagonal principal é: %d", soma_diag);
        
        return 0;
        
    }
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

// --> Exercício 3

/*#include <stdio.h>

int main (){

    int i, j, matriz[5][3];
        
    printf("Digite os valores da matriz 5x3: \n");
    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int matriz_transposta[3][5];

    for (i=0; i<3; i++){
        for (j=0; j<5; j++){
            matriz_transposta[j][i] = matriz[i][j];
        }
    }

    printf("Matriz original: \n");
    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Matriz transposta: \n");
    for (i=0; i<3; i++){
        for (j=0; j<5; j++){
            printf("%d\t", matriz_transposta[i][j]);
        }
        printf("\n");
    }

    return 0;

}*/