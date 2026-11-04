// Exercício 1 

/*
1) Sabendo que A=20, B=0, C=1 e D=10, informe se as expressões são Verdadeiras ou Falsas.
(A – B + D) >= (C)
(A > (A + D)) || (C > B)
((A * D) > (C + A)) && (A > B)
(((A + B) / C) >= 0,9) && ((B * D) < 0)
((A + C)/D) > 0,3) && (((B –C)<0) ) || ((C+A) > D))
(((A + C)/D) > 0,3) && ((B –C)<0) )) || ((C+A) > D)

1 - verdadeiro
2 - verdadeiro
3 - verdadeiro
4 - falso
5 - verdadeiro
6 - verdadeiro
*/


// Exercício 2
/*
#include <stdio.h>

int main()
{
    int idade;
    float peso;

    printf("Digite a sua idade: ");
    scanf("%i", &idade);

    printf("Digite o seu peso: ");
    scanf("%f", &peso);

    if ((idade >= 16 && idade <= 69) && (peso >= 50))
    {
        printf("Pessoa Apta\n");
    }
    else
    {
        printf("Pessoa não apta\n");
    }
    return 0;
}
    */

// Exercício 3
/*
#include <stdio.h>

int main()
{
    float nota; 
    
    printf("Digite a sua nota: ");
    scanf("%f", &nota);

    if (nota < 5)
    {
        printf("Nota insuficiente");
    }
    else if (nota >= 5 && nota <= 6.9)
    {
        printf("Nota regular");
    }
    else if (nota >= 6.9 && nota <= 8.9)
    {
        printf("Nota boa");
    }
    else
    {
        printf("Nota excelente");
    }

    return 0;
}*/

// Exercício 4 
/*
#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Digite o primeiro valor: ");
    scanf("%i", &a);

    printf("Digite o segundo valor: ");
    scanf("%i", &b);

    printf("Digite o terceiro valor: ");
    scanf("%i", &c);

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        printf("Triângulo válido\n");
    }
    else
    {
        printf("Triângulo inválido\n");
    }

    return 0;
}*/

// Exercício 5

#include <stdio.h>

int main()
{
    int opcao; 
    float a, b, calculo, aux;

    printf("opção 1: Soma\n");
    printf("opção 2: Subtração\n");
    printf("opção 3: Multiplicação\n");
    printf("opção 4: Divisão\n");
    printf("Digite a opção: ");
    scanf("%i", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);
        printf("Digite o segundo valor: ");
        scanf("%f", &b);
        calculo = a + b;
        printf("Soma: %.2f\n", calculo);
        break;
    
    case 2:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);
        printf("Digite o segundo valor: ");
        scanf("%f", &b);
        if (b > a)
        {   
            aux = a;
            a = b;
            b = aux;
        }
        calculo = a - b;
        printf("Subtração: %.2f\n", calculo);
        break;

    case 3:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);
        printf("Digite o segundo valor: ");
        scanf("%f", &b);
        calculo = a * b;
        printf("Multiplicação: %.2f\n", calculo);
        break;

    case 4:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);
        printf("Digite o segundo valor: ");
        scanf("%f", &b);
        if (b == 0)
        {
            printf("Erro: divisão por zero não é permitida.\n");
        }
        else
        {
            calculo = a / b;
            printf("Divisão: %.2f\n", calculo);
        }
        break;
    
    default:
        printf("Opção digitada inválida\n");
        break;
    }

    return 0;
}