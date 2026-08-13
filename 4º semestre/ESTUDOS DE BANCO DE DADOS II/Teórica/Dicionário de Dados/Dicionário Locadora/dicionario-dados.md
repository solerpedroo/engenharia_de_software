# Título Incorreto: Dicionário de Dados: Sistema de Locação de Veículos
> Incorreto porque é genérico demais.

# Título mais adequado: Dicionário de Dados do Sistema de Locação de Veículos Automotores de Passeio da Localiza/SA
> Esse título especifica que o dicionário de dados se aplica ao contexto apenas de locação de veículos para a empresa Localiza/SA.

## Histórico de Revisões (ou Versões)

|Data|Autor|Versão|Observações|
|----|-----|------|-----------|
|10/08/2026|Pedro Soler| 1.0.0 | Versão Inicial do dicionário de dados, especificando as entidades: Cliente, Veículo, Locação|

## Entidades

A seguir são documentadas as entidades e seus dados (atributos) que serão necessárias para suportar todas as operações que o sistema de locação necessita.

### 1. Cliente 

Descrição: Representa uma pessoa física ou jurídica (empresa) que aluga um ou mais veículos ao longo do tempo. É importante destacar que clientes que nunca alugaram um veículo, devem ser representados também.

Atributos: 

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários | 
|------|------|-----------------|----------|
|Código|Inteiro Único|Sim|Este dado diferencia o cliente em relação aos demais em todas as partes do sistema. São aceitos números de 1 a inteiro longo maior possível, acrescidos de um em um.|
|Tipo| Lista lateral e estática de valores|Sim|A lista é composta de apenas dois valores: Física (pessoa física) e Jurídica (empresa). Não devem ser acrescentados valores futuros e só deve ser atribuído um único valor para o tipo: física ou jurídica.|
|Documento|Par chave-valor|Sim| Chave é uma lista estática contendo: "CPF", "CNPJ", "PASSAPORTE" (pesquisar se o passaporte serve para emissão de um documento fiscal, caso o cliente seja estrangeiro). Valor: Conteúdo textual do documento, com formatação própria.|
|Nome|String livre sem caractéres especiais|Sim|Este é um campo que armazenará pela primeira vez o nome do cliente. Após a emissão da primeira nota fiscal, o nome ou razão social da empresa é corrigido de acordo com a receita federal. Sempre o nome será armazenado em maiúsculo para não ter variações ou problemas de formatação em relatórios e listas.|

### 2. Veículo

Descrição: Representa um veículo pertencente à frota da locadora, que pode ser disponibilizado para aluguel por diferentes clientes ao longo do tempo. Cada veículo deve ser representado independentemente de já ter sido alugado ou não.

Atributos:

| Nome    | Tipo          | Obrigatoriedade | Exemplos/Comentários                                                                                                                                                 |
| ------- | ------------- | --------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Código  | Inteiro Único | Sim             | Este dado diferencia o veículo em relação aos demais em todas as partes do sistema. São aceitos números de 1 a inteiro longo maior possível, acrescidos de um em um. |
| Placa   | Texto         | Sim             | Identificação do veículo utilizada para circulação. Deve seguir o padrão de placas adotado no Brasil, como "ABC1D23".                                                |
| Chassi  | Texto         | Sim             | Número de identificação único do veículo, composto por 17 caracteres.                                                                                                |
| RENAVAM | Texto         | Sim             | Registro Nacional de Veículos Automotores que identifica o veículo perante os órgãos de trânsito.                                                                    |
| Marca   | Texto         | Sim             | Marca do fabricante do veículo, como "Chevrolet", "Toyota" ou "Volkswagen".                                                                                          |
| Modelo  | Texto         | Sim             | Modelo do veículo, como "Onix", "Corolla" ou "Gol".                                                                                                                  |
| Ano     | Inteiro       | Sim             | Ano de fabricação ou modelo do veículo, conforme o critério adotado pelo sistema.                                                                                    |
| Status  | Texto         | Sim             | Indica a situação atual do veículo na locadora. São aceitos valores como: "DISPONÍVEL", "ALUGADO", "EM MANUTENÇÃO" e "INATIVO".                                      |


