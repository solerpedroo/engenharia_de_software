package aula0109;

public class ControladorDeErros implements Cloneable
{
    private int qtdMax, qtdErr=0;

    public ControladorDeErros (int qtdMax) throws Exception
    {
        // verifica se qtdMax fornecida não é positiva, lançando
        // uma exceção.
        // armazena qtdMax fornecida em this.qtdMax.
        if (qtdMax < 0 ) throw new Exception("Quantidade inválida");
        this.qtdMax = qtdMax;
    }

    public void registreUmErro () throws Exception
    {
        // verifica se this.qtdErr ja é igual a this.qtdMax,
        // lançando excecao em caso positivo ou
        // incrementando this.qtdErr em caso negativo
        if(this.qtdErr == this.qtdMax) throw new Exception("É giual a qtdMax");
        this.qtdErr++;
    }

    public boolean isAtingidoMaximoDeErros  ()
    {
        // returna true se this.qtdErr for igual a this.qtdMax,
        // ou então false, caso contrario.
        if (this.qtdErr == this.qtdMax) return true;
        return false;
    }

    @Override
    public String toString ()
    {
        return this.qtdErr + "/" + this.qtdMax;
    }

    @Override
    public boolean equals (Object obj)
    {
        // verificar se this e obj possuem o mesmo conteúdo, retornando
        // true no caso afirmativo ou false no caso negativo
        if(obj == this) return true;
        if(obj == null) return true;
        if(obj.getClass() != this.getClass()) return false;
        ControladorDeErros contr = (ControladorDeErros) obj;
        if(contr.qtdMax != this.qtdMax) return false;
        if(contr.qtdErr != this.qtdErr) return false;
        return true;
    }

    @Override
    public int hashCode ()
    {
        // calcular e retornar o hashcode de this
        int retorno = 1;
        retorno = retorno*2 +((Integer) this.qtdErr).hashCode();
        retorno = retorno*2 +((Integer) this.qtdMax).hashCode();
        if(retorno<0) retorno = -retorno;
        return retorno;
    }

    public ControladorDeErros (ControladorDeErros c) throws Exception // construtor de cópia
    {
        // copiar c.qtdMax e c.qtdErr, respectivamente em, this.qtdMax e this.qtdErr
        c.qtdErr = this.qtdErr;
        c.qtdMax = this.qtdMax;
    }

    @Override
    public Object clone ()
    {
        // returnar uma cópia de this
        ControladorDeErros retorno = null;
        try {
            retorno = new ControladorDeErros(this);
        } catch (Exception erro) {}
        return retorno;
    }
}

