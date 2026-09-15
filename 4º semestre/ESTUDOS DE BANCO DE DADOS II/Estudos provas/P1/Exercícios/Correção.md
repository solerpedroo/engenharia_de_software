Você fez uma análise boa, mas **cometeu alguns erros justamente nos pontos mais importantes de modelagem**. Vou corrigir questão por questão, separando o que você acertou e o que precisa ajustar.

# 1. Cliente

**Sua análise: correta.**

Você identificou os três problemas principais:

* CPF deveria ser obrigatório.
* Telefone deveria ser opcional.
* Telefone deveria permitir múltiplos valores, portanto uma `String` simples não representa corretamente a cardinalidade.

**Nota: 10/10.**

---

# 2. Funcionário

Aqui você acertou **um problema importante**, mas levantou alguns pontos que não são necessariamente erros.

### Você acertou:

> Departamento deveria ser uma referência ao departamento, e não simplesmente uma String.

Isso é uma boa análise **se o domínio realmente possui uma entidade Departamento**.

Se existir:

```text
Departamento
    Código → Inteiro Único
```

então:

```text
Funcionário
    Departamento → Inteiro
```

é uma modelagem coerente.

### Mas cuidado:

Você disse que está faltando:

> "coluna de exemplos, comentários, regras de negócio"

Isso **não é necessariamente um erro do modelo**.

O dicionário pode ter diferentes estruturas de documentação. Se o exercício exigir aquela estrutura específica, aí sim podemos considerar incompleto. Mas conceitualmente, o problema principal é a representação de `Departamento`.

Você também falou que não há descrição da entidade. Novamente: **é uma deficiência documental**, não necessariamente um erro de modelagem.

**Nota: 8/10.**

---

# 3. Banco simulado

### Documento 1

Você disse:

> "está correto"

❌ **Aqui faltou perceber um detalhe.**

O dicionário diz:

```text
Raça → String → Não obrigatória
```

O documento possui:

```json
"raca": null
```

Isso pode ser aceitável dependendo da convenção adotada para representar um atributo opcional.

Portanto, eu **aceitaria seu raciocínio**.

Mas existe uma distinção importante:

```text
atributo ausente ≠ atributo presente com null
```

Se o dicionário simplesmente diz que o campo não é obrigatório, ambas as representações podem ser possíveis, dependendo da regra definida.

### Documento 2

Você acertou:

> tutor obrigatório e ausente.

**Correto.**

### Documento 3

Você identificou:

* `especie` deveria ser String;
* `tutor` deveria ser Inteiro.

**Correto.**

Mas há um detalhe adicional:

```json
"especie": 15
```

Você chamou isso de "uma string foi colocada".

Na verdade, foi o contrário:

> **Foi colocado um inteiro onde o dicionário exige uma String.**

**Nota: 9/10.**

---

# 4. Consulta

Aqui você entrou em uma armadilha interessante.

Você disse que:

> `animal` deveria ser String livre.

❌ **Isso está errado.**

O dicionário diz:

```text
Animal → Inteiro
```

Então o documento:

```json
"animal": 8
```

está **correto quanto ao tipo**.

O `8` representa o código do animal.

Você confundiu:

> **identificação do animal**

com

> **nome/descrição do animal**.

Se `Animal` é uma referência, o inteiro é perfeitamente adequado.

---

### Situação

Você acertou:

```text
REALIZADA
```

não está entre:

```text
AGENDADA
CANCELADA
CONCLUÍDA
```

Portanto, existe **erro de domínio**.

---

### Valor

Você acertou que:

```json
"valor": -50
```

é problemático.

Porém, existe uma sutileza:

O dicionário apenas diz:

```text
Valor → Decimal
```

Ele **não estabeleceu explicitamente**:

> valor >= 0

Então você não pode dizer que o valor negativo viola o dicionário **apenas pelo tipo**.

Para dizer que é uma violação, precisamos de uma **regra de negócio** dizendo que o valor não pode ser negativo.

Isso é exatamente o que a questão queria que você identificasse.

---

### Sua crítica ao dicionário

Você disse que a falta de comentários/regras torna o dicionário superficial.

✅ Isso é uma **boa crítica documental**.

