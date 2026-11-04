package P2.simulado4;

public interface PadraoDeTurma<T> {
    void matricular(int quantidade) throws Exception;
    void cancelarMatriculas(int quantidade) throws Exception;
    int getMatriculados();
    T getCurso();
}
