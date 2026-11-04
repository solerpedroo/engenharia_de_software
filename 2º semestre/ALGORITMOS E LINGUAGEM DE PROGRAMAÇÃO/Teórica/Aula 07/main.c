// Exercício 1

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main (){

    int i, cont=0;
    char c, text[21];
    
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    c = toupper(c);

    printf("Digite um texto (máximo 20 caracteres): ");
    scanf(" %[^\n]", text);

    for (i=0; text[i] != '\0'; i++){

        text[i] = toupper(text[i]);

        if (c == text[i]){
            cont++;
        }
    }

    printf("A quantidade de vezes digitada foi: %d", cont);

    return 0;

}*/

// Exercício 2

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main (){

    int i, qtd_letras;
    char x[11], y[11];

    printf("Digite o texto que você quer (máx 10 caracteres): ");
    scanf(" %[^\n]", x);

    qtd_letras = strlen(x);

    for (i=0; x[i] != '\0'; i++){
        y[i] = x[qtd_letras - 1 - i];
    }

    printf("\nString original: %s\n", x);
    printf("\nString invertida: %s\n", y);

    return 0;

}*/

// Exercício 3

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main (){

    int i, qtd_letras;
    char x[11], y[11];

    printf("Digite o texto que você quer (máx 10 caracteres): ");
    scanf(" %[^\n]", x);

    qtd_letras = strlen(x);

    for (i=0; x[i] != '\0'; i++){
        y[i] = x[qtd_letras - 1 - i];
    }

    y[qtd_letras] = '\0';

    int resultado = strcmp(x, y);
    if (resultado == 0){
        printf("A string é um palíndromo");
    }
    else{
        printf("A string não é um palíndromo");
    }

    return 0;
}*/

// Exercício 4

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main (){

    char nome[100], sobrenome[100], nome_completo[100];
    int tamanho;

    printf("Digite seu nome: ");
    scanf(" %[^\n]", nome);

    printf("Digite seu sobrenome: ");
    scanf(" %[^\n]", sobrenome);

    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome);


    tamanho = strlen(nome_completo);

    printf("\nO nome completo é: %s\n", nome_completo);
    printf("\nO tamanho dela é: %d\n", tamanho);
    printf("\nA primeira letra é %c, a ultima letra é %c\n", nome_completo[0], nome_completo[tamanho-1]);

    return 0;

}*/

// Exercício 5

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main (){

    char nome[101];
    int i;

    printf("Digite o nome completo: ");
    scanf(" %[^\n]", nome);

    printf("\n%c", toupper(nome[0]));

    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == ' ') {
            printf("%c", toupper(nome[i+1]));
        }
    }

    return 0;
}*/

// Exercício 6

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main (){

    int cont_vogal=0, cont_consoante=0, i;
    char texto[100];

    printf("Digite a palavra que você quer verificar: ");
    scanf(" %[^\n]", texto);

    for (i=0; texto[i] != '\0'; i++){

        texto[i] = tolower(texto[i]);

        if (isalpha(texto[i])){
            if (texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
                cont_vogal++;
            }
            else{
                cont_consoante ++;
            }
        }

    }

    printf("\nA palavra digitada foi: %s\n", texto);
    printf("\nA quantidade de vogais é: %d\n", cont_vogal);
    printf("\nA quantidade de consoantes é: %d\n", cont_consoante);

    return 0;

}*/

// Exercício 7

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main (){

    char texto[100];
    int i;

    printf("Digite um texto: ");
    scanf(" %[^\n]", texto);

    for (i=0; texto[i] != '\0'; i++){

        if (texto[i] == ' '){
            printf("\n");
        }
        else{
            printf("%c", texto[i]);
        }

    }

    return 0;
}*/