package P2.simulado8;

public interface PadraoDeQuadro<T> {
    T getProjeto();
    int getPendentes();
    int getConcluidas();
    boolean isEncerrado();
    void adicionarTarefas(int quantidade) throws Exception;
    void concluirTarefas(int quantidade) throws Exception;
    void encerrar() throws Exception;
}
