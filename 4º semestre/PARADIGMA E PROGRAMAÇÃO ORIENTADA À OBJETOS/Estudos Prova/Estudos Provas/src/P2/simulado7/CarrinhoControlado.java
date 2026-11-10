package P2.simulado7;

public class CarrinhoControlado<T> extends Carrinho<T> implements Cloneable{
    private int limiteMaximoItens;
    private int minimoParaFinalizar;

    public CarrinhoControlado(T cliente, int quantidadeInicial, int limiteMaximoItens, int minimoParaFinalizar) throws Exception{
        super(cliente, quantidadeInicial);
        if (limiteMaximoItens <= 0) throw new Exception("Limite Máximo deve ser positivo");
        if (minimoParaFinalizar <= 0) throw new Exception("Mínimo para finalziar deve ser positivo");
        if (minimoParaFinalizar > limiteMaximoItens) throw new Exception("Não pode ser maior que o limite máximo");
        if (this.getQuantidadeItens() > limiteMaximoItens) throw new Exception("Quantidade inicial excede o limite");
        this.limiteMaximoItens = limiteMaximoItens;
        this.minimoParaFinalizar = minimoParaFinalizar;
    }

    public int getLimiteMaximoItens(){
        return this.limiteMaximoItens;
    }

    public int getMinimoParaFinalizar(){
        return this.minimoParaFinalizar;
    }

    public void setLimiteMaximoItens(int novoLimite) throws Exception{
        if (novoLimite <= 0) throw new Exception("Não pode ser menor ou igual a zero");
        if (novoLimite < this.getQuantidadeItens()) throw new Exception("Não pode ser menor que a quantidade de itens já armazenada");
        if (novoLimite < this.getMinimoParaFinalizar()) throw new Exception("Não pode ser inferior que o mínimo para finalizar");
        if (this.isFinalizado()) throw new Exception("Não é possível alterar pois o carrinho já está finalizadp");
        this.limiteMaximoItens = novoLimite;
    }

    public void setMinimoParaFinalizar(int novoMinimo) throws Exception{
        if (novoMinimo <= 0) throw new Exception("Não pode ser menor ou igual a zero");
        if (novoMinimo > this.getLimiteMaximoItens()) throw new Exception("Não pode ser superior ao limite máximo de itens");
        if (this.isFinalizado()) throw new Exception("Não é possível alterar pois o carrinho já está finalizadp");
        this.minimoParaFinalizar = novoMinimo;
    }

    public int getEspacoDisponivel(){
        return this.getLimiteMaximoItens() - this.getQuantidadeItens();
    }

    public boolean atingiuLimiteMaximo(){
        return this.getQuantidadeItens() == this.getLimiteMaximoItens();
    }

    public boolean podeAdicionar(int quantidade){
        if (quantidade <= 0) return false;
        if (this.isFinalizado()) return false;
        if (this.getQuantidadeItens() + quantidade > this.getLimiteMaximoItens()) return false;
        return true;
    }

    public boolean podeFinalizar(){
        if (this.isFinalizado()) return false;
        return this.getQuantidadeItens() >= this.getMinimoParaFinalizar();
    }

    @Override
    public void adicionar(int quantidade) throws Exception{
        if (!this.podeAdicionar(quantidade)) throw new Exception("Não é possível adicionar");
        super.adicionar(quantidade);
    }

    @Override
    public void finalizar() throws Exception{
        if (!this.podeFinalizar()) throw new Exception("Não é possível finalizar");
        super.finalizar();
    }

    @Override
    public String toString(){
        return super.toString() +
                "\nLimite máximo de itens: " + this.getLimiteMaximoItens() +
                "\nMínimo para finalizar: " + this.getMinimoParaFinalizar();
    }

    @Override
    public boolean equals(Object obj){
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        if (!super.equals(obj)) return false;
        CarrinhoControlado<?> outro = (CarrinhoControlado<?>) obj;
        if (this.minimoParaFinalizar != outro.minimoParaFinalizar) return false;
        if (this.limiteMaximoItens != outro.limiteMaximoItens) return false;
        return true;
    }

    @Override
    public int hashCode(){
        int retorno = super.hashCode();
        retorno = retorno*2+((Integer)this.limiteMaximoItens).hashCode();
        retorno = retorno*2+((Integer)this.minimoParaFinalizar).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public CarrinhoControlado(CarrinhoControlado<T> outro) throws Exception{
        super(outro);
        this.minimoParaFinalizar = outro.minimoParaFinalizar;
        this.limiteMaximoItens = outro.limiteMaximoItens;
    }

    @Override
    public Object clone(){
        CarrinhoControlado<T> retorno = null;
        try {
            retorno = new CarrinhoControlado<T>(this);
        } catch (Exception e) {}
        return retorno;
    }
}