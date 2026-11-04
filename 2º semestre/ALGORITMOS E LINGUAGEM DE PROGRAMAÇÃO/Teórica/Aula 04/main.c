// Exercícios

// Exercício 1 
/*
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i;
    bool primo = true;

    printf("Digite um número inteiro: ");
    scanf("%i", &n);

    if (n < 2)
    {
        primo = false;
    }
    else
    {
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                primo = false;
                break;
            }
        }
    }

    if (primo)
    {
        printf("%d é primo\n", n);
    }
    else
    {
        printf("%d não é primo\n", n);
    }

    return 0;
}*/

// Exercício 2 
/*
#include <stdio.h>

int main()
{
    int n, cont = 0, maior, menor;
    int primeiro = 1;

    printf("Digite um número inteiro (0 para parar): ");
    scanf("%i", &n);

    while (n != 0)
    {
        if (primeiro)
        {
            maior = n;
            menor = n;
            primeiro = 0;
        }
        else
        {
            if (n > maior)
            {
                maior = n;
            }
            if (n < menor)
            {
                menor = n;
            }
        }

        cont++;

        printf("Digite outro número (0 para parar): ");
        scanf("%i", &n);
    }

    printf("\nA quantidade de números digitados foi: %d", cont);
    printf("\nO maior número digitado foi: %d", maior);
    printf("\nO menor número digitado foi: %d\n", menor);

    return 0;
}*/

// Exercício 3 
/*
#include <stdio.h>

int main()
{
    int num, fatorial, i;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    while (num > 0)
    {
        fatorial = 1;
        for (i = num; i > 0; i--)
        {
            fatorial *= i;
        }
        printf("O fatorial de %d é: %d\n", num, fatorial);

        printf("Digite um número inteiro positivo (0 para sair): ");
        scanf("%d", &num);
    }
    return 0;

}*/

// Exercício 4
/*
#include <stdio.h>

int main()
{
    int senha = 123, tentativa, cont = 0;
    int maxTentativas = 3;

    while (cont < maxTentativas)
    {
        printf("Digite a senha: ");
        scanf("%d", &tentativa);

        if (tentativa == senha)
        {
            printf("Acesso liberado\n");
            return 0;
        }
        else
        {
            cont++;
            if (cont == maxTentativas)
            {
                printf("Limite máximo de tentativas excedido. Usuário bloqueado!\n");
            }
            else
            {
                printf("Acesso negado\n");
                printf("Tente novamente\n");
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
