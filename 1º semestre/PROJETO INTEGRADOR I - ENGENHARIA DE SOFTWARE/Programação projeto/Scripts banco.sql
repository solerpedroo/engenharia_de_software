show databases;	

-- CREATE database ProjetoSustentabilidade;

USE ProjetoSustentabilidade;

show tables;

SELECT * FROM projetodesustentabilidade;

SELECT * FROM manipulacao_dados;

CREATE TABLE ProjetoDeSustentabilidade( 
  ID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
  DataEntrada VARCHAR (50) NOT NULL,
  LitrosConsumidos VARCHAR (50) NOT NULL,
  KWHConsumido VARCHAR (50) NOT NULL, 
  KgNaoReciclaveis VARCHAR (50) NOT NULL, 
  PorcentagemResiduos VARCHAR (50) NOT NULL, 
  MeioDeTransporte VARCHAR (250)
  );

ALTER TABLE projetodesustentabilidade  MODIFY COLUMN DataEntrada VARCHAR (50);
ALTER TABLE projetodesustentabilidade  MODIFY COLUMN LitrosConsumidos VARCHAR (50);
ALTER TABLE projetodesustentabilidade  MODIFY COLUMN  KWHConsumido VARCHAR (50);
ALTER TABLE projetodesustentabilidade  MODIFY COLUMN KgNaoReciclaveis VARCHAR (50);
ALTER TABLE projetodesustentabilidade  MODIFY COLUMN PorcentagemResiduos VARCHAR (50);
ALTER TABLE projetodesustentabilidade  MODIFY COLUMN MeioDeTransporte VARCHAR (250);
    
CREATE TABLE Manipulacao_Dados( 
  ID_Usuario INT NOT NULL,
  Nivel_LitrosConsumidos VARCHAR (50) NOT NULL,
  Nivel_KWHConsumido VARCHAR (50) NOT NULL, 
  Nivel_KgNaoReciclaveis VARCHAR (50) NOT NULL, 
  Nivel_MeioDeTransporte VARCHAR (50) NOT NULL
  );
  
ALTER TABLE Manipulacao_Dados
ADD CONSTRAINT fk_usuario
FOREIGN KEY (ID_Usuario)
REFERENCES ProjetoDeSustentabilidade (ID);

DELETE FROM Manipulacao_Dados WHERE ID_Usuario = 28;
DELETE FROM ProjetoDeSustentabilidade WHERE ID = 28;	

SELECT LitrosConsumidos, KWHConsumido FROM projetodesustentabilidade WHERE ID = 10;

UPDATE ProjetoDeSustentabilidade
SET 
    LitrosConsumidos = 2,
    KWHConsumido = 3
WHERE ID = 10;