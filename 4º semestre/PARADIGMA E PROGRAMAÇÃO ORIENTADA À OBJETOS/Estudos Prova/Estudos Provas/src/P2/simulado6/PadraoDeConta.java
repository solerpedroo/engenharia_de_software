package P2.simulado6;

public interface PadraoDeConta<T> {
    T getTitular();
    int getSaldo();
    void depositar(int valor) throws Exception;
    void sacar(int valor) throws Exception;
}
