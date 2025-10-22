// PONTEIROS

//1
/*#include <stdio.h>

int main(){
    int var1 = 10, var2 = 20, aux;
    int *pt1, *pt2;

    pt1=&var1;
    pt2=&var2;

    aux = *pt1;
    *pt1 = *pt2;
    *pt2 = aux;

    printf("Var1: %d\n", var1);
    printf("Var2: %d\n", var2);
    printf("Ponteiro 1: %d\n", *pt1);
    printf("Ponteiro 2: %d\n", *pt2);

    return 0;
}*/

//2
/*#include <stdio.h>

int main(){
    int var1=10, var2=20;
    int *pt1, *pt2;

    pt1=&var1;
    pt2=&var2;

    int var3= *pt1 + *pt2;

    printf("Var1: %d\n", var1);
    printf("Var2: %d\n", var2);
    printf("Var3: %d\n", var3);
    printf("Ponteiro 1: %d\n", *pt1);
    printf("Ponteiro 2: %d\n", *pt2);

    return 0;
}*/

//3
/*#include <stdio.h>

int main(){
    double var1=10, var2=20, *pt1, *pt2;

    pt1=&var1;
    pt2=&var2;

    double var3 = *pt1 * *pt2;

    pt2=&var3;

    *pt2 = *pt2/2;

    printf("Var1: %.2lf\n", var1);
    printf("Var2: %.2lf\n", var2);
    printf("Var3: %.2lf\n", var3);
    printf("Ponteiro 1: %.2lf\n", *pt1);
    printf("Ponteiro 2: %.2lf\n", *pt2);

    return 0;
}*/

//4
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

    printf("Var1: %d\n", var1);
    printf("Var2: %d\n", var2);
    printf("Var3: %d\n", var3);
    printf("Ponteiro 1: %d\n", *pt1);
    printf("Ponteiro 2: %d\n", *pt2);
    printf("Ponteiro 3: %d\n", *pt3);

    return 0;
}*/

//5
/*Baseado no ‘int a’, responda para cada item se está certo ou errado. Caso esteja errado, diga o porque.
int a = 3;
a) int *p = a; --> errado
b) int *p = &a; --> certo
c) int *p = *a; --> errado
d) Para alterar o valor apontado por um ponteiro ‘p’ para 4, fazemos “p = 4”? --> errado
e) Para alterar o valor apontado por um ponteiro ‘p’ para 4, fazemos “&p = 4”? --> errado
f) Para alterar o valor apontado por um ponteiro ‘p’ para 4, fazemos “*p = 4”? --> errado */

//6
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

//7
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

//8
/*#include <stdio.h>

int Soma(int a, int *b){

    return (a + *b);

}

int main(){

    int num1 = 3, num2 = 4;
    int *p = &num2;
    int s = Soma(*p, &num1);
    printf("soma = %d", s);
    return 0;

}*/

// STRUCTS

//1
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
    int idade;
} Pessoa;

void print(Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
}

int main(){
    Pessoa p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    print(p);

    return 0;
}*/

//2
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
    int idade;
} Pessoa;

void print(const Pessoa *p){
    printf("Nome: %s ", p->nome);
    printf("Idade: %d", p->idade);
}

int main(){
    Pessoa p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    print(&p);

    return 0;    
}*/

//3
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

void comparar(Pessoa p1, Pessoa p2){
    if (p1.idade > p2.idade) printf("%s é mais velha que %s", p1.nome, p2.nome);
    else printf("%s é mais velha que %s", p2.nome, p1.nome);
}

int main(){
    Pessoa p1, p2;

    printf("Nome P1: ");
    scanf(" %[^\n]", p1.nome);
    printf("Idade p1: ");
    scanf("%d", &p1.idade);

    printf("Nome P2: ");
    scanf(" %[^\n]", p2.nome);
    printf("Idade p2: ");
    scanf("%d", &p2.idade);

    comparar(p1, p2);

    return 0;
}*/

//4
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
    int idade;
} Pessoa;

int retorno(Pessoa p){
    return (printf("\n\nNome: %s, Idade: %d", p.nome, p.idade));
}

int main(){
    Pessoa p;

    printf("Inserir nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Inserir idade: ");
    scanf("%d", &p.idade);

    retorno(p);

    return 0;
}*/

