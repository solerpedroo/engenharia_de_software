// Exercício 1

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main(){
    
    int cont=0, i;
    char c, texto[20];

    printf("Digite a letra para verificar: ");
    scanf(" %c", &c);

    c = tolower(c);

    printf("Digite o texto para analisar (max 20): ");
    scanf(" %[^\n]", texto);

    for (i=0; i<20; i++){
        texto[i] = tolower(texto[i]);

        if (c == texto[i]){
            cont ++;
        }
    }

    printf("A quantidade de vezes que o caractere: %c apareceu foi: %d", c, cont);

    return 0;

}*/

// Exercício 2

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main(){

    int i, qtd_letras=0;
    char normal[11], invertida[11];

    printf("Digite uma string (max 10): ");
    scanf(" %[^\n]", normal);

    qtd_letras = strlen(normal);

    for (i=0; i<qtd_letras; i++){
        invertida[i] = normal[qtd_letras-1-i];
    }

    invertida[qtd_letras] = '\0';

    printf("A string normal é %s\n", normal);
    printf("A string invertida é %s\n", invertida);

    return 0;
}*/

// Exercício 3

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main(){

    int i, qtd_letras=0;
    char normal[11], invertida[11];

    printf("Digite uma string (max 10): ");
    scanf(" %[^\n]", normal);

    qtd_letras = strlen(normal);

    for (i=0; i<qtd_letras; i++){
        invertida[i] = normal[qtd_letras-1-i];
    }

    invertida[qtd_letras] = '\0';
    
    int resultado = strcmp(normal, invertida);

    if (resultado == 0){
        printf("É um palindromo");
    }
    else{
        printf("Não é um palindromo");
    }

    return 0;
}*/

// Exercício 4

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main(){

    char nome[100], sobrenome[100], completo[100];
    int tamanho;

    printf("Digite o seu nome: ");
    scanf(" %[^\n]", nome);

    printf("Digite o seu sobre nome: ");
    scanf(" %[^\n]", sobrenome);

    strcpy(completo, nome);
    strcat(completo, " ");
    strcat(completo, sobrenome);    

    tamanho = strlen(completo);

    completo[tamanho] = '\0';

    printf("O nome completo é: %s\n", completo);
    printf("O seu tamanho contando os espaços é: %d\n", tamanho);
    printf("A primeira letra é %c, a última letra é %c", completo[0], completo[tamanho-1]);

    return 0;

}*/

// Exercício 5

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main(){

    char nome_completo[100];
    int i, tamanho=0;

    printf("Digite o seu nome completo: ");
    scanf(" %[^\n]", nome_completo);

    printf("%c", toupper(nome_completo[0]));

    tamanho=strlen(nome_completo);

    for (i=0; i<tamanho; i++){
        if (nome_completo[i] == ' '){
            printf("%c", toupper(nome_completo[i+1]));
        }
    }

    return 0;
}*/

// Exercício 6

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main(){

    int i, tamanho=0, cont_vogal=0, cont_consoante=0;
    char string[21];

    printf("Digite uma string (max20): ");
    scanf(" %[^\n]", string);

    tamanho = strlen(string);

    for(i=0; i<tamanho; i++){
        string[i] = toupper(string[i]);
        if (string[i] == 'A' || string[i] == 'E' || string[i] =='I' || string[i] == 'O' || string[i] == 'U'){
            cont_vogal ++;
        }
        else{
            cont_consoante ++;
        }
    }

    printf("QTD Vogais: %d\n", cont_vogal);
    printf("QTD Consoantes: %d", cont_consoante);

    return 0;

}*/

// Exercício 7

/*#include <stdio.h>  
#include <ctype.h>
#include <string.h>

int main(){

    int i, tamanho=0;
    char txt[100];

    printf("Digite uma string (max99): ");
    scanf(" %[^\n]", txt);

    tamanho = strlen(txt);

    for (i=0; i<tamanho; i++){
        if (txt[i] == ' '){
            printf("\n");
        }
        else{
            printf("%c", txt[i]);
        }
    }

    return 0;

}*/