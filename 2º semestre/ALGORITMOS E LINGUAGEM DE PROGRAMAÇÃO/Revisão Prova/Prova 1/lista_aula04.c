// Exercício 1

/*#include <stdio.h>
#include <stdbool.h>

int main (){

    int i, n;
    bool primo = true;

    printf("Digite o número para verificar: ");
    scanf("%d", &n);

    if (n < 2){
        primo = false;
    }
    else{
        for (i=2; i<n; i++){
            if (n % i == 0){
                primo = false;
                break;
            }
        }
    }

    if (primo){
        printf("O número %d é primo", n);
    }
    else{
        printf("O número %d não é primo", n);
    }

    return 0;

}*/

// Exercício 2

/*#include <stdio.h>

int main (){

    int maior, menor, cont=0, n, primeiro=1;

    printf("Digite um número inteiro (0 para parar): ");
    scanf("%d", &n);

    while (n != 0 ){

        if (primeiro){
            maior = n;
            menor = n;
            primeiro = 0;
        }
        else{
            if (n > maior){
                maior = n;
            }
            if (n < menor){
                menor = n;
            }
        }

        cont ++;

        printf("Digite um número inteiro (0 para parar): ");
        scanf("%d", &n);

    }

    printf("\nForam lidos: %d\n", cont);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;

}*/

// Exercício 3

/*#include <stdio.h>

int main (){

    int i, n, fatorial;

    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    while (n > 0){

        fatorial = 1;

        for (i=n; i > 0; i--){
            fatorial*=i;
        }
        printf("O fatorial de %d é: %d\n", n, fatorial);

        printf("\nDigite um número inteiro: ");
        scanf("%d", &n);

    }

    return 0;

}*/

// Exercício 4

/*#include <stdio.h>

int main (){

    int senha=123, n, cont=0;

    while (cont < 3){
        printf("Digite a senha: ");
        scanf("%d", &n);

        if (n == senha){
            printf("Acesso liberado");
            break;
        }
        else{
            cont ++;
            if (cont == 3){
                printf("Número máximo de tentativas atingido. Usuário bloqueado");
            }
            else{
                printf("Senha inválida.\nTente novamente\n");
            }
        }
    }

    return 0;
}*/

// Exercício 5

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num1, num2, num3, num4, num5;
    bool mustStop = false;
    int temp;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    printf("Digite o terceiro número: ");
    scanf("%d", &num3);
    printf("Digite o quarto número: ");
    scanf("%d", &num4);
    printf("Digite o quinto número: ");
    scanf("%d", &num5);

    while (mustStop == false)
    {
        mustStop = true;

        if (num1 > num2) { temp = num1; num1 = num2; num2 = temp; mustStop = false; }
        if (num2 > num3) { temp = num2; num2 = num3; num3 = temp; mustStop = false; }
        if (num3 > num4) { temp = num3; num3 = num4; num4 = temp; mustStop = false; }
        if (num4 > num5) { temp = num4; num4 = num5; num5 = temp; mustStop = false; }
    }

    printf("\nNúmeros em ordem crescente: %d, %d, %d, %d, %d\n", num1, num2, num3, num4, num5);

    return 0;
}