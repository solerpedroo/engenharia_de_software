package P2.simulado6;

public class ContaComBloqueio<T> extends ContaDigital<T> {
    private int saldoBloqueado;
    private int limitePorSaque;

    public ContaComBloqueio(T titular, int saldoInicial, int saldoBloqueado, int limitePorSaque) throws Exception{
        super(titular, saldoInicial);
        if (saldoBloqueado < 0) throw new Exception("O saldo nunca pode ser negativo");
        if (saldoBloqueado > this.getSaldo()) throw new Exception("Saldo bloqueado não pode passar do saldo total");
        if (limitePorSaque <= 0) throw new Exception("O limite do saldo deve ser estritamente positivio");
        this.saldoBloqueado = saldoBloqueado;
        this.limitePorSaque = limitePorSaque;
    }

    public int getSaldoBloqueado(){
        return this.saldoBloqueado;
    }

    public int getLimitePorSaque(){
        return this.limitePorSaque;
    }

    public void setLimitePorSaque(int novoLimite) throws Exception{
        if (novoLimite <= 0) throw new Exception("Novo limite deve ser estritamente positivo");
        this.limitePorSaque = novoLimite;
    }

    public int getSaldoLivre(){
        return this.getSaldo() - this.getSaldoBloqueado();
    }

    public boolean estaTotalmenteBloqueado(){
        return this.getSaldo() == this.getSaldoBloqueado() || this.getSaldo() == 0;
    }

    public boolean podeSacar(int valor){
        if (valor <= 0) return false;
        if (valor > this.getLimitePorSaque()) return false;
        if (valor > this.getSaldoLivre()) return false;
        return true;
    }

    @Override
    public void sacar(int valor) throws Exception{
        if (!this.podeSacar(valor)) throw new Exception("Saque não permitido");
        super.sacar(valor);
    }

    public void bloquear(int valor) throws Exception{
        if (valor <= 0) throw new Exception("Valor deve ser positivo");
        if (valor > this.getSaldoLivre()) throw new Exception("Não é possível bloquar mais valor do que existe de saldo");
        this.saldoBloqueado += valor;
    }

    public void desbloquear(int valor) throws Exception{
        if (valor <= 0) throw new Exception("Valor deve ser positivo");
        if (valor > this.getSaldoBloqueado()) throw new Exception("Não é permitido desbloquear mais do que está bloqueado");
        this.saldoBloqueado -= valor;
    }

    public void depositarBloqueado(int valor) throws Exception{
        if (valor <= 0) throw new Exception("Valor deve ser positivo");
        super.depositar(valor);
        this.saldoBloqueado += valor;
    }
}