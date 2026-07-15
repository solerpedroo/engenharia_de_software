show databases;

use BD180225127;

CREATE TABLE tutores (
id_tutor INT PRIMARY KEY,
nome VARCHAR(100),
telefone VARCHAR(20),
cidade VARCHAR(50)
);

CREATE TABLE pacientes (
id_paciente INT PRIMARY KEY,
nome VARCHAR(100),
especie VARCHAR(50),
idade INT,
peso DECIMAL(5,2),
tutor_id INT,
FOREIGN KEY (tutor_id) REFERENCES tutores(id_tutor)
);

CREATE TABLE consultas (
id_consulta INT PRIMARY KEY,
id_paciente INT,
data DATE,
valor DECIMAL(8,2),
procedimento VARCHAR(100),
FOREIGN KEY (id_paciente) REFERENCES pacientes(id_paciente)
);

INSERT INTO tutores VALUES
(1, 'Ana Silva', '11999999999', 'São Paulo'),
(2, 'Carlos Lima', '11888888888', 'Campinas'),
(3, 'João Souza', '11777777777', 'Sorocaba'),
(4, 'Beatriz Ramos', '11911111111', 'Campinas'),
(5, 'Marcos Tadeu', '11922222222', 'Osasco'),
(6, 'Luciana Costa', '11788888888', 'São Paulo'),
(7, 'Daniel Rocha', '11944444444', 'Jundiaí'),
(8, 'Fernanda Torres', '11666666666', 'Campinas'),
(9, 'Juliano Nogueira', '11955555555', 'Sorocaba'),
(10, 'Marta Fernandes', '11977777777', 'Campinas');

INSERT INTO pacientes VALUES
(1, 'Luna', 'Cachorro', 5, 12.5, 1),
(2, 'Mingau', 'Gato', 3, 4.8, 2),
(3, 'Bob', 'Cachorro', 8, 20.1, 3),
(4, 'Frajola', 'Gato', 2, 3.7, 4),
(5, 'Rex', 'Cachorro', 6, 18.4, 5),
(6, 'Tom', 'Gato', 9, 5.2, 6),
(7, 'Bella', 'Cachorro', 4, 9.5, 7),
(8, 'Nina', 'Gato', 7, 4.3, 8),
(9, 'Pingo', 'Coelho', 1, 2.0, 9),
(10, 'Spike', 'Cachorro', 10, 25.0, 10);

INSERT INTO consultas VALUES
(1, 1, '2024-01-10', 120.00, 'Vacinação'),
(2, 2, '2024-01-15', 180.00, 'Exame de sangue'),
(3, 3, '2024-02-01', 250.00, 'Cirurgia'),
(4, 4, '2024-02-20', 100.00, 'Consulta geral'),
(5, 5, '2024-03-05', 300.00, 'Internação'),
(6, 6, '2024-03-10', 180.00, 'Ultrassom'),
(7, 7, '2024-03-12', 120.00, 'Vacinação'),
(8, 8, '2024-04-01', 150.00, 'Consulta geral'),
(9, 9, '2024-04-10', 90.00, 'Curativo'),
(10, 10, '2024-04-15', 200.00, 'Raio-X');

-- Liste o nome e idade dos pacientes com idade maior que 5
SELECT nome, idade FROM pacientes WHERE idade > 5;

-- Mostre os nomes dos pacientes ordenados do mais pesado para o mais leve
SELECT nome FROM pacientes ORDER BY peso DESC;

-- Exiba a quantidade de pacientes por espécie
SELECT especie, COUNT(*) AS quantidade FROM pacientes GROUP BY especie;

-- Liste os pacientes com suas respectivas classificações (Felino, Canino ou Outro) usando CASE
SELECT
    nome,
    CASE
        WHEN especie = 'Gato' THEN 'Felino'
        WHEN especie = 'Cachorro' THEN 'Canino'
        ELSE 'Outro'
    END AS classificacao
FROM pacientes;

-- Mostre o total de consultas realizadas por paciente
SELECT
    p.nome AS nome_paciente,
    COUNT(c.id_consulta) AS total_consultas
FROM
    pacientes p
LEFT JOIN
    consultas c ON p.id_paciente = c.id_paciente
GROUP BY
    p.nome;
    
-- Liste o nome de todos os pacientes e a cidade em que seus tutores moram. (Use JOIN entre pacientes e tutores.)
SELECT
    p.nome AS nome_paciente,
    t.cidade AS cidade_tutor
FROM
    pacientes p
JOIN
    tutores t ON p.tutor_id = t.id_tutor;
    
-- Mostre o nome do paciente, a data da consulta e o procedimento realizado.(Use JOIN entre consultas e pacientes.)
SELECT
    p.nome AS nome_paciente,
    c.data AS data_consulta,
    c.procedimento
FROM
    consultas c
JOIN
    pacientes p ON c.id_paciente = p.id_paciente;

-- Traga o nome do tutor, nome do paciente e o valor das consultas.(Use JOIN entre as três tabelas.)
SELECT
    t.nome AS nome_tutor,
    p.nome AS nome_paciente,
    c.valor AS valor_consulta
FROM
    tutores t
JOIN
    pacientes p ON t.id_tutor = p.tutor_id
JOIN
    consultas c ON p.id_paciente = c.id_paciente;
    
-- Exiba os nomes dos pacientes que tiveram consultas com valor acima de R$ 150,00, junto com o nome de seus tutores. (Use JOIN e filtro com WHERE.)
SELECT
    p.nome AS nome_paciente,
    t.nome AS nome_tutor
FROM
    consultas c
JOIN
    pacientes p ON c.id_paciente = p.id_paciente
JOIN
    tutores t ON p.tutor_id = t.id_tutor
WHERE
    c.valor > 150.00;
    
-- Mostre o total de consultas realizadas por cada tutor. (Use JOIN, GROUP BY e COUNT.)
SELECT
    t.nome AS nome_tutor,
    COUNT(c.id_consulta) AS total_consultas
FROM
    tutores t
JOIN
    pacientes p ON t.id_tutor = p.tutor_id
JOIN
    consultas c ON p.id_paciente = c.id_paciente
GROUP BY
    t.nome;