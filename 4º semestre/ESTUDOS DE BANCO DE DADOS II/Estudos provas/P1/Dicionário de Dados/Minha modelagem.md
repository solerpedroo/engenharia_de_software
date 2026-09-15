# Dicionário de Dados do Sistema de Controle de Atendimentos de Clientes da Clínica Veterinária PetCare Campinas

## Histórico de Versões

| Data | Autor | Versão | Observações |
|---|---|---|---|
| 13/09/2026 | Pedro Soler | 1.0.0 | Versão inicial do dicionário de dados, especificando as entidades: Tutores, Animais, Consultas Veterinárias, Prescrição e Veterinários, e seus respectivos atributos. |

---

# 1. Tutor

**Descrição:** Representa uma pessoa física que trabalha na clínica.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro único | Sim | Diferencia o tutor dos demais presentes no sistema. |
| Nome | String livre | Sim | Indica o nome do tutor. |
| Documento | Par chave-valor | Sim | Lista estática contendo os documentos do tutor, como RG, CPF, CNH e afins. |
| Contato | Par chave-valor | Sim | Lista estática contendo os contatos do tutor, como e-mail, telefone fixo, telefone celular e afins. |

---

# 2. Animal

**Descrição:** Representa o animal que será consultado na clínica.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro único | Sim | Diferencia o animal dos demais. |
| Nome | String livre | Sim | Indica o nome do animal. |
| Espécie | String livre | Sim | Indica a espécie do animal. |
| Raça | String livre | Sim | Indica a raça do animal. |
| Sexo | Lista lateral e estática de valores | Sim | Indica o sexo do animal: feminino ou masculino. |
| Data de nascimento | Data | Sim | Indica a data em que o animal nasceu. |
| Observações | String livre | Não | Indica informações extras do animal. |
| Tutor | Inteiro | Sim | Indica a qual tutor o animal pertence. |

---

# 3. Consulta

**Descrição:** Representa a consulta do animal na clínica e suas informações durante o processo.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro único | Sim | Diferencia a consulta das demais. |
| Animal | Inteiro | Sim | Indica qual animal foi consultado; deve corresponder ao código do animal previamente cadastrado. |
| Data | Data | Sim | Indica a data em que o animal foi consultado. |
| Horário | Horário | Sim | Indica o horário em que o animal foi consultado. |
| Situação | Lista lateral e estática | — | Indica a situação da consulta naquele momento, ex.: `{"AGENDA", "CANCELADA", "CONCLUIDA"}`. |
| Valor | Decimal | Sim | Valor daquela consulta. |
| Observações | String livre | Não | Indica possíveis observações durante a consulta do animal. |
| Prescrição | Inteiro | Não | Indica o respectivo código de uma possível prescrição daquele animal. |

---

# 4. Prescrição

**Descrição:** Indica uma possível recomendação para o animal, como medicação, tratamento e afins.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro único | Sim | Diferencia uma prescrição da outra. |
| Medicamento | String livre | Sim | Indica o medicamento que o animal deverá tomar. |
| Dosagem | Inteiro | Sim | Indica a dosagem que o animal deverá tomar por vez. |
| Frequência | Inteiro | Sim | Indica a frequência com que o animal deverá tomar o medicamento no dia ou no período da prescrição. |
| Duração | Decimal | Sim | Indica a duração do tratamento. |
| Consulta | Inteiro | Sim | Indica o código da respectiva consulta. |

---

# 5. Veterinário

**Descrição:** Indica os veterinários que trabalham na clínica.

| Nome | Tipo | Obrigatoriedade | Exemplos/Comentários |
|---|---|---|---|
| Código | Inteiro único | Sim | Indica um código único para cada veterinário. |
| Nome | String | Sim | Indica o nome do veterinário. |
| Registro profissional | Inteiro | Sim | Indica o número do registro profissional do veterinário. |
| Especialidade | Lista | Sim | Indica a(s) especialidade(s) que o veterinário atende. |
| Contato | Chave-valor | Sim | Indica as formas de contato, ex.: e-mail, telefone fixo, telefone celular e afins. |
| Animais | Lista | Sim | Indica quais animais ele já atendeu e o respectivo código do animal. |
| Consultas | Lista | Sim | Indica quais consultas ele já realizou e o respectivo código da consulta. |
