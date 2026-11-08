package P2.simulado7;

public interface PadraoDeCarrinho<T> {
    T getCliente();
    int getQuantidadeItens();
    void adicionar(int quantidade) throws Exception;
    void remover(int quantidade) throws Exception;
    void finalizar() throws Exception;
}
