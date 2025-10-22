show databases;

-- create database aula_exp_bd;
use aula_exp_bd;

-- CRIAÇÕES

CREATE TABLE Usuarios (
    id_usuario INT PRIMARY KEY AUTO_INCREMENT,
    nome_completo VARCHAR(100) NOT NULL,
    email VARCHAR(50) UNIQUE NOT NULL,
    data_nascimento DATE NOT NULL,
    cpf VARCHAR(14) UNIQUE,
    senha VARCHAR(30) NOT NULL,
    data_cadastro DATETIME DEFAULT CURRENT_TIMESTAMP,
    tipo_usuario ENUM('organizador', 'comprador') NOT NULL
);
CREATE TABLE Organizadores (
    id_organizador INT PRIMARY KEY AUTO_INCREMENT,
    nome_empresa VARCHAR(100) NOT NULL,
    cnpj VARCHAR(18) UNIQUE NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    telefone VARCHAR(20),
    endereco VARCHAR(255),
    data_cadastro DATETIME DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE Eventos (
    id_evento INT PRIMARY KEY AUTO_INCREMENT,
    nome_evento VARCHAR(255) NOT NULL,
    descricao TEXT,
    data_evento DATE NOT NULL,
    hora_inicio TIME,
    hora_fim TIME,
    capacidade_maxima INT NOT NULL,
    local_evento VARCHAR(255) NOT NULL,
    ingressos_vendidos INT DEFAULT 0,
    id_organizador INT NOT NULL,
    status_evento ENUM('programado', 'em_andamento', 'concluido', 'cancelado', 'adiado') NOT NULL,
    CONSTRAINT fk_organizador_evento FOREIGN KEY (id_organizador) REFERENCES Organizadores(id_organizador)
);
CREATE TABLE Compras (
	id_compra INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    id_usuario INT NOT NULL,
    cod_ingresso INT NOT NULL,
    data_compra DATETIME DEFAULT CURRENT_TIMESTAMP,
    valor_compra FLOAT NOT NULL,
    status_compra ENUM('concluída','pendente') NOT NULL,
    forma_pagamento ENUM('pix', 'cartão de crédito', 'cartão de débito', 'dinheiro') NOT NULL,
    parcelas_pagamento INT NOT NULL DEFAULT 0,
    CONSTRAINT fk_usuario_compras FOREIGN KEY (id_usuario) REFERENCES Usuarios(id_usuario)
);
CREATE TABLE Ingressos (
	cod_ingresso INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    id_evento INT NOT NULL,
    id_compra INT NOT NULL,
    id_usuario INT NOT NULL,
    tipo_ingresso ENUM ('comum','premium') NOT NULL,
    valor_ingresso FLOAT NOT NULL,
    status_ingresso ENUM ('usado','não usado') NOT NULL,
    data_emissao DATETIME DEFAULT CURRENT_TIMESTAMP,
    data_realizacao DATETIME NOT NULL,
    validade DATETIME NOT NULL,
    CONSTRAINT fk_evento_ingresso FOREIGN KEY (id_evento) REFERENCES Eventos (id_evento),
    CONSTRAINT fk_compra_ingresso FOREIGN KEY (id_compra) REFERENCES Compras (id_compra),
    CONSTRAINT fk_usuario_ingresso FOREIGN KEY (id_usuario) REFERENCES Usuarios (id_usuario)
);
CREATE TABLE Eventos_favoritados (
	id_favoritado INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    id_usuario INT NOT NULL,
    id_evento INT NOT NULL,
    data_favoritado DATETIME NOT NULL,
    CONSTRAINT fk_evento_favoritado FOREIGN KEY (id_evento) REFERENCES Eventos (id_evento),
    CONSTRAINT fk_usuario_favoritado FOREIGN KEY (id_usuario) REFERENCES Usuarios (id_usuario)
);
CREATE TABLE Carrinho_compras (
	id_item_carrinho INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    id_evento INT NOT NULL,
    id_usuario INT NOT NULL,
    data_adicionado DATETIME NOT NULL,
    CONSTRAINT fk_evento_carrinho FOREIGN KEY (id_evento) REFERENCES Eventos (id_evento),
    CONSTRAINT fk_usuario_carrinho FOREIGN KEY (id_usuario) REFERENCES Usuarios (id_usuario)
);

-- INSERÇÕES

-- USUÁRIOS
INSERT INTO Usuarios (nome_completo, email, data_nascimento, cpf, senha, tipo_usuario) VALUES
('Ana Carolina Silva', 'ana.carol@email.com', '1992-07-22', '111.222.333-44', 'senhaana123', 'comprador'),
('Bruno Costa', 'bruno.c@email.com', '1988-03-10', NULL, 'brunosegura', 'organizador'),
('Camila Santos', 'cami.santos@email.com', '1995-01-05', '222.333.444-55', 'camilasenha', 'comprador'),
('Daniel Oliveira', 'daniel.o@email.com', '1980-09-30', NULL, 'danieldo', 'organizador'),
('Eduarda Lima', 'eduarda.l@email.com', '1993-11-12', '333.444.555-66', 'eduardapwd', 'comprador'),
('Fernando Rocha', 'fer.rocha@email.com', '1975-06-25', NULL, 'fernando_org', 'organizador'),
('Giovanna Alves', 'gio.alves@email.com', '1999-02-18', '444.555.666-77', 'giovanna123', 'comprador'),
('Hugo Pereira', 'hugo.p@email.com', '1982-04-01', NULL, 'hugocomp', 'organizador'),
('Isabela Mendes', 'isabela.m@email.com', '1997-08-08', '555.666.777-88', 'isabelasegura', 'comprador'),
('Julio Cesar', 'julio.c@email.com', '1970-12-03', NULL, 'juliopwr', 'organizador'),
('Karen Dias', 'karen.d@email.com', '1994-05-20', '666.777.888-99', 'karendias', 'comprador'),
('Luiz Alberto', 'luiz.a@email.com', '1987-01-14', NULL, 'luizalberto', 'organizador'),
('Monica Vieira', 'monica.v@email.com', '1991-10-29', '777.888.999-00', 'monicavieira', 'comprador'),
('Nelson Gomes', 'nelson.g@email.com', '1978-07-07', NULL, 'nelsongo', 'organizador'),
('Olivia Fernandes', 'olivia.f@email.com', '1996-03-28', '888.999.000-11', 'oliviafern', 'comprador');
-- ORGANIZADORES
INSERT INTO Organizadores (nome_empresa, cnpj, email, telefone, endereco) VALUES
('Global Eventos SA', '01.234.567/0001-89', 'contato@globaleventos.com', '(11) 2222-3333', 'Av. Paulista, 1000 - São Paulo, SP'),
('Festas & Cia Ltda.', '02.345.678/0001-90', 'atendimento@festasecia.com', '(21) 4444-5555', 'Rua da Praia, 50 - Rio de Janeiro, RJ'),
('Mega Produções Eventos', '03.456.789/0001-01', 'info@megaproducoes.com', '(31) 6666-7777', 'Av. do Contorno, 800 - Belo Horizonte, MG'),
('Experiências Únicas', '04.567.890/0001-12', 'suporte@experienciasunicas.com', '(41) 8888-9999', 'Rua XV de Novembro, 200 - Curitiba, PR'),
('Conecta Eventos Digitais', '05.678.901/0001-23', 'sac@conectaeventos.com', '(51) 0000-1111', 'Av. Borges de Medeiros, 700 - Porto Alegre, RS'),
('Primeiro Plano Eventos', '06.789.012/0001-34', 'comercial@primeiroplano.com', '(85) 1111-2222', 'Rua das Palmeiras, 30 - Fortaleza, CE'),
('Horizonte Eventos', '07.890.123/0001-45', 'orcamento@horizonte.com', '(71) 3333-4444', 'Av. Tancredo Neves, 400 - Salvador, BA'),
('Inovação Eventos', '08.901.234/0001-56', 'contato@inovacao.com', '(61) 5555-6666', 'Setor Comercial Sul, Quadra 1 - Brasília, DF'),
('Realiza Produções', '09.012.345/0001-67', 'vendas@realizaproducoes.com', '(81) 7777-8888', 'Av. Boa Viagem, 600 - Recife, PE'),
('Crescer Eventos', '10.123.456/0001-78', 'faleconosco@crescereventos.com', '(19) 9999-0000', 'Av. Brasil, 900 - Campinas, SP'),
('Sonhos Realizados', '11.234.567/0001-89', 'contato@sonhosrealizados.com', '(11) 2121-3434', 'Praça da Liberdade, 10 - São Paulo, SP'),
('Caminhos Eventos', '12.345.678/0001-90', 'caminhos@eventos.com', '(21) 4545-6767', 'Av. Atlântica, 1200 - Rio de Janeiro, RJ'),
('Mundo Diverso', '13.456.789/0001-01', 'info@mundodiverso.com', '(31) 6767-8989', 'Rua da Bahia, 500 - Belo Horizonte, MG'),
('Ponto de Encontro', '14.567.890/0001-12', 'contato@pontodeencontro.com', '(41) 8989-0101', 'Rua das Flores, 70 - Curitiba, PR'),
('Soluções em Eventos', '15.678.901/0001-23', 'atendimento@solucoes.com', '(51) 0101-2323', 'Av. Protásio Alves, 1500 - Porto Alegre, RS');
-- EVENTOS
INSERT INTO Eventos (nome_evento, descricao, data_evento, hora_inicio, hora_fim, capacidade_maxima, local_evento, id_organizador, status_evento) VALUES
('Festival de Música Verão 2025', 'Um festival de música com diversos artistas nacionais e internacionais, celebrando o verão.', '2025-01-20', '16:00:00', '23:00:00', 10000, 'Parque da Cidade, Indaiatuba', 1, 'programado'),
('Workshop de Fotografia Digital', 'Aprenda técnicas avançadas de fotografia com profissionais renomados.', '2025-02-10', '09:00:00', '17:00:00', 50, 'Estúdio Central, São Paulo', 2, 'programado'),
('Feira de Empreendedorismo e Inovação', 'Conecte-se com startups e investidores, e descubra as últimas inovações.', '2025-03-05', '10:00:00', '19:00:00', 800, 'Expo Center Norte, São Paulo', 3, 'programado'),
('Concurso de Culinária Gourmet', 'Chefs amadores e profissionais competem para criar o prato perfeito.', '2025-04-12', '14:00:00', '20:00:00', 150, 'Clube da Gastronomia, Campinas', 4, 'programado'),
('Maratona Beneficente da Saúde', 'Corra por uma boa causa! Evento de arrecadação de fundos para hospitais.', '2025-05-01', '07:00:00', '12:00:00', 2000, 'Parque Ibirapuera, São Paulo', 5, 'programado'),
('Palestra: Futuro da IA e Robótica', 'Explore as tendências e impactos da inteligência artificial e robótica na sociedade.', '2025-06-18', '19:00:00', '21:00:00', 300, 'Auditório Principal, Curitiba', 6, 'programado'),
('Exposição de Arte Moderna', 'Uma coleção fascinante de obras de arte contemporânea de artistas emergentes.', '2025-07-01', '10:00:00', '18:00:00', 400, 'Galeria de Arte Municipal, Rio de Janeiro', 7, 'programado'),
('Hackathon de Desenvolvimento de Software', 'Desenvolva soluções inovadoras em um fim de semana de programação intensa.', '2025-08-09', '09:00:00', '20:00:00', 100, 'Tech Hub Coworking, Porto Alegre', 8, 'programado'),
('Semana da Sustentabilidade', 'Discussões, workshops e feira de produtos e serviços sustentáveis.', '2025-09-22', '09:00:00', '17:00:00', 600, 'Centro Ecológico, Florianópolis', 9, 'programado'),
('Campeonato de E-sports FIFA 25', 'Os melhores gamers do Brasil se enfrentam no torneio de FIFA 25.', '2025-10-05', '13:00:00', '22:00:00', 700, 'Arena Gamer, Belo Horizonte', 10, 'programado'),
('Feira de Artesanato Local', 'Descubra produtos únicos feitos à mão por artesãos da região.', '2025-11-15', '10:00:00', '18:00:00', 200, 'Praça Central, Indaiatuba', 11, 'programado'),
('Congresso Internacional de Medicina', 'Apresentação das últimas pesquisas e avanços na área médica.', '2025-12-01', '08:00:00', '18:00:00', 1200, 'Centro de Convenções, Brasília', 12, 'programado'),
('Show de Comédia Stand-Up', 'Noite de risadas com os melhores comediantes da atualidade.', '2025-01-25', '20:00:00', '22:00:00', 250, 'Teatro Municipal, São Paulo', 13, 'programado'),
('Encontro de Colecionadores de Vinil', 'Troca, venda e exposição de discos de vinil raros e clássicos.', '2025-02-28', '10:00:00', '16:00:00', 80, 'Mercado de Pulgas, Rio de Janeiro', 14, 'programado'),
('Lançamento de Livro e Sessão de Autógrafos', 'Conheça o autor e participe do lançamento do seu novo best-seller.', '2025-03-10', '18:30:00', '21:00:00', 100, 'Livraria Cultura, Campinas', 15, 'programado');
-- COMPRAS
INSERT INTO Compras (id_usuario, cod_ingresso, valor_compra, status_compra, forma_pagamento, parcelas_pagamento) VALUES
(11, 6, 150.00, 'concluída', 'cartão de crédito', 3),
(14, 3, 75.50, 'concluída', 'pix', 0),
(13, 13, 220.99, 'pendente', 'cartão de crédito', 2),
(15, 9, 50.00, 'concluída', 'dinheiro', 0),
(9, 2, 300.00, 'concluída', 'cartão de débito', 0),
(12, 11, 120.00, 'concluída', 'pix', 0),
(10, 8, 450.00, 'pendente', 'cartão de crédito', 6),
(1, 4, 80.00, 'concluída', 'dinheiro', 0),
(5, 14, 199.90, 'concluída', 'cartão de crédito', 1),
(2, 10, 65.00, 'concluída', 'pix', 0),
(3, 1, 280.50, 'pendente', 'cartão de débito', 0),
(7, 12, 100.00, 'concluída', 'pix', 0),
(14, 7, 350.00, 'concluída', 'cartão de crédito', 4),
(8, 15, 90.00, 'pendente', 'dinheiro', 0),
(6, 5, 500.00, 'concluída', 'cartão de débito', 0);
-- INGRESSOS
INSERT INTO Ingressos (cod_ingresso, id_evento, id_compra, id_usuario, tipo_ingresso, valor_ingresso, status_ingresso, data_realizacao, validade) VALUES
(1, 7, 11, 3, 'comum', 55.00, 'não usado', '2025-07-01 10:00:00', '2025-07-01 18:59:59'),
(2, 1, 5, 9, 'premium', 130.00, 'não usado', '2025-01-20 16:00:00', '2025-01-20 23:59:59'),
(3, 12, 2, 14, 'comum', 75.00, 'usado', '2025-12-01 08:00:00', '2025-12-01 18:59:59'),
(4, 3, 8, 1, 'comum', 40.00, 'não usado', '2025-03-05 10:00:00', '2025-03-05 19:59:59'),
(5, 9, 15, 6, 'premium', 100.00, 'não usado', '2025-09-22 09:00:00', '2025-09-22 17:59:59'),
(6, 5, 1, 11, 'comum', 65.00, 'não usado', '2025-05-01 07:00:00', '2025-05-01 12:59:59'),
(7, 14, 13, 4, 'premium', 95.00, 'usado', '2025-02-28 10:00:00', '2025-02-28 16:59:59'),
(8, 2, 7, 10, 'comum', 50.00, 'não usado', '2025-02-10 09:00:00', '2025-02-10 17:59:59'),
(9, 10, 4, 15, 'premium', 115.00, 'não usado', '2025-10-05 13:00:00', '2025-10-05 22:59:59'),
(10, 6, 10, 2, 'comum', 80.00, 'não usado', '2025-06-18 19:00:00', '2025-06-18 21:59:59'),
(11, 15, 6, 12, 'premium', 140.00, 'não usado', '2025-03-10 18:30:00', '2025-03-10 21:59:59'),
(12, 4, 12, 7, 'comum', 35.00, 'usado', '2025-04-12 14:00:00', '2025-04-12 20:59:59'),
(13, 8, 3, 13, 'comum', 70.00, 'não usado', '2025-08-09 09:00:00', '2025-08-09 20:59:59'),
(14, 11, 9, 5, 'premium', 105.00, 'não usado', '2025-11-15 10:00:00', '2025-11-15 18:59:59'),
(15, 13, 14, 8, 'comum', 45.00, 'não usado', '2025-01-25 20:00:00', '2025-01-25 22:59:59');
-- FAVORITADOS
INSERT INTO Eventos_favoritados (id_usuario, id_evento, data_favoritado) VALUES
(14, 1, '2025-05-20 10:30:00'),
(9, 3, '2025-05-21 14:00:00'),
(10, 5, '2025-05-22 09:15:00'),
(2, 2, '2025-05-22 11:45:00'),
(8, 7, '2025-05-23 16:20:00'),
(4, 9, '2025-05-23 18:00:00'),
(6, 11, '2025-05-24 08:00:00'),
(13, 4, '2025-05-24 13:00:00'),
(11, 6, '2025-05-24 15:30:00'),
(7, 8, '2025-05-25 09:40:00'),
(3, 10, '2025-05-25 11:00:00'),
(1, 12, '2025-05-25 14:10:00'),
(14, 1, '2025-05-25 17:00:00'), -- Mesmo usuário favoritando outro evento
(15, 3, '2025-05-26 09:00:00'),
(12, 5, '2025-05-26 10:25:00');
-- CARRINHO
INSERT INTO Carrinho_compras (id_evento, id_usuario, data_adicionado) VALUES
(3, 8, '2025-05-26 15:00:00'),
(2, 4, '2025-05-26 15:05:00'),
(11, 4, '2025-05-26 15:10:00'),
(9, 4, '2025-05-26 15:15:00'),
(4, 7, '2025-05-26 15:20:00'),
(7, 11, '2025-05-26 15:25:00'),
(12, 5, '2025-05-26 15:30:00'),
(15, 2, '2025-05-26 15:35:00'),
(5, 9, '2025-05-26 15:40:00'),
(10, 10, '2025-05-26 15:45:00'),
(14, 7, '2025-05-26 15:50:00'),
(1, 3, '2025-05-26 15:55:00'),
(8, 11, '2025-05-26 16:00:00'),
(13, 8, '2025-05-26 16:05:00'),
(6, 1, '2025-05-26 16:10:00');

-- LISTAGENS

SELECT * FROM Usuarios;
SELECT * FROM Eventos;
SELECT * FROM Organizadores;
SELECT * FROM Compras;
SELECT * FROM Ingressos;
SELECT * FROM Eventos_favoritados;
SELECT * FROM Carrinho_compras;



-- APAGAMENTO

-- ALTER TABLE Eventos DROP FOREIGN KEY fk_organizador_evento;
-- ALTER TABLE Compras DROP FOREIGN KEY fk_usuario_compras;
-- ALTER TABLE Ingressos DROP FOREIGN KEY fk_evento_ingresso;
-- ALTER TABLE Ingressos DROP FOREIGN KEY fk_compra_ingresso;
-- ALTER TABLE Ingressos DROP FOREIGN KEY fk_usuario_ingresso;
-- ALTER TABLE Eventos_favoritados DROP FOREIGN KEY fk_evento_favoritado;
-- ALTER TABLE Eventos_favoritados DROP FOREIGN KEY fk_usuario_favoritado;
-- ALTER TABLE Carrinho_compras DROP FOREIGN KEY fk_evento_carrinho;
-- ALTER TABLE Carrinho_compras DROP FOREIGN KEY fk_usuario_carrinho;
-- DROP TABLE Usuarios;
-- DROP TABLE Eventos;
-- DROP TABLE Organizadores;
-- DROP TABLE Compras;
-- DROP TABLE Ingressos;
-- DROP TABLE Eventos_favoritados;
-- DROP TABLE Carrinho_compras;