// Exercício 1

/*#include <stdio.h>

int main (){

    int var1=10, var2=20, temp;
    int *pt1;
    int *pt2;

    pt1 = &var1;
    pt2 = &var2;

    temp = *pt1;
    *pt1 = *pt2;
    *pt2 = temp;

    printf("\nValor de Var1 = %d", var1);
    printf("\nValor de Var2 = %d", var2);
    printf("\nValor guardado ponteiro 1= %d\n", *pt1);
    printf("\nValor guardado ponteiro 2= %d\n", *pt2);

    return 0;

}*/

// Exercício 2

/*#include <stdio.h>

int main (){

    int var1=10, var2=20;
    int *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    int var3 = *pt1 + *pt2;

    pt1 = &var3;

    *pt1 = 40;

    printf("\nValor de Var1 = %d", var1);
    printf("\nValor de Var2 = %d", var2);
    printf("\nValor de Var3 = %d", var3);    
    printf("\nValor guardado ponteiro 1= %d", *pt1);
    printf("\nValor guardado ponteiro 2= %d\n", *pt2);

    return 0;

}*/

// Exercício 3

/*#include <stdio.h>

int main (){

    double var1=22, var2=33;
    double *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    double var3 = *pt1 * *pt2;

    pt2 = &var3;
    *pt2 = *pt2 / 2;

    printf("\nValor de Var1 = %lf", var1);
    printf("\nValor de Var2 = %lf", var2);
    printf("\nValor guardado ponteiro 1= %lf", *pt1);
    printf("\nValor guardado ponteiro 2= %lf\n", *pt2);

    return 0;

}*/

// Exercício 4

/*#include <stdio.h>

int main (){

    int num1=10, num2=20, num3=30;
    int *pt1, *pt2, *pt3;

    pt1 = &num1;
    pt2 = &num2;
    pt3 = &num3;

    *pt1 = 40;

    pt1 = pt2;
    *pt1 = 50;

    pt1 = pt3; 
    *pt1 = 60;

    printf("\nValor de num1= %d", num1);
    printf("\nValor de num2= %d", num2);
    printf("\nValor de num3= %d", num3);

    return 0;

}*/

// Exercício 5

/*

Baseado no ‘int a’, responda para cada item se está certo ou errado. Caso esteja errado, diga o porque.
int a = 3;
a) int *p = a;
R: errado, está tentando guardar um valor inteiro em um ponteito, porém há a falta do & comercial na variável a, pois p é um ponteiro.

b) int *p = &a;
R: certo.

c) int *p = *a;
R: errado, ao invés de * deve se usar o & para atribuir a variável a para o ponteiro p, pois a é um valor inteiro e não um ponteiro.

d) Para alterar o valor apontado por um ponteiro ‘p’ para 4, fazemos “p = 4”?
R: errado, para alterar o valor apontado por um ponteiro deve se usar o * antes do nome do ponteiro declarado, neste contexto está tentando fazer o ponteiro apontar para a posiçãoo de endereço 4 da memória.

e) Para alterar o valor apontado por um ponteiro ‘p’ para 4, fazemos “&p = 4”?
R: errado, para alterar o valor apontado por um ponteiro deve se usar o * antes do nome do ponteiro declarado.

f) Para alterar o valor apontado por um ponteiro ‘p’ para 4, fazemos “*p = 4”?
R: certo.

*/

// Exercício 6

/*#include <stdio.h>

int Soma(int a, int *b){

    return (a + *b);

}

int main(){

    int num1 = 3, num2 = 4;
    int s = Soma(num1, &num2);
    printf("soma = %d", s);
    return 0;

}*/

// Exercício 7 

/*#include <stdio.h>

int Soma(int a, int *b){
    
    return (a + *b);

}

int main(){

    int num1 = 3, num2 = 4;
    int *p = &num2;
    int s = Soma(num1, p);
    printf("soma = %d", s);
    return 0;

}*/

// Exercício 8
#include <stdio.h>

int Soma(int a, int *b){

    return (a + *b);

}

int main(){

    int num1 = 3, num2 = 4;
    int *p = &num2;
    int s = Soma(*p, &num1);
    printf("soma = %d", s);
    return 0;

}
