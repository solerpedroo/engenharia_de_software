package P2.simulado8;

import java.util.stream.Stream;

public class QuadroControlado<T> extends QuadroTarefas<T> implements Cloneable {
    private int limiteMaximoPendentes;
    private int minimoConcluidasParaEncerrar;

    public QuadroControlado(T projeto, int pendentesIniciais, int concluidasIniciais, int limiteMaximoPendentes, int minimoConcluidasParaEncerrar) throws Exception{
        super(projeto, pendentesIniciais, concluidasIniciais);
        if (limiteMaximoPendentes <= 0) throw new Exception("Limite máximo de pendentes deve ser estritamente positivo");
        if (minimoConcluidasParaEncerrar < 0) throw new Exception("Não pode ser negativo");
        if (pendentesIniciais > limiteMaximoPendentes) throw new Exception("Quantidade inicial ultrapassa o limite");
        this.limiteMaximoPendentes = limiteMaximoPendentes;
        this.minimoConcluidasParaEncerrar = minimoConcluidasParaEncerrar;
    }

    public int getLimiteMaximoPendentes(){
        return this.limiteMaximoPendentes;
    }

    public int getMinimoConcluidasParaEncerrar(){
        return this.minimoConcluidasParaEncerrar;
    }

    public void setLimiteMaximoPendentes(int novoLimite) throws Exception{
        if (novoLimite <= 0) throw new Exception("Novo limite deve ser positivo");
        if (novoLimite < this.getPendentes()) throw new Exception("Não pode ser inferior a quantidade de pendentes");
        if (this.isEncerrado()) throw new Exception("Quadro encerrado, não pode ser alterado");
        this.limiteMaximoPendentes = novoLimite;
    }

    public void setMinimoConcluidasParaEncerrar (int novoLimite) throws Exception{
        if (novoLimite < 0) throw new Exception("Novo limite deve ser positivo");
        if (this.isEncerrado()) throw new Exception("Quadro encerrado, não pode ser alterado");
        this.minimoConcluidasParaEncerrar = novoLimite;
    }

    public int getEspacoParaPendentes(){
        return this.getLimiteMaximoPendentes() - this.getPendentes();
    }

    public int getFaltamParaMinimo(){
        if (this.getConcluidas() >= this.getMinimoConcluidasParaEncerrar()) return 0;
        return this.getMinimoConcluidasParaEncerrar() - this.getConcluidas();
    }

    public boolean atingiuLimitePendentes(){
        return this.getPendentes() == this.getLimiteMaximoPendentes();
    }

    public boolean podeAdicionarTarefas(int quantidade){
        if (quantidade <= 0) return false;
        if (this.isEncerrado()) return false;
        if (this.getPendentes() + quantidade > this.getLimiteMaximoPendentes()) return false;
        return true;
    }

    public boolean podeConcluirTarefas(int quantidade){
        if (quantidade <= 0) return false;
        if (this.isEncerrado()) return false;
        if (this.getPendentes() == 0) return false;
        if (quantidade > this.getPendentes()) return false;
        return true;
    }

    public boolean podeEncerrar(){
        if (this.isEncerrado()) return false;
        if (this.getPendentes() > 0) return false;
        if (this.getConcluidas() < this.getMinimoConcluidasParaEncerrar()) return false;
        return true;
    }

    @Override
    public void adicionarTarefas(int quantidade) throws Exception{
        if (!this.podeAdicionarTarefas(quantidade)) throw new Exception("Não é possível adicionar tarefas");
        super.adicionarTarefas(quantidade);
    }

    @Override
    public void concluirTarefas(int quantidade) throws Exception{
        if (!this.podeConcluirTarefas(quantidade)) throw new Exception("Não pode concluir tarefas");
        super.concluirTarefas(quantidade);
    }

    @Override
    public void encerrar() throws Exception{
        if (!this.podeEncerrar()) throw new Exception("Não pode encerrar");
        super.encerrar();
    }

    @Override
    public String toString(){
        return super.toString() +
                "\nLimite máximo de pendentes: " + this.getLimiteMaximoPendentes() +
                "\nMínimo concluíudas para encerrar: " + this.getMinimoConcluidasParaEncerrar();
    }

    @Override
    public boolean equals(Object obj){
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        QuadroControlado<?> outro = (QuadroControlado<T>) obj;
        if (!super.equals(outro)) return false;
        if (this.limiteMaximoPendentes != outro.limiteMaximoPendentes) return false;
        if (this.minimoConcluidasParaEncerrar != outro.minimoConcluidasParaEncerrar) return false;
        return true;
    }

    @Override
    public int hashCode(){
        int retorno = super.hashCode();
        retorno = retorno*2+((Integer)this.minimoConcluidasParaEncerrar).hashCode();
        retorno = retorno*2+((Integer)this.limiteMaximoPendentes).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public QuadroControlado(QuadroControlado<T> outro) throws Exception{
        super(outro);
        this.limiteMaximoPendentes = outro.limiteMaximoPendentes;
        this.minimoConcluidasParaEncerrar = outro.minimoConcluidasParaEncerrar;
    }

    @Override
    public Object clone(){
        QuadroControlado<T> retorno = null;
        try{
            retorno = new QuadroControlado<T>(this);
        } catch (Exception e) {}
        return retorno;
    }
}
