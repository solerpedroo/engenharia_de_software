
package P2.simulado9;

public class FrotaControlada<T> extends Frota<T> implements Cloneable {
    private int reservaTecnica;
    private int limiteSimultaneo;

    public FrotaControlada(T filial, int totalVeiculos, int alugadosIniciais, int reservaTecnica, int limiteSimultaneo) throws Exception{
        super(filial, totalVeiculos, alugadosIniciais);
        if (reservaTecnica < 0) throw new Exception("Reserva técnica não pode ser negativa");
        if (limiteSimultaneo <= 0) throw new Exception("Limite simultâneo deve ser positivo");
        if (limiteSimultaneo > this.getTotalVeiculos()) throw new Exception("Limite simultâneo não pode ultrapassar o total da frota");
        if (alugadosIniciais > limiteSimultaneo) throw new Exception("Alugados não podem ultrapassar o limite simultâneo");
        if (reservaTecnica > this.getDisponiveis()) throw new Exception("Reserva técnica não pode ultrapassar os veículos disponíveis");
        this.reservaTecnica = reservaTecnica;
        this.limiteSimultaneo = limiteSimultaneo;
    }

    public int getReservaTecnica(){
        return this.reservaTecnica;
    }

    public int getLimiteSimultaneo(){
        return this.limiteSimultaneo;
    }

    public void setReservaTecnica(int novaReserva) throws Exception{
        if (this.isEncerrada()) throw new Exception("Frota encerrada");
        if (novaReserva < 0) throw new Exception("Reserva técnica não pode ser negativa");
        if (novaReserva > this.getDisponiveis()) throw new Exception("Reserva não pode ultrapassar os veículos disponíveis");
        this.reservaTecnica = novaReserva;
    }

    public void setLimiteSimultaneo(int novoLimite) throws Exception{
        if (this.isEncerrada()) throw new Exception("Frota encerrada");
        if (novoLimite <= 0) throw new Exception("Limite deve ser positivo");
        if (novoLimite < this.getAlugados()) throw new Exception("Limite não pode ser inferior à quantidade alugada");
        if (novoLimite > this.getTotalVeiculos()) throw new Exception("Limite não pode ultrapassar o total de veículos");
        this.limiteSimultaneo = novoLimite;
    }

    public int getDisponiveis(){
        return this.getTotalVeiculos() - this.getAlugados();
    }

    public int getDisponiveisParaAluguel(){
        int disponiveisFisicos = this.getDisponiveis() - this.getReservaTecnica();
        int restantesNoLimite = this.getLimiteSimultaneo() - this.getAlugados();
        if (disponiveisFisicos < 0) return 0;
        if (restantesNoLimite < 0) return 0;
        return Math.min(disponiveisFisicos, restantesNoLimite);
    }

    public boolean atingiuLimiteSimultaneo(){
        return this.getAlugados() == this.getLimiteSimultaneo();
    }

    public boolean podeAlugar(int quantidade){
        if (quantidade <= 0) return false;
        if (this.isEncerrada()) return false;
        if (quantidade > this.getDisponiveisParaAluguel()) return false;
        return true;
    }

    public boolean podeDevolver(int quantidade){
        if (quantidade <= 0) return false;
        if (this.isEncerrada()) return false;
        if (quantidade > this.getAlugados()) return false;
        return true;
    }

    public boolean podeEncerrar(){
        if (this.isEncerrada()) return false;
        if (this.getAlugados() > 0) return false;
        return true;
    }

    @Override
    public void alugar(int quantidade) throws Exception{
        if (!this.podeAlugar(quantidade)) throw new Exception("Não é possível alugar, não atende aos critérios");
        super.alugar(quantidade);
    }

    @Override
    public void devolver(int quantidade) throws Exception{
        if (!this.podeDevolver(quantidade)) throw new Exception("Não é possível devolver, não atende aos critérios");
        super.devolver(quantidade);
    }

    @Override
    public void encerrarOperacao() throws Exception{
        if (!this.podeEncerrar()) throw new Exception("Não é possível encerrar, não atende aos critérios");
        super.encerrarOperacao();
    }

    @Override
    public String toString(){
        return super.toString() +
                "\nReserva técnica: " + this.getReservaTecnica() +
                "\nLimite simultâneo: " + this.getLimiteSimultaneo();
    }

    @Override
    public boolean equals(Object obj){
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        FrotaControlada<?> outro = (FrotaControlada<?>) obj;
        if (!super.equals(outro)) return false;
        if (this.reservaTecnica != outro.reservaTecnica) return false;
        if (this.limiteSimultaneo != outro.limiteSimultaneo) return false;
        return true;
    }

    @Override
    public int hashCode(){
        int retorno = super.hashCode();
        retorno = retorno*2+((Integer)this.limiteSimultaneo).hashCode();
        retorno = retorno*2+((Integer)this.reservaTecnica).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public FrotaControlada(FrotaControlada<T> outra) throws Exception{
        super(outra);
        this.reservaTecnica = outra.reservaTecnica;
        this.limiteSimultaneo = outra.limiteSimultaneo;
    }

    @Override
    public Object clone(){
        FrotaControlada<T> retorno = null;
        try{
            retorno = new FrotaControlada<T>(this);
        } catch (Exception e) {}
        return retorno;
    }
}
