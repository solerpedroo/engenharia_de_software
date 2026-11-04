package P2.simulado3;

public class EstoqueMinimo<T> extends Estoque<T> implements Cloneable{
    private int quantidadeMinima;
    public EstoqueMinimo(T produto, int quantidadeInicial, int quantidadeMinima) throws Exception{
        super(produto, quantidadeInicial);
        if (quantidadeMinima < 0) throw new Exception("Quantidade mínima não pode ser negativa");
        if (quantidadeMinima > this.getQuantidade()) throw new Exception("Quantidade mínima não pode ser maior que a quantidade atualmente armazenada");
        this.quantidadeMinima = quantidadeMinima;
    }

    public int getQuantidadeMinima() {
        return this.quantidadeMinima;
    }

    public void setQuantidadeMinima(int novaQuantidadeMinima) throws Exception {
        if (novaQuantidadeMinima < 0) throw new Exception("Nova quantidade mínima não pode ser negativa");
        if (novaQuantidadeMinima > this.getQuantidade()) throw new Exception("Nova quantidade mínima não pode ser maior que a quantidade armazenada");
        this.quantidadeMinima = novaQuantidadeMinima;
    }

    public int getQuantidadeDisponivel(){
        return this.getQuantidade() - this.quantidadeMinima;
    }

    public boolean atingiuMinimo(){
        return this.getQuantidadeDisponivel() == this.quantidadeMinima;
    }

    @Override
    public void retirar(int quantidade) throws Exception {
        if (quantidade > this.getQuantidadeDisponivel()) throw new Exception("Estoque mínimo seria ultrapassado");
        super.retirar(quantidade);
    }

    @Override
    public String toString(){
    return super.toString() +
            "\nQuantidade mínima: " + this.getQuantidadeMinima();
    }

    @Override
    public boolean equals(Object obj){
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        if(!super.equals(obj)) return false;
        EstoqueMinimo<?> outro =  (EstoqueMinimo<?>)obj;
        if (this.quantidadeMinima != outro.quantidadeMinima) return false;
        return true;
    }

    @Override
    public int hashCode(){
        int retorno = super.hashCode();
        retorno = retorno*2+((Integer)this.quantidadeMinima).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public EstoqueMinimo(EstoqueMinimo<T> outro) throws Exception{
        super(outro);
        this.quantidadeMinima = outro.quantidadeMinima;
    }

    @Override
    public EstoqueMinimo<T> clone(){
        EstoqueMinimo<T> retorno = null;
        try{
            retorno = new EstoqueMinimo<T>(this);
        } catch (Exception e){}
        return retorno;
    }
}
