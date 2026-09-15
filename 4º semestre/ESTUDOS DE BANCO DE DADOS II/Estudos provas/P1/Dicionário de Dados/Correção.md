# Dicionário de Dados do Sistema de Controle de Atendimentos Veterinários da Clínica PetCare Campinas

## Histórico de Versões

| Data | Autor | Versão | Observações |
|---|---|---|---|
| 13/09/2026 | Pedro Soler | 1.0.0 | Versão Inicial do dicionário de dados, especificando as entidades: Tutor, Animal, Consulta, Prescrição e Veterinário, e seus respectivos atributos. |

---

# 1. Tutor

**Descrição:** Representa uma pessoa responsável por um ou mais animais atendidos pela clínica.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro Único | Sim | Identifica unicamente o tutor no sistema. |
| Nome | String livre | Sim | Nome completo do tutor. |
| Documento | Par chave-valor | Sim | Documentos de identificação do tutor, como CPF, RG, CNH e outros documentos aceitos. |
| Contatos | Lista | Não | Lista de formas de contato, como e-mail, telefone fixo e telefone celular. |

---

# 2. Animal

**Descrição:** Representa um animal cadastrado na clínica e vinculado a um tutor.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro Único | Sim | Identifica unicamente o animal no sistema. |
| Nome | String livre | Sim | Nome do animal. |
| Espécie | String livre | Sim | Espécie do animal, como cão, gato etc. |
| Raça | String livre | Não | Raça do animal, podendo permanecer vazia quando desconhecida. |
| Sexo | Lista lateral e estática de valores | Sim | Valores definidos pelo sistema. |
| Data de nascimento | Data | Sim | Data de nascimento do animal. |
| Observações | String livre | Não | Informações adicionais sobre o animal. |
| Tutor | Inteiro | Sim | Código do tutor responsável pelo animal. Deve corresponder a um tutor previamente cadastrado. |

---

# 3. Consulta

**Descrição:** Representa uma consulta veterinária realizada ou agendada para um animal.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro Único | Sim | Identifica unicamente a consulta no sistema. |
| Animal | Inteiro | Sim | Código do animal atendido. Deve corresponder a um animal previamente cadastrado. |
| Veterinário | Inteiro | Sim | Código do veterinário responsável pela consulta. Deve corresponder a um veterinário previamente cadastrado. |
| Data | Data | Sim | Data da consulta. |
| Horário | Horário | Sim | Horário da consulta. |
| Situação | Lista lateral e estática de valores | Sim | Valores aceitos: `"AGENDADA"`, `"CANCELADA"` e `"CONCLUÍDA"`. |
| Valor | Decimal | Sim | Valor cobrado pela consulta. |
| Observações | String livre | Não | Observações registradas durante o atendimento. |
| Prescrições | Lista de inteiros | Não | Lista contendo os códigos das prescrições associadas à consulta. |

---

# 4. Prescrição

**Descrição:** Representa uma recomendação ou orientação médica realizada durante uma consulta, como medicamentos e tratamentos.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro Único | Sim | Identifica unicamente a prescrição no sistema. |
| Medicamento | String livre | Sim | Nome do medicamento prescrito. |
| Dosagem | Decimal/Estrutura | Sim | Valor e unidade da dosagem do medicamento. |
| Frequência | String/Estrutura | Sim | Frequência do tratamento, como `"2 vezes ao dia"` ou `"a cada 8 horas"`. |
| Duração | String/Estrutura | Sim | Duração do tratamento, como `"7 dias"` ou `"2 semanas"`. |
| Consulta | Inteiro | Sim | Código da consulta à qual a prescrição pertence. |

---

# 5. Veterinário

**Descrição:** Representa um veterinário responsável pela realização de consultas na clínica.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro Único | Sim | Identifica unicamente o veterinário no sistema. |
| Nome | String livre | Sim | Nome completo do veterinário. |
| Registro profissional | Inteiro/String | Sim | Número do registro profissional do veterinário. |
| Especialidades | Lista | Sim | Lista contendo uma ou mais especialidades do veterinário. |
| Contatos | Lista | Sim | Formas de contato do veterinário, como e-mail, telefone fixo e telefone celular. |
