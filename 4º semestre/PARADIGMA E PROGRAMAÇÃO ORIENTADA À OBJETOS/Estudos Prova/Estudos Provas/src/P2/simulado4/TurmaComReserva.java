package P2.simulado4;

public class TurmaComReserva<T> extends Turma<T> implements Cloneable {
    private int vagasReservadas;

    public TurmaComReserva(T curso, int capacidade, int matriculadosIniciais, int vagasReservadas) throws Exception{
        super(curso, capacidade, matriculadosIniciais);
        if (vagasReservadas < 0) throw new Exception("VagasReservadas deve ser positiva");
        if (this.getMatriculados() + vagasReservadas > this.getCapacidade()) throw new Exception("Capacidade ultrapassada");
        this.vagasReservadas = vagasReservadas;
    }

    public int getVagasReservadas() {
        return this.vagasReservadas;
    }

    public void setVagasReservadas(int novaQuantidade) throws Exception {
        if (novaQuantidade < 0) throw new Exception("Nova quantidade deve ser positive");
        if (this.getMatriculados() + novaQuantidade > this.getCapacidade()) throw new  Exception("Nova quantidade não pode ultrapassar a capacidade");
        this.vagasReservadas = novaQuantidade;
    }

    public int getVagasLivres(){
        return this.getCapacidade() - this.vagasReservadas - this.getMatriculados();
    }

    public boolean esgotouVagasLivres(){
        return this.getVagasLivres() == 0;
    }

    @Override
    public void matricular(int quantidade) throws Exception{
        if (this.getVagasLivres() - quantidade < 0)  throw new  Exception("Não há vagas livres disponíveis");
        super.matricular(quantidade);
    }

    public void matricularPrioritario(int quantidade) throws Exception{
        if (quantidade < 0) throw new Exception("Quantidade deve ser positive");
        if (quantidade > this.vagasReservadas) throw new Exception("Quantidade não pode ultrapassar as vagas reservadas");
        super.matricular(quantidade);
        this.vagasReservadas -= quantidade;
    }

    public void liberarVagasReservadas(int quantidade) throws Exception{
        if (quantidade <= 0) throw new Exception("Quantidade deve ser positive");
        if (quantidade > this.vagasReservadas) throw new Exception("Não é possível liberar mais vagas do que existem");
        this.vagasReservadas -= quantidade;
    }

    @Override
    public String toString(){
        return super.toString() +
                "Vagas Reservadas: " + this.vagasReservadas;
    }

    @Override
    public boolean equals(Object obj){
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        TurmaComReserva<?> outra = (TurmaComReserva<?>) obj;
        if (!super.equals(outra)) return false;
        if (this.vagasReservadas != outra.vagasReservadas) return false;
        return true;
    }

    @Override
    public int hashCode(){
        int retorno = super.hashCode();
        retorno = retorno*2+((Integer)(this.vagasReservadas)).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public TurmaComReserva(TurmaComReserva<T> outra) throws Exception{
        super(outra);
        this.vagasReservadas = outra.vagasReservadas;
    }

    @Override
    public TurmaComReserva<T> clone(){
        TurmaComReserva<T> retorno = null;
        try{
            retorno = new TurmaComReserva<T>(this);
        } catch (Exception e){}
        return retorno;
    }
}
