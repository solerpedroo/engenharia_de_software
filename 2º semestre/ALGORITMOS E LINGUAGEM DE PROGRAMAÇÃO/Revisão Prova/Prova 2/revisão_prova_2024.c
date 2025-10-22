/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int codigo;
    char nome[50];
    float salario;
    int idade;
} Funcionario;

Funcionario funcionario[100];
int sz=0;

void cadastrar(){
    printf("Cadastro de Funcionários:\n\n");
    
    if (sz >= 100){
        printf("Limite atingido\n"); 
        return;
    }   
    else{
        printf("===> FUNCIONÁRIO [%d] <===\n", sz+1);
        
        printf("Código: ");
        scanf("%d", &funcionario[sz].codigo);
        
        printf("Nome: ");
        scanf(" %[^\n]", funcionario[sz].nome);

        printf("Salário: R$ ");
        scanf("%f", &funcionario[sz].salario);

        printf("Idade: ");
        scanf("%d", &funcionario[sz].idade);

        sz++;
        printf("\nFuncionário cadastrado com sucesso");

    }
}

void exibir(){
    int i;
    printf("===> FUNCIONÁRIOS CADASTRADOS <===\n");

    if (sz == 0) printf("Nenhum funcionário cadastrado");

    else{
        for(i=0; i<sz; i++){
            printf("Funcionário [%d]\n",i+1);

            printf("Código: %d\n", funcionario[i].codigo);
            printf("Nome: %s\n", funcionario[i].nome);
            printf("Salário: R$ %.2f\n", funcionario[i].salario);
            printf("Idade: %d\n", funcionario[i].idade);

            printf("\n\n");
        }
    }   
}

void aumentar_salario(){
    int id;
    float percentual;

    printf("Digite o código do funcionário: ");
    scanf("%d", &id);

    printf("Digite o percentual para aumentar: ");
    scanf("%f", &percentual);

    for(int i=0; i<sz; i++){
        if(id == funcionario[i].codigo){
            funcionario[i].salario = funcionario[i].salario + (funcionario[i].salario * (percentual/100));
            printf("\nSalário atualizado, novo valor R$ %.2f", funcionario[i].salario);
            return;
        }
    }
    printf("ID não encontrado\n"); 
}

void salario_filtrado(){
    float buscar_salario;

    printf("Digite o salário para buscar: ");
    scanf("%f", &buscar_salario);

    int encontrado = 0;
    for(int i=0; i<sz; i++){
        if (funcionario[i].salario >= buscar_salario){
            printf("Nome: %s\n", funcionario[i].nome);
            printf("Salário: R$ %.2f\n", funcionario[i].salario);
            encontrado = 1;
        }
    }
    if(encontrado == 0) printf("Nenhum funcionário com salário igual ou superior a este\n");
}

void media(){
    float soma=0;

    if (sz==0){ 
        printf("Nenhum funcionário cadastrado ainda\n"); 
        return;
    }
    
    else{
        for(int i=0; i<sz; i++){
            soma += funcionario[i].salario;
        }
        printf("A média salarial da empresa é de R$ %.2f\n", soma/sz);
    }
}

int main(){
    int opc;

    do
    {
        printf("\n==> SISTEMA DE GERENCIAMENTO DE FUNCIONÁRIOS <==\n\n");
        printf("\n1. Cadastrar Funcionários\n");
        printf("2. Exibir Funcionários\n");
        printf("3. Aumentar Salário\n");
        printf("4. Exibir funcionários com determinado salário ou superior\n");
        printf("5. Média Salarial\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1: cadastrar(); break;
        case 2: exibir(); break;
        case 3: aumentar_salario(); break;
        case 4: salario_filtrado(); break;
        case 5: media(); break;
        case 6: printf("\nFim do programa...\n"); break;
        default: printf("Opção inválida..."); break;
        }
    } while (opc != 6);   
}*/