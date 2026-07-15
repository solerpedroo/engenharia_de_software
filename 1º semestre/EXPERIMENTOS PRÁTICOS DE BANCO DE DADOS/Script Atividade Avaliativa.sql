-- Nome: Pedro Henrique Contardi Soler
-- RA: 25005592

-- Requisitos pré-operacionais para manipular o banco de dados da puc no Workbench

show databases;

use BD180225127;

show tables;

select * from audiobooks_p;

-- ETAPA 1

-- Resolução Exercício 1

CREATE TABLE autores_p(
id_autor_p INT PRIMARY KEY,
nome_p VARCHAR(255),
nacionalidade_p VARCHAR(100));

-- Resolução Exercício 2

CREATE TABLE editoras_p(
id_editora_p INT PRIMARY KEY,
nome_p VARCHAR(255),
pais_p VARCHAR(100));

-- Resolução Exercício 3

CREATE TABLE audiobooks_p(
id_audiobook_p INT PRIMARY KEY,
titulo_p VARCHAR(255),
genero_p VARCHAR(255),
id_autor_p INT,
id_editora_p INT);

-- Resolução Exercício 4

ALTER TABLE audiobooks_p
ADD CONSTRAINT fk_autor_p
FOREIGN KEY (id_autor_p) REFERENCES autores_p(id_autor_p);

-- Resolução Exercício 5

ALTER TABLE audiobooks_p
ADD CONSTRAINT fk_editora_p
FOREIGN KEY (id_editora_p) REFERENCES editoras_p(id_editora_p);

-- ETAPA 2

-- Resolução Exercício 6

ALTER TABLE audiobooks_p
ADD COLUMN duracao_p INT;

-- Resolução Exercício 7

ALTER TABLE audiobooks_p
ADD COLUMN data_lancamento_p DATE;

-- ETAPA 3

-- Resolução Exercício 8

INSERT INTO autores_p (id_autor_p, nome_p, nacionalidade_p) VALUES (1, "Machado de Assis", "Brasileira");

-- Resolução Exercício 9

INSERT INTO editoras_p (id_editora_p, nome_p, pais_p) VALUES (1, "Editora Brasil", "Brasil");

-- Resolução Exercício 10

INSERT INTO audiobooks_p (id_audiobook_p, titulo_p, genero_p, id_autor_p, id_editora_p, duracao_p, data_lancamento_p) VALUES (1, "Dom Casmurro", "Romance", 1, 1, 480, "1899-01-01");

-- Resolução Exercício 11

INSERT INTO autores_p (id_autor_p, nome_p, nacionalidade_p) VALUES (2, "Douglas Adams", "Britânica");

-- Resolução Exercício 12

INSERT INTO audiobooks_p (id_audiobook_p, titulo_p, genero_p, id_autor_p, id_editora_p, duracao_p, data_lancamento_p) VALUES (2, "O guia do Mochileiro das Galáxias", "Ficção Científica", 2, 1, 700, "1979-10-12");

-- ETAPA 4

-- Resolução Exercício 13

ALTER TABLE audiobooks_p
DROP FOREIGN KEY fk_editora_p;

-- Resolução Exercício 14

ALTER TABLE audiobooks_p
DROP COLUMN id_editora_p;

-- Resolução Exercício 15

DROP TABLE editoras_p;