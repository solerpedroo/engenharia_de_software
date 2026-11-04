/*
  Trabalho Final - Sistema de Gerenciamento de Biblioteca
  Aluno: Pedro Henrique Contardi Soler - 25005592
*/

#include <stdio.h>
#include <string.h>

/* 
   Estrutura que representa uma pessoa que faz empréstimos.
   O CPF é do tipo char (texto), e não int, 
   porque pode começar com zero e também pode ter traços ou pontos.
   Exemplo: "012.345.678-90" — se fosse int, o zero do começo sumiria.
*/
typedef struct {
    char nome[100];
    char cpf[15];
} Pessoa;

/*
   Estrutura do livro com as informações básicas.
   Cada livro pode ter até 50 pessoas que o pegaram emprestado.
   "cont_emprestados" conta quantos leitores estão com este livro no momento.
*/
typedef struct {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int id;
    int qtd_disponivel;           // número de exemplares disponíveis
    Pessoa emprestimos[50];       // vetor com até 50 pessoas
    int cont_emprestados;         // contador de pessoas que pegaram emprestado
} Livro;

/*
   Estrutura da biblioteca que guarda até 100 livros diferentes.
   "cont_livros" indica quantos livros já estão cadastrados.
*/
typedef struct {
    Livro livros[100];
    int cont_livros;
} Biblioteca;


/* ---------- FUNÇÕES PRINCIPAIS ---------- */

// Mostra o menu de opções do sistema
void menu() {
    printf("\n===== SISTEMA DE BIBLIOTECA =====\n");
    printf("1. Cadastrar livro\n");
    printf("2. Listar livros\n");
    printf("3. Buscar livro por ID\n");
    printf("4. Realizar empréstimo\n");
    printf("5. Devolver livro\n");
    printf("6. Remover livro\n");
    printf("0. Sair\n");
    printf("=================================\n");
}

/*
   Função que cadastra um novo livro na biblioteca.
   O usuário informa os dados do livro, e o sistema verifica:
   - Se o ID é único (não pode repetir);
   - Se a quantidade de exemplares é válida (máximo de 10).
*/
void cadastrarLivro(Biblioteca *b) {
    // verifica se já atingiu o limite de 100 livros diferentes
    if (b->cont_livros >= 100) {
        printf("Limite máximo de livros atingido.\n");
        return;
    }

    Livro novo;

    printf("Título: ");
    scanf(" %[^\n]", novo.titulo);

    printf("Autor: ");
    scanf(" %[^\n]", novo.autor);

    printf("Ano de publicação: ");
    scanf("%d", &novo.ano_publicacao);

    printf("ID do livro: ");
    scanf("%d", &novo.id);

    // Verifica se o ID já existe (laço for percorre todos os livros cadastrados)
    for (int i = 0; i < b->cont_livros; i++) {
        if (b->livros[i].id == novo.id) {
            printf("Já existe um livro com este ID!\n");
            return; // sai da função
        }
    }

    // Loop que força o usuário a inserir uma quantidade entre 1 e 10
    do {
        printf("Quantidade de exemplares (máx 10): ");
        scanf("%d", &novo.qtd_disponivel);

        if (novo.qtd_disponivel > 10 || novo.qtd_disponivel <= 0) {
            printf("O máximo de exemplares permitidos é 10 e o mínimo é 1.\n");
            printf("Por favor, insira um valor válido.\n\n");
        }
    } while (novo.qtd_disponivel > 10 || novo.qtd_disponivel <= 0);

    novo.cont_emprestados = 0; // começa com zero empréstimos

    // Adiciona o livro ao vetor da biblioteca e incrementa o contador
    b->livros[b->cont_livros] = novo;
    b->cont_livros++;

    printf("Livro cadastrado com sucesso!\n");
}

