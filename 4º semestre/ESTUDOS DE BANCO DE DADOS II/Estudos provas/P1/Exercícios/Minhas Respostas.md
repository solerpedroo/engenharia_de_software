# Minhas Respostas — Exercícios de Análise

## Questão 1

O enunciado fala que todo cliente deve possuir **nome** e **CPF**. Porém, no dicionário, o `CPF` está com obrigatoriedade como **Não**. O enunciado também fala que o telefone é opcional. Porém, no dicionário fornecido, o `Telefone` aparece como obrigatório. Além disso, o enunciado diz que um cliente pode possuir mais de um telefone; nesse caso, o tipo dele é `String`, e não uma **lista** em que possa ser inserido mais de um telefone.

## Questão 2

Existem alguns problemas, sim, principalmente na parte do dicionário: ele não tem a coluna de exemplos, comentários e regras de negócio, e não tem nenhuma descrição sobre a entidade em si. Quanto ao tipo do `Departamento`, acredito que seria um **inteiro**, porque, na entidade de departamento, ele teria um código — um código inteiro único —, o qual o atributo `Departamento` da entidade Funcionário deveria referenciar (o código do departamento em que aquele funcionário trabalha). Então, acredito que o tipo não deveria ser `String` nesse caso, mas sim um tipo **inteiro**.

## Questão 3

O **primeiro** banco simulado está correto, pois todos os atributos seguem os atributos descritos no dicionário.

O **banco 2** possui uma inconsistência: o atributo `tutor` é obrigatório, e neste documento não possui o código do tutor.

No **banco 3**, há algumas inconsistências, principalmente na parte da `especie`, em que uma string foi colocada. No atributo `tutor`, que é um código inteiro, foi colocada uma string.

## Questão 4

O dicionário possui algumas divergências em relação ao documento JSON:

- Os atributos `valor` e `animal` não possuem um comentário nem regra de negócio. Isso faz diferença no documento, saindo fora do escopo do que seria o projeto.
- No atributo `animal`, também se tem a seguinte restrição: o tipo é um **inteiro**, quando o adequado seria uma **string livre** no documento JSON.
- O atributo `situacao` possui uma divergência, porque, nos comentários do dicionário, não se cita o termo `"REALIZADA"` para uma lista lateral e estática. O adequado seria `"CONCLUÍDA"`.
- O `valor` não tem uma regra de negócio detalhada na parte de comentários do dicionário, o que deixa implícito que o usuário pode digitar qualquer valor. Nesse caso do atributo, foi negativo, e o mesmo se aplica ao `animal`. Como comentado anteriormente, no dicionário está o tipo `inteiro`, então ele não consegue indicar qual o animal é; foi colocado um número, saindo da regra de negócio do dicionário.

O dicionário possui algumas inconsistências, principalmente na parte de comentários, pois está muito superficial. Não dá para detalhar de uma maneira correta, para a pessoa que vai desenvolver o banco simulado aplicar essas regras na prática, pois não há um escopo pré-definido.

## Questão 5

Primeiro, nesses dicionários está faltando a coluna de comentários, regras de negócio e exemplos. No dicionário de Consulta, o `Animal` está com um tipo **inteiro** que não é muito adequado, mesmo para o caso descrito anteriormente. Não acho necessário ter, no campo de Consulta, um campo chamado `Veterinário`, pois isso é uma inconsistência de **N para N**. Temos dois lados da moeda:

- uma lista de inteiros com os códigos das consultas no dicionário de Veterinário;
- um campo `Veterinário` dentro do dicionário Consulta, que pega o ID do veterinário.

Então, há ambos os casos batendo consigo mesmos. Isso é uma **redundância**, o que poderia ocasionar uma possível falha de query caso, em uma modelagem de busca, seja algo tão ineficiente, e também gastaria recursos de memória nessa eventual implementação de banco. Acredito que não há necessidade de ter essa redundância de informações, pois, fazendo uma busca no MongoDB ou no `mongosh`, conseguimos identificar qual foi a consulta, qual foi o veterinário que realizou uma determinada consulta e quais consultas o veterinário X realizou, por exemplo.

## Questão 6

