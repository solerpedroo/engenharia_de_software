show databases;

show tables;

use BD180225127;

CREATE TABLE medico ( crm INT PRIMARY KEY, nome VARCHAR(100) NOT NULL,
especialidade VARCHAR(100), telefone VARCHAR(15));
CREATE TABLE paciente ( cpf INT PRIMARY KEY, nome VARCHAR(100) NOT NULL, data_nasc DATE,
telefone VARCHAR(15));
CREATE TABLE consulta ( numero INT PRIMARY KEY, data_consulta DATE, descricao TEXT,
prescricao TEXT, crm int, cpf int, foreign key (crm) references medico(crm),
foreign key (cpf) references paciente(cpf));

ALTER TABLE medico ADD COLUMN email VARCHAR(100) unique;

ALTER TABLE medico MODIFY COLUMN especialidade varchar(100);

ALTER TABLE paciente ADD COLUMN endereco varchar(150);

INSERT INTO medico (crm, nome, especialidade, telefone, email) VALUES (101, 'Carlos Silva', 'Cardiologista', '11999999999', 'carlos@email.com');
INSERT INTO medico (crm, nome, especialidade, telefone, email) VALUES (102, 'Ana Souza', 'Dermatologista', '11988888888', 'ana@email.com');

INSERT INTO paciente (cpf, nome, data_nasc, telefone, endereco)
VALUES (1001, 'João Pereira', '1985-05-20', '11966666666', 'Rua A, 123'),
(1002, 'Maria Oliveira', '1990-07-15', '11955555555', 'Rua B, 456');

INSERT INTO consulta (numero, data_consulta, descricao, prescricao, crm, cpf)
VALUES (1, '2024-03-02', 'Check Geral', 'Tomar vitaminas', 101, 1001),
(2, '2024-05-21', 'Dor no joelho', 'Fisioterapia', 101, 1002),
(3, '2024-06-14', 'Lesão ombro', 'Dipirona', 102, 1001),
(4, '2024-09-17', 'Acompanhamento', 'Reduzir sal', 102, 1002);

UPDATE medico
SET telefone = '11911111111'
WHERE crm = 101;

CREATE TABLE convenio (ID INT PRIMARY KEY AUTO_INCREMENT, nome VARCHAR (100) NOT NULL, telefone VARCHAR(100));

ALTER TABLE paciente
ADD COLUMN convenio_id INT;

ALTER TABLE paciente
ADD CONSTRAINT fk_convenio
FOREIGN KEY (convenio_id)
REFERENCES convenio(id);

CREATE TABLE hospital (ID INT PRIMARY KEY AUTO_INCREMENT, nome VARCHAR (100) NOT NULL, cidade VARCHAR (50), estado VARCHAR (2));

ALTER TABLE consulta 
ADD COLUMN hospital_id INT;

ALTER TABLE consulta 
ADD CONSTRAINT fk_hospital
FOREIGN KEY (hospital_id)
REFERENCES hospital(id);

CREATE TABLE especialidade (ID INT PRIMARY KEY AUTO_INCREMENT, descricao VARCHAR(50) NOT NULL);

ALTER TABLE medico
ADD COLUMN especialidade_id INT;

ALTER TABLE medico
ADD CONSTRAINT fk_especialidade
FOREIGN KEY (especialidade_id)
REFERENCES especialidade(id);

ALTER TABLE especialidade MODIFY COLUMN descricao VARCHAR (100);

ALTER TABLE hospital
DROP COLUMN estado;

ALTER TABLE hospital
RENAME TO unidade_saude;

ALTER TABLE convenio
ADD COLUMN status VARCHAR(20) DEFAULT 'Ativo';