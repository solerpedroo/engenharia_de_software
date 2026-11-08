
package P2.simulado6;

public class ContaDigital<T> implements PadraoDeConta<T>, Cloneable {

    private T titular;
    protected int saldo;

    public ContaDigital(T titular, int saldoInicial)
            throws Exception {

        if (titular == null)
            throw new Exception("Titular não pode ser nulo");

        if (saldoInicial < 0)
            throw new Exception("Saldo inicial inválido");

        this.titular = titular;
        this.saldo = saldoInicial;
    }

    @Override
    public T getTitular() {
        return this.titular;
    }

    @Override
    public int getSaldo() {
        return this.saldo;
    }

    @Override
    public void depositar(int valor) throws Exception {

        if (valor <= 0)
            throw new Exception("Valor deve ser positivo");

        if (valor > Integer.MAX_VALUE - this.saldo)
            throw new Exception("Saldo excede limite numérico");

        this.saldo += valor;
    }

    @Override
    public void sacar(int valor) throws Exception {

        if (valor <= 0)
            throw new Exception("Valor deve ser positivo");

        if (valor > this.saldo)
            throw new Exception("Saldo insuficiente");

        this.saldo -= valor;
    }

    @Override
    public String toString() {
        return "Titular: " + this.titular +
                "\nSaldo: " + this.saldo;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        ContaDigital<?> outra = (ContaDigital<?>) obj;

        if (!this.titular.equals(outra.titular))
            return false;

        if (this.saldo != outra.saldo)
            return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.titular.hashCode();
        retorno = retorno * 2 +
                ((Integer)this.saldo).hashCode();

        if (retorno < 0)
            retorno = -retorno;

        return retorno;
    }

    public ContaDigital(ContaDigital<T> outra)
            throws Exception {

        if (outra == null)
            throw new Exception("Conta ausente");

        this.titular = outra.titular;
        this.saldo = outra.saldo;
    }

    @Override
    public Object clone() {

        ContaDigital<T> retorno = null;

        try {
            retorno = new ContaDigital<T>(this);
        } catch (Exception e) {}

        return retorno;
    }
}
