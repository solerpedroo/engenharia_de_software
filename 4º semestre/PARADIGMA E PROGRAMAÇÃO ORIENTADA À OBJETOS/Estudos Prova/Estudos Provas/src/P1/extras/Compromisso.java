package P1.extras;

public class Compromisso implements Comparable<Compromisso>, Cloneable {

    private String descricao;
    private Data data;
    private Horario inicio;
    private Horario fim;

    public Compromisso(String descricao, Data data, Horario inicio, Horario fim) throws Exception {

        if (descricao == null)
            throw new Exception("Descrição não pode ser nula");

        if (descricao.isEmpty())
            throw new Exception("Descrição não pode estar vazia");

        if (data == null)
            throw new Exception("Data não pode ser nula");

        if (inicio == null)
            throw new Exception("Horário inicial não pode ser nulo");

        if (fim == null)
            throw new Exception("Horário final não pode ser nulo");

        if (inicio.compareTo(fim) >= 0)
            throw new Exception("Horário final deve ser posterior ao inicial");

        this.descricao = descricao;
        this.data = new Data(data);
        this.inicio = new Horario(inicio);
        this.fim = new Horario(fim);
    }

    public int getDuracaoEmMinutos() {

        int inicioEmMinutos =
                this.inicio.getHora() * 60 +
                        this.inicio.getMinuto();

        int fimEmMinutos =
                this.fim.getHora() * 60 +
                        this.fim.getMinuto();

        return fimEmMinutos - inicioEmMinutos;
    }

    public boolean contem(Horario horario) throws Exception {

        if (horario == null)
            throw new Exception("Horário ausente");

        return horario.compareTo(this.inicio) >= 0 &&
                horario.compareTo(this.fim) <= 0;
    }

    public boolean colide(Compromisso outro) throws Exception {

        if (outro == null)
            throw new Exception("Compromisso ausente");

        if (!this.data.equals(outro.data))
            return false;

        if (this.fim.compareTo(outro.inicio) < 0)
            return false;

        if (outro.fim.compareTo(this.inicio) < 0)
            return false;

        return true;
    }

    public Compromisso getIntersecao(Compromisso outro) throws Exception {

        if (outro == null)
            throw new Exception("Compromisso ausente");

        if (!this.colide(outro))
            return null;

        Horario inicioIntersecao;
        Horario fimIntersecao;

        if (this.inicio.compareTo(outro.inicio) > 0)
            inicioIntersecao = this.inicio;
        else
            inicioIntersecao = outro.inicio;

        if (this.fim.compareTo(outro.fim) < 0)
            fimIntersecao = this.fim;
        else
            fimIntersecao = outro.fim;

        return new Compromisso(
                "Interseção",
                this.data,
                inicioIntersecao,
                fimIntersecao
        );
    }

    @Override
    public String toString() {

        return "Descrição: " + this.descricao +
                "\nData: " + this.data +
                "\nHorário de início: " + this.inicio +
                "\nHorário de término: " + this.fim;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this)
            return true;

        if (obj == null)
            return false;

        if (obj.getClass() != this.getClass())
            return false;

        Compromisso comp = (Compromisso) obj;

        if (!comp.descricao.equals(this.descricao))
            return false;

        if (!comp.data.equals(this.data))
            return false;

        if (!comp.inicio.equals(this.inicio))
            return false;

        if (!comp.fim.equals(this.fim))
            return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.descricao.hashCode();
        retorno = retorno * 2 + this.data.hashCode();
        retorno = retorno * 2 + this.inicio.hashCode();
        retorno = retorno * 2 + this.fim.hashCode();

        if (retorno < 0)
            retorno = -retorno;

        return retorno;
    }

    @Override
    public int compareTo(Compromisso c) {

        int comparacao;

        comparacao = this.data.compareTo(c.data);

        if (comparacao != 0)
            return comparacao;

        comparacao = this.inicio.compareTo(c.inicio);

        if (comparacao != 0)
            return comparacao;

        return this.fim.compareTo(c.fim);
    }

    public Compromisso(Compromisso compromisso) throws Exception {

        if (compromisso == null)
            throw new Exception("Compromisso ausente");

        this.descricao = compromisso.descricao;
        this.data = new Data(compromisso.data);
        this.inicio = new Horario(compromisso.inicio);
        this.fim = new Horario(compromisso.fim);
    }

    @Override
    protected Object clone() {

        Compromisso retorno = null;

        try {
            retorno = new Compromisso(this);
        }
        catch (Exception e) {
        }

        return retorno;
    }
}