//5
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool maior = true;

typedef struct 
{
    char nome[50];
    int idade;
} Pessoa;

bool comparacao(Pessoa p){
    if (p.idade >= 18) return (maior=true);
    else return (maior=false);
}

int main(){
    Pessoa p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    int resultado = comparacao(p);

    if (resultado == true) printf("Retorno True");
    else printf("Retorno False");

    return 0;
}*/

//6
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
} Pessoa;

void print_vec(Pessoa vec[], int sz){
    for (int i=0; i<sz; i++){
        printf("Nome: %s\n", vec[i].nome);
    }
}

int main(){
    int qtd;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &qtd);

    Pessoa vec[qtd];

    for(int i=0; i<qtd; i++){
        printf("Inserir Nome: ");
        scanf(" %[^\n]", vec[i].nome);
    }

    print_vec(vec, qtd);

    return 0;
}*/

//7
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
} Pessoa;

int buscar_nome(Pessoa vec[], const char *nome, int sz){
    for (int i=0; i<sz; i++){
        if (strcmp(vec[i].nome, nome) == 0) return i;
    }
    return -1;
}

int main(){
    int sz;

    printf("SZ vec: ");
    scanf("%d", &sz);

    Pessoa vec[sz];

    for (int i = 0; i < sz; i++) {
        printf("Inserir nome no vec: ");
        scanf(" %[^\n]", vec[i].nome);

        for (int j = 0; vec[i].nome[j] != '\0'; j++) {
            vec[i].nome[j] = toupper(vec[i].nome[j]);
        }
    }

    char buscar[50];
    printf("Buscar: ");
    scanf(" %[^\n]", buscar);

    for (int i=0; buscar[i] != '\0'; i++){
        buscar[i] = toupper(buscar[i]);
    }

    int resultado = buscar_nome(vec, buscar, sz);

    if(resultado == -1) printf("Pessoa não encontrada (retorno %d)", resultado);
    else printf("Pessoa encontrada no índice: %d", resultado);

    return 0;
}*/

//8
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
    int idade;
} Pessoa;

int mais_velha(Pessoa vec[], int sz){
    int velha = vec[0].idade;
    int index = 0;

    for(int i=0; i<sz; i++){
        if(vec[i].idade > velha){
            velha = vec[i].idade;
            index = i;
        }
    }

    return (index);
}

int main(){
    int sz;

    printf("Sz: ");
    scanf("%d", &sz);

    Pessoa vec[sz];

    for (int i=0; i<sz; i++){
        printf("Inserir nome pessoa %d: ", i);
        scanf(" %[^\n]", vec[i].nome);

        printf("Inserir idade pessoa %d: ", i);
        scanf("%d", &vec[i].idade);
    }

    int resultado = mais_velha(vec, sz);

    printf("A pessoa mais velha é %s e a sua idade é %d", vec[resultado].nome, vec[resultado].idade);

    return 0;
}*/

//9
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
} Pessoa;

