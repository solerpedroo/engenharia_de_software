package aula2508;

public class Main
{
    public static void main(String[] args)
    {
        try
        {
            // ==========================================
            // 1. TESTE DO CONSTRUTOR
            // ==========================================

            Horario horario = new Horario((byte) 10, (byte) 30, (byte) 45);

            System.out.println("Horário inicial: " + horario);


            // ==========================================
            // 2. TESTE DOS GETTERS
            // ==========================================

            System.out.println("\n--- GETTERS ---");

            System.out.println("Hora: " + horario.getHora());
            System.out.println("Minuto: " + horario.getMinuto());
            System.out.println("Segundo: " + horario.getSegundo());


            // ==========================================
            // 3. TESTE DOS SETTERS
            // ==========================================

            System.out.println("\n--- SETTERS ---");

            horario.setHora((byte) 12);
            horario.setMinuto((byte) 15);
            horario.setSegundo((byte) 20);

            System.out.println("Depois dos setters: " + horario);


            // ==========================================
            // 4. TESTE DO ADIANTE
            // ==========================================

            System.out.println("\n--- ADIANTE ---");

            Horario horarioAdiante = new Horario(
                    (byte) 10,
                    (byte) 30,
                    (byte) 45
            );

            System.out.println("Antes: " + horarioAdiante);

            horarioAdiante.adiante(20);

            System.out.println("Depois de +20 segundos: " + horarioAdiante);

            horarioAdiante.adiante(3600);

            System.out.println("Depois de +1 hora: " + horarioAdiante);


            // ==========================================
            // 5. TESTE DE VIRADA DO DIA
            // ==========================================

            System.out.println("\n--- VIRADA DO DIA ---");

            Horario viradaDia = new Horario(
                    (byte) 23,
                    (byte) 59,
                    (byte) 50
            );

            System.out.println("Antes: " + viradaDia);

            viradaDia.adiante(20);

            System.out.println("Depois de +20 segundos: " + viradaDia);


            // ==========================================
            // 6. TESTE DO RETROCEDA
            // ==========================================

            System.out.println("\n--- RETROCEDA ---");

            Horario horarioRetroceder = new Horario(
                    (byte) 10,
                    (byte) 30,
                    (byte) 45
            );

            System.out.println("Antes: " + horarioRetroceder);

            horarioRetroceder.retroceda(20);

            System.out.println("Depois de -20 segundos: " + horarioRetroceder);

            horarioRetroceder.retroceda(3600);

            System.out.println("Depois de -1 hora: " + horarioRetroceder);


            // ==========================================
            // 7. TESTE DE RETROCEDER PASSANDO DA MEIA-NOITE
            // ==========================================

            System.out.println("\n--- RETROCEDER PASSANDO DA MEIA-NOITE ---");

            Horario meiaNoite = new Horario(
                    (byte) 0,
                    (byte) 0,
                    (byte) 10
            );

            System.out.println("Antes: " + meiaNoite);

            meiaNoite.retroceda(20);

            System.out.println("Depois de -20 segundos: " + meiaNoite);


            // ==========================================
            // 8. TESTE DO GET HORARIO FUTURO
            // ==========================================

            System.out.println("\n--- GET HORARIO FUTURO ---");

            Horario original = new Horario(
                    (byte) 10,
                    (byte) 30,
                    (byte) 45
            );

            Horario futuro = original.getHorarioFuturo(3600);

            System.out.println("Original: " + original);
            System.out.println("Futuro: " + futuro);


            // ==========================================
            // 9. TESTE DO GET HORARIO PASSADO
            // ==========================================

            System.out.println("\n--- GET HORARIO PASSADO ---");

            Horario passado = original.getHorarioPassado(3600);

            System.out.println("Original: " + original);
            System.out.println("Passado: " + passado);


            // ==========================================
            // 10. TESTE DO EQUALS
            // ==========================================

            System.out.println("\n--- EQUALS ---");

            Horario horario1 = new Horario(
                    (byte) 15,
                    (byte) 20,
                    (byte) 30
            );

            Horario horario2 = new Horario(
                    (byte) 15,
                    (byte) 20,
                    (byte) 30
            );

            Horario horario3 = new Horario(
                    (byte) 15,
                    (byte) 20,
                    (byte) 31
            );

            System.out.println("horario1: " + horario1);
            System.out.println("horario2: " + horario2);
            System.out.println("horario3: " + horario3);

            System.out.println("horario1.equals(horario2): "
                    + horario1.equals(horario2));

            System.out.println("horario1.equals(horario3): "
                    + horario1.equals(horario3));


            // ==========================================
            // 11. TESTE DO HASHCODE
            // ==========================================

            System.out.println("\n--- HASHCODE ---");

            System.out.println("Hash horario1: " + horario1.hashCode());
            System.out.println("Hash horario2: " + horario2.hashCode());
            System.out.println("Hash horario3: " + horario3.hashCode());


            // ==========================================
            // 12. TESTE DE EXCEÇÕES
            // ==========================================

            System.out.println("\n--- TESTE DE EXCEÇÕES ---");

            try
            {
                new Horario((byte) 25, (byte) 10, (byte) 10);
            }
            catch (Exception erro)
            {
                System.out.println("Erro de hora: " + erro.getMessage());
            }

            try
            {
                new Horario((byte) 10, (byte) 60, (byte) 10);
            }
            catch (Exception erro)
            {
                System.out.println("Erro de minuto: " + erro.getMessage());
            }

            try
            {
                new Horario((byte) 10, (byte) 10, (byte) 60);
            }
            catch (Exception erro)
            {
                System.out.println("Erro de segundo: " + erro.getMessage());
            }

            try
            {
                horario.adiante(-10);
            }
            catch (Exception erro)
            {
                System.out.println("Erro no adiante: " + erro.getMessage());
            }

            try
            {
                horario.retroceda(-10);
            }
            catch (Exception erro)
            {
                System.out.println("Erro no retroceda: " + erro.getMessage());
            }
        }
        catch (Exception erro)
        {
            System.out.println("Erro inesperado: " + erro.getMessage());
        }
    }
}