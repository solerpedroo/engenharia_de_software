## Aula 03/11

### Anotações Gerais

- Dados sensíveis: aquilo que pertence a alguém e não é público 

- Dados identificáveis: aqueles que identificam uma empresa ou pessoa
    - exemplo: CNPJ

- LGPD: foi feito para pegar gente de má fé

- Privacidade e direito de propriedade vão além da LGPD, são constitucionais

- Exemplo de criptografia física: chave de acesso yubico

- Contas de empresa / coorporativas, o ideal é não ter nenhuma maneira de recuperação, apenas a chave física

- Protocolo FIDO

- Vazamento de dados ocorre geralmente por mãos humanas

### Como aplicar corretamente a LGPD numa empresa

1. Criptografia de dados sensíveis e identificáveis, contas devem possuir em claro, por exemplo: email de acesso, mas o resto do registro todo cifrado. Motivo: se alguém roubar (acesso indevido) a tabela de clientes, nada se perde. 

2. As chaves criptográficas do cliente ficam num provedor de chaves, que chamamos de cofre de chaves digitais. Esse cofre só uma ou duas pessoas no máximo têm acessos. Quando o cliente vai fazer o login, o cofre entra em ação e tenta comparar a senha digitada com a senha armazenada (sem tornar a senha em claro). Sistema de KeyVault.

3. Definir políticas internas de acesso e compliance dos dados. Comitê de LGPD / Segurança de dados onde o CSO e o CIO façam parte obrigatoriamente. Desde o início de um negócio, cuidar da segmentação de acesso aos dados. 

4. Um cliente de ecommerce solicitou a remocação / exclusão completa de seus dados de uma plataforma (inclusive dos backups). Considerando o MongoDB: se todos os pedidos de compra do cliente, estão como subdocumentos do cliente numa coleção clientes, e todo resto concentrado em um único documento, o apagamento é fácil. Basta remover o documento e tudo será excluído.

5. Defina nas políticas da empresa, termos de aceite para que o cliente concorde com que será feito com os dados dele. Exemplo: na hora de criar a cotna (ler os termos/políticas)