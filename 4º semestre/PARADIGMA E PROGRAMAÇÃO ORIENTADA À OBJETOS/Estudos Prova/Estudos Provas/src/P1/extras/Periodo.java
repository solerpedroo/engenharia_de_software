package P1.extras;

public class Periodo implements Comparable<Periodo>, Cloneable {

    private Data inicio;
    private Data fim;

    public Periodo(Data inicio, Data fim) throws Exception {

        if (inicio == null)
            throw new Exception("Data de início ausente");

        if (fim == null)
            throw new Exception("Data de fim ausente");

        if (inicio.compareTo(fim) > 0)
            throw new Exception("Data final não pode ser anterior à inicial");

        this.inicio = new Data(inicio);
        this.fim = new Data(fim);
    }

    public int getQuantidadeDeDias() throws Exception {

        int quantidade = 0;

        Data auxiliar = new Data(this.inicio);

        while (!auxiliar.equals(this.fim)) {
            auxiliar.avanceUmDia();
            quantidade++;
        }

        return quantidade;
    }

    public boolean contem(Data data) throws Exception {

        if (data == null)
            throw new Exception("Data ausente");

        return data.compareTo(this.inicio) >= 0 &&
                data.compareTo(this.fim) <= 0;
    }

    public boolean colide(Periodo outro) throws Exception {

        if (outro == null)
            throw new Exception("Período ausente");

        if (this.fim.compareTo(outro.inicio) < 0)
            return false;

        if (outro.fim.compareTo(this.inicio) < 0)
            return false;

        return true;
    }

    public Periodo getIntersecao(Periodo outro) throws Exception {

        if (outro == null)
            throw new Exception("Período ausente");

        if (!this.colide(outro))
            return null;

        Data inicioIntersecao;
        Data fimIntersecao;

        if (this.inicio.compareTo(outro.inicio) > 0)
            inicioIntersecao = this.inicio;
        else
            inicioIntersecao = outro.inicio;

        if (this.fim.compareTo(outro.fim) < 0)
            fimIntersecao = this.fim;
        else
            fimIntersecao = outro.fim;

        return new Periodo(inicioIntersecao, fimIntersecao);
    }

    @Override
    public String toString() {

        return "Data de início: " + this.inicio +
                "\nData de fim: " + this.fim;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this)
            return true;

        if (obj == null)
            return false;

        if (obj.getClass() != this.getClass())
            return false;

        Periodo periodo = (Periodo)obj;

        if (!this.inicio.equals(periodo.inicio))
            return false;

        if (!this.fim.equals(periodo.fim))
            return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.inicio.hashCode();
        retorno = retorno * 2 + this.fim.hashCode();

        if (retorno < 0)
            retorno = -retorno;

        return retorno;
    }

    @Override
    public int compareTo(Periodo periodo) {

        int comparacao;

        comparacao = this.inicio.compareTo(periodo.inicio);

        if (comparacao != 0)
            return comparacao;

        return this.fim.compareTo(periodo.fim);
    }

    public Periodo(Periodo periodo) throws Exception {

        if (periodo == null)
            throw new Exception("Período ausente");

        this.inicio = new Data(periodo.inicio);
        this.fim = new Data(periodo.fim);
    }

    @Override
    protected Object clone() {

        Periodo retorno = null;

        try {
            retorno = new Periodo(this);
        }
        catch (Exception erro) {
        }

        return retorno;
    }
}