/*
   Lista todos os livros cadastrados.
   Se o contador estiver em 0, significa que não há nenhum livro ainda.
*/
void listarLivros(Biblioteca *b) {
    if (b->cont_livros == 0) {
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    printf("\n--- Lista de Livros ---\n");

    // Laço percorre todos os livros cadastrados
    for (int i = 0; i < b->cont_livros; i++) {
        Livro l = b->livros[i];
        printf("\nID: %d\nTítulo: %s\nAutor: %s\nAno: %d\nDisponíveis: %d\n",
               l.id, l.titulo, l.autor, l.ano_publicacao, l.qtd_disponivel);
    }
}

/*
   Busca um livro específico pelo ID informado.
   Mostra também os nomes das pessoas que o pegaram emprestado.
*/
void buscarLivro(Biblioteca *b) {
    int id;
    printf("Digite o ID do livro: ");
    scanf("%d", &id);

    int encontrado = 0;

    // Laço percorre todos os livros cadastrados
    for (int i = 0; i < b->cont_livros; i++) {
        if (b->livros[i].id == id) {
            Livro l = b->livros[i];
            printf("\nTítulo: %s\nAutor: %s\nAno: %d\nDisponíveis: %d\nEmprestados: %d\n",
                   l.titulo, l.autor, l.ano_publicacao, l.qtd_disponivel, l.cont_emprestados);

            // Caso existam pessoas com o livro emprestado, lista todas
            if (l.cont_emprestados > 0) {
                printf("\nPessoas com este livro emprestado:\n");
                for (int j = 0; j < l.cont_emprestados; j++) {
                    printf("- %s (CPF: %s)\n", l.emprestimos[j].nome, l.emprestimos[j].cpf);
                }
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Livro não encontrado.\n");
}

/*
   Realiza o empréstimo de um livro:
   - Diminui a quantidade disponível.
   - Adiciona a pessoa ao vetor de empréstimos.
   - Impede que a mesma pessoa pegue o mesmo livro duas vezes.
*/
void emprestarLivro(Biblioteca *b) {
    int id;
    printf("Digite o ID do livro para empréstimo: ");
    scanf("%d", &id);

    int encontrado = -1;
    // Laço busca o índice do livro com o ID informado
    for (int i = 0; i < b->cont_livros; i++) {
        if (b->livros[i].id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Livro não encontrado.\n");
        return;
    }

    Livro *l = &b->livros[encontrado];

    if (l->qtd_disponivel == 0) {
        printf("Não há exemplares disponíveis.\n");
        return;
    }

    Pessoa p;
    printf("Nome do leitor: ");
    scanf(" %[^\n]", p.nome);
    printf("CPF do leitor: ");
    scanf(" %[^\n]", p.cpf);

    // Verifica se a pessoa já pegou este livro antes
    for (int i = 0; i < l->cont_emprestados; i++) {
        if (strcmp(l->emprestimos[i].cpf, p.cpf) == 0) {
            printf("Esta pessoa já possui este livro emprestado.\n");
            return;
        }
    }

    // Registra o empréstimo e atualiza contadores
    l->emprestimos[l->cont_emprestados] = p;
    l->cont_emprestados++;
    l->qtd_disponivel--;

    printf("Empréstimo realizado com sucesso!\n");
}

/*
   Devolução de um livro:
   - Aumenta a quantidade disponível.
   - Remove o leitor da lista de empréstimos.
*/
void devolverLivro(Biblioteca *b) {
    int id;
    char cpf[15];

    printf("Digite o ID do livro a devolver: ");
    scanf("%d", &id);

    int encontrado = -1;
    for (int i = 0; i < b->cont_livros; i++) {
        if (b->livros[i].id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Livro não encontrado.\n");
        return;
    }

    Livro *l = &b->livros[encontrado];

    printf("Digite o CPF do leitor: ");
    scanf(" %[^\n]", cpf);

    // Busca o CPF dentro do vetor de pessoas que pegaram o livro
    int pos = -1;
    for (int i = 0; i < l->cont_emprestados; i++) {
        if (strcmp(l->emprestimos[i].cpf, cpf) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Nenhum empréstimo encontrado para este CPF.\n");
        return;
    }

    // "Volta" os elementos do vetor uma posição para trás
    for (int i = pos; i < l->cont_emprestados - 1; i++) {
        l->emprestimos[i] = l->emprestimos[i + 1];
    }

    // Atualiza os contadores
    l->cont_emprestados--;
    l->qtd_disponivel++;

    printf("Devolução registrada com sucesso!\n");
}

/*
   Remove um livro do sistema de forma permanente.
   Após encontrar o índice, "move" os outros livros para a esquerda,
   substituindo a posição removida.
*/
void removerLivro(Biblioteca *b) {
    int id;
    printf("Digite o ID do livro a remover: ");
    scanf("%d", &id);

    int encontrado = -1;
    for (int i = 0; i < b->cont_livros; i++) {
        if (b->livros[i].id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Livro não encontrado.\n");
        return;
    }

    // Move os livros para preencher o "espaço" deixado
    for (int i = encontrado; i < b->cont_livros - 1; i++) {
        b->livros[i] = b->livros[i + 1];
    }

    b->cont_livros--;
    printf("Livro removido com sucesso!\n");
}


/* ---------- FUNÇÃO PRINCIPAL (MAIN) ---------- */

int main() {
    Biblioteca biblioteca;
    biblioteca.cont_livros = 0;  // começa sem nenhum livro cadastrado

    int opcao;

    printf("Bem-vindo ao Sistema de Gerenciamento de Biblioteca!\n");

    // Loop principal do programa — exibe o menu até que o usuário digite 0
    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Estrutura condicional que chama a função correta
        if (opcao == 1)
            cadastrarLivro(&biblioteca);
        else if (opcao == 2)
            listarLivros(&biblioteca);
        else if (opcao == 3)
            buscarLivro(&biblioteca);
        else if (opcao == 4)
            emprestarLivro(&biblioteca);
        else if (opcao == 5)
            devolverLivro(&biblioteca);
        else if (opcao == 6)
            removerLivro(&biblioteca);
        else if (opcao == 0)
            printf("\nPrograma encerrado com sucesso.\n");
        else
            printf("Opção inválida!\n");

    } while (opcao != 0); // repete enquanto a opção for diferente de 0

    return 0;
}