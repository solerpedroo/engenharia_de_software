show databases;

use BD180225127;

CREATE TABLE clientes (
id INT AUTO_INCREMENT PRIMARY KEY,
nome VARCHAR(100) NOT NULL,
email VARCHAR(100) UNIQUE NOT NULL,
cpf CHAR(11) UNIQUE,
telefone VARCHAR(20),
endereco TEXT,
cidade VARCHAR(50),
estado CHAR(2),
ativo BOOLEAN DEFAULT TRUE,
data_cadastro TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE pedidos (
id INT AUTO_INCREMENT PRIMARY KEY,
cliente_id INT NOT NULL,
valor_total DECIMAL(10,2) NOT NULL,
status_pedido VARCHAR(30) DEFAULT 'Em aberto',
forma_pagamento VARCHAR(30),
endereco_entrega TEXT,
data_pedido TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
observacao TEXT,
cupom_aplicado VARCHAR(20),
confirmado BOOLEAN DEFAULT FALSE,
FOREIGN KEY (cliente_id) REFERENCES clientes(id)
);

INSERT INTO clientes (nome, email, cpf, telefone, endereco, cidade, estado)
VALUES
('Mariana Costa', 'mariana@gmail.com', '12345678901', '(11)91234-5678', 'Rua A, 100', 'Campinas', 'SP'),
('Roberto Dias', 'roberto@hotmail.com', '23456789012', '(19)98765-4321', 'Av B, 200', 'São Paulo', 'SP');

INSERT INTO pedidos (cliente_id, valor_total, forma_pagamento, endereco_entrega, cupom_aplicado)
VALUES
(1, 299.90, 'Cartão de Crédito', 'Rua A, 100', 'PROMO10'),
(2, 99.99, 'Pix', 'Av B, 200', NULL);

INSERT INTO clientes (nome, email, cpf, telefone, endereco, cidade, estado)
VALUES
('Pedro Soler', 'pedro@gmail.com', '987654321', '(19)98708-701,', 'Rua C, 200', 'Campinas', 'SP');

INSERT INTO clientes (nome, email, cpf, cidade, estado)
VALUES
('João Souza', 'joao@gmail.com', '1234567892', 'Campinas', 'SP');

-- INSERT INTO clientes (nome, email, cpf, cidade, estado)
-- VALUES
-- 'Pedro Souza', 'joao@gmail.com', '98765432102', 'Campinas', 'SP');
-- Não funcionará pois foi definido como UNIQUE o e-mail

INSERT INTO clientes (nome, email, cpf, cidade, estado, ativo)
VALUES
('Ana Clara', 'ana.clara@outlook.com', '11223344556', 'Valinhos', 'SP', FALSE);

-- Tentativa de inserir cliente com ID duplicado
-- INSERT INTO clientes (id, nome, email, cpf, cidade, estado)
-- VALUES
-- (1, 'Teste Duplicidade', 'teste@gmail.com', '00011122233', 'Campinas', 'SP');
-- Não funcionará pois já foi inserido um ID de nº 1 anteriormente e devido também que é uma coluna de auto incremento

INSERT INTO pedidos (cliente_id, valor_total, forma_pagamento, endereco_entrega)
VALUES
(1, 150.50, 'Boleto', 'Rua das Flores, 321, Apto 10');

INSERT INTO pedidos (cliente_id, valor_total, forma_pagamento, endereco_entrega)
VALUES
(2, 599.90, 'PIX', 'Rua D, 300');

-- INSERT INTO pedidos (cliente_id, valor_total, forma_pagamento, endereco_entrega, cupom_aplicado)
-- VALUES
-- (1, -299.90, 'Cartão de Crédito', 'Rua A, 100');
-- Erro devido que o valor é negativo

INSERT INTO pedidos (cliente_id, valor_total, forma_pagamento, endereco_entrega, observacao)
VALUES
(1, 79.90, 'Pix', 'Rua das Flores, 321, Apto 10', 'Entrega rápida, por favor.'),
(1, 199.50, 'Cartão de Crédito', 'Rua das Flores, 321, Apto 10', NULL),
(1, 35.00, 'Boleto', 'Rua das Flores, 321, Apto 10', 'Pagamento na sexta-feira.');

-- INSERT INTO pedidos (cliente_id, valor_total, forma_pagamento, endereco_entrega, observacao)
-- VALUES
-- (999, 79.90, 'Pix', 'Rua das Flores, 321, Apto 10', 'Entrega rápida, por favor.');
-- Erro devido que não existe nenhum cliente com o ID 999 existente ainda, por usar uma fk ele dá esse erro pois referencia o ID da tabela principal