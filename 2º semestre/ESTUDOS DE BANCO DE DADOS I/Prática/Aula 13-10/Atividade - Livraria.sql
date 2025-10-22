SELECT USER FROM dual;

-- ======================================================
-- 1. CRIAÇÃO DAS TABELAS
-- ======================================================

CREATE TABLE CLIENTE (
    Cod_Cliente NUMBER(6) PRIMARY KEY,
    Nome VARCHAR2(100) NOT NULL,
    CPF CHAR(11) UNIQUE NOT NULL,
    Telefone VARCHAR2(15)
);

CREATE TABLE VENDEDOR (
    Cod_Vendedor NUMBER(6) PRIMARY KEY,
    Nome VARCHAR2(100) NOT NULL,
    Percentual_Comissao NUMBER(5,2)
);

CREATE TABLE LIVRO (
    Cod_Livro NUMBER(6) PRIMARY KEY,
    Titulo VARCHAR2(150) NOT NULL,
    Autor VARCHAR2(100),
    Preco NUMBER(8,2) NOT NULL,
    Estoque_Atual NUMBER(5)
);

CREATE TABLE VENDA (
    Cod_Venda NUMBER(6) PRIMARY KEY,
    Data_Venda DATE DEFAULT SYSDATE,
    fk_Cliente_Cod_Cliente NUMBER(6) NOT NULL,
    fk_Vendedor_Cod_Vendedor NUMBER(6) NOT NULL,
    CONSTRAINT fk_Cliente_Cod_Cliente FOREIGN KEY (fk_Cliente_Cod_Cliente)
        REFERENCES CLIENTE (Cod_Cliente),
    CONSTRAINT fk_Vendedor_Cod_Vendedor FOREIGN KEY (fk_Vendedor_Cod_Vendedor)
        REFERENCES VENDEDOR (Cod_Vendedor)
);

CREATE TABLE ITEM_VENDA (
    fk_Venda_Cod_Venda NUMBER(6) NOT NULL,
    fk_Livro_Cod_Livro NUMBER(6) NOT NULL,
    Quantidade NUMBER(4) NOT NULL,
    Preco_Venda NUMBER(8,2) NOT NULL,
    CONSTRAINT pk_Item_Venda PRIMARY KEY (fk_Venda_Cod_Venda, fk_Livro_Cod_Livro),
    CONSTRAINT fk_Venda_Cod_Venda FOREIGN KEY (fk_Venda_Cod_Venda)
        REFERENCES VENDA (Cod_Venda),
    CONSTRAINT fk_Livro_Cod_Livro FOREIGN KEY (fk_Livro_Cod_Livro)
        REFERENCES LIVRO (Cod_Livro)
);

-- ======================================================
-- 2. INSERÇÃO DE DADOS DE EXEMPLO
-- ======================================================

-- CLIENTE
INSERT INTO CLIENTE VALUES (1, 'Ana Pereira', '12345678901', '1199887766');
INSERT INTO CLIENTE VALUES (2, 'Bruno Souza', '98765432100', '2199554433');
INSERT INTO CLIENTE VALUES (3, 'Carla Lima', '32165498712', '1199332244');
INSERT INTO CLIENTE VALUES (4, 'Diego Costa', '65498732109', '1199776655');
INSERT INTO CLIENTE VALUES (5, 'Elisa Martins', '45678912345', '3199223344');

-- VENDEDOR
INSERT INTO VENDEDOR VALUES (10, 'João Ribeiro', 5.00);
INSERT INTO VENDEDOR VALUES (11, 'Mariana Lopes', 6.50);
INSERT INTO VENDEDOR VALUES (12, 'Paulo Fernandes', 4.75);
INSERT INTO VENDEDOR VALUES (13, 'Fernanda Alves', 5.25);
INSERT INTO VENDEDOR VALUES (14, 'Ricardo Santos', 6.00);

-- LIVRO
INSERT INTO LIVRO VALUES (100, 'Dom Casmurro', 'Machado de Assis', 39.90, 50);
INSERT INTO LIVRO VALUES (101, 'O Cortiço', 'Aluísio Azevedo', 29.50, 60);
INSERT INTO LIVRO VALUES (102, 'Capitães da Areia', 'Jorge Amado', 45.00, 40);
INSERT INTO LIVRO VALUES (103, 'Vidas Secas', 'Graciliano Ramos', 34.90, 30);
INSERT INTO LIVRO VALUES (104, 'Memórias Póstumas de Brás Cubas', 'Machado de Assis', 42.50, 70);

