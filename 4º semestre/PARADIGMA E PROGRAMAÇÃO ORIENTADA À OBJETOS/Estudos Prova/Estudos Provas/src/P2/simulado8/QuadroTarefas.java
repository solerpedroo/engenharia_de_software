
package P2.simulado8;

public class QuadroTarefas<T>
        implements PadraoDeQuadro<T>, Cloneable {

    private T projeto;
    protected int pendentes;
    protected int concluidas;
    private boolean encerrado;

    public QuadroTarefas(T projeto, int pendentesIniciais,
                         int concluidasIniciais) throws Exception {

        if (projeto == null)
            throw new Exception("Projeto não pode ser nulo");

        if (pendentesIniciais < 0)
            throw new Exception("Pendentes não podem ser negativas");

        if (concluidasIniciais < 0)
            throw new Exception("Concluídas não podem ser negativas");

        this.projeto = projeto;
        this.pendentes = pendentesIniciais;
        this.concluidas = concluidasIniciais;
        this.encerrado = false;
    }

    @Override
    public T getProjeto() {
        return this.projeto;
    }

    @Override
    public int getPendentes() {
        return this.pendentes;
    }

    @Override
    public int getConcluidas() {
        return this.concluidas;
    }

    @Override
    public boolean isEncerrado() {
        return this.encerrado;
    }

    @Override
    public void adicionarTarefas(int quantidade)
            throws Exception {

        if (this.encerrado)
            throw new Exception("Quadro encerrado");

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        this.pendentes += quantidade;
    }

    @Override
    public void concluirTarefas(int quantidade)
            throws Exception {

        if (this.encerrado)
            throw new Exception("Quadro encerrado");

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > this.pendentes)
            throw new Exception("Tarefas pendentes insuficientes");

        this.pendentes -= quantidade;
        this.concluidas += quantidade;
    }

    @Override
    public void encerrar() throws Exception {

        if (this.encerrado)
            throw new Exception("Quadro já encerrado");

        if (this.pendentes > 0)
            throw new Exception("Existem tarefas pendentes");

        this.encerrado = true;
    }

    @Override
    public String toString() {
        return "Projeto: " + this.projeto +
                "\nPendentes: " + this.pendentes +
                "\nConcluídas: " + this.concluidas +
                "\nEncerrado: " + this.encerrado;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        QuadroTarefas<?> outro = (QuadroTarefas<?>) obj;

        if (!this.projeto.equals(outro.projeto)) return false;
        if (this.pendentes != outro.pendentes) return false;
        if (this.concluidas != outro.concluidas) return false;
        if (this.encerrado != outro.encerrado) return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.projeto.hashCode();
        retorno = retorno * 2 + ((Integer)this.pendentes).hashCode();
        retorno = retorno * 2 + ((Integer)this.concluidas).hashCode();
        retorno = retorno * 2 + ((Boolean)this.encerrado).hashCode();

        if (retorno < 0) retorno = -retorno;

        return retorno;
    }

    public QuadroTarefas(QuadroTarefas<T> outro)
            throws Exception {

        if (outro == null)
            throw new Exception("Quadro ausente");

        this.projeto = outro.projeto;
        this.pendentes = outro.pendentes;
        this.concluidas = outro.concluidas;
        this.encerrado = outro.encerrado;
    }

    @Override
    public Object clone() {

        QuadroTarefas<T> retorno = null;

        try {
            retorno = new QuadroTarefas<T>(this);
        } catch (Exception e) {}

        return retorno;
    }
}
