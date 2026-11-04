
package P2.simulado3;

public class Estoque<T> implements PadraoDeEstoque<T>, Cloneable {

    private T produto;
    private int quantidade;

    public Estoque(T produto, int quantidadeInicial) throws Exception {
        if (produto == null)
            throw new Exception("Produto não pode ser nulo");

        if (quantidadeInicial < 0)
            throw new Exception("Quantidade inicial não pode ser negativa");

        this.produto = produto;
        this.quantidade = quantidadeInicial;
    }

    @Override
    public T getProduto() {
        return this.produto;
    }

    @Override
    public int getQuantidade() {
        return this.quantidade;
    }

    @Override
    public void adicionar(int quantidade) throws Exception {
        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > Integer.MAX_VALUE - this.quantidade)
            throw new Exception("Capacidade numérica excedida");

        this.quantidade += quantidade;
    }

    @Override
    public void retirar(int quantidade) throws Exception {
        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > this.quantidade)
            throw new Exception("Quantidade insuficiente em estoque");

        this.quantidade -= quantidade;
    }

    @Override
    public String toString() {
        return "Produto: " + this.produto +
                "\nQuantidade: " + this.quantidade;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        Estoque<?> outro = (Estoque<?>) obj;

        if (!this.produto.equals(outro.produto)) return false;
        if (this.quantidade != outro.quantidade) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;

        retorno = retorno * 2 + this.produto.hashCode();
        retorno = retorno * 2 + ((Integer)this.quantidade).hashCode();

        if (retorno < 0)
            retorno = -retorno;

        return retorno;
    }

    public Estoque(Estoque<T> outro) throws Exception {
        if (outro == null)
            throw new Exception("Estoque ausente");

        this.produto = outro.produto;
        this.quantidade = outro.quantidade;
    }

    @Override
    public Estoque<T> clone() {
        try {
            return new Estoque<T>(this);
        }
        catch (Exception e) {
            throw new IllegalStateException("Erro ao clonar estoque", e);
        }
    }
}
