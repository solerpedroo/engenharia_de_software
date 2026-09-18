package P1.extras;

public class Sessao {

    private Data data;
    private Horario inicio;
    private Horario fim;
    private int qtdMaximaEspectadores;
    private int qtdAtualEspectadores;

    public Sessao(Data data, Horario inicio, Horario fim, int capacidade) throws Exception {

        if (fim.compareTo(inicio) < 0) {
            throw new Exception("Horário de fim não pode ser anterior ao de início");
        }

        if (capacidade <= 0) {
            throw new Exception("A capacidade deve ser maior que zero");
        }

        this.data = data;
        this.inicio = inicio;
        this.fim = fim;
        this.qtdMaximaEspectadores = capacidade;
        this.qtdAtualEspectadores = 0;
    }

    public void entrar(int quantidade) throws Exception {

        if (quantidade <= 0) {
            throw new Exception("A quantidade deve ser maior que zero");
        }

        if (qtdAtualEspectadores + quantidade > qtdMaximaEspectadores) {
            throw new Exception("Quantidade ultrapassa a capacidade máxima");
        }

        qtdAtualEspectadores += quantidade;
    }

    public void sair(int quantidade) throws Exception {

        if (quantidade <= 0) {
            throw new Exception("A quantidade deve ser maior que zero");
        }

        if (quantidade > qtdAtualEspectadores) {
            throw new Exception("Não é possível remover mais espectadores do que existem");
        }

        qtdAtualEspectadores -= quantidade;
    }

    public boolean estaLotada() {
        return qtdAtualEspectadores == qtdMaximaEspectadores;
    }

    public int getDuracaoEmMinutos() {
        return fim.diferencaEmMinutos(inicio);
    }

    public boolean contem(Horario horario) {
        return horario.compareTo(inicio) >= 0 &&
                horario.compareTo(fim) <= 0;
    }

    @Override
    public String toString() {
        return "Data: " + data +
                "\nHorário de Início: " + inicio +
                "\nHorário de Término: " + fim +
                "\nQuantidade Máxima: " + qtdMaximaEspectadores +
                "\nQuantidade Atual: " + qtdAtualEspectadores;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        Sessao sessao = (Sessao) obj;

        if (!this.data.equals(sessao.data)) return false;
        if (!this.inicio.equals(sessao.inicio)) return false;
        if (!this.fim.equals(sessao.fim)) return false;
        if (this.qtdMaximaEspectadores != sessao.qtdMaximaEspectadores) return false;
        if (this.qtdAtualEspectadores != sessao.qtdAtualEspectadores) return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.data.hashCode();
        retorno = retorno * 2 + this.inicio.hashCode();
        retorno = retorno * 2 + this.fim.hashCode();
        retorno = retorno * 2 + ((Byte) this.qtdMaximaEspectadores).hashCode();
        retorno = retorno * 2 + ((Byte) this.qtdAtualEspectadores).hashCode();

        if (retorno < 0) retorno = -retorno;

        return retorno;
    }

    @Override
    public int compareTo(Sessao sessao) {

        int comparacao;

        comparacao = this.data.compareTo(sessao.data);
        if (comparacao != 0) return comparacao;

        comparacao = this.inicio.compareTo(sessao.inicio);
        if (comparacao != 0) return comparacao;

        comparacao = this.fim.compareTo(sessao.fim);
        if (comparacao != 0) return comparacao;

        if (this.qtdMaximaEspectadores < sessao.qtdMaximaEspectadores)
            return -1;

        if (this.qtdMaximaEspectadores > sessao.qtdMaximaEspectadores)
            return 1;

        if (this.qtdAtualEspectadores < sessao.qtdAtualEspectadores)
            return -1;

        if (this.qtdAtualEspectadores > sessao.qtdAtualEspectadores)
            return 1;

        return 0;
    }
}