Mas não significa automaticamente que o documento JSON esteja errado.

**Nota: 7/10.**

O principal erro foi dizer que `animal` deveria ser String.

---

# 5. Redundância

Aqui você fez uma análise **muito boa**, mas com um erro conceitual importante.

Você disse:

> "não acho necessário ter o campo veterinário dentro da consulta, pois isso é uma inconsistência de N para N."

❌ **Não.**

O problema **não é ser N:N**.

Pelo cenário:

> Um veterinário pode realizar várias consultas.

E:

> Cada consulta é realizada por um veterinário.

Isso é:

```text
Veterinário 1 ─────── N Consultas
```

Ou seja:

**1:N**

Portanto, faz sentido:

```text
Consulta
    Veterinário → código
```

O que é redundante é ter **as duas direções armazenadas**:

```text
Consulta
    Veterinário → 3
```

e simultaneamente:

```text
Veterinário
    Consultas → [10, 11, 12]
```

Você acertou a **conclusão**, mas errou a justificativa da cardinalidade.

E sua observação sobre conseguir consultar as informações pelo MongoDB está correta.

**Nota: 8,5/10.**

---

# 6. Cardinalidade

Você acertou a parte principal:

> Tutor → Animais deveria permitir vários animais.

Porém:

> "deveria ser uma lista de inteiros"

⚠️ **Não necessariamente.**

Essa é uma decisão de modelagem NoSQL.

Você pode representar:

### Opção A

```text
Tutor
    Animais → [1, 2, 3]
```

### Opção B

```text
Animal
    Tutor → 10
```

E consultar os animais cujo tutor é `10`.

As duas podem representar a relação.

Para esse exercício, a questão está justamente fazendo você analisar a cardinalidade, então dizer que `Tutor → Inteiro` **não representa diretamente vários animais** está correto.

Você também percebeu corretamente a possível redundância.

**Nota: 8,5/10.**

---

# 7. NoSQL

Você acertou a essência:

> "Não é porque o MongoDB não tem schema enforcement que não precisamos de dicionário."

✅ Correto.

Mas você escreveu:

> "devido a que, como não temos um esquema definido"

⚠️ Cuidado.

NoSQL **pode ter schema**, dependendo da tecnologia e das validações utilizadas.

O MongoDB possui **flexibilidade de schema**, mas isso não significa necessariamente que todos os documentos possam ter qualquer estrutura sem controle.

Sua conclusão está correta:

> O dicionário ajuda a documentar a estrutura esperada e evitar divergências entre o que foi projetado e o que é implementado.

**Nota: 9/10.**

---

# 8. Produto

Aqui você foi bem.

### Documento 1

Você percebeu a questão de:

> categorias não especificar o tipo dos elementos.

⚠️ Essa é uma **deficiência do dicionário**, mas não necessariamente um erro do documento.

O documento:

```json
"categorias": ["Periféricos", "Informática"]
```

é perfeitamente coerente com:

```text
Categorias → Lista
```

porque os elementos são strings.

Mas o dicionário poderia ser mais preciso:

```text
Lista de Strings
```

### Documento 2

Você acertou:

```text
preco → String
```

quando deveria ser:

```text
Decimal
```

E:

```text
categorias → String
```

quando deveria ser:

```text
Lista
```

### Estoque

Você disse:

> estoque negativo devido à falta de regra.

✅ Excelente análise.

O tipo está correto:

```text
-5 → Inteiro
```

Mas existe uma possível violação de regra de negócio se estoque negativo não for permitido.

**Nota: 9/10.**

---

# 9. Biblioteca

Aqui você **perdeu o foco principal da questão**.

Você disse:

> "O enunciado não indica explicitamente quais são os atributos de um livro."

Isso é verdade.

Mas a questão não queria que você inventasse atributos como:

> ano de lançamento, autor etc.

Você deve analisar **somente o que o domínio permite concluir**.

O problema principal era outro.

### Entidade faltante

Existe uma entidade implícita:

```text
Empréstimo
```

Ela já aparece no dicionário, então não está faltando como entidade.

### Problema principal

O empréstimo precisa saber:

```text
Livro
Usuário
Data
```

