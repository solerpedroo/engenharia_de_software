package P2.simulado5;

public class PlanoDeCreditos<T>
        implements PadraoDeCreditos<T>, Cloneable {

    protected T identificador;
    protected int creditosDisponiveis;
    protected int consumidosNoPeriodo;

    public PlanoDeCreditos(T identificador,
                           int creditosIniciais) throws Exception {

        if (identificador == null)
            throw new Exception("Identificador ausente");

        if (creditosIniciais < 0)
            throw new Exception("Créditos não podem ser negativos");

        this.identificador = identificador;
        this.creditosDisponiveis = creditosIniciais;
        this.consumidosNoPeriodo = 0;
    }

    @Override
    public T getIdentificador() {
        return this.identificador;
    }

    @Override
    public int getCreditosDisponiveis() {
        return this.creditosDisponiveis;
    }

    public int getConsumidosNoPeriodo() {
        return this.consumidosNoPeriodo;
    }

    @Override
    public void adicionarCreditos(int quantidade)
            throws Exception {

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > Integer.MAX_VALUE - this.creditosDisponiveis)
            throw new Exception("Quantidade excede limite numérico");

        this.creditosDisponiveis += quantidade;
    }

    @Override
    public void consumirCreditos(int quantidade)
            throws Exception {

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > this.creditosDisponiveis)
            throw new Exception("Créditos insuficientes");

        if (quantidade > Integer.MAX_VALUE - this.consumidosNoPeriodo)
            throw new Exception("Consumo excede limite numérico");

        this.creditosDisponiveis -= quantidade;
        this.consumidosNoPeriodo += quantidade;
    }

    public void reiniciarPeriodo() {
        this.consumidosNoPeriodo = 0;
    }

    @Override
    public String toString() {
        return "Identificador: " + this.identificador +
                "\nCréditos disponíveis: " + this.creditosDisponiveis +
                "\nConsumidos no período: " + this.consumidosNoPeriodo;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        PlanoDeCreditos<?> outro = (PlanoDeCreditos<?>) obj;

        if (!this.identificador.equals(outro.identificador))
            return false;

        if (this.creditosDisponiveis != outro.creditosDisponiveis)
            return false;

        if (this.consumidosNoPeriodo != outro.consumidosNoPeriodo)
            return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.identificador.hashCode();
        retorno = retorno * 2 +
                ((Integer)this.creditosDisponiveis).hashCode();
        retorno = retorno * 2 +
                ((Integer)this.consumidosNoPeriodo).hashCode();

        if (retorno < 0)
            retorno = -retorno;

        return retorno;
    }

    public PlanoDeCreditos(PlanoDeCreditos<T> outro)
            throws Exception {

        if (outro == null)
            throw new Exception("Plano ausente");

        this.identificador = outro.identificador;
        this.creditosDisponiveis = outro.creditosDisponiveis;
        this.consumidosNoPeriodo = outro.consumidosNoPeriodo;
    }

    @Override
    public Object clone() {
        PlanoDeCreditos<T> retorno = null;
        try {
            retorno = new PlanoDeCreditos<T>(this);
        } catch (Exception e) {}

        return retorno;
    }
}
