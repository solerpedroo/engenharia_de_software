package P2.simulado7;

public class Carrinho<T> implements PadraoDeCarrinho<T>, Cloneable {

    private T cliente;
    protected int quantidadeItens;
    private boolean finalizado;

    public Carrinho(T cliente, int quantidadeInicial)
            throws Exception {

        if (cliente == null)
            throw new Exception("Cliente não pode ser nulo");

        if (quantidadeInicial < 0)
            throw new Exception("Quantidade inicial inválida");

        this.cliente = cliente;
        this.quantidadeItens = quantidadeInicial;
        this.finalizado = false;
    }

    @Override
    public T getCliente() {
        return this.cliente;
    }

    @Override
    public int getQuantidadeItens() {
        return this.quantidadeItens;
    }

    public boolean isFinalizado() {
        return this.finalizado;
    }

    @Override
    public void adicionar(int quantidade) throws Exception {

        if (this.finalizado)
            throw new Exception("Carrinho já finalizado");

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > Integer.MAX_VALUE - this.quantidadeItens)
            throw new Exception("Limite numérico ultrapassado");

        this.quantidadeItens += quantidade;
    }

    @Override
    public void remover(int quantidade) throws Exception {

        if (this.finalizado)
            throw new Exception("Carrinho já finalizado");

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > this.quantidadeItens)
            throw new Exception("Quantidade insuficiente");

        this.quantidadeItens -= quantidade;
    }

    @Override
    public void finalizar() throws Exception {

        if (this.finalizado)
            throw new Exception("Carrinho já finalizado");

        if (this.quantidadeItens == 0)
            throw new Exception("Carrinho vazio");

        this.finalizado = true;
    }

    @Override
    public String toString() {
        return "Cliente: " + this.cliente +
                "\nQuantidade: " + this.quantidadeItens +
                "\nFinalizado: " + this.finalizado;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        Carrinho<?> outro = (Carrinho<?>) obj;

        if (!this.cliente.equals(outro.cliente))
            return false;

        if (this.quantidadeItens != outro.quantidadeItens)
            return false;

        if (this.finalizado != outro.finalizado)
            return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.cliente.hashCode();

        retorno = retorno * 2 +
                ((Integer)this.quantidadeItens).hashCode();

        retorno = retorno * 2 +
                ((Boolean)this.finalizado).hashCode();

        if (retorno < 0)
            retorno = -retorno;

        return retorno;
    }

    public Carrinho(Carrinho<T> outro) throws Exception {

        if (outro == null)
            throw new Exception("Carrinho ausente");

        this.cliente = outro.cliente;
        this.quantidadeItens = outro.quantidadeItens;
        this.finalizado = outro.finalizado;
    }

    @Override
    public Object clone() {

        Carrinho<T> retorno = null;

        try {
            retorno = new Carrinho<T>(this);
        } catch (Exception e) {}

        return retorno;
    }
}
