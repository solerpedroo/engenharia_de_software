package aula0109;

public class ControladorDeLetrasJaDigitadas implements Cloneable
{
    private String letrasJaDigitadas;

    public ControladorDeLetrasJaDigitadas ()
    {
        // torna this.letrasJaDigitadas igual ao String vazio
        this.letrasJaDigitadas = "";
    }

    public boolean isJaDigitada (char letra)
    {
        // percorrer o String this.letrasJaDigitadas e verificar se ele
        // possui a letra fornecida, retornando true em caso afirmativo
        // ou false em caso negativo
        return letrasJaDigitadas.contains(String.valueOf(letra));
    }

    public void registre (char letra) throws Exception
    {
        // verifica se a letra fornecida ja foi digitada (pode usar
        // o método this.isJaDigitada, para isso), lancando uma exceção
        // em caso afirmativo.
        // concatena a letra fornecida a this.letrasJaDigitadas.
        if (this.isJaDigitada(letra)) throw new Exception("letra já digitada");
        this.letrasJaDigitadas += letra;
    }

    public String toString ()
    {
        // retorna um String com TODAS as letras presentes em
        // this.letrasJaDigitadas separadas por vírgula (,).
        String resposta = "";

        for (int i = 0; i < letrasJaDigitadas.length(); i++)
        {
            if (i > 0)
                resposta += ", ";

            resposta += letrasJaDigitadas.charAt(i);
        }

        return resposta;
    }

    @Override
    public boolean equals (Object obj)
    {
        // verificar se this e obj são iguais
        if(obj == this) return true;
        if(obj == null) return true;
        if(obj.getClass() != this.getClass()) return false;
        ControladorDeLetrasJaDigitadas contr = (ControladorDeLetrasJaDigitadas) obj;
        if(contr.letrasJaDigitadas != this.letrasJaDigitadas) return false;
        return true;
    }

    @Override
    public int hashCode ()
    {
        // calcular e retornar o hashcode de this
        int retorno = 1;
        retorno = retorno*2+(this.letrasJaDigitadas).hashCode();
        if(retorno<0) retorno = -retorno;
        return retorno;
    }

    public ControladorDeLetrasJaDigitadas(
            ControladorDeLetrasJaDigitadas controladorDeLetrasJaDigitadas)
            throws Exception // construtor de cópia
    {
        // copiar c.letrasJaDigitadas em this.letrasJaDigitadas
        try{
            controladorDeLetrasJaDigitadas.letrasJaDigitadas = this.letrasJaDigitadas;
        } catch (Exception erro){
            throw new Exception("erro");
        }
    }

    @Override
    public Object clone ()
    {
        // criar uma cópia do this com o construtor de cópia e retornar
        ControladorDeLetrasJaDigitadas retorno = null;
        try {
            retorno = new ControladorDeLetrasJaDigitadas(this);
        } catch (Exception erro) {}
        return retorno;
    }
}