-- VENDA
INSERT INTO VENDA VALUES (1000, TO_DATE('2025-10-01', 'YYYY-MM-DD'), 1, 10);
INSERT INTO VENDA VALUES (1001, TO_DATE('2025-10-03', 'YYYY-MM-DD'), 2, 11);
INSERT INTO VENDA VALUES (1002, TO_DATE('2025-10-04', 'YYYY-MM-DD'), 3, 12);
INSERT INTO VENDA VALUES (1003, TO_DATE('2025-10-05', 'YYYY-MM-DD'), 4, 13);
INSERT INTO VENDA VALUES (1004, TO_DATE('2025-10-06', 'YYYY-MM-DD'), 5, 14);


-- ITEM_VENDA
-- Venda 1000 (Cliente 1 - Vendedor 10)
INSERT INTO ITEM_VENDA VALUES (1000, 100, 2, 39.90);
INSERT INTO ITEM_VENDA VALUES (1000, 104, 1, 42.50);

-- Venda 1001 (Cliente 2 - Vendedor 11)
INSERT INTO ITEM_VENDA VALUES (1001, 101, 1, 29.50);
INSERT INTO ITEM_VENDA VALUES (1001, 102, 1, 45.00);

-- Venda 1002 (Cliente 3 - Vendedor 12)
INSERT INTO ITEM_VENDA VALUES (1002, 103, 2, 34.90);
INSERT INTO ITEM_VENDA VALUES (1002, 104, 1, 42.50);

-- Venda 1003 (Cliente 4 - Vendedor 13)
INSERT INTO ITEM_VENDA VALUES (1003, 100, 1, 39.90);
INSERT INTO ITEM_VENDA VALUES (1003, 102, 1, 45.00);

-- Venda 1004 (Cliente 5 - Vendedor 14)
INSERT INTO ITEM_VENDA VALUES (1004, 101, 1, 29.50);
INSERT INTO ITEM_VENDA VALUES (1004, 103, 1, 34.90);

COMMIT;

-- ======================================================
-- 3. CONSULTAS
-- ======================================================

-- 1. Listar todos os clientes cadastrados.
SELECT * FROM CLIENTE;

-- 2. Mostrar o nome dos vendedores e suas comissões.
SELECT Nome, Percentual_Comissao
FROM VENDEDOR;

-- 3. Listar todos os livros com preço e estoque.
SELECT Titulo, Autor, Preco, Estoque_Atual
FROM LIVRO;

-- 4. Exibir as vendas realizadas (código da venda, data, cliente e vendedor).
SELECT V.Cod_Venda, V.Data_Venda, C.Nome AS Nome_Cliente, VD.Nome AS Nome_Vendedor
FROM VENDA V
JOIN CLIENTE C ON V.fk_Cliente_Cod_Cliente = C.Cod_Cliente
JOIN VENDEDOR VD ON V.fk_Vendedor_Cod_Vendedor = VD.Cod_Vendedor;

-- 5. Mostrar quais produtos cada cliente comprou, incluindo a quantidade vendida.
SELECT C.Nome AS Cliente, L.Titulo AS Livro, IV.Quantidade
FROM ITEM_VENDA IV
JOIN VENDA V ON IV.fk_Venda_Cod_Venda = V.Cod_Venda
JOIN CLIENTE C ON V.fk_Cliente_Cod_Cliente = C.Cod_Cliente
JOIN LIVRO L ON IV.fk_Livro_Cod_Livro = L.Cod_Livro
ORDER BY C.Nome;

-- 6. Exibir quais clientes foram atendidos por um vendedor específico.
SELECT VD.Nome AS Vendedor, C.Nome AS Cliente
FROM VENDA V
JOIN CLIENTE C ON V.fk_Cliente_Cod_Cliente = C.Cod_Cliente
JOIN VENDEDOR VD ON V.fk_Vendedor_Cod_Vendedor = VD.Cod_Vendedor
WHERE VD.Nome = 'Ricardo Santos';

-- 7. Listar o total de itens vendidos em cada venda.
SELECT V.Cod_Venda, COUNT(*) AS Total_Itens
FROM ITEM_VENDA IV
JOIN VENDA V ON IV.fk_Venda_Cod_Venda = V.Cod_Venda
GROUP BY V.Cod_Venda;

COMMIT;