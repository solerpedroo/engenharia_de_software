
package P2.simulado9;

public class Frota<T>
        implements PadraoDeFrota<T>, Cloneable {

    private T filial;
    protected int totalVeiculos;
    protected int alugados;
    private boolean encerrada;

    public Frota(T filial, int totalVeiculos,
                 int alugadosIniciais) throws Exception {

        if (filial == null)
            throw new Exception("Filial não pode ser nula");

        if (totalVeiculos <= 0)
            throw new Exception("Total deve ser positivo");

        if (alugadosIniciais < 0)
            throw new Exception("Alugados não podem ser negativos");

        if (alugadosIniciais > totalVeiculos)
            throw new Exception("Alugados excedem o total");

        this.filial = filial;
        this.totalVeiculos = totalVeiculos;
        this.alugados = alugadosIniciais;
        this.encerrada = false;
    }

    @Override
    public T getFilial() {
        return this.filial;
    }

    @Override
    public int getTotalVeiculos() {
        return this.totalVeiculos;
    }

    @Override
    public int getAlugados() {
        return this.alugados;
    }

    @Override
    public boolean isEncerrada() {
        return this.encerrada;
    }

    @Override
    public void adicionarVeiculos(int quantidade)
            throws Exception {

        if (this.encerrada)
            throw new Exception("Frota encerrada");

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > Integer.MAX_VALUE - this.totalVeiculos)
            throw new Exception("Limite numérico ultrapassado");

        this.totalVeiculos += quantidade;
    }

    @Override
    public void alugar(int quantidade) throws Exception {

        if (this.encerrada)
            throw new Exception("Frota encerrada");

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > this.totalVeiculos - this.alugados)
            throw new Exception("Veículos insuficientes");

        this.alugados += quantidade;
    }

    @Override
    public void devolver(int quantidade) throws Exception {

        if (this.encerrada)
            throw new Exception("Frota encerrada");

        if (quantidade <= 0)
            throw new Exception("Quantidade deve ser positiva");

        if (quantidade > this.alugados)
            throw new Exception("Devolução excede veículos alugados");

        this.alugados -= quantidade;
    }

    @Override
    public void encerrarOperacao() throws Exception {

        if (this.encerrada)
            throw new Exception("Frota já encerrada");

        if (this.alugados > 0)
            throw new Exception("Existem veículos alugados");

        this.encerrada = true;
    }

    @Override
    public String toString() {
        return "Filial: " + this.filial +
                "\nTotal: " + this.totalVeiculos +
                "\nAlugados: " + this.alugados +
                "\nEncerrada: " + this.encerrada;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        Frota<?> outra = (Frota<?>) obj;

        if (!this.filial.equals(outra.filial)) return false;
        if (this.totalVeiculos != outra.totalVeiculos) return false;
        if (this.alugados != outra.alugados) return false;
        if (this.encerrada != outra.encerrada) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;

        retorno = retorno * 2 + this.filial.hashCode();
        retorno = retorno * 2 +
                ((Integer)this.totalVeiculos).hashCode();
        retorno = retorno * 2 +
                ((Integer)this.alugados).hashCode();
        retorno = retorno * 2 +
                ((Boolean)this.encerrada).hashCode();

        if (retorno < 0) retorno = -retorno;

        return retorno;
    }

    public Frota(Frota<T> outra) throws Exception {
        if (outra == null)
            throw new Exception("Frota ausente");

        this.filial = outra.filial;
        this.totalVeiculos = outra.totalVeiculos;
        this.alugados = outra.alugados;
        this.encerrada = outra.encerrada;
    }

    @Override
    public Object clone() {
        Frota<T> retorno = null;

        try {
            retorno = new Frota<T>(this);
        } catch (Exception e) {}

        return retorno;
    }
}
