# Exercícios de Análise — Banco Simulado e Dicionário de Dados

# Questão 1 — Encontrando erros em um dicionário

Você recebeu este trecho:

### Cliente

Descrição: Representa uma pessoa que realiza compras na loja.

| Nome | Tipo | Obrigatoriedade | Comentários |
|---|---|---|---|
| Código | Inteiro Único | Sim | Identifica o cliente |
| Nome | String | Sim | Nome do cliente |
| Telefone | String | Sim | Telefone do cliente |
| CPF | String | Não | CPF do cliente |

O enunciado do sistema diz:

> Todo cliente deve possuir nome e CPF. O telefone é opcional. Um cliente pode possuir mais de um telefone.

### Pergunta

Analise o dicionário e identifique todos os problemas encontrados.

Considere principalmente:

- obrigatoriedade;
- cardinalidade;
- tipo/estrutura dos dados.

---

# Questão 2 — Erro entre entidade e domínio

## Enunciado

> O sistema registra funcionários de uma empresa. Cada funcionário possui nome, matrícula, cargo e departamento. Um departamento possui vários funcionários.

## Dicionário

### Funcionário

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Nome | String | Sim |
| Matrícula | Inteiro Único | Sim |
| Cargo | String | Sim |
| Departamento | String | Sim |

### Pergunta

Existe algum problema conceitual nesse dicionário?

Analise principalmente se a modelagem representa adequadamente o domínio descrito.

---

# Questão 3 — Banco simulado inconsistente com o dicionário

## Dicionário

### Animal

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Nome | String | Sim |
| Espécie | String | Sim |
| Raça | String | Não |
| Tutor | Inteiro | Sim |

## Banco simulado

### Documento 1

```json
{
  "codigo": 1,
  "nome": "Rex",
  "especie": "Cachorro",
  "raca": null,
  "tutor": 10
}
```

### Documento 2

```json
{
  "codigo": 2,
  "nome": "Mimi",
  "especie": "Gato",
  "raca": "Siamês"
}
```

### Documento 3

```json
{
  "codigo": 3,
  "nome": "Thor",
  "especie": 15,
  "raca": "Labrador",
  "tutor": "10"
}
```

### Pergunta

Analise os três documentos.

Para cada um, determine:

- está correto ou incorreto;
- qual problema existe;
- qual regra do dicionário foi violada.

---

# Questão 4 — Banco simulado e regra de negócio

## Dicionário

### Consulta

| Nome | Tipo | Obrigatoriedade | Comentários |
|---|---|---|---|
| Código | Inteiro Único | Sim | Identificador da consulta |
| Situação | Lista lateral e estática | Sim | AGENDADA, CANCELADA, CONCLUÍDA |
| Valor | Decimal | Sim | Valor cobrado |
| Animal | Inteiro | Sim | Código do animal |

## Banco simulado

```json
{
  "codigo": 15,
  "situacao": "REALIZADA",
  "valor": -50,
  "animal": 8
}
```

### Pergunta

Identifique todos os erros possíveis nesse documento.

Classifique cada problema como:

- erro de tipo;
- erro de domínio;
- erro de regra de negócio;
- erro de valor.

---

# Questão 5 — Redundância

O dicionário possui:

### Consulta

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Animal | Inteiro | Sim |
| Veterinário | Inteiro | Sim |

### Veterinário

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Nome | String | Sim |
| Consultas | Lista de inteiros | Sim |

Um aluno justificou:

> "A lista de consultas dentro de Veterinário é necessária porque facilita descobrir quais consultas foram realizadas por cada veterinário."

### Pergunta

Você concorda ou discorda?

Justifique pensando em:

- consistência;
- duplicação de informação;
- possibilidade de obter a informação por meio de outra entidade.

---

# Questão 6 — Análise de cardinalidade

## Enunciado

> Um tutor pode possuir vários animais. Cada animal pertence obrigatoriamente a um único tutor.

## Dicionário

### Tutor

| Nome | Tipo | Obrigatoriedade | Comentários |
|---|---|---|---|
| Animais | Inteiro | Sim | Código do animal pertencente ao tutor |

### Animal

| Nome | Tipo | Obrigatoriedade | Comentários |
|---|---|---|---|
| Tutor | Inteiro | Sim | Código do tutor responsável |

### Pergunta

A modelagem está adequada?

Analise especificamente:

- a cardinalidade da relação;
- a estrutura escolhida para representar essa relação;
- se existe alguma inconsistência entre Tutor e Animal.

---

# Questão 7 — Análise de NoSQL

