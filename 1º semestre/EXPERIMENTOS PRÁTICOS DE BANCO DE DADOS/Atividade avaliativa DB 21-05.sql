show databases;

-- create database clinica_veterinaria_p;

use clinica_veterinaria_p;
-- show tables;
-- drop table tutores_p, animais_p, consultas_p;

CREATE TABLE tutores_p (
id_tutor_p INT PRIMARY KEY,
nome_p VARCHAR(100),
telefone_p VARCHAR(15),
email_p VARCHAR(100),
endereco_p VARCHAR(150)
);
CREATE TABLE animais_p (
id_animal_p INT PRIMARY KEY,
nome_p VARCHAR(50),
especie_p VARCHAR(30),
raca_p VARCHAR(50),
idade_p INT,
peso_p DECIMAL(5,2),
sexo_p CHAR(1),
id_tutor_p INT,
FOREIGN KEY (id_tutor_p) REFERENCES tutores_p(id_tutor_p)
);
CREATE TABLE consultas_p (
id_consulta_p INT PRIMARY KEY,
id_animal_p INT,
data_consulta_p DATE,
procedimento_p VARCHAR(100),
valor_p DECIMAL(10,2),
retorno_p BOOLEAN,
FOREIGN KEY (id_animal_p) REFERENCES animais_p(id_animal_p)
);

INSERT INTO tutores_p (id_tutor_p, nome_p, telefone_p, email_p, endereco_p) VALUES
(1, 'Carlos Mendes', '11999887766', 'carlos@email.com', 'Rua das Flores, 123'),
(2, 'Ana Lúcia', '11988776655', 'ana@email.com', 'Av. Central, 456'),
(3, 'Juliana Silva', '11977665544', 'juliana@email.com', 'Rua Verde, 789'),
(4, 'Roberto Nunes', '11966554433', 'roberto@email.com', 'Travessa Sol, 321'),
(5, 'Fernanda Dias', '11955443322', 'fernanda@email.com', 'Alameda Azul, 852');
INSERT INTO animais_p (id_animal_p, nome_p, especie_p, raca_p, idade_p, peso_p, sexo_p, id_tutor_p) VALUES
(1, 'Toby', 'Cão', 'Labrador', 5, 28.5, 'M', 1),
(2, 'Mimi', 'Gato', 'Persa', 3, 4.2, 'F', 2),
(3, 'Rex', 'Cão', 'Vira-lata', 2, 12.7, 'M', 1),
(4, 'Luna', 'Gato', 'Siamês', 4, 5.1, 'F', 3),
(5, 'Bolinha', 'Cão', 'Poodle', 10, 7.8, 'F', 4),
(6, 'Thor', 'Cão', 'Husky', 6, 32.0, 'M', 5),
(7, 'Nina', 'Gato', 'Maine Coon', 2, 6.9, 'F', 3),
(8, 'Max', 'Cão', 'Bulldog', 4, 24.0, 'M', 4),
(9, 'Mel', 'Gato', 'SRD', 1, 3.5, 'F', 5),
(10, 'Bob', 'Cão', 'Beagle', 3, 10.2, 'M', 2);
INSERT INTO consultas_p (id_consulta_p, id_animal_p, data_consulta_p, procedimento_p, valor_p, retorno_p) VALUES
(1, 1, '2024-12-10', 'Vacinação Antirrábica', 80.0, False),
(2, 2, '2024-12-15', 'Consulta Rotina', 120.0, True),
(3, 3, '2025-01-10', 'Tratamento de pele', 200.0, False),
(4, 1, '2025-02-05', 'Retorno Vacinação', 0.0, False),
(5, 4, '2025-02-20', 'Exame de sangue', 150.0, True),
(6, 5, '2025-03-01', 'Consulta geriátrica', 160.0, True),
(7, 6, '2025-03-15', 'Cirurgia ortopédica', 800.0, False),
(8, 7, '2025-04-02', 'Tratamento vermífugo', 95.0, False),
(9, 8, '2025-04-10', 'Check-up', 180.0, True),
(10, 9, '2025-04-20', 'Consulta Rotina', 110.0, False),
(11, 10, '2025-04-25', 'Vacinação múltipla', 90.0, True),
(12, 2, '2025-05-05', 'Retorno Consulta', 0.0, False);

-- Altere o peso do animal chamado 'Thor' para 33.5 kg
UPDATE animais_p SET peso_p = 33.5 WHERE nome_p = "Thor";

-- Remova a consulta com id_consulta = 6
DELETE FROM consultas_p WHERE id_consulta_p = 6;

-- Exiba o nome dos animais e o nome dos tutores responsáveis
SELECT a.nome_p AS nome_animal, t.nome_p AS nome_tutor
FROM animais_p a
JOIN tutores_p t ON a.id_tutor_p = t.id_tutor_p;

-- Quais animais têm peso maior que 25 kg? Mostre nome, espécie e peso
SELECT nome_p, especie_p, peso_p
FROM animais_p
WHERE peso_p > 25;

-- Marque todas as consultas de 'Mimi' como realizadas (retorno = TRUE) **
UPDATE consultas_p
JOIN animais_p ON consultas_p.id_animal_p = animais_p.id_animal_p
SET consultas_p.retorno_p = TRUE
WHERE animais_p.nome_p = 'Mimi';

-- Delete todos os animais do tutor 'Juliana Silva' 
DELETE c FROM consultas_p c
JOIN animais_p a ON c.id_animal_p = a.id_animal_p
JOIN tutores_p t ON a.id_tutor_p = t.id_tutor_p
WHERE t.nome_p = 'Juliana Silva';
DELETE a FROM animais_p a
JOIN tutores_p t ON a.id_tutor_p = t.id_tutor_p
WHERE t.nome_p = 'Juliana Silva';

-- Liste o nome de cada animal e o total que ele gastou em consultas
SELECT a.nome_p AS nome_animal, SUM(c.valor_p) AS total_gastos
FROM animais_p a
JOIN consultas_p c ON a.id_animal_p = c.id_animal_p
GROUP BY a.nome_p;

-- Mostre o nome de cada tutor e a quantidade de animais sob seus cuidados
SELECT t.nome_p AS nome_tutor, COUNT(a.id_animal_p) AS quantidade_animais
FROM tutores_p t
LEFT JOIN animais_p a ON t.id_tutor_p = a.id_tutor_p
GROUP BY t.nome_p;

-- Acrescente 1 ano à idade de todos os animais da espécie 'Cão'
UPDATE animais_p
SET idade_p = idade_p + 1
WHERE especie_p = 'Cão';

-- Liste o nome e a data das consultas realizadas para animais da espécie 'Gato'
SELECT a.nome_p AS nome_animal, c.data_consulta_p
FROM animais_p a
JOIN consultas_p c ON a.id_animal_p = c.id_animal_p
WHERE a.especie_p = 'Gato';