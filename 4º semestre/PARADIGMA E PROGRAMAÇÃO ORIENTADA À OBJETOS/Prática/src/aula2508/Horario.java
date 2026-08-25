package aula2508;

public class Horario
{
    private byte hora, minuto, segundo;

    public /*void*/ Horario (byte hora, byte minuto, byte segundo) throws Exception
    {
        // não é o recomendado acessar os setters pelo construtor, mas como já está validado não tem problema, nesse caso
        // no caso da data não é possível, pois toda vez que chama um elemento para fazer o set, os demais ficam como 0, o que invalida o elemento
        this.setHora(hora);
        this.setMinuto(minuto);
        this.setSegundo(segundo);
    }

    public void setHora (byte hora) throws Exception
    {
        if (hora < 0 || hora > 23) throw new Exception("Hora inválida");
        this.hora = hora;
    }

    public void setMinuto (byte minuto) throws Exception
    {
        if (minuto < 0 || minuto > 59) throw new Exception("Minuto inválido");
        this.minuto = minuto;
    }

    public void setSegundo (byte segundo) throws Exception
    {
        if (segundo < 0 || segundo > 59) throw new Exception("Segundo inválido");
        this.segundo = segundo;
    }

    public byte getHora ()
    {
        return this.hora;
    }

    public byte getMinuto ()
    {
        return this.minuto;
    }

    public byte getSegundo ()
    {
        return this.segundo;
    }

    public void adiante(int qtdSegundos) throws Exception
    {
        if (qtdSegundos < 0) throw new Exception("Segundos inválidos");

        int segundosTotal = (this.hora * 3600) + (this.minuto * 60) + this.segundo;

        segundosTotal += qtdSegundos;
        segundosTotal = segundosTotal % 86400;

        byte hora = (byte) (segundosTotal / 3600);
        int resto = segundosTotal % 3600;
        byte minuto = (byte) (resto / 60);
        byte segundo = (byte) (resto % 60);

        this.hora = hora;
        this.minuto = minuto;
        this.segundo = segundo;
    }

    public void retroceda(int qtdSegundos) throws Exception
    {
        if (qtdSegundos < 0) throw new Exception("Segundos inválidos");

        int segundosTotal = (this.hora * 3600) + (this.minuto * 60) + this.segundo;

        segundosTotal -= qtdSegundos;
        segundosTotal = segundosTotal % 86400;

        if (segundosTotal < 0) segundosTotal += 86400;

        byte hora = (byte) (segundosTotal / 3600);
        int resto = segundosTotal % 3600;
        byte minuto = (byte) (resto / 60);
        byte segundo = (byte) (resto % 60);

        this.hora = hora;
        this.minuto = minuto;
        this.segundo = segundo;
    }

    public Horario getHorarioFuturo (int qtdSegundos) throws Exception // nao altera o this
    {
        Horario retorno = null;
        try{
            retorno = new Horario(this.hora, this.minuto, this.segundo);
        } catch (Exception erro){ }
        retorno.adiante(qtdSegundos);
        return retorno;
    }

    public Horario getHorarioPassado (int qtdSegundos) throws Exception // nao altera o this
    {
        Horario retorno = null;
        try{
            retorno = new Horario(this.hora, this.minuto, this.segundo);
        } catch (Exception erro){ }
        retorno.retroceda(qtdSegundos);
        return retorno;
    }

    // faça também toString, equals e hashCode

    @Override
    public String toString() {
        return String.format("%02d:%02d:%02d",
                this.hora,
                this.minuto,
                this.segundo);
    }

    @Override
    public int hashCode() {
        int retorno = 1;

        retorno = retorno * 2 + ((Byte)this.hora).hashCode();
        retorno = retorno * 2 + ((Byte)this.minuto).hashCode();
        retorno = retorno * 2 + ((Byte)this.segundo).hashCode();

        if (retorno<0) retorno = -retorno;
        return retorno;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj == null) return false;
        if(obj.getClass() != this.getClass()) return false;
        Horario hor = (Horario) obj;
        if((hor.hora != this.hora) || (hor.minuto != this.minuto) || (hor.segundo != this.segundo)) return false;
        return true;
    }
}