Mas atualmente possui apenas:

```text
Livro
Data
```

Falta:

```text
Usuário
```

Isso é uma inconsistência clara.

### Outro problema

O `Usuário` possui:

```text
Livros → Lista
```

Isso é uma representação ruim porque o que relaciona usuário e livro é o **empréstimo**.

O ideal seria algo como:

```text
Usuário
    Empréstimos → [códigos]
```

ou simplesmente manter a relação por meio da entidade `Empréstimo`, dependendo da estratégia escolhida.

### Outro problema importante

O livro possui:

```text
Usuário → Inteiro
```

Isso não representa bem o histórico de empréstimos.

Um livro pode ser emprestado:

```text
Pedro → janeiro
João → fevereiro
Maria → março
```

Logo, armazenar um único `Usuário` dentro de Livro não representa o histórico.

**Nota: 5,5/10.**

Essa foi a questão em que você mais desviou da análise pedida.

---

# 10. Pedido

Aqui você acertou bastante coisa.

### Produtos

Você disse:

> deveria ser uma lista de inteiros.

⚠️ **É uma opção coerente**, mas não necessariamente a única.

O dicionário diz apenas:

```text
Produtos → Lista
```

Então o documento:

```json
"produtos": [3, 5]
```

é coerente com isso.

Se a intenção é representar códigos de produtos, então:

```text
Lista de inteiros
```

seria muito mais explícito.

### Documento 1

✅ Correto.

### Documento 2

Você acertou:

```json
"produtos": []
```

viola:

> Todo pedido deve possuir pelo menos um produto.

### Valor total

Você disse que `0` é um inteiro e deveria ser decimal.

❌ **Esse ponto está errado.**

Em JSON:

```json
0
```

é um número.

O dicionário diz:

```text
Decimal
```

e, dependendo da implementação, a distinção entre `0` e `0.0` pode não funcionar da forma que você está imaginando.

Mais importante: **numericamente, 0 é perfeitamente válido para uma regra `>= 0`**.

Portanto, não considero isso um erro conceitual da questão.

### Documento 3

Você acertou os dois problemas:

```text
valorTotal = -50
```

viola:

```text
valorTotal >= 0
```

e:

```text
status = FINALIZADO
```

não pertence ao domínio permitido:

```text
ABERTO
PAGO
CANCELADO
```

**Nota: 8,5/10.**

---

# Resultado geral

| Questão | Nota |
|---|---|
| 1 | 10 |
| 2 | 8 |
| 3 | 9 |
| 4 | 7 |
| 5 | 8,5 |
| 6 | 8,5 |
| 7 | 9 |
| 8 | 9 |
| 9 | 5,5 |
| 10 | 8,5 |

### Média aproximada: **8,3/10**

E isso mostra uma coisa importante: **você entendeu o raciocínio de análise.**

Seus principais erros não foram de desconhecimento do conteúdo. Foram principalmente de **precisão conceitual**.

## Os 5 macetes que eu quero que você leve para a prova

### 1. Não confunda referência com descrição

```text
Animal → Inteiro
```

pode significar:

> código do animal

Não significa que você precisa guardar o nome do animal.

---

### 2. N:N não é sinônimo de redundância

Primeiro descubra a cardinalidade:

```text
1:1
1:N
N:N
```

Depois analise a redundância.

---

### 3. Tipo ≠ regra de negócio

```text
Valor → Decimal
```

não significa automaticamente:

```text
Valor > 0
```

A segunda afirmação precisa ser uma **regra de negócio**.

---

### 4. "Lista" é diferente de "Lista de Inteiros"

Se o dicionário diz apenas:

```text
Produtos → Lista
```

não dá para afirmar que `[1, 2, 3]` é obrigatório.

O dicionário precisa especificar a estrutura se isso for uma regra.

---

### 5. Não invente requisitos

Na questão 9, você começou a pensar:

> "poderia ter ano, autor..."

Pare.

Em uma questão de análise, use esta regra:

> **Analise o que foi especificado. Não corrija o sistema adicionando requisitos que o enunciado nunca pediu.**

Esse último ponto, principalmente, pode fazer bastante diferença numa questão aberta de prova.
