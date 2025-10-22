// Exercício 1

/*#include <stdio.h>

int main (){

    int a, b, aux=0;

    printf("Digite o valor A: ");
    scanf("%d", &a);

    printf("Digite o valor B: ");
    scanf("%d", &b);

    aux = a;
    a = b;
    b = aux;
    
    printf("O SWAP fica A= %d, B= %d", a, b);

}*/

// Exercício 2

/*#include <stdio.h>

int main (){

    int horas, minutos, segundos;

    printf("Digite quantos segundos: ");
    scanf("%d", &segundos);

    minutos = segundos / 60;
    horas = minutos / 60;    
    
    printf("\nA quantidade de segundos digitas: %d", segundos); 
    printf("\nA quantidade de minutos convertidos de segundos: %d", minutos);
    printf("\nA quantidade de horas convertidos de segundos: %d", horas);

    return 0;

}*/

// Exercício 3

/*#include <stdio.h>

int main (){

    double salario_inicial, percentual, salario_final;

    printf("Digite o salário inicial: R$ ");
    scanf("%lf", &salario_inicial);

    printf("Digite o percentual de reajuste: ");
    scanf("%lf", &percentual);

    salario_final = salario_inicial * (1 + percentual / 100);

    printf("O antigo salário de R$ %.2lf, com o novo aumento percentual de %.2lf%%, foi para R$ %.2lf", salario_inicial, percentual, salario_final);

    return 0;
}*/

// Exercício 4

#include <stdio.h>

int main (){

    double peso, altura, imc;

    printf("Digite a sua altura (m): ");
    scanf("%lf", &altura);

    printf("Digite o seu peso (KG): ");
    scanf("%lf", &peso);

    imc = peso / (altura*altura);

    printf("O IMC de acordo com a altura %.2lf e o peso %.2lf é %.2lf", altura, peso, imc);

    return 0;

}