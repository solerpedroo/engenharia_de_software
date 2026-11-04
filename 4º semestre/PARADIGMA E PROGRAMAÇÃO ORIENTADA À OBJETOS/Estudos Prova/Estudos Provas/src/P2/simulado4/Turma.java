package P2.simulado4;

public class Turma<T> implements PadraoDeTurma<T>, Cloneable {

    private T curso;
    private int capacidade;
    private int matriculados;

    public Turma(T curso, int capacidade, int matriculadosIniciais) throws Exception {
        if (curso == null) throw new Exception("Curso não pode ser nulo");
        if (capacidade <= 0) throw new Exception("Capacidade deve ser positiva");
        if (matriculadosIniciais < 0) throw new Exception("Matrículas não podem ser negativas");
        if (matriculadosIniciais > capacidade) throw new Exception("Capacidade ultrapassada");
        this.curso = curso;
        this.capacidade = capacidade;
        this.matriculados = matriculadosIniciais;
    }

    @Override
    public T getCurso() {
        return this.curso;
    }

    public int getCapacidade() {
        return this.capacidade;
    }

    @Override
    public int getMatriculados() {
        return this.matriculados;
    }

    @Override
    public void matricular(int quantidade) throws Exception {
        if (quantidade <= 0) throw new Exception("Quantidade deve ser positiva");
        if (quantidade > this.capacidade - this.matriculados) throw new Exception("Capacidade insuficiente");
        this.matriculados += quantidade;
    }

    @Override
    public void cancelarMatriculas(int quantidade) throws Exception {
        if (quantidade <= 0) throw new Exception("Quantidade deve ser positiva");
        if (quantidade > this.matriculados) throw new Exception("Quantidade maior que matrículas");
        this.matriculados -= quantidade;
    }

    @Override
    public String toString() {
        return "Curso: " + this.curso +
                "\nCapacidade: " + this.capacidade +
                "\nMatriculados: " + this.matriculados;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        Turma<?> outra = (Turma<?>) obj;
        if (!this.curso.equals(outra.curso)) return false;
        if (this.capacidade != outra.capacidade) return false;
        if (this.matriculados != outra.matriculados) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno * 2 + this.curso.hashCode();
        retorno = retorno * 2 + ((Integer) this.capacidade).hashCode();
        retorno = retorno * 2 + ((Integer) this.matriculados).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    public Turma(Turma<T> outra) throws Exception {
        if (outra == null) throw new Exception("Turma ausente");
        this.curso = outra.curso;
        this.capacidade = outra.capacidade;
        this.matriculados = outra.matriculados;
    }

    @Override
    public Turma<T> clone() {
        try {
            return new Turma<T>(this);
        } catch (Exception e) {
            throw new IllegalStateException("Erro na clonagem", e);
        }
    }
}
