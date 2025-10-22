// Exercício 1

/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct lista_aula10
{
    char nome[50];
    int idade;
} Pessoa;

void print_pessoa(Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
}

int main(){
    Pessoa p;

    printf("Seu nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Sua idade: ");
    scanf("%d", &p.idade);

    printf("\n\n");

    print_pessoa(p);

    return 0;
}*/

// Exercício 2

/*#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

void print_pessoa(const Pessoa *p){
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
}

int main(){
    Pessoa p;

    printf("Sua idade: ");
    scanf("%d", &p.idade);
    printf("Seu nome: ");
    scanf(" %[^\n]", p.nome);

    printf("\n\n");

    print_pessoa(&p);

    return 0;
}*/

// Exercício 3

/*#include <stdio.h>
#include <string.h>

struct PF
{
    char nome[50];
    int idade;
};

int main(){
    struct PF pessoa1, pessoa2;

    strcpy(pessoa1.nome, "Maria");
    pessoa1.idade = 15;

    strcpy(pessoa2.nome, "Ana");
    pessoa2.idade = 16;

    if (pessoa1.idade > pessoa2.idade) printf("%s é mais velha que %s", pessoa1.nome, pessoa2.nome);
    else printf("%s é mais velha que %s", pessoa2.nome, pessoa1.nome);

    return 0;
}*/

// Exercício 4

/*#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
};

struct Pessoa criarPessoa(){
    return (struct Pessoa){.nome = "Pedro", .idade = 18};
}

int main(){
    struct Pessoa p = criarPessoa();

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);

    return 0;
}*/

// Exercício 5

/*#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool maior = true;

typedef struct 
{
    char nome[50];
    int idade;
} Pessoa;

bool analisar(Pessoa p){
    if (p.idade >= 18) maior = true;
    else maior = false;
    return maior;
}

int main(){
    Pessoa p;

    printf("Digite a sua idade: ");
    scanf("%d", &p.idade);
    printf("Digite o seu nome: ");
    scanf(" %[^\n]", p.nome);

    analisar(p);

    if (maior == true) printf("%s é maior de idade", p.nome);
    else printf("%s não é maior de idade", p.nome);

    return 0;
}*/

// Exercício 6

/*#include <stdio.h>
#include <string.h>

struct Pessoa 
{
    char nome[50];
};

void print_people(struct Pessoa p){
    printf("Nome: %s", p.nome);
}

int main(){
    int i, qtd=0;

    printf("Digite quantas pessoas quer colocar: ");
    scanf("%d", &qtd);

    struct Pessoa vec[qtd];

    for (i=0; i<qtd; i++){
        printf("%dº nome: ", i);
        scanf(" %[^\n]", vec[i].nome);
    }

    for (i=0; i<qtd; i++){
        printf(vec[i]);
    }
    
    return 0;
}*/

// Exercício 7

/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
} Pessoa;

int busca(Pessoa vec[], int tamanho, const char *nome){
    int i;
    for (i=0; i<tamanho; i++){
        if (strcmp(vec[i].nome, nome) == 0)
        return i;
    }
    return -1;
}

int main(){
    Pessoa pessoas[3]={
        {"PEDRO"},
        {"JOÃO"},
        {"ANA"}
    };

    char buscar[50];
    int i=0;
    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", buscar);

    while(buscar[i] != '\0'){
        buscar[i] = toupper(buscar[i]);
        i++;
    }

    int indice = busca(pessoas, 3, buscar);

    if (indice != -1){
        printf("Pessoa encontrada no índice %d (Nome: %s)", indice, pessoas[indice].nome);
    }
    else{
        printf("Pessoa não encontrada");
    }

    return 0;
}*/

// Exercício 8

/*#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
};

int main(){
    int qtd;
    printf("Digite a quantidade que quer inserir: ");
    scanf("%d", &qtd);

    struct Pessoa vec[qtd];

    int maior = vec[0].idade;
    char nome_maior[50];

    for (int i=0; i<qtd; i++){
        printf("Nome: ");
        scanf(" %[^\n]", vec[i].nome);

        printf("Idade: ");
        scanf("%d", &vec[i].idade);

    }

    for (int i=0; i<qtd; i++){
        if (vec[i].idade > maior){
            strcpy(nome_maior, vec[i].nome);
            maior = vec[i].idade;
        }
    }

    printf("\nA pessoa mais velha é: %s e a sua idade é %d", nome_maior, maior);
    
    return 0;
}*/

// Exercício 9

/*#include <string.h>
#include <stdio.h>

typedef struct 
{
    char nome[50];
} Pessoa;

void ordenar_nome(Pessoa vec[], int tamanho){
    int i, j;

    for (i=0; i<tamanho-1; i++){
        for (j=0; j<tamanho-i-1; j++){
            if (strcmp(vec[j].nome, vec[j+1].nome)>0){
                Pessoa temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

int main(){
    int qtd;

    printf("QTD de nomes para inserir: ");
    scanf("%d", &qtd);

    Pessoa vec[qtd];

    for (int i=0; i<qtd; i++){
        printf("Nome: ");
        scanf(" %[^\n]", vec[i].nome);
    }

    ordenar_nome(vec, qtd);

    printf("Nomes ordenados:\n");
    for(int i=0; i<qtd; i++){
        printf("%s", vec[i].nome);
        printf("\n");
    }

    return 0;
}*/

