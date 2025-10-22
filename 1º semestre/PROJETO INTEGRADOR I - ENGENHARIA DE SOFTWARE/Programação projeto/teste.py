# # Declarando a tabela do alfabeto
# T = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

# chave = [[4,3],[1,2]]

# # Função de multiplicação de matrizes
# def matmul(A, B):
#     result = [[0]*len(B[0]) for _ in range(len(A))]
#     for i in range(len(A)):
#         for j in range(len(B[0])):
#             for k in range(len(B)):
#                 result[i][j] += A[i][k] * B[k][j]
#     return result

# # Transposição de matriz (para exibição)
# def transpose(matrix):
#     return [list(row) for row in zip(*matrix)]

# def criptografia_palavras(chave, nome):
#     nome = nome.upper().replace(' ', '')

#     # Vetor de indexação
#     I = []
#     for i in range(len(nome)):
#         pos = T.index(nome[i])
#         I.append(pos + 1)   

#     # Caso a palavra tenha um tamanho ímpar, repete a última letra 
#     if len(nome) % 2 != 0:
#         I.append(I[-1])

#     # Construindo matriz P
#     P = [[], []]
#     for i in range(len(I)):
#         if i % 2 == 0:
#             P[0].append(I[i])
#         else:
#             P[1].append(I[i])

#     # Multiplicando matriz chave por P
#     C = matmul(chave, P)

#     # Ajustando valores para módulo 26
#     for i in range(len(C)):
#         for j in range(len(C[0])):
#             C[i][j] %= 26
#             if C[i][j] == 0:
#                 C[i][j] = 26

#     # Convertendo para letras
#     TC = []
#     for i in range(len(C)):
#         for j in range(len(C[0])):
#             TC.append(T[C[i][j]-1])

#     # Organizando o resultado final
#     cripto = [[],[]]
#     metade = len(TC) // 2
#     for i in range(metade):
#         cripto[0].append(TC[i])
#         cripto[1].append(TC[metade + i])

#     cripto = transpose(cripto)

#     texto_cripto = ''
#     for i in range(len(cripto)):
#         for j in range(len(cripto[0])):
#             texto_cripto += cripto[i][j]

#     return texto_cripto

# def descriptografia_palavras(chave, nome_cifrado):
#     # Tabela dos inversos no Z26
#     TABELA = [[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25],
#               [1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25]]

#     det = (chave[0][0] * chave[1][1] - chave[0][1] * chave[1][0]) % 26

#     try:
#         indice_inverso = TABELA[0].index(det)
#     except ValueError:
#         raise ValueError("Determinante não tem inverso módulo 26")
#     inverso = TABELA[1][indice_inverso]

#     matriz_inversa = [
#         [(chave[1][1] * inverso) % 26, (-chave[0][1] * inverso) % 26],
#         [(-chave[1][0] * inverso) % 26, (chave[0][0] * inverso) % 26]
#     ]

#     nome_cifrado = nome_cifrado.upper().replace(' ', '')

#     V = []
#     for letra in nome_cifrado:
#         pos = T.index(letra)
#         V.append(pos + 1)

#     # Construindo matriz P
#     P = [[], []]
#     for i in range(len(V)):
#         if i % 2 == 0:
#             P[0].append(V[i])
#         else:
#             P[1].append(V[i])
#     if len(P[0]) > len(P[1]):
#         P[1].append(0)

#     # Multiplicando matriz inversa por P
#     M = [[], []]
#     for j in range(len(P[0])):
#         M[0].append((matriz_inversa[0][0] * P[0][j] + matriz_inversa[0][1] * P[1][j]) % 26)
#         M[1].append((matriz_inversa[1][0] * P[0][j] + matriz_inversa[1][1] * P[1][j]) % 26)

#     for i in range(len(M)):
#         for j in range(len(M[0])):
#             if M[i][j] == 0:
#                 M[i][j] = 26

#     # Convertendo para texto
#     texto_descripto = ''
#     for j in range(len(M[0])):
#         for i in range(len(M)):
#             texto_descripto += T[M[i][j] - 1]

