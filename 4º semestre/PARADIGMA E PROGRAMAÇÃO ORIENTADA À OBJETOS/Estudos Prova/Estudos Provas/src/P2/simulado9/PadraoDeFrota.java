package P2.simulado9;

public interface PadraoDeFrota<T> {
    T getFilial();
    int getTotalVeiculos();
    int getAlugados();
    boolean isEncerrada();
    void adicionarVeiculos(int quantidade) throws Exception;
    void alugar(int quantidade) throws Exception;
    void devolver(int quantidade) throws Exception;
    void encerrarOperacao() throws Exception;
}
