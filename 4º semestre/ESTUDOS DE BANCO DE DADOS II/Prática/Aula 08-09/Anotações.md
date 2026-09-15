# Aula 08-09

## Tema: Consultas no mongo altas

### Anotações prévias

- A massa de dados que gerammos não serve somente para a simulação do banco, mas para outras coisas também

- É importante saber o que tem que entregar, não somente baseado no escopo

- Tem coisas que precisam nascer no banco, geralmente alguns nomes são: **seed, dump**

- O banco de simulação ajuda a amadurecer essa parte de análise

- Processo é: simular para ver se está aderente à realidade ou não

> As coleções e o nome do banco devem estar como constantes no playground do mongodb, ex: `const collProfessor = "professor";`

- O comando db.getCollection(nomeDaColecao).insertMany(

);

> Serve para inserir os documentos json dentro da coleção específica

- O Playground Result só mostra os logs de insert da última coleção

### Comandos de consulta no compass:

- O mongo shell funciona com base em JS

- No mongo define campos de consultas (fáceis, médias e difíceis)

- Fáceis:
    - find
    - find one

- Médias:
    - find 
        + +operadores 
        + +ordenção 
        + +projeção
    - find one
        + +operadores 
        + +ordenção 
        + +projeção

- Difícies:
    - aggregate (funções de agregação / pipeline de agregação)
        + +operador de `$lookup` (faz join)

- **Ambientes**
    - Mongo shell (mongosh)
    - Compass
    - JS (puro)

- As consultas usam uma "pseudo linguagem" MQL => mongo query language

- Tudo se faz no Mongosh mas nem tudo se faz no compass

- É legal usar o compass para facilitar a busca de dados, para não ficar vendo todo o output diretamente no shell, pois dificulta a visualização em muitos casos

- A vírgula no compass significa o "&&" (and)

- Quando se faz a busca por diferença, impacta vários subprocessos 

- Para buscar o que quer, `curso: { $in: ["Administração", "Economia", "Direito"]};` 

- **Alguns comandos:**

- Comando `show collections` - mostra as coleções do banco atual 
- Para trocar de banco usa-se o comando `use`
- Comando `db.nomeColecao.countDocuments();`- contar documentos
- Comando para consultar uma parte específica, exemplo com coleção estudantes `db.estudantes.find({'periodo': 4});`
- Para contar quantos documentos `db.estudantes.find({'periodo': 4}).count();` => RUIM, o adequado é `db.estudantes.countDocuments({'periodo': 4});`, porém tudo isso depende da arquitetura, infraestrutura de cluster e afins

- **Alguns comparadores:**

- $lt = less than `<`           
- $lte = less than equals `<=`
- $gt = greater than `>`
- $gte = greater than equals `>=`

- Operadores: https://www.w3schools.com/mongodb/mongodb_query_operators.php, https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/regex/

- Significado do "i" no options 