#     # Removendo padding, se necessário
#     if len(texto_descripto) > 1 and texto_descripto[-1] == texto_descripto[-2]:
#         texto_descripto = texto_descripto[:-1]

#     return texto_descripto

# # Input de palavra criptografada
# entrada = input("Digite a palavra criptografada: ")
# texto_descriptografado = descriptografia_palavras(chave, entrada)
# print(f"Texto descriptografado: {texto_descriptografado}")

# Declarando a tabela do alfabeto
T = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

chave = [[3, 5], [1, 2]]

# Função de multiplicação de matrizes
def matmul(A, B):
    result = [[0]*len(B[0]) for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    return result

# Transposição de matriz (para exibição)
def transpose(matrix):
    return [list(row) for row in zip(*matrix)]

def criptografia_palavras(chave, nome):
    nome = nome.upper().replace(' ', '')
    I = []
    for i in range(len(nome)):
        pos = T.index(nome[i])
        I.append(pos + 1)
    if len(nome) % 2 != 0:
        I.append(I[-1])
    P = [[], []]
    for i in range(len(I)):
        if i % 2 == 0:
            P[0].append(I[i])
        else:
            P[1].append(I[i])
    C = matmul(chave, P)
    for i in range(len(C)):
        for j in range(len(C[0])):
            C[i][j] %= 26
            if C[i][j] == 0:
                C[i][j] = 26
    TC = []
    for i in range(len(C)):
        for j in range(len(C[0])):
            TC.append(T[C[i][j]-1])
    cripto = [[], []]
    metade = len(TC) // 2
    for i in range(metade):
        cripto[0].append(TC[i])
        cripto[1].append(TC[metade + i])
    cripto = transpose(cripto)
    texto_cripto = ''
    for i in range(len(cripto)):
        for j in range(len(cripto[0])):
            texto_cripto += cripto[i][j]
    return texto_cripto

def descriptografia_palavras(chave, nome_cifrado):
    TABELA = [[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25],
              [1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25]]
    det = (chave[0][0] * chave[1][1] - chave[0][1] * chave[1][0]) % 26
    try:
        indice_inverso = TABELA[0].index(det)
    except ValueError:
        raise ValueError("Determinante não tem inverso módulo 26")
    inverso = TABELA[1][indice_inverso]
    matriz_inversa = [
        [(chave[1][1] * inverso) % 26, (-chave[0][1] * inverso) % 26],
        [(-chave[1][0] * inverso) % 26, (chave[0][0] * inverso) % 26]
    ]
    nome_cifrado = nome_cifrado.upper().replace(' ', '')
    V = []
    for letra in nome_cifrado:
        pos = T.index(letra)
        V.append(pos + 1)
    P = [[], []]
    for i in range(len(V)):
        if i % 2 == 0:
            P[0].append(V[i])
        else:
            P[1].append(V[i])
    if len(P[0]) > len(P[1]):
        P[1].append(0)
    M = [[], []]
    for j in range(len(P[0])):
        M[0].append((matriz_inversa[0][0] * P[0][j] + matriz_inversa[0][1] * P[1][j]) % 26)
        M[1].append((matriz_inversa[1][0] * P[0][j] + matriz_inversa[1][1] * P[1][j]) % 26)
    for i in range(len(M)):
        for j in range(len(M[0])):
            if M[i][j] == 0:
                M[i][j] = 26
    texto_descripto = ''
    for j in range(len(M[0])):
        for i in range(len(M)):
            texto_descripto += T[M[i][j] - 1]
    if len(texto_descripto) > 1 and texto_descripto[-1] == texto_descripto[-2]:
        texto_descripto = texto_descripto[:-1]
    return texto_descripto

# Escolha: criptografar ou descriptografar
acao = input("Digite 'C' para criptografar ou 'D' para descriptografar: ").strip().upper()
if acao == 'C':
    entrada = input("Digite a palavra para criptografar: ")
    texto_criptografado = criptografia_palavras(chave, entrada)
    print(f"Texto criptografado: {texto_criptografado}")
elif acao == 'D':
    entrada = input("Digite a palavra criptografada: ")
    texto_descriptografado = descriptografia_palavras(chave, entrada)
    print(f"Texto descriptografado: {texto_descriptografado}")
else:
    print("Opção inválida. Digite 'C' para criptografar ou 'D' para descriptografar.")

# from numpy import matmul
# T = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
# chave = [[4,3],[1,2]]

# def criptografia_palavras(chave, nome):
#     nome = nome.upper().replace(' ', '')
#     I = []
#     for i in range (len(nome)):
#         pos = T.index(nome[i])
#         if pos == '25':
#             I.append(0)
#         else:
#             I.append(pos+1)   
#     if len(nome)%2 != 0:
#         pos = T.index(nome[-1])
#         if pos == '25':
#             I.append(0)
#         else:
#             I.append(pos+1)
#     P = [[],[]]
#     for i in range(len(I)):
#         if i%2 == 0:
#             P[0].append(I[i])
#         else:
#             P[1].append(I[i])
#     C = matmul(chave, P)
#     for i in range(len(C)):
#         for j in range(len(C[0])):
#             C[i][j] %= 26
#             if C[i][j] == 0:
#                 C[i][j] = 26
#     TC = []
#     for i in range(len(C)):
#         for j in range(len(C[0])):
#             TC.append(T[C[i][j]-1])
#     cripto = [[],[]]
#     for i in range(int(len(TC)/2)):
#         cripto[0].append(TC[i])
#         cripto[1].append(TC[int(len(TC)/2)+i])
#     cripto = transpose(cripto)
#     texto_cripto = ''
#     for i in range(len(cripto)):
#         for j in range(len(cripto[0])):
#             texto_cripto += cripto[i][j]
#     return texto_cripto

# def descriptografia_palavras(chave, nome_cifrado):
#     TABELA = [[1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25],
#               [1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25]]

#     T = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
#          'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
#     det = chave[0][0] * chave[1][1] - chave[0][1] * chave[1][0]
#     det = det % 26
#     try:
#         indice_inverso = TABELA[0].index(det)
#     except ValueError:
#         raise ValueError("Determinante não tem inverso módulo 26")     
#     inverso = TABELA[1][indice_inverso]
#     matriz_inversa = [
#         [(chave[1][1] * inverso) % 26, (-chave[0][1] * inverso) % 26],
#         [(-chave[1][0] * inverso) % 26, (chave[0][0] * inverso) % 26]
#     ]
#     nome_cifrado = nome_cifrado.upper().replace(' ', '')
#     V = []
#     for letra in nome_cifrado:
#         pos = T.index(letra)
#         V.append(pos + 1)
#     P = [[], []]
#     for i in range(len(V)):
#         P[i % 2].append(V[i])
#     if len(P[0]) > len(P[1]):
#         P[1].append(0)
#     M = [[], []]
#     for j in range(len(P[0])):
#         M[0].append((matriz_inversa[0][0] * P[0][j] + matriz_inversa[0][1] * P[1][j]) % 26)
#         M[1].append((matriz_inversa[1][0] * P[0][j] + matriz_inversa[1][1] * P[1][j]) % 26)
#     for i in range(len(M)):
#         for j in range(len(M[0])):
#             if M[i][j] == 0:
#                 M[i][j] = 26
#     texto_descripto = ''
#     for j in range(len(M[0])):
#         for i in range(len(M)):
#             texto_descripto += T[M[i][j] - 1]
#     if len(texto_descripto) > 1 and texto_descripto[-1] == texto_descripto[-2]:
#         texto_descripto = texto_descripto[:-1]
#     if texto_descripto == 'BAIXASUSTENTABILIDADE':
#         texto_descripto = 'BAIXA SUSTENTABILIDADE'
#     elif texto_descripto == 'MODERADASUSTENTABILIDADE':
#         texto_descripto = 'MODERADA SUSTENTABILIDADE'
#     elif texto_descripto == 'ALTASUSTENTABILIDADE':
#         texto_descripto = 'ALTA SUSTENTABILIDADE'
#     return texto_descripto