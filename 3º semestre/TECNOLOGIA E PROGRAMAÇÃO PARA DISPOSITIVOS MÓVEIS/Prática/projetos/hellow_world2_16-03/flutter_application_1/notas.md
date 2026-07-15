# Estrutura do Projeto em Flutter

## Flutter

- é um base code one, você cria em dart e ele adpata para as demais plataformas (ios, android, macOS, windows, web...)

---

## Importante: 

- no diretório lib colocamos os códigos em dart, portanto é o diretório mais importante do projeto

---

## Arquivo pubspec.yaml

- neste arquivo definimos: versão do flutter, plugins de dependências (ou pacotes de dependências), ferramentas de teste e configurações de montagem (build)

--- 

## Conceito (lint/linter): 

- no python a estilização de código é obrigatória, lá usamos uma especificação chamada pep8

- na especificação pep8 é definido como o programador deve escrever o código (em termos de formatação)

- o flutter usa uma ferramenta linter chamada flutter_lints, e ele é habilitado no arquivo pubspec.yaml

--- 

## Arquivo analysis_options.yaml

- o analysis_options.yaml **configuramos** o comportamento de algumas opções do linter/lint

--- 

## Estrutura geracional (código gerado)

- nos diretórios android, ios, web e entre outros, temos o código nativo gerado pelo flutter

- quem gera o código nativo é o flutter (framework), o dart não enxerga o flutter, flutter não sabe da existência do dart

- portanto o que vai nas pastas de plataformas, são códigos nativos

---

## Pasta test 

- aqui escrevemos os testes unitários e de instrumentação

--- 

## Curiosidade

- aprender a fazer um teste unitário simples em dart com ou sem flutter, de preferência sem flutter primeiro

---

## Programação reativa / declarativa

- ao invés de prepararmos tudo antes de usar, vamos preparando conforme o uso (reativamente)

--- 

## Programação interativa

- prepara antes para depois usar

--- 

## Scaffold

- miolo do layout, pode colocar ele em qualquer tela

--- 

## Tarefas para casa 

### Tarefa 1 

- criar o app hello world em casa

### Tarefa 2 

- criar novamente o app hello world, porém chamá-lo de calculadora IMC, modificar a tela para ter: peso e altura, e o botão calcular, ao clicar no botão calcular, fazer o cálculo do IMC e mostrar na tela

### Tarefa 3

- pegar o exemplo de calculadora do professor, colocar todos os arquivos dart dentro da pasta lib de um novo projeto novo chamado calculadora, modificar as classes MyHomePage e MyHomePageState para mostrar a tela de uma calculadora e fazer funcionar

- dica: no projeto da calculadora, nomeie as classes da seguinte maneira: MyApp<Calculator>, classe MyHomePage<CalculatorUI>, classe _MyHomePageState<_CalculatorUIState>