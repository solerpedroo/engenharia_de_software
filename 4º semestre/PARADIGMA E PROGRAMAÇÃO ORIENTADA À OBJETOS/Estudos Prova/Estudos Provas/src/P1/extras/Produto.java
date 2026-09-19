package P1.extras;

public class Produto implements Comparable<Produto>, Cloneable{
    private String codigo;
    private String descricao;
    private double preco;
    private int estoque;

    public Produto(String codigo, String descricao, double preco, int estoque) throws Exception{
        if(codigo == null) throw new Exception("Código não pode ser null");
        if(codigo.isEmpty()) throw new Exception("Código não pode ser vazio");
        if(descricao == null) throw new Exception("Descrição não pode ser null");
        if(descricao.isEmpty()) throw new Exception("Descrição não pode ser vazia");
        if(preco < 0) throw new Exception("Preço não pode ser negativo");
        if(estoque < 0) throw new Exception("Estoque não pode ser negativo");

        this.codigo = codigo;
        this.descricao = descricao;
        this.preco = preco;
        this.estoque = estoque;
    }

    public void adicionarEstoque(int quantidade) throws Exception{
        if(quantidade < 0) throw new Exception("Quantidade não pode ser negativo");
        if (quantidade == 0) throw new Exception("Não será adicionado ao estoque pois a quantidade é zero");
        this.estoque += quantidade;
    }

    public void removerEstoque(int quantidade) throws Exception{
        if(quantidade < 0) throw new Exception("Quantidade não pode ser negativo");
        if (quantidade == 0) throw new Exception("Não será removido ao estoque pois a quantidade é zero");
        if(quantidade > this.estoque) throw new Exception("Não é possível remover mais itens do que existem no estoque.");
        this.estoque -= quantidade;
    }

    public double getValorEmEstoque(){
        return this.estoque * this.preco;
    }

    public Produto aplicarDesconto(double percentual) throws Exception{
        if(percentual < 0) throw new Exception("Não é possível aplicar um desconto com o percentual negativo");
        Produto aux = new Produto(this);
        aux.preco = aux.preco - (aux.preco * percentual / 100);
        return aux;
    }

    @Override
    public String toString() {
        return "Código: " + this.codigo +
                "\nDescrição: " + this.descricao +
                "\nPreço: R$" + this.preco +
                "\nEstoque: " + this.estoque;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj == null) return false;
        if(obj.getClass() != this.getClass()) return false;
        Produto prod = (Produto) obj;
        if (!prod.codigo.equals(this.codigo)) return false;
        if (!prod.descricao.equals(this.descricao)) return false;
        if (prod.preco != this.preco) return false;
        if (prod.estoque != this.estoque) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno*2+((String)this.codigo).hashCode();
        retorno = retorno*2+((String)this.descricao).hashCode();
        retorno = retorno*2+((Double)this.preco).hashCode();
        retorno = retorno*2+((Integer)this.estoque).hashCode();
        if(retorno <0) retorno = -retorno;
        return retorno;
    }

    @Override
    public int compareTo(Produto o) {
        if(this.preco < o.preco) return -1;
        if(this.preco > o.preco) return 1;
        if(this.estoque < o.estoque) return -1;
        if(this.estoque > o.estoque) return 1;
        return 0;
    }

    public Produto(Produto produto) throws Exception{
        if(produto == null) throw new Exception("Produto ausente");
        this.codigo = produto.codigo;
        this.descricao = produto.descricao;
        this.preco = produto.preco;
        this.estoque = produto.estoque;
    }

    @Override
    protected Object clone(){
        Produto retorno = null;
        try {
            retorno = new Produto(this);
        } catch (Exception e){}
        return retorno;
    }
}