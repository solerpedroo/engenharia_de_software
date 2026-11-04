// Exercício 1

/*#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

void valorpessoa (Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
}

int main(){
    Pessoa p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    valorpessoa(p);
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

void valorpessoa (const Pessoa *p){
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
}

int main(){
    Pessoa p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    valorpessoa(&p);
    return 0;
}*/

// Exercício 3

/*#include <stdio.h>
#include <string.h>

struct PF{
    char nome[50];
    int idade;
};

int main(){
    struct PF pessoa1, pessoa2;

    strcpy(pessoa1.nome, "João");
    pessoa1.idade = 15;

    strcpy(pessoa2.nome, "Maria");
    pessoa2.idade = 16;

    if (pessoa1.idade > pessoa2.idade){
        printf("%s é mais velho que %s", pessoa1.nome, pessoa2.nome);
    }
    else{
        printf("%s é mais velho que %s", pessoa2.nome, pessoa1.nome);
    }

    return 0;
    
}*/

// Exercício 4

/*#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
};

struct Pessoa criarPessoa(){
    return (struct Pessoa){.nome = "João"};
}

int main(){
    struct Pessoa p = criarPessoa();

    printf("Nome: %s", p.nome);

    return 0;
}*/

// Exercício 5

/*#include <stdio.h>
#include <stdbool.h>

bool marcador = true;

typedef struct main
{
    int idade;
} Pessoa;

bool idade(Pessoa p){
    return p.idade >= 18;
}

int main(){
    Pessoa p;

    printf("Idade: ");
    scanf("%d", &p.idade);

    if (idade(p)){
        printf("True");
    }
    else{
        printf("False");
    }

    return 0;
}*/

// Exercício 6

/*#include <stdio.h>
#include <string.h>

struct PF{
    char nome[50];
};

void print(struct PF p){
    printf("Nome: %s\n", p.nome);
}

int main(){
    int qtd_pessoas=0, i;

    printf("Digite a quantidade de pessoas que deseja inserir as infos: ");
    scanf("%d", &qtd_pessoas);

    struct PF pessoavec[qtd_pessoas];

    for (i=0; i<qtd_pessoas; i++){
        printf("Nome: ");
        scanf(" %[^\n]", pessoavec[i].nome);
    }

    for (i=0; i<qtd_pessoas; i++){
        print(pessoavec[i]);
    }
    
    return 0;
}*/

// Exercício 7

/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char nome[50];
    int idade;
} Pessoa;

int buscarpessoa(Pessoa vec[], int tamanho, const char *nome){
    int i;
    for (i=0; i<tamanho; i++){
        if (strcmp(vec[i].nome, nome) == 0)
        return i;
    }
    return -1;
}

int main(){
    Pessoa pessoas[3]={
        {"JOAO", 20},
        {"MARIA", 22},
        {"ANA", 21}
    };

    char busca[50];
    printf("Digite um nome para procurar: ");
    scanf("%s", busca);

    int indice = buscarpessoa(pessoas, 3, busca);

    if (indice != -1){
        printf("Pessoa encontrada no índice %d (Nome: %s, idade: %d)", indice, pessoas[indice].nome, pessoas[indice].idade);
    }
    else{
        printf("Pessoa não encontrada");
    }

    return 0;
}*/

// Exercício 8

/*#include <stdio.h>
#include <string.h>

struct PF{
    char nome[50];
    int idade;
};

int main(){
    int qtd_pessoas=0, i;

    printf("QTD pessoas: ");
    scanf("%d", &qtd_pessoas);

    struct PF pessoasvec[qtd_pessoas];

    for (i=0; i<qtd_pessoas; i++){
        printf("Nome: ");
        scanf(" %[^\n]", pessoasvec[i].nome);

        printf("Idade: ");
        scanf("%d", &pessoasvec[i].idade);
    }

    int maior = pessoasvec[0].idade;
    char nome_maior[50];
    strcpy(nome_maior, pessoasvec[0].nome);

    for (i=0; i<qtd_pessoas; i++){
        if (pessoasvec[i].idade > maior){
            maior = pessoasvec[i].idade;
            strcpy(nome_maior, pessoasvec[i].nome);
        }
    }

    printf("Pessoas mais velha: %s, Idade: %d\n", nome_maior, maior);

    return 0;
}*/

// Exercício 9

/*#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void ordenarPorNome(Pessoa vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(vetor[j].nome, vetor[j + 1].nome) > 0) {
                Pessoa temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    int qtd_pessoas;

    printf("Quantidade de pessoas: ");
    scanf("%d", &qtd_pessoas);

    Pessoa pessoas[qtd_pessoas];

    for (int i = 0; i < qtd_pessoas; i++) {
        printf("Nome: ");
        scanf(" %[^\n]", pessoas[i].nome);
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
    }

    ordenarPorNome(pessoas, qtd_pessoas);

    printf("\nPessoas em ordem alfabética:\n");
    for (int i = 0; i < qtd_pessoas; i++) {
        printf("%s - %d anos\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}*/

// Exercício 10

/*#include <stdio.h>

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

void lerDados(Aluno *a) {
    printf("Nome do aluno: ");
    scanf(" %[^\n]", a->nome);

    printf("Nota 1: ");
    scanf("%f", &a->nota1);
    printf("Nota 2: ");
    scanf("%f", &a->nota2);
    printf("Nota 3: ");
    scanf("%f", &a->nota3);
}

float calcularMedia(Aluno a) {
    return (a.nota1 + a.nota2 + a.nota3) / 3.0;
}

int estaAprovado(Aluno a) {
    float media = calcularMedia(a);
    return media >= 6.0;
}

int main() {
    Aluno aluno;

    lerDados(&aluno);

    float media = calcularMedia(aluno);
    printf("\nMédia: %.2f\n", media);

    if (estaAprovado(aluno)) {
        printf("Aluno aprovado\n");
    } else {
        printf("Aluno reprovado\n");
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