void ordenar(Pessoa vec[], int sz){
    int i, j;
    for (i=0; i<sz-1; i++){
        for(j=0; j<sz-i-1; j++){
            if (strcmp(vec[j].nome, vec[j+1].nome)>0){
                Pessoa temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

int main(){
    int sz;

    printf("SZ: ");
    scanf("%d", &sz);

    Pessoa vec[sz];

    for(int i=0; i<sz; i++){
        printf("Nome[%d]: ", i);
        scanf(" %[^\n]", vec[i].nome);
    }

    ordenado = ordenar(vec, sz);

    printf("Nomes ordenados:\n");
    for(int i=0; i<sz; i++){
        printf("%s ", vec[i].nome);
    }

    return 0;
}*/

//10
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
    float n1, n2, n3;
} Aluno;

void ler(Aluno *a){
    printf("Nome: ");
    scanf(" %[^\n]", a->nome);
    printf("\n");

    printf("Nota 1: ");
    scanf("%f", &a->n1);
    printf("\n");

    printf("Nota 2: ");
    scanf("%f", &a->n2);
    printf("\n");

    printf("Nota 3: ");
    scanf("%f", &a->n3);
    printf("\n");
}

float media(Aluno a){
    return ((a.n1 + a.n2 + a.n3)/3);
}

int aprovado(Aluno a){
    float resultado_media = media(a);
    return (resultado_media >= 6.0);
}

int main(){
    Aluno a;

    ler(&a);

    float media_calculada = media(a);
    printf("Média: %.2f\n", media_calculada);

    if(aprovado(a)) printf("Aprovado");
    else printf("Não aprovado");

    return 0;
}*/

//11
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[50];
    float n1, n2, n3;
} Aluno;

typedef struct 
{
    Aluno aluno[30];
    int quantidade;
} Turma;

float calcular_media(Aluno a){
    return ((a.n1 + a.n2 + a.n3) / 3);
}

int melhores_alunos (Turma turma, Aluno melhores[]){
    float maior_media = -1.0;
    int cont=0;

    for (int i=0; i<turma.quantidade; i++){
        float media = calcular_media(turma.aluno[i]);

        if (media > maior_media){
            maior_media = media;
            cont=0;
            melhores[cont++] = turma.aluno[i];
        }
        else if (media == maior_media) {
            melhores[cont++] = turma.aluno[i];
        }
    }

    return cont;
}

int main (){
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
        scanf(" %[^\n]", turma.aluno[i].nome);
        printf("Nota 1: ");
        scanf("%f", &turma.aluno[i].n1);
        printf("Nota 2: ");
        scanf("%f", &turma.aluno[i].n2);
        printf("Nota 3: ");
        scanf("%f", &turma.aluno[i].n3);
    }

    Aluno melhores[30];
    int qtdMelhores = melhores_alunos(turma, melhores);

    printf("\nMelhor(es) aluno(s):\n");
    for (int i = 0; i < qtdMelhores; i++) {
        printf("%s - Media: %.2f\n", melhores[i].nome, calcular_media(melhores[i]));
    }

    return 0;
}*/

//12
/*#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    int cod;
    char nome[50];
    float preco;
    int qtd;
} Produto;

typedef struct 
{
    Produto produtos[100];
    int qtd;
} Loja;

void cadastrar(Loja *loja){
    printf("Quantos produtos deseja cadastrar: ");
    scanf("%d", &loja->qtd);

    if (loja->qtd > 100){
        printf("QTD Excedida");
        loja->qtd=100;
    }

    for(int i=0; i<loja->qtd; i++){
        printf("Produto[%d]:\n", i);
        printf("Código: ");
        scanf("%d", &loja->produtos[i].cod);

        printf("Nome: ");
        scanf(" %[^\n]", loja->produtos[i].nome);

        printf("Preço: R$ ");
        scanf("%f", &loja->produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &loja->produtos[i].qtd);
    }   
}

int buscar(Loja loja, int cod){
    for(int i=0; i<loja.qtd; i++){
        if(loja.produtos[i].cod == cod){
            return i;
        }
    }
    return -1;
}

void atualizar(Loja *loja, int codigo, int novaQuantidade) {
    int indice = buscar(*loja, codigo);
    if (indice != -1) {
        loja->produtos[indice].qtd = novaQuantidade;
        printf("Quantidade atualizada com sucesso!\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

int main() {
    Loja minhaLoja;
    cadastrar(&minhaLoja);

    int codigoBusca;
    printf("\nDigite o código do produto para buscar: ");
    scanf("%d", &codigoBusca);

    int indice = buscar(minhaLoja, codigoBusca);
    if (indice != -1) {
        Produto p = minhaLoja.produtos[indice];
        printf("Produto encontrado: %s - Preço: %.2f - Quantidade: %d\n",
               p.nome, p.preco, p.qtd);
    } else {
        printf("Produto nao encontrado.\n");
    }

    int novaQtd;
    printf("\nDigite nova quantidade para atualizar (produto %d): ", codigoBusca);
    scanf("%d", &novaQtd);
    atualizar(&minhaLoja, codigoBusca, novaQtd);

    indice = buscar(minhaLoja, codigoBusca);
    if (indice != -1) {
        Produto p = minhaLoja.produtos[indice];
        printf("Produto atualizado: %s - Preço: %.2f - Quantidade: %d\n",
               p.nome, p.preco, p.qtd);
    }

    return 0;
}*/