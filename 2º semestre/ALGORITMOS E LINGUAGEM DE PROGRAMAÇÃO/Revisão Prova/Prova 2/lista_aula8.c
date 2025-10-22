// Exercício 1

/*#include <stdio.h>

int main(){

    int var1=10, var2=20, temp;
    int *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    temp = *pt1;
    *pt1 = *pt2;
    *pt2 = temp;

    printf("Valor var1= %d\n", var1);
    printf("Valor var2= %d\n", var2);
    printf("Valor *pt1= %d\n", *pt1);
    printf("Valor *pt2= %d\n", *pt2);

    return 0;
}*/

// Exercício 2

/*#include <stdio.h>

int main(){

    int var1=10, var2=20, var3=0;
    int *pt1, *pt2;

    pt1 = &var1;

    pt2 = &var2;

    var3=*pt1+*pt2;

    pt1 = &var3;
    *pt1 = 40;

    printf("Valor var1= %d\n", var1);
    printf("Valor var2= %d\n", var2);
    printf("Valor var3= %d\n", var3);
    printf("Valor *pt1= %d\n", *pt1);
    printf("Valor *pt2= %d\n", *pt2);    

    return 0;
}*/

// Exercício 3

/*#include <stdio.h>

int main(){

    double var1=10.1, var2=20.2, *pt1, *pt2;

    pt1 = &var1;
    pt2 = &var2;

    double var3 = *pt1 * *pt2;

    pt2 = &var3;
    *pt2 = *pt2/2;

    printf("Valor var1= %.2lf\n", var1);
    printf("Valor var2= %.2lf\n", var2);
    printf("Valor var3= %.2lf\n", var3);
    printf("Valor *pt1= %.2lf\n", *pt1);
    printf("Valor *pt2= %.2lf\n", *pt2);    

    return 0; 
}*/

// Exercício 4

/*#include <stdio.h>

int main(){

    int var1=10, var2=20, var3=30, *pt1, *pt2, *pt3;

    pt1 = &var1;
    pt2 = &var2;
    pt3 = &var3;

    *pt1 = 40;

    pt1 = pt2;
    *pt1 = 50;

    pt1 = pt3;
    *pt1 = 60;

    printf("Var1 = %d\n", var1);
    printf("Var2 = %d\n", var2);
    printf("Var3 = %d\n", var3);

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