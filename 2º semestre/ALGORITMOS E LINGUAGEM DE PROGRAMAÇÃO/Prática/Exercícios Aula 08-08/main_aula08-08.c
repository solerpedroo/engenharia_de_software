// Exercício 1 
/*
#include <stdio.h>

int main()
{
    int a=5, b=13, aux;
    
    aux = a;
    a = b;
    b = aux;
    
    printf("O swap ficou B: %i", b);
    printf("\nO swap ficou A: %i", a);

    return 0;
}
*/

// Exercício 2
/*
#include <stdio.h>

int main()
{
    int segundos, minutos, horas;
    

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &segundos);
    
    minutos = segundos / 60;
    horas = minutos / 60;
    
    printf("\nA quantidade de segundos digitas: %i", segundos);
    printf("\nA quantidade de minutos convertidos de segundos: %i", minutos);
    printf("\nA quantidade de horas convertidos de segundos: %i", horas);
    

    return 0;
}
*/

// Exercício 3
/*
#include <stdio.h>

int main()
{
    double salario_inicial, porcentagem, salario_ajustado;

    printf("Digite o seu salário atual: R$ ");
    scanf("%lf", &salario_inicial);
    
    printf("Digite o percentual de aumento do seu salário: ");
    scanf("%lf", &porcentagem);
    
    salario_ajustado = salario_inicial * (1 + porcentagem / 100);
    
    printf("\nO salário corrigido com a porcentagem informada é igual a : R$ %.2lf", salario_ajustado);

    return 0;
}
*/

// Exercício 4
/*
#include <stdio.h>

int main()
{
    double peso, altura, imc;
    
    printf("Digite o peso em KG: ");
    scanf("%lf", &peso);
    
    printf("Digite a altura em metros: ");
    scanf("%lf", &altura);
    
    imc = peso / (altura * altura);
    
    printf("\nO IMC de acordo com o peso e altura informada é igual a: %.2lf", imc);

    return 0;
}
    */

/*Escreva um programa em C que leia a base e a altura de um retângulo (em metros) e calcule:

A área do retângulo

O perímetro do retângulo
Mostre os resultados com duas casas decimais.*/

/*
#include <stdio.h>

int main(){

    double base, altura, area, perimetro;

    printf("Digite a base do retângulo em metros: ");
    scanf("%lf", &base);

    printf("Digite a altura do retângulo: ");
    scanf("%lf", &altura);

    area = base * altura;
    perimetro = 2 * (base + altura);

    printf("\nO perímetro do retângulo é: %.2lf m²", perimetro);
    printf("\nA área do retângulo é: %.2lf m²", area);

    return 0;

}*/

/*
Escreva um programa em C que leia uma temperatura em graus Celsius e converta para Fahrenheit usando a fórmula:

𝐹=(𝐶×9/5)+32
Mostre o resultado com duas casas decimais.

#include <stdio.h>

int main(){
    double celsius, fahrenheit;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("A temperatura convertida para Fahrenheit é: %.2lfº F", fahrenheit);

    return 0;
}*/