import os
from random import randint

# Loop principal do jogo
jogar = 1

while jogar == 1:
    # Gerando o número secreto aleatório
    numGerado = randint(1000,9999)

    # Número secreto fixo
    # numGerado = 1234
    
    # Desmembramento do número gerado
    milhar = numGerado // 1000
    centena = (numGerado % 1000) // 100
    dezena = (numGerado % 100) // 10
    unidade = numGerado % 10

    # Resetando variáveis para uma nova rodada
    cont = 1
    venceu = 0
    acertos = 0
    pos1 = pos2 = pos3 = pos4 = -1
    dica1 = dica2 = dica3 = dica4 = 0
    tipo1 = tipo2 = tipo3 = tipo4 = 0
   
    os.system('cls' if os.name == 'nt' else 'clear')

    # Introdução do jogo

    print('\n\t=-=-=-=-= BEM VINDO(A) AO JOGO SECRETO =-=-=-=-=\n\n')
    print('Você tem 10 tentativas para acertar o número secreto entre [1000 e 9999]\n')
    print('Caso você acerte a posição e o número, o jogo irá mantê-lo e informará que está correto!\n')
    print('A partir da 5ª tentativa, o jogo irá te ajudar com dicas.\n\tBoa sorte!!')
    input('\n\t<< Tecle Enter para continuar >>')

    os.system('cls' if os.name == 'nt' else 'clear')
                                  
    # Loop de tentativas
    while cont <= 10:
        # Entrada do palpite do usuário
        print('-'*50)
        numPalpite = int(input(f"\n\t>> {cont}ª Tentativa <<\nDigite seu palpite: "))
        while numPalpite < 1000 or numPalpite > 9999:
            numPalpite = int(input(f"\nTentativa inválida. O número deve ser entre 1000 e 9999.\n\n\t>> {cont}ª Tentativa <<\nDigite seu palpite: "))

        # Verificação de vitória
        if numPalpite == numGerado:
            venceu = 1
            break  # Sai do loop, pois o jogador venceu

        # Se não venceu, verifica os acertos

        # Desmembramento do número inserido
        milhar2 = numPalpite // 1000
        centena2 = (numPalpite % 1000) // 100
        dezena2 = (numPalpite % 100) // 10
        unidade2 = numPalpite % 10


        # Comparação dos dígitos
        if -3 <= pos1 < 0 and milhar == milhar2:
            pos1 = milhar2
            acertos += 1
        if -3 <= pos2 < 0 and centena == centena2:
            pos2 = centena2
            acertos += 1
        if -3 <= pos3 < 0 and dezena == dezena2:
            pos3 = dezena2
            acertos += 1
        if -3 <= pos4 < 0 and unidade == unidade2:
            pos4 = unidade2
            acertos += 1
            
        # Exibição do resultado da tentativa
        print(f'\nVocê acertou {acertos} dígito(s) dessa vez...')
        print('\nSeu código atual é: ', end='')
        if -3 <= pos1 < 0:
            print('__', end=' ')
        else:
            print(pos1, end=' ')
        if -3 <= pos2 < 0:
            print('__', end=' ')
        else:
            print(pos2, end=' ')
        if -3 <= pos3 < 0:
            print('__', end=' ')
        else:
            print(pos3, end=' ')
        if -3 <= pos4 < 0:
            print('__', end=' ')
        else:
            print(pos4, end=' ')

        if cont < 10:
            print(f'\n\nFalta(m) {10-cont} tentativa(s)...\n')

        # Zera a quantidade de acertos para a proxima rodada
        acertos = 0

        # >> DICAS << (se é par ou ímpar e/ou maior ou igual a cinco ou menor que cinco)
        # Caso seja a partir da 5ª tentativa e as outras posições não estejam todas preenchidas (por dicas ou números)
        if (5 <= cont < 10) and not ((pos1 > -1 or pos1 < -2) and (pos2 > -1 or pos2 < -2) and (pos3 > -1 or pos3 < -2) and (pos4 > -1 or pos4 < -2)):
            print(f'\nVou te dar uma dica...\n')
            # Gera um número aleatório entre 1 e 4 -> DEFINE PARA QUAL POSIÇÃO A DICA VAI
            dica = randint(1,4)

            # Garante que a dica não será para um número já adivinhado
            while dica < 5:
                if (dica == 1 and (pos1 > -1 or pos1 < -2)) or (dica == 2 and (pos2 > -1 or pos2 < -2)) or (dica == 3 and (pos3 > -1 or pos3 < -2)) or (dica == 4 and (pos4 > -1 or pos4 < -2)):
                    # Caso a dica sorteada corresponda a uma posição já ocupada, sorteia de novo até achar uma que não esteja
                    dica = randint(1,4)
                else:
                    break

            # Posição do milhar
            if dica == 1:
                # Determina o tipo de dica
                tipo = randint(1,2)

                # Garante que o tipo sorteado não seja o mesmo que um já utilizado
                while tipo < 3:
                    if (tipo == tipo1 == 1) or (tipo == tipo1 == 2):
                        tipo = randint(1,2)
                    else:
                        break

                # Dica de par ou ímpar
                if tipo == 1:
                    # Identifica se é par e mostra para o usuário
                    if milhar % 2 == 0:
                        print('==> O Primeiro dígito (milhar) é PAR!!\n')
                        # Marca qual dica foi usada
                        dica1 = 1
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos1 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo1 = 1
                    # Caso não seja --> mostra para o usuário que é ímpar
                    else:
                        print('==> O Primeiro dígito (milhar) é ÍMPAR!!')
                        # Marca qual dica foi dada
                        dica1 = 2
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos1 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo1 = 1

                # Dica do número ser maior ou igual a cinco ou número menor que cinco
                else:
                    # Se o milhar for maior ou igual a cinco
                    if milhar >= 5:
                        print('==> O Primeiro dígito (milhar) é MAIOR OU IGUAL A 5!!')
                        # Marca qual dica foi dada
                        dica1 = 3
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos1 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo1 = 2
                    # Se o milhar for menor que cinco
                    else:
                        print('==> O Primeiro dígito (milhar) é MENOR QUE 5!!')
                        # Marca qual dica foi dada
                        dica1 = 4
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos1 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo1 = 2

            # Posição da centena
            elif dica == 2: 
                # Determinação do tipo de dica
                tipo = randint(1, 2)
                
                # Garante que o tipo sorteado não seja o mesmo que um já utilizado
                while tipo < 3:
                    if (tipo == tipo2 == 1) or (tipo == tipo2 == 2):
                        tipo = randint(1,2)
                    else:
                        break

                if tipo == 1:
                    #identifica se é par e mostra para o usuário
                    if centena % 2 == 0:
                        print('==> O Segundo dígito (centena) é PAR!!')
                        # Marca qual dica foi dada
                        dica2 = 1
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos2 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo2 = 1
                    #caso não for --> mostra para o usuário que é ímpar
                    else:
                        print('==> O Segundo dígito (centena) é ÍMPAR!! ')
                        # Marca qual dica foi dada
                        dica2 = 2
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos2 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo2 = 1
                #dica do número ser maior ou igual a cinco ou número menor que cinco
                else:
                    #se a dezena for maior ou igual a cinco
                    if centena >= 5:
                        print('==> O Segundo dígito (centena) é maior ou igual a 5!!')
                        # Marca qual dica foi dada
                        dica2 = 3
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos2 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo2 = 2
                    #se a dezena for menor que cinco
                    else:
                        print('==> O Segundo dígito (centena) é menor que 5!!')
                        # Marca qual dica foi dada
                        dica2 = 4
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos2 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo2 = 2

            # Posição da dezena
            elif dica == 3:
                # Determina o tipo de dica
                tipo = randint(1,2)

                # Garante que o tipo sorteado não seja o mesmo que um já utilizado
                while tipo < 3:
                    if (tipo == tipo3 == 1) or (tipo == tipo3 == 2):
                        tipo = randint(1,2)
                    else:
                        break

                # dica de par ou ímpar
                if tipo == 1:
                    #identifica se é par e mostra para o usuário
                    if dezena % 2 == 0:
                        print('==> O terceiro dígito (dezena) é PAR!!')
                        # Marca qual dica foi dada
                        dica3 = 1
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos3 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo3 = 1
                    #caso não for --> mostra para o usuário que é ímpar
                    else:
                        print('==> O terceiro dígito (dezena) é ÍMPAR!!')
                        # Marca qual dica foi dada
                        dica3 = 2
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos3 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo3 = 1
                #dica do número ser maior ou igual a cinco ou número menor que cinco
                else:
                    #se a dezena for maior ou igual a cinco
                    if dezena >= 5:
                        print('==> O terceiro dígito (dezena) é MAIOR OU IGUAL A 5!!')
                        # Marca qual dica foi dada
                        dica3 = 3
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos3 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo3 = 2
                    #se a dezena for menor que cinco
                    else:
                        print('==> O terceiro dígito (dezena) é MENOR QUE 5!!')
                        # Marca qual dica foi dada
                        dica3 = 4
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos3 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo3 = 2
            
            # Posição da unidade
            elif dica == 4: 
                # Determina o tipo da dica
                tipo = randint(1, 2)
                
                # Garante que o tipo sorteado não seja o mesmo que um já utilizado
                while tipo < 3:
                    if (tipo == tipo4 == 1) or (tipo == tipo4 == 2):
                        tipo = randint(1,2)
                    else:
                        break

                # dica de par ou ímpar
                if tipo == 1:
                    #identifica se é par e mostra para o usuário
                    if unidade % 2 == 0:
                        print('==> O Quarto dígito (unidade) é PAR!!')
                        # Marca qual dica foi dada
                        dica4 = 1
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos4 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo4 = 1
                    #caso não for --> mostra para o usuário que é ímpar
                    else:
                        print('==> O Quarto dígito (unidade) é ÍMPAR!! ')
                        # Marca qual dica foi dada
                        dica4 = 2
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos4 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo4 = 1
                #dica do número ser maior ou igual a cinco ou número menor que cinco
                else:
                    #se a unidade for maior ou igual a cinco
                    if unidade >= 5:
                        print('==> O Quarto dígito (unidade) é maior ou igual a 5!!')
                        # Marca qual dica foi dada
                        dica4 = 3
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos4 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo4 = 2
                    #se a unidade for menor que cinco
                    else:
                        print('==> O Quarto dígito (unidade) é menor que 5!!')
                        # Marca qual dica foi dada
                        dica4 = 4
                        # Decresce a posição para indicar que uma dica já foi dada
                        pos4 -= 1
                        # Determina que esse tipo de dica já foi dado
                        tipo4 = 2    
            
            # Exibe o código com a dica
            print('\n==> ', end='')
            # Posição 1
            if -3 <= pos1 < 0:
                if pos1 == -1 or tipo1 == 0 or dica1 == 0:
                    print('__', end=' ')
                else:
                    if dica1 == 1:
                        print('PAR', end=' ')
                    elif dica1 == 2:
                        print('ÍMPAR', end=' ')
                    elif dica1 == 3:
                        print('>=5', end=' ')
                    elif dica1 == 4:
                        print('<5', end=' ')
            else:
                print(pos1, end=' ')
            # Posição 2
            if -3 <= pos2 < 0:
                if pos2 == -1 or tipo2 == 0 or dica2 == 0:
                    print('__', end=' ')
                else:
                    if dica2 == 1:
                        print('PAR', end=' ')
                    elif dica2 == 2:
                        print('ÍMPAR', end=' ')
                    elif dica2 == 3:
                        print('>=5', end=' ')
                    elif dica2 == 4:
                        print('<5', end=' ')
            else:
                print(pos2, end=' ')
            # Posição 3
            if -3 <= pos3 < 0:
                if pos3 == -1 or tipo3 == 0 or dica3 == 0:
                    print('__', end=' ')
                else:
                    if dica3 == 1:
                        print('PAR', end=' ')
                    elif dica3 == 2:
                        print('ÍMPAR', end=' ')
                    elif dica3 == 3:
                        print('>=5', end=' ')
                    elif dica3 == 4:
                        print('<5', end=' ')
            else:
                print(pos3, end=' ')
            # Posição 4
            if -3 <= pos4 < 0:
                if pos4 == -1 or tipo4 == 0 or dica4 == 0:
                    print('__', end=' ')
                else:
                    if dica4 == 1:
                        print('PAR', end=' ')
                    elif dica4 == 2:
                        print('ÍMPAR', end=' ')
                    elif dica4 == 3:
                        print('>=5', end=' ')
                    elif dica4 == 4:
                        print('<5', end=' ')
            else:
                print(pos4, end=' ')
            print('\n')

        # Incremento do contador
        cont += 1

    # Mensagem de finalização do jogo
    if venceu == 1:
        os.system('cls' if os.name == 'nt' else 'clear')
        print(f'\n\t>=<>=<>=< PARABÉNS >=<>=<>=<\nVocê acertou o <<CÓDIGO SECRETO>> na {cont}ª tentativa.')
    else:
        os.system('cls' if os.name == 'nt' else 'clear')
        print(f'\nQue pena! Não foi dessa vez :(\nO <<CÓDIGO SECRETO>> era {numGerado}\nMas não se preocupe, você pode jogar de novo!\n')

    print('-' * 60)
    
    # Perguntar se o usuário deseja jogar novamente
    jogar = int(input('\nDeseja jogar novamente?\n[1] - SIM\n[0] - NÃO\n\n>> '))
    while jogar not in [0, 1]:
        jogar = int(input('\nOpção inválida\nDeseja jogar novamente?\n[1] - SIM\n[0] - NÃO\n\n>> '))  

# Mensagem de encerramento
print('\n\t=-=-=-=-= Muito obrigado por jogar!! =-=-=-=-=')