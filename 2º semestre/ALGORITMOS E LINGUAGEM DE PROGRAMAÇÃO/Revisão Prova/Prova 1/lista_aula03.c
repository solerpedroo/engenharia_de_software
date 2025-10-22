// Exercício 2

/*#include <stdio.h>

int main (){

    int idade;
    double peso;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    printf("Digite o seu peso (KG): ");
    scanf("%lf", &peso);

    if ((idade >= 16 && idade <= 69) && peso >= 50){
        printf("Pessoa apta a doar sangue");
    }
    else{
        printf("Pessoa não apta a doar sangue");
    }

    return 0;

}*/

// Exercício 3

/*#include <stdio.h>

int main (){

    double nota;

    printf("Digite uma nota de 0 a 10: ");
    scanf("%lf", &nota);

    if (nota < 0 || nota > 10){
        printf("Nota digitada é inválida");
    }
    else if (nota < 5){
        printf("Insuficiente");
    }
    else if (nota < 7){
        printf("Regular");
    }
    else if (nota < 9){
        printf("Bom");
    }
    else{
        printf("Excelente");
    }

    return 0;

}*/

// Exercício 4

/*#include <stdio.h>

int main (){

    int a, b, c;

    printf("Digite o valor do primeiro lado: ");
    scanf("%d", &a);

    printf("Digite o valor do segundo lado: ");
    scanf("%d", &b);

    printf("Digite o valor do terceiro lado: ");
    scanf("%d", &c);

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

int main (){

    int escolha;
    float a, b;

    printf("==ESCOLHA A calculo NO MENU A BAIXO==\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("Digite a sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);

        printf("Digite o segundo valor: ");
        scanf("%f", &b);

        printf("\nA soma dos valores é: %.2f", a+b);
        break;
    
    case 2:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);

        printf("Digite o segundo valor: ");
        scanf("%f", &b);

        printf("A subtração é: %.2f", a-b);
        break;

    case 3:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);

        printf("Digite o segundo valor: ");
        scanf("%f", &b);

        printf("A multiplicação é: %.2f", a*b);
        break;

    case 4:
        printf("Digite o primeiro valor: ");
        scanf("%f", &a);

        printf("Digite o segundo valor: ");
        scanf("%f", &b);

        if (b==0){
            printf("Divisão por 0 não é válida");
        }
        else{
            printf("A divisão é: %.2f", a/b);
        }
        break;
    
    default:
    printf("Opção digitada inválida");
        break;
    }

    return 0;
}