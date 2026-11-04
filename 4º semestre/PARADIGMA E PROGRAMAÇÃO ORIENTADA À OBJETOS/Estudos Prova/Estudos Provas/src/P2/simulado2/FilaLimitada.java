package P2.simulado2;

public class FilaLimitada<T> extends Fila<T> implements Cloneable{
    private int limiteItens;

    public FilaLimitada(int tamanhoInicial, int limiteItens) throws Exception {
        super(tamanhoInicial);
        if (limiteItens <= 0) throw new Exception("Limite deve ser positivo");
        this.limiteItens = limiteItens;
    }

    public int getLimiteItens() {
        return this.limiteItens;
    }

    public void setLimiteItens(int novoLimite) throws Exception {
        if (novoLimite <= 0) throw new Exception("Não pode ser menor ou igual que zero");
        if (novoLimite < this.getQuantidade()) throw new Exception("Não pode ser inferior a quantidade atual de elementos armazenados");
        this.limiteItens = novoLimite;
    }

    public int getQuantidade() {
        return this.getUltimo()+1;

    }

    public boolean isVazia(){
        return this.getUltimo() == -1;
    }

    public boolean atingiuLimite(){
        return this.getQuantidade() == this.getLimiteItens();
    }

    @Override
    public void guardeItem(T item) throws Exception{
        if (item == null) throw new Exception("Não pode ser nulo");
        if(atingiuLimite()) throw new Exception("Limite lógico atingido");
        super.guardeItem(item);
    }

    @Override
    public String toString() {
        return super.toString() +
                "\nLimite de itens: " + this.limiteItens;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        if (!super.equals(obj)) return false;
        FilaLimitada<?> outro = (FilaLimitada<?>) obj;
        if (this.limiteItens != outro.limiteItens) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = super.hashCode();
        retorno = retorno * 2 + ((Integer)this.limiteItens).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public FilaLimitada(FilaLimitada<T> outro) throws Exception{
        super(outro);
        this.limiteItens = outro.limiteItens;
    }

    @Override
    public FilaLimitada<T> clone(){
        FilaLimitada<T> retorno = null;
        try {
            retorno = new FilaLimitada<T>(this);
        } catch (Exception ex) {}
        return retorno;
    }
}
