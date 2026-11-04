package P2.simulado3;

public interface PadraoDeEstoque<T> {
    void adicionar (int quantidade) throws Exception;
    void retirar (int quantidade) throws Exception;
    int getQuantidade();
    T getProduto();
}
