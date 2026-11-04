// Exercícios Aula 04

// --> Exercício 1
/*
#include <stdio.h>
#include <stdbool.h>

int main ()
{

    int num, i;
    bool primo = true;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    if (num < 2)
    {
        primo = false;
    }
    else
    {
        for (i = 2; i < num; i ++)
        {
            if (num % i == 0)
            {
                primo = false;
                break;
            }
        }
    }

    if (primo)
    {
        printf("%d é primo.\n", num);
    }
    else
    {
        printf("%d é primo.\n", num);
    }

    return 0;

}*/

// --> Exercício 2 
/*
#include <stdio.h>

int main()
{

    int num, cont = 0, maior, menor, primeiro = 1;
    

    printf("Digite um número inteiro (0 para parar): ");
    scanf("%i", &num);

    while (num != 0)
    {

        if (primeiro)
        {
            maior = num;
            menor = num;
            primeiro = 0;
        }
        else
        {
            if (num > maior)
            {
                maior = num;
            }
            if (num < menor)
            {
                menor = num;
            }
        }

        cont ++;

        printf("Digite um número inteiro (0 para parar): ");
        scanf("%d", &num);


    }

    if (cont > 0)
    {
        printf("\nO maior número digitado foi %d.", maior);
        printf("\nO menor número digitado foi %d.", menor);
        printf("\nA quantidade de números digitados foi %d.", cont);
    }
    else
    {
        printf("\nNenhum número foi digitado.");
    }
    return 0;

}*/


// --> Exercício 3
/*
#include <stdio.h>

int main ()
{

    int num, fatorial, i;

    printf("Digite um número inteiro (número negativo para sair): ");
    scanf("%d", &num);
    
    if (num < 0)
    {
        printf("Número negativo digitado.\nFim do programa.");
    }
    else
    {
        while (num > 0)
        {
            fatorial = 1;

            for (i=num; i > 0; i --)
            {
                fatorial *= i;
            }

            printf("O fatorial de %d é %d\n", num, fatorial);

            printf("Digite um número inteiro (número negativo para sair): ");
            scanf("%d", &num);

        }
    }

    return 0;

}*/

// --> Exerício 4 
/*
#include <stdio.h>

int main()
{

    int senha = 123, tentativa, cont=0, max_tent = 3;

    while (cont < max_tent)
    {
        
        printf("Digite uma senha de três dígitos: ");
        scanf("%d", &tentativa);

        if (senha == tentativa)
        {
            printf("\nAcesso liberado.");
            break;
        }
        else
        {
            cont +=1;
            if (cont == max_tent)
            {
                printf("\nLimite máximo de tentativas excedido. Usuário bloqueado.");
            }
            else
            {
                printf("Acesso negado, tente novamente.\n");
            }
        }
        

    }

    return 0;

}*/

// --> Exercício 5

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