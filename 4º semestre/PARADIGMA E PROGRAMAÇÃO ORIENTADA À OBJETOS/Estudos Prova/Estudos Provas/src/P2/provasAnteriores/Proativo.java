package P2.provasAnteriores;

import java.io.*;
import java.net.*;
import java.util.*;

public class Proativo {

    public static void main(String[] args) {

        try (
                Socket conexao = new Socket("localhost", 5000);

                Scanner teclado = new Scanner(System.in);

                DataInputStream entrada = new DataInputStream(
                        conexao.getInputStream());

                DataOutputStream saida = new DataOutputStream(
                        conexao.getOutputStream())
        ) {

            System.out.println("Conectado ao servidor.");

            while (true) {

                System.out.print("\nDigite um comando SQL ou QUIT: ");

                String comando = teclado.nextLine();

                // Envia o comando ao servidor
                saida.writeUTF(comando);
                saida.flush();

                if (comando.trim().equalsIgnoreCase("QUIT")) {
                    System.out.println("Conexão encerrada.");
                    break;
                }

                // Recebe a quantidade de textos
                int quantidade = entrada.readInt();

                String[] resposta = new String[quantidade];

                // Recebe todos os textos da resposta
                for (int i = 0; i < quantidade; i++) {
                    resposta[i] = entrada.readUTF();
                }

                // Recebe o marcador de fim
                String fim = entrada.readUTF();

                if (!fim.equals("EOR")) {
                    throw new IOException("Resposta inválida.");
                }

                // Identifica se o comando foi SELECT
                boolean ehSelect = comando.trim()
                        .matches("(?is)^SELECT\\b.*");

                if (ehSelect) {

                    System.out.println("\nResultado do SELECT:");

                    for (int i = 0; i < resposta.length; i++) {
                        System.out.println(resposta[i]);
                    }

                    // Desconta o cabeçalho
                    int linhas = Math.max(0, resposta.length - 1);

                    System.out.println(
                            "Quantidade de linhas selecionadas: " + linhas
                    );

                } else {

                    // Comandos INSERT, UPDATE, DELETE etc.
                    if (resposta.length > 0 &&
                            resposta[0].equalsIgnoreCase("true")) {

                        System.out.println(
                                "Comando executado com sucesso."
                        );

                    } else {

                        System.out.println(
                                "Comando não executado com sucesso."
                        );
                    }
                }
            }

        } catch (IOException e) {
            System.out.println(
                    "Erro na comunicação: " + e.getMessage()
            );
        }
    }
}