Um aluno afirma:

> "Como MongoDB é NoSQL e não exige schema rígido, não precisamos de dicionário de dados. Cada documento pode ter qualquer estrutura que quisermos."

### Pergunta

Analise essa afirmação.

Explique:

- se ela está correta ou incorreta;
- qual é o papel do dicionário de dados em um banco NoSQL;
- por que schema flexível não significa ausência de estrutura conceitual.

---

# Questão 8 — Dicionário × Banco Simulado

## Dicionário

### Produto

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Nome | String | Sim |
| Preço | Decimal | Sim |
| Categorias | Lista | Não |
| Estoque | Inteiro | Sim |

## Banco simulado

### Documento 1

```json
{
  "codigo": 1,
  "nome": "Teclado",
  "preco": 129.90,
  "categorias": ["Periféricos", "Informática"],
  "estoque": 20
}
```

### Documento 2

```json
{
  "codigo": 2,
  "nome": "Mouse",
  "preco": "89.90",
  "categorias": "Periféricos",
  "estoque": -5
}
```

### Pergunta

Compare os dois documentos com o dicionário e faça uma análise completa das inconsistências.

Considere:

- tipos;
- obrigatoriedade;
- estrutura;
- valores;
- regras relacionadas ao domínio.

---

# Questão 9 — Análise completa de um dicionário

## Enunciado

> Uma biblioteca possui livros e usuários. Um usuário pode realizar vários empréstimos. Cada empréstimo está associado a um único usuário e a um único livro. Um livro pode ser emprestado várias vezes ao longo do tempo, mas não pode estar emprestado para duas pessoas simultaneamente.

## Dicionário apresentado pelo aluno

### Livro

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Título | String | Sim |
| Usuário | Inteiro | Não |
| Status | String | Sim |

### Usuário

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Nome | String | Sim |
| Livros | Lista | Sim |

### Empréstimo

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Livro | Inteiro | Sim |
| Data | Data | Sim |

### Pergunta

Faça uma análise crítica completa desse dicionário.

Procure:

- entidade faltante;
- relacionamento faltante;
- atributo desnecessário;
- cardinalidade incorreta;
- informação redundante;
- regra de negócio não representada;
- problemas de obrigatoriedade.

---

# Questão 10 — Banco simulado completo

## Dicionário

### Pedido

| Nome | Tipo | Obrigatoriedade |
|---|---|---|
| Código | Inteiro Único | Sim |
| Cliente | Inteiro | Sim |
| Produtos | Lista | Sim |
| Valor Total | Decimal | Sim |
| Status | Lista lateral e estática | Sim |

## Regras

- Status: `ABERTO`, `PAGO`, `CANCELADO`
- Valor Total deve ser maior ou igual a zero.
- Todo pedido deve possuir pelo menos um produto.
- Cliente deve existir previamente.

## Banco simulado

### Documento 1

```json
{
  "codigo": 1,
  "cliente": 10,
  "produtos": [3, 5],
  "valorTotal": 250.00,
  "status": "PAGO"
}
```

### Documento 2

```json
{
  "codigo": 2,
  "cliente": 15,
  "produtos": [],
  "valorTotal": 0,
  "status": "ABERTO"
}
```

### Documento 3

```json
{
  "codigo": 3,
  "cliente": 20,
  "produtos": [8],
  "valorTotal": -50,
  "status": "FINALIZADO"
}
```

### Pergunta

Analise cada documento individualmente e determine:

1. Quais estão corretos?
2. Quais estão incorretos?
3. Qual regra foi violada?
4. O problema está no tipo, domínio, obrigatoriedade, cardinalidade, valor ou regra de negócio?

---

# Roteiro geral para resolver as questões

Use mentalmente esta sequência:

```text
ENUNCIADO
   ↓
Quais entidades existem?
   ↓
Quais atributos existem?
   ↓
Quais relações existem?
   ↓
Quais são as cardinalidades?
   ↓
Quais regras de negócio existem?
   ↓
DICTIONÁRIO
   ↓
A estrutura representa o enunciado?
   ↓
BANCO SIMULADO
   ↓
Os documentos respeitam o dicionário?
   ↓
Os valores respeitam as regras?
```

## Principais categorias de erro

```text
1. Erro de entidade
2. Erro de atributo
3. Erro de tipo
4. Erro de obrigatoriedade
5. Erro de cardinalidade
6. Erro de domínio
7. Erro de regra de negócio
8. Redundância de informação
9. Inconsistência entre dicionário e banco simulado
10. Informação importante do enunciado não representada
```
