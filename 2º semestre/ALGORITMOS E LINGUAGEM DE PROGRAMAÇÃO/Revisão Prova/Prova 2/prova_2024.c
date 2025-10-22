#include <stdio.h>
#include <string.h>

struct Funcionario
{
    int id;
    char nome[50];
    float salario;
    int idade;
};

struct Funcionario funcionarios [100];
int qtd = 0;

void cadastro(){
    if (qtd >= 100){
        printf("\nLimite atingido\n");
        return;
    }
    else{
        printf("\n=== Cadastro de Funcionário ===\n");

        printf("ID: ");
        scanf("%d", &funcionarios[qtd].id);

        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[qtd].nome);

        printf("Salário: R$ ");
        scanf("%f", &funcionarios[qtd].salario);

        printf("Idade: ");
        scanf("%d", &funcionarios[qtd].idade);

        qtd ++;

        printf("\nFuncionário cadastrado com sucesso\n");
    }
}

void exibir(){
    printf("\n=== Lista de Funcionários Cadastrados ===\n");

    if (qtd == 0) printf("\nNenhum funcionário cadastrado\n");
    else{
        for (int i=0; i< qtd; i++){
            printf("\nID: %d\n", funcionarios[i].id);
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Salário: R$ %.2f\n", funcionarios[i].salario);
            printf("Idade: %d\n", funcionarios[i].idade);
            printf("\n");
        }
    }
}

void aumento(){
    int id;
    float percentual;

    printf("Digite o ID: ");
    scanf("%d", &id);
    printf("Percentual: ");
    scanf("%f", &percentual);

    for (int i=0; i<qtd; i++){
        if (funcionarios[i].id == id){
            funcionarios[i].salario = funcionarios[i].salario + (funcionarios[i].salario * (percentual/100));
            printf("\nSalário atualizado\n");
            return;
        }
    }
    printf("ID não encontrado\n");
}

void exibir_salario_filtrado(){
    float valor;

    printf("\nValor: R$ ");
    scanf("%f", &valor);

    int encontrado = 0;
    for (int i=0; i<qtd; i++){
        if (funcionarios[i].salario > valor){
            printf("\nID: %d\n", funcionarios[i].id);
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Salário: R$ %f\n", funcionarios[i].salario);
            printf("Idade: %d\n", funcionarios[i].idade);
            printf("\n");

            encontrado = 1;
        }
    }
    if (encontrado == 0) printf("\nNenhum funcionário encontrado com este filtro de salário\n");
}

void media(){
    float soma=0;

    if (qtd == 0) printf("Não há funcionários cadastrados no sistema\n");

    for (int i=0; i<qtd; i++){
        soma += funcionarios[i].salario;
    }

    printf("A média salarial é R$ %.2f", soma/qtd);
}

int main(){
    int opc;
    do
    {
        printf("\n=== Sistema de Gerenciamento ===\n");
        printf("\n1. Cadastrar Funcionário.\n");
        printf("\n2. Exibir Funcionários.\n");
        printf("\n3. Aumentar Salário.\n");
        printf("\n4. Exibir Funcionários com Salário Acima de um Valor.\n");
        printf("\n5. Média Salarial.\n");
        printf("\n6. Sair do Programa.\n");
        printf("\n\n");
        printf("Qual função deseja utilizar? ");
        scanf("%d", &opc);
        printf("\n\n");

        switch (opc)
        {
        case 1: cadastro(); break;
        case 2: exibir(); break;
        case 3: aumento(); break;
        case 4: exibir_salario_filtrado(); break;
        case 5: media(); break;
        case 6: printf("\nFim do Programa..."); break;
        default: printf("\nOpção Inválida...");
        }

    } while (opc != 6);
    
    return 0;
}