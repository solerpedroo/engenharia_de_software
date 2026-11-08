package P2.simulado5;

public interface PadraoDeCreditos<T> {
    T getIdentificador();
    int getCreditosDisponiveis();
    void adicionarCreditos(int quantidade) throws Exception;
    void consumirCreditos(int quantidade) throws Exception;
}
