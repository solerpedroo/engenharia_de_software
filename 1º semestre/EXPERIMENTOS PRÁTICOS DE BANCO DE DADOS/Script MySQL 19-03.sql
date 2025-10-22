show databases;
use BD180225127;

show tables;

SELECT * FROM funcionarios;

CREATE TABLE Cliente (
 ID INT PRIMARY KEY AUTO_INCREMENT,
 Nome VARCHAR(50) NOT NULL,
 Email VARCHAR(100),
 Telefone VARCHAR(15)
);

CREATE TABLE Pedido (
 ID INT PRIMARY KEY AUTO_INCREMENT,
 NumeroPedido VARCHAR(20) NOT NULL,
 DataPedido DATE NOT NULL,
 ClienteID INT,
 FOREIGN KEY (ClienteID) REFERENCES Cliente(ID)
);

CREATE TABLE funcionarios (
ID INT PRIMARY KEY AUTO_INCREMENT,
Nome VARCHAR(100) NOT NULL,
Cargo VARCHAR(50) NOT NULL,
Salario DECIMAL(10,2) NOT NULL
);

ALTER TABLE funcionarios
ADD data_admissao
DATE NOT NULL;

ALTER TABLE funcionarios
DROP COLUMN Cargo;

ALTER TABLE funcionarios
MODIFY COLUMN Salario DECIMAL(12,2);

CREATE TABLE departamentos (
ID INT PRIMARY KEY AUTO_INCREMENT,
Nome VARCHAR(100) NOT NULL
);

ALTER TABLE departamentos
ADD departamento_id
VARCHAR(50) NOT NULL;

ALTER TABLE funcionarios ADD COLUMN departamento_id INT;
ALTER TABLE funcionarios ADD FOREIGN KEY (departamento_id) REFERENCES departamentos(id);

ALTER TABLE funcionarios
ADD COLUMN Orcamento DECIMAL(12,2);

ALTER TABLE funcionarios
DROP COLUMN Orcamento; 

ALTER TABLE departamentos
ADD COLUMN Orcamento DECIMAL(12,2);

ALTER TABLE departamentos
DROP COLUMN Orcamento; 

ALTER TABLE departamentos
MODIFY COLUMN Nome VARCHAR(150);

ALTER TABLE departamentos RENAME TO setores;

DROP TABLE setores;

 ALTER TABLE funcionarios ADD COLUMN status VARCHAR(20) NOT NULL DEFAULT 'Ativo';