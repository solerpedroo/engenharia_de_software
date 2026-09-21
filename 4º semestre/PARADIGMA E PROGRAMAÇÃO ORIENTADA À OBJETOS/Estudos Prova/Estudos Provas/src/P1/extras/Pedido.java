package P1.extras;

public class Pedido implements Comparable<Pedido>, Cloneable {
    private String codigo;
    private Produto produto;
    private int quantidade;
    private double desconto;
    private boolean finalizado;

    public Pedido(String codigo, Produto produto, int quantidade, double desconto) throws Exception{
        if (codigo == null) throw new Exception("Código é nulo");
        if (codigo.isEmpty()) throw new Exception("Código é vazio");
        if (produto == null) throw new Exception("Produto não pode ser null");
        if (quantidade <= 0) throw new Exception("Quantidade deve ser maior que zero");
        if (desconto < 0) throw new Exception("Desconto não pode ser menor que zero");
        if (desconto > 100) throw new Exception("Desconto não pode ser maior que 100");

        this.codigo = codigo;
        this.produto = produto;
        this.quantidade = quantidade;
        this.desconto = desconto;
    }

    public double getValorSemDesconto(){
        return this.produto.getPreco() * quantidade;
    }

    public double getValorDesconto(){
        return this.getValorSemDesconto() * (this.desconto / 100);
    }

    public double getValorTotal(){
        return this.getValorSemDesconto() - this.getValorDesconto();
    }

    public void alterarQuantidade(int novaQuantidade) throws Exception{
        if (novaQuantidade <= 0) throw new Exception("Quantidade deve ser positiva");
        if (this.finalizado) throw new Exception("Finalizado não pode ser alterado");
        this.quantidade = novaQuantidade;
    }

    public void alterarDesconto(double novoDesconto) throws Exception{
        if (novoDesconto < 0) throw new Exception("Não pode ser menor que zero");
        if (novoDesconto > 100) throw new Exception("Não pode ser maior que cem");
        if (this.finalizado) throw new Exception("Finalizado não pode ser alterado");
        this.desconto = novoDesconto;
    }

    public void finalizar() throws Exception{
        if (this.finalizado) throw new Exception("Já está finalizado");
        this.finalizado = true;
    }

    public Pedido criarPedidoComQuantidade(int novaQuantidade) throws Exception{
        if (novaQuantidade <= 0) throw new Exception("Quantidade deve ser maior que zero");
        return new Pedido(this.codigo, this.produto, novaQuantidade, this.desconto);
    }

    @Override
    public String toString() {
        return "\nCódigo: " + this.codigo +
                "\nProduto: " + this.produto +
                "\nQuantidade: " + this.quantidade +
                "\nDesconto: " + this.desconto + "%" +
                "\nFinalizado? " + this.finalizado;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj == null) return false;
        if(obj.getClass() != this.getClass()) return false;
        Pedido pedido = (Pedido) obj;
        if(!pedido.codigo.equals(this.codigo)) return false;
        if(!pedido.produto.equals(this.produto)) return false;
        if(pedido.quantidade != this.quantidade) return false;
        if(pedido.desconto != this.desconto) return false;
        if(pedido.finalizado != this.finalizado) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno*2+((String)this.codigo).hashCode();
        retorno = retorno*2+(this.produto).hashCode();
        retorno = retorno*2+((Integer)this.quantidade).hashCode();
        retorno = retorno*2+((Double)this.desconto).hashCode();
        retorno = retorno*2+((Boolean)this.finalizado).hashCode();
        if(retorno<0) retorno = -retorno;
        return retorno;
    }

    @Override
    public int compareTo(Pedido o) {
        if (this.getValorTotal() < o.getValorTotal()) return -1;
        if (this.getValorTotal() > o.getValorTotal()) return 1;
        return 0;
    }

    public Pedido(Pedido pedido) throws Exception {
        if (pedido == null) throw new Exception("Pedido ausente");
        this.codigo = pedido.codigo;
        this.produto = new Produto(pedido.produto);
        this.quantidade = pedido.quantidade;
        this.desconto = pedido.desconto;
        this.finalizado = pedido.finalizado;
    }

    @Override
    protected Object clone(){
        Pedido retorno = null;
        try {
            retorno = new Pedido(this);
        } catch (Exception e) {}
        return retorno;
    }
}
