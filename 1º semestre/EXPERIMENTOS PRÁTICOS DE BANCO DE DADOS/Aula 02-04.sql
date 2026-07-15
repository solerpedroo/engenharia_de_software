show databases;

show tables;

select * from assistidos;

use BD180225127;

CREATE TABLE usuarios (id_usuario INT PRIMARY KEY, nome varchar(100), email varchar(100));

CREATE TABLE filmes (id_filme INT PRIMARY KEY, titulo varchar(100), genero varchar(100));

CREATE TABLE assistidos (id_assistido INT PRIMARY KEY, id_usuario INT, id_filme INT, data_assistido INT);

ALTER TABLE usuarios ADD COLUMN idade INT;

ALTER TABLE assistidos
ADD FOREIGN KEY (id_usuario)
REFERENCES usuarios(id_usuario);

ALTER TABLE assistidos
ADD FOREIGN KEY (id_filme)
REFERENCES filmes(id_filme);

ALTER TABLE filmes DROP COLUMN genero;

INSERT INTO usuarios (id_usuario, nome, email, idade) VALUES
(1, "João Silva", "joao@email.com", 30);

INSERT INTO usuarios (id_usuario, nome, email, idade) VALUES
(2, "Ana Lima", "ana@email.com", 25);

ALTER TABLE filmes
ADD COLUMN genero VARCHAR(100);

INSERT INTO filmes (id_filme, titulo, genero) VALUES
(1, "Matrix", "Ficção Científica");

INSERT INTO filmes (id_filme, titulo, genero) VALUES
(2, "A Origem", "Ação");

ALTER TABLE assistidos
MODIFY COLUMN data_assistido date;

DELETE FROM assistidos WHERE id_assistido = 1;

INSERT INTO assistidos (id_assistido, id_usuario, id_filme, data_assistido) VALUES
(1, 1, 1, "2025-03-01");

INSERT INTO assistidos (id_assistido, id_usuario, id_filme, data_assistido) VALUES
(2, 2, 2, "2025-03-02");

SHOW CREATE TABLE assistidos;