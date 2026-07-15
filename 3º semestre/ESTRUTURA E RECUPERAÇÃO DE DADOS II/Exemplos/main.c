#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


/* int main(){

//===================CRIAR PILHA E VERIFICAR SE ESTÁ VAZIA===================
    Pilha *novaPilha = criarPilha();

    if(pilhaVazia(novaPilha)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }

//=====================EMPILHAR ELEMENTOS NA PILHA===================
    empilhar(novaPilha, 10);
    empilhar(novaPilha, 20);
    empilhar(novaPilha, 30);
    empilhar(novaPilha, 40);

    imprimirPilha(novaPilha);

//=====================ACESSAR O VALOR NO TOPO DA PILHA===================
        int valorTopo;
        valorTopo = topoPilha(novaPilha);
        printf("Valor no topo da pilha: %d\n", valorTopo);

//=====================ATUALIZAR O VALOR NO TOPO DA PILHA===================
        // atualizarTopo(novaPilha, 50);
        // valorTopo = topoPilha(novaPilha);
        // printf("Valor atualizado no topo da pilha: %d\n", valorTopo);
        // imprimirPilha(novaPilha);

//======================DESEMPILHAR TODOS OS ELEMENTOS DA PILHA======================

    int valorDesempilhado;
    while(!pilhaVazia(novaPilha)) {
        desempilhar(novaPilha, &valorDesempilhado);
        printf("Valor desempilhado: %d\n", valorDesempilhado);
    }

    if(pilhaVazia(novaPilha)) {
        printf("A pilha está vazia após desempilhar todos os elementos.\n");
    } else {
        printf("A pilha não está vazia após desempilhar todos os elementos.\n");
    }

// ====================APAGAR A PILHA E LIBERAR MEMÓRIA=======
    apagarPilha(novaPilha);

return 0;

} */








// // // ======================
// // // MAIN do exercício de ler 5 números e imprimir na ordem inversa usando a pilha
// // // ======================

// int main() {
//     Pilha* pilha = criarPilha();

//     int numero;

//     printf("Digite 5 numeros inteiros:\n");

//     for (int i = 0; i < 5; i++) {
//         scanf("%d", &numero);
//         empilhar(pilha, numero);
//     }

//     printf("\nNumeros na ordem inversa:\n");

//     while (!pilhaVazia(pilha)) {
//         desempilhar(pilha, &numero);
//         printf("%d\n", numero);
//     }

//     apagarPilha(pilha);

//     return 0;
// }






// ======================
// MAIN do exercício de verificar se uma palavra é palíndromo usando a pilha
// ======================

#include <string.h>

int main() {
    Pilha* pilha = criarPilha();
    
    char palavra[100];


    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);
    int i;
    // Empilha cada caractere
    for (i = 0; i < tamanho; i++) {
        empilhar(pilha, palavra[i]);
    }

    int ehPalindromo = 1;
    int valor;
    // Compara desempilhando
    for (i = 0; i < tamanho; i++) {
        desempilhar(pilha, &valor);

        if (palavra[i] != valor) {
            ehPalindromo = 0;
            break;
        }
    }

    if (ehPalindromo)
        printf("Eh palindromo!\n");
    else
        printf("Nao eh palindromo!\n");

    apagarPilha(pilha);
    return 0;
}