A modelagem está errada. O texto do enunciado fala que um tutor pode possuir vários animais. No dicionário, fala que os `Animais` são, na verdade, um tipo **inteiro**, o que acaba sendo incorreto. Deveria ser uma **lista de inteiros**, pois um tutor pode ter vários animais. Entretanto, a modelagem do lado do Animal está correta; porém, acaba sendo um pouco **redundante** ter essa mesma informação em ambas as entidades. Poderia ser somente uma, na minha perspectiva.

## Questão 7

A afirmação dele está **incorreta**. Não é porque o MongoDB não tem *schema enforcement* que não precisamos de um dicionário de dados. Pelo contrário, é de extrema necessidade ter um dicionário de dados para um banco NoSQL, porque, como não temos um esquema definido, é necessário termos documentadas todas as informações de todas as entidades, os possíveis atributos e afins. Isso é para que não possa haver uma divergência entre o que foi esperado na documentação e o que é aplicado na prática.

## Questão 8

O mesmo para esse dicionário: ele não possui regras de negócio nem exemplos, então podem ocorrer falhas na implementação dos documentos JSON, como ocorreu nesse primeiro documento.

Ele tem uma inconsistência no seguinte contexto: `categorias`, no dicionário, não são definidas como uma lista de strings. Implicitamente, sabemos que as categorias são strings, porém no dicionário isso não consta. Esse é um ponto que poderia gerar uma possível divergência.

Já no segundo documento, ele utiliza o campo `preco` como uma **string**, sendo que foi definido no dicionário como um **decimal**. Nas `categorias`, ele não utiliza uma lista, mas uma única string. O mesmo para o `estoque`: o estoque está como um número negativo, devido a não haver uma restrição e uma regra de negócio.

## Questão 9

O enunciado não indica explicitamente quais são os atributos de um livro. Por exemplo, o dicionário fala de título do livro, e o cenário não fala quais são os atributos. Os atributos poderiam ser, além do título, por exemplo, ano de lançamento, autor e outros. Isso não é falado.

Outra inconsistência na entidade Livro: o `Usuário` fala que não é obrigatório; no caso, seria obrigatório, porque, como vou saber qual usuário está com um determinado livro, ele deveria ser obrigatório. O `Status` deveria ser uma **lista estática de strings**, porque podemos inserir qualquer coisa nesse contexto se não tivermos uma lista pré-definida, como, por exemplo, reservado, fora de estoque, disponível e afins.

No Usuário, da mesma forma, não conseguimos saber quais são os atributos dele. O enunciado não deixa de forma explícita quais são. Por exemplo, poderia ter atributos de nome, telefone, contato, idade e coisas assim. Mesmo que se encaixe a parte de `Livros` dentro dessa entidade Usuário, ele define como lista; porém, o adequado seria uma **lista de inteiros**, porque “lista” é algo muito generalizado. O `Código` que foi definido dentro da entidade Livro é um inteiro único; consequentemente, para termos uma lista de livros, deveria ser uma lista de inteiros para armazenar o código especificamente. Na entidade Usuário, como comentado, deveria ter também uma lista de inteiros de empréstimos para associar.

Deveria ter, nesse caso, o comentário que fiz anteriormente: não deveria ter o livro na coleção na entidade Usuário, mas sim a entidade Empréstimo como uma lista de inteiros.

Na entidade Empréstimo, não conseguimos saber qual é o usuário, pois não há um atributo `Usuário`. O correto seria criar um atributo `Usuário` do tipo inteiro, com campo de obrigatoriedade.

Sim, acredito que, olhando superficialmente, essas são as questões que eu consegui encontrar.

## Questão 10

No dicionário, acredito que há uma inconsistência principalmente no atributo de `Produtos`, pois ele não especifica qual é o tipo da lista. O adequado seria uma **lista de inteiros**.

O **documento 1** está certo.

O **documento 2** tem uma inconsistência porque, nas regras, o pedido deve conter pelo menos um produto, e o array de `produtos` está vazio.

No **documento 3**, o `valorTotal` — pela regra — é um valor negativo, e o `status` está como `"FINALIZADO"`, que não foi previamente definido nem descrito. O adequado seria `ABERTO`, `PAGO` ou `CANCELADO`.

No documento 2, há outra inconsistência: o `valorTotal` está como um **inteiro**. Deveria ser um **decimal**. O mesmo se aplica ao `valorTotal` do documento 3.
