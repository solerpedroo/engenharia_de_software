package P2.simulado5;

public class PlanoControlado<T> extends PlanoDeCreditos<T> {
    private int limitePorOperacao;
    private int limitePorPeriodo;

    public PlanoControlado(T identificador, int creditosIniciais, int limitePorOperacao, int limitePorPeriodo) throws Exception{
        super(identificador, creditosIniciais);
        if (limitePorOperacao <= 0) throw new Exception("Limites devem ser maiores que zero");
        if (limitePorPeriodo <= 0) throw new Exception("Limites devem ser maiores que zero");
        this.limitePorOperacao = limitePorOperacao;
        this.limitePorPeriodo = limitePorPeriodo;
    }

    public int getLimitePorOperacao(){
        return this.limitePorOperacao;
    }

    public int getLimitePorPeriodo(){
        return this.limitePorPeriodo;
    }

    public void setLimitePorOperacao(int novoLimite) throws Exception{
     if (novoLimite <= 0) throw new Exception("Limite deve ser maior que zero");
     this.limitePorOperacao = novoLimite;
    }

    public void setLimitePorPeriodo(int novoLimite) throws Exception{
        if (novoLimite <= 0) throw new Exception("Limite deve ser maior que zero");
        if (novoLimite < this.getConsumidosNoPeriodo()) throw new Exception("Limite não pode ser reduzido da quantidade que já foi utilizada");
        this.limitePorPeriodo = novoLimite;
    }

    public int getRestanteNoPeriodo(){
        return this.getLimitePorPeriodo() - this.getConsumidosNoPeriodo();
    }

    public int getDisponivelParaConsumo(){
        return Math.min(this.getCreditosDisponiveis(), this.getRestanteNoPeriodo());
    }

    public boolean atingiuLimiteDoPeriodo(){
        return this.getLimitePorPeriodo() == this.getConsumidosNoPeriodo();
    }

    public boolean podeConsumir(int quantidade) {
        if (quantidade <= 0) return false;
        if (quantidade > this.getLimitePorOperacao()) return false;
        if (quantidade > this.getDisponivelParaConsumo()) return false;
        return true;
    }

    @Override
    public void consumirCreditos(int quantidade) throws Exception {
        if (!this.podeConsumir(quantidade)) throw new Exception("Consumo não permitido");
        super.consumirCreditos(quantidade);
    }

    @Override
    public String toString() {
        return super.toString() +
                "\nLimite por operação: " + this.limitePorOperacao +
                "\nLimite por período: " + this.limitePorPeriodo;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        PlanoControlado<?> outro = (PlanoControlado<?>) obj;
        if (!super.equals(outro)) return false;
        if (this.limitePorOperacao != outro.limitePorOperacao) return false;
        if (this.limitePorPeriodo != outro.limitePorPeriodo) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = super.hashCode();
        retorno = retorno * 2 + ((Integer)this.limitePorOperacao).hashCode();
        retorno = retorno * 2 + ((Integer)this.limitePorPeriodo).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public PlanoControlado(PlanoControlado<T> outro) throws Exception {
        super(outro);
        this.limitePorOperacao = outro.limitePorOperacao;
        this.limitePorPeriodo = outro.limitePorPeriodo;
    }

    @Override
    public Object clone() {
        PlanoControlado<T> retorno = null;
        try {
            retorno = new PlanoControlado<T>(this);
        } catch (Exception e) {}
        return retorno;
    }
}
