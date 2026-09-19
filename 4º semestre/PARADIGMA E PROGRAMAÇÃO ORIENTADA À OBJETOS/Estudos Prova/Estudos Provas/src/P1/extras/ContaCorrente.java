package P1.extras;

public class ContaCorrente implements Comparable<ContaCorrente>, Cloneable {
    private String numero;
    private String titular;
    private double saldo;

    public ContaCorrente(String numero, String titular, double saldoInicial) throws Exception{
        if (numero == null) throw new Exception("Número da conta não pode ser nulo");
        if (numero.isEmpty()) throw new Exception("Número da conta não pode ser vazio");
        if (titular == null) throw new Exception("Titular não pode ser nulo");
        if (titular.isEmpty()) throw new Exception("Titular não pode ser vazio");
        if (saldoInicial < 0) throw new Exception("Saldo inicial não pode ser negativo");
        this.numero = numero;
        this.titular = titular;
        this.saldo = saldoInicial;
    }

    public void depositar(double valor) throws Exception{
        if (valor <= 0) throw new Exception("Depósito não pode ser negativo");
        this.saldo += valor;
    }

    public void sacar(double valor) throws Exception{
        if (valor <= 0) throw new Exception("O valor de um saque não pode ser negativo");
        if (valor > this.saldo) throw new Exception("O saque não pode deixar o saldo negativo");
        this.saldo -= valor;
    }

    public void transferir(ContaCorrente destino, double valor) throws Exception{
        if (destino == null) throw new Exception("Conta de destino ausente");
        if (valor <= 0) throw new Exception("Valor da transferência deve ser positivo");
        this.sacar(valor);
        destino.depositar(valor);
    }

    public double getSaldo(){
        return this.saldo;
    }

    public boolean temSaldoPara(double valor) throws Exception{
        if(valor<0) throw new Exception("Não é possível comparar pois o valor é negativo");
        return this.saldo >= valor;
    }

    @Override
    public String toString() {
        return "Titular da conta é: " + this.titular +
                "\nO número da conta é: " + this.numero +
                "\nO saldo é: R$" + this.saldo;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj == null) return false;
        if(obj.getClass() != this.getClass()) return false;
        ContaCorrente cont = (ContaCorrente) obj;
        if(cont.saldo != this.saldo) return false;
        if(cont.numero != this.numero) return false;
        if(cont.titular != this.titular) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno*2+((String)this.titular).hashCode();
        retorno = retorno*2+((String)this.numero).hashCode();
        retorno = retorno*2+((Double)this.saldo).hashCode();
        if(retorno<0) retorno = -retorno;
        return retorno;
    }

    @Override
    public int compareTo(ContaCorrente o) {
        if(this.saldo < o.saldo) return -1;
        if(this.saldo > o.saldo) return 1;
        return 0;
    }

    public ContaCorrente(ContaCorrente conta) throws Exception{
        if(conta == null) throw new Exception("Conta ausente");
        this.saldo = conta.saldo;
        this.titular = conta.titular;
        this.numero = conta.numero;
    }

    @Override
    protected Object clone(){
        ContaCorrente retorno = null;
        try {
            retorno = new ContaCorrente(this);
        } catch (Exception e){}
        return retorno;
    }
}