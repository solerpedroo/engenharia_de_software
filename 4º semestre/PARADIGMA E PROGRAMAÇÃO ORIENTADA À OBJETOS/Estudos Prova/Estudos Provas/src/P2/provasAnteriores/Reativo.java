package P2.provasAnteriores;


import java.io.*;
import java.net.*;

public class Reativo {

    public static void main(String[] args) {

        try (ServerSocket servidor = new ServerSocket(5000)) {

            System.out.println("Servidor iniciado na porta 5000.");

            while (true) {

                Socket cliente = servidor.accept();

                System.out.println("Novo cliente conectado.");

                AtendimentoCliente thread =
                        new AtendimentoCliente(cliente);

                thread.start();
            }

        } catch (IOException e) {
            System.out.println("Erro no servidor: " + e.getMessage());
        }
    }
}

class AtendimentoCliente extends Thread {

    private Socket cliente;

    public AtendimentoCliente(Socket cliente) {
        this.cliente = cliente;
    }

    @Override
    public void run() {

        try (
                Socket conexao = this.cliente;

                DataInputStream entrada = new DataInputStream(
                        conexao.getInputStream());

                DataOutputStream saida = new DataOutputStream(
                        conexao.getOutputStream())
        ) {

            BD banco = new BD();

            while (true) {

                String comando;

                try {
                    comando = entrada.readUTF();
                } catch (EOFException e) {
                    break;
                }

                if (comando.trim().equalsIgnoreCase("QUIT")) {
                    System.out.println("Cliente desconectado.");
                    break;
                }

                Object resultado;

                try {
                    resultado = banco.executaComando(comando);
                } catch (Exception e) {
                    resultado = Boolean.FALSE;
                }

                if (resultado instanceof String[]) {

                    String[] linhas = (String[]) resultado;

                    // Quantidade de textos da resposta
                    saida.writeInt(linhas.length);

                    for (int i = 0; i < linhas.length; i++) {
                        saida.writeUTF(linhas[i]);
                    }

                } else if (resultado instanceof Boolean) {

                    // Comandos que retornam true ou false
                    saida.writeInt(1);
                    saida.writeUTF(resultado.toString());

                } else {

                    // Resposta inválida ou nula
                    saida.writeInt(1);
                    saida.writeUTF("false");
                }

                // Finaliza a resposta
                saida.writeUTF("EOR");

                saida.flush();
            }

        } catch (IOException e) {
            System.out.println(
                    "Erro na conexão com cliente: " + e.getMessage()
            );
        }
    }
}