// Exercício 10

/*#include <stdio.h>

typedef struct 
{
    char nome[50];
    float nota1, nota2, nota3;
} Aluno;

void ler_dados(Aluno *a){
    printf("Digite os dados: \n");

    printf("Nome: ");
    scanf(" %[^\n]", a->nome);
    printf("\n");

    printf("Nota 1: ");
    scanf("%f", &a->nota1);
    printf("\n");

    printf("Nota 2: ");
    scanf("%f", &a->nota2);
    printf("\n");

    printf("Nota 3: ");
    scanf("%f", &a->nota3);
    printf("\n");
}

float calculo_media(Aluno a){
    return ((a.nota1 + a.nota2 + a.nota3) / 3);
}

int aprovado(Aluno a){
    float media = calculo_media(a);
    return media >= 6.0;
}

int main(){
    Aluno a;

    ler_dados(&a);

    float media = calculo_media(a);
    printf("Média: %.2f", media);

    if(aprovado(a)){
        printf("\nAprovado");
    }
    else{
        printf("\nNão aprovado");
    }

    return 0;
}*/

// Exercício 11

/*#include <stdio.h>

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

typedef struct {
    Aluno alunos[30];
    int quantidade;
} Turma;

float calcularMedia(Aluno a) {
    return (a.nota1 + a.nota2 + a.nota3) / 3.0;
}

int melhoresAlunos(Turma turma, Aluno melhores[]) {
    float maiorMedia = -1.0;
    int count = 0;

    for (int i = 0; i < turma.quantidade; i++) {
        float media = calcularMedia(turma.alunos[i]);

        if (media > maiorMedia) {
            maiorMedia = media;
            count = 0;
            melhores[count++] = turma.alunos[i];
        } else if (media == maiorMedia) {
            melhores[count++] = turma.alunos[i];
        }
    }

    return count;
}

int main() {
    Turma turma;
    int maxAlunos = 30;

    printf("Quantos alunos deseja cadastrar (max 30)? ");
    scanf("%d", &turma.quantidade);

    if (turma.quantidade > maxAlunos) {
        printf("Limite excedido! Cadastrando apenas 30 alunos.\n");
        turma.quantidade = maxAlunos;
    }

    for (int i = 0; i < turma.quantidade; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", turma.alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &turma.alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &turma.alunos[i].nota2);
        printf("Nota 3: ");
        scanf("%f", &turma.alunos[i].nota3);
    }

    Aluno melhores[30];
    int qtdMelhores = melhoresAlunos(turma, melhores);

    printf("\nMelhor(es) aluno(s):\n");
    for (int i = 0; i < qtdMelhores; i++) {
        printf("%s - Media: %.2f\n", melhores[i].nome, calcularMedia(melhores[i]));
    }

    return 0;
}*/

// Exercício 12

#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto produtos[100];
    int quantidade;
} Loja;

void cadastrarProdutos(Loja *loja) {
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &loja->quantidade);

    if (loja->quantidade > 100) {
        printf("Limite excedido! Serão cadastrados apenas 100 produtos.\n");
        loja->quantidade = 100;
    }

    for (int i = 0; i < loja->quantidade; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Código: ");
        scanf("%d", &loja->produtos[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", loja->produtos[i].nome);
        printf("Preço: ");
        scanf("%f", &loja->produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &loja->produtos[i].quantidade);
    }
}

int buscarProduto(Loja loja, int codigo) {
    for (int i = 0; i < loja.quantidade; i++) {
        if (loja.produtos[i].codigo == codigo) {
            return i; 
        }
    }
    return -1;
}

void atualizarQuantidade(Loja *loja, int codigo, int novaQuantidade) {
    int indice = buscarProduto(*loja, codigo);
    if (indice != -1) {
        loja->produtos[indice].quantidade = novaQuantidade;
        printf("Quantidade atualizada com sucesso!\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

int main() {
    Loja minhaLoja;
    cadastrarProdutos(&minhaLoja);

    int codigoBusca;
    printf("\nDigite o código do produto para buscar: ");
    scanf("%d", &codigoBusca);

    int indice = buscarProduto(minhaLoja, codigoBusca);
    if (indice != -1) {
        Produto p = minhaLoja.produtos[indice];
        printf("Produto encontrado: %s - Preço: %.2f - Quantidade: %d\n",
               p.nome, p.preco, p.quantidade);
    } else {
        printf("Produto nao encontrado.\n");
    }

    int novaQtd;
    printf("\nDigite nova quantidade para atualizar (produto %d): ", codigoBusca);
    scanf("%d", &novaQtd);
    atualizarQuantidade(&minhaLoja, codigoBusca, novaQtd);

    indice = buscarProduto(minhaLoja, codigoBusca);
    if (indice != -1) {
        Produto p = minhaLoja.produtos[indice];
        printf("Produto atualizado: %s - Preço: %.2f - Quantidade: %d\n",
               p.nome, p.preco, p.quantidade);
    }

    return 0;
}