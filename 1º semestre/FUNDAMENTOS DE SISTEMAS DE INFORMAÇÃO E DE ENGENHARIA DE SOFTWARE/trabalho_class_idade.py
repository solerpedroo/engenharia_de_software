# sem o quarto requisito

# lista_inadimplentes = ["Carlos Silva", "Ana Souza", "João Lima"]
# def verificar_elegibilidade(nome, idade, renda):
#     motivos = []
#     if idade < 18:
#         motivos.append("Idade inferior a 18 anos.")
#     if renda < 2000:
#         motivos.append("Renda mensal inferior a R$ 2.000.")
#     if nome in lista_inadimplentes:
#         motivos.append("Nome consta na lista de inadimplentes.")
#     if not motivos:
#         print(f"{nome} é elegível para o empréstimo.")
#     else:
#         print(f"{nome} **não é elegível** para o empréstimo pelos seguintes motivos:")
#         for motivo in motivos:
#             print("- " + motivo)
# nome = input("Digite o nome: ")
# idade = int(input("Digite a idade: "))
# renda = float(input("Digite a renda mensal (em R$): "))
# verificar_elegibilidade(nome, idade, renda)

# com o quarto requisito

lista_inadimplentes = ["Carlos Silva", "Ana Souza", "João Lima"]
def verificar_elegibilidade(nome, idade, renda, escolaridade):
    motivos = []
    if idade < 18:
        motivos.append("Idade inferior a 18 anos.")
    if renda < 2000:
        motivos.append("Renda mensal inferior a R$ 2.000.")
    if escolaridade.upper() != "SUPERIOR":
        motivos.append("Escolaridade não é de nível superior")
    if nome in lista_inadimplentes:
        motivos.append("Nome consta na lista de inadimplentes.")
    return (len(motivos) == 0, motivos)
if __name__ == "__main__":
    nome = input("Digite o nome: ")
    idade = int(input("Digite a idade: "))
    renda = float(input("Digite a renda mensal (em R$): "))
    escolaridade = input("Digite o seu nível de escolaridade: ").upper()
    resultado, motivos = verificar_elegibilidade(nome, idade, renda, escolaridade)
    if resultado:
        print(f"{nome} é elegível para o empréstimo.")
    else:
        print(f"{nome} **não é elegível** para o empréstimo pelos seguintes motivos:")
        for motivo in motivos:
            print("- " + motivo)