show databases;

use BD180225127;

SELECT * FROM produtos ;
SELECT nome, preco FROM produtos;

CREATE TABLE produtos (
id_produto INT PRIMARY KEY,
nome VARCHAR(100),
preco DECIMAL(10,2),
categoria VARCHAR(50)
);

INSERT INTO produtos VALUES
(1, 'Notebook', 3500.00, 'Informática'),
(2, 'Mouse', 80.00, 'Acessórios'),
(3, 'Teclado', 150.00, 'Acessórios'),
(4, 'Monitor', 1200.00, 'Informática'),
(5, 'Cadeira Gamer', 850.00, 'Móveis');

-- SELECT simples com alias (sem apelido para tabela, somente com colunas)
SELECT nome AS produto, preco AS valor FROM produtos;

-- SELECT com alias para colunas e tabela
SELECT p.nome AS produto_nome, p.preco AS valor
FROM produtos AS p;

SELECT p.nome AS item, p.categoria AS tipo
FROM produtos AS p;

-- Exiba apenas o nome e o preço dos produtos, usando apelidos 'item' e 'preço_final’
SELECT nome AS item, preco AS preço_final FROM produtos;

-- Liste o nome e a categoria dos produtos, mas troque o nome da tabela por um apelido
SELECT p.nome, p.categoria
FROM produtos AS p;

-- Mostre o nome do produto e o valor com um reajuste de 10%, usando um alias apropriado
SELECT nome, preco * 1.10 AS preco_reajustado
FROM produtos;