### 3. Locação

Descrição: Representa o registro de uma locação realizada por um cliente, vinculando-o a um veículo durante determinado período. Cada locação deve registrar as informações necessárias para controlar o aluguel, independentemente de a locação estar em andamento ou já ter sido encerrada.

Atributos:

| Nome                     | Tipo          | Obrigatoriedade | Exemplos/Comentários                                                                                                                                                |
| ------------------------ | ------------- | --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Código                   | Inteiro Único | Sim             | Este dado diferencia a locação em relação às demais em todas as partes do sistema. São aceitos números de 1 a inteiro longo maior possível, acrescidos de um em um. |
| Data de início           | Data          | Sim             | Data em que a locação é iniciada pelo cliente.                                                                                                                      |
| Data de término prevista | Data          | Sim             | Data prevista para a devolução do veículo pelo cliente.                                                                                                             |
| Data de término real     | Data          | Não             | Data em que o veículo foi efetivamente devolvido. Deve permanecer vazia enquanto a locação estiver em andamento.                                                    |
| Valor da diária          | Decimal       | Sim             | Valor cobrado por cada diária do veículo no momento da locação.                                                                                                     |
| Valor total              | Decimal       | Sim             | Valor total calculado para a locação, considerando o período e o valor da diária.                                                                                   |
| Status                   | Texto         | Sim             | Indica a situação atual da locação. São aceitos valores como: "ATIVA", "ENCERRADA" e "CANCELADA".                                                                   |
| Cliente                  | Inteiro       | Sim             | Código que identifica o cliente responsável pela locação. Deve corresponder a um cliente previamente cadastrado.                                                    |
| Veículo                  | Inteiro       | Sim             | Código que identifica o veículo alugado. Deve corresponder a um veículo previamente cadastrado.                                                                     |

### 4. Condutor 

Descrição: Representa uma pessoa física autorizada a conduzir um ou mais veículos da locadora durante uma locação. O condutor deve possuir uma habilitação válida e compatível com o veículo que irá conduzir, podendo ser brasileiro ou estrangeiro.

Atributos:

| Nome             | Tipo            | Obrigatoriedade | Exemplos/Comentários                                                                                                                                                                                                                               |
| ---------------- | --------------- | --------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Código           | Inteiro Único   | Sim             | Este dado diferencia o condutor em relação aos demais em todas as partes do sistema. São aceitos números de 1 a inteiro longo maior possível, acrescidos de um em um.                                                                              |
| Nome             | Texto           | Sim             | Nome completo do condutor.                                                                                                                                                                                                                         |
| Documento        | Par chave-valor | Sim             | Chave é uma lista estática contendo: "CPF", "PASSAPORTE", entre outros documentos de identificação aceitos. Valor: número ou identificação correspondente ao documento. Para documentos estrangeiros, deve ser informado também o país de emissão. |
| Habilitação      | Par chave-valor | Sim             | Chave é uma lista estática contendo: "CNH", "CARTEIRA_ESTRANGEIRA". Valor: número correspondente à habilitação do condutor. Deve conter também informações sobre categoria, data de emissão, data de validade e país de emissão.                   |
| Categoria        | Texto           | Sim             | Categoria da habilitação do condutor. Para habilitações brasileiras, podem ser utilizados valores como "A", "B", "C", "D" e "E".                                                                                                                   |
| Data de emissão  | Data            | Sim             | Data em que a habilitação foi emitida.                                                                                                                                                                                                             |
| Data de validade | Data            | Sim             | Data limite de validade da habilitação. Deve ser utilizada para verificar se o condutor está habilitado no período da locação.                                                                                                                     |
| País de emissão  | Texto           | Sim             | País responsável pela emissão da habilitação. Para uma CNH brasileira, o valor pode ser "BRA"; para uma carteira norte-americana, por exemplo, "EUA".                                                                                              |
| E-mail           | Texto           | Não             | Endereço de e-mail utilizado para contato com o condutor.                                                                                                                                                                                          |
| Telefones        | Lista           | Não             | Lista de números de telefone utilizados para contato com o condutor. Pode conter informações como código do país, código de área, número, indicação de celular, WhatsApp e telefone principal.                                                     |
