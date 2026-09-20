package P1.extras;

public class LocacaoDeSala implements Comparable<LocacaoDeSala>, Cloneable {
    private String codigo;
    private String responsavel;
    private Data data;
    private Horario inicio;
    private Horario fim;
    private int capacidade;
    private int participantes;
    private boolean cancelada;

    public LocacaoDeSala(String codigo, String responsavel, Data data, Horario inicio, Horario fim, int capacidade) throws Exception{
       if (codigo == null) throw new Exception("Código é nulo");
       if (codigo.isEmpty()) throw new Exception("Código é vazio");
       if (responsavel == null) throw new Exception("Responsável é nulo");
       if (responsavel.isEmpty()) throw new Exception("Responsável é vazio");
       if (data == null) throw new Exception("Data não pode ser null");
       if (inicio == null) throw new Exception("Inicio não pode ser null");
       if (fim == null) throw new Exception("Fim não pode ser null");
       if (fim.compareTo(inicio) <= 0) throw new Exception("Final não pode ser anterior a inicio");
       if (capacidade <= 0) throw new Exception("Capacidade deve ser maior que zero");

       this.codigo = codigo;
       this.responsavel = responsavel;
       this.data = data;
       this.inicio = inicio;
       this.fim = fim;
       this.capacidade = capacidade;
       this.participantes = 0;
    }

    public void adicionarParticipantes(int quantidade) throws Exception {
        if (quantidade <= 0) throw new Exception("Quantidade deve ser positiva");
        if (this.cancelada) throw new Exception("Locação está cancelada");
        if (this.participantes + quantidade > this.capacidade) throw new Exception("Capacidade máxima ultrapassada");
        this.participantes += quantidade;
    }

    public void removerParticipantes(int quantidade) throws Exception{
        if (quantidade <= 0) throw new Exception("Não é permitido quantidade não positiva");
        if (quantidade > this.participantes) throw new Exception("Não é possível remover mais pessoas do que existe");
        this.participantes -= quantidade;
    }

    public boolean estaLotada(){
        return this.participantes == this.capacidade;
    }

    public void cancelar() throws Exception{
        if (this.cancelada) throw new Exception("Já está cancelada");
        this.cancelada = true;
    }

    public void alterarFim(Horario novoFim) throws Exception{
        if (novoFim == null) throw new Exception("Novo Fim não pode ser null");
        if (this.cancelada) throw new Exception("Cancelada não pode ser alterada");
        if (novoFim.compareTo(this.inicio) <= 0) throw new Exception("Não pode ser menor que o inicio");
        this.fim = novoFim;
    }

    public boolean contem(Horario horario) throws Exception{
        if (horario == null) throw new Exception("Horário ausente");
        return horario.compareTo(this.inicio) >= 0 && horario.compareTo(this.fim) <= 0;
    }

    public boolean colide(LocacaoDeSala outra) throws Exception {
        if (outra == null) throw new Exception("Locação ausente");
        if (!this.data.equals(outra.data)) return false;
        if (this.fim.compareTo(outra.inicio) < 0) return false;
        if (outra.fim.compareTo(this.inicio) < 0) return false;
        return true;
    }

    @Override
    public String toString() {
        return "Código: " + this.codigo +
                "\nResponsável: " + this.responsavel +
                "\nData: " + this.data +
                "\nHorário de início: " + this.inicio +
                "\nHorário de término: " + this.fim +
                "\nCapacidade: " + this.capacidade +
                "\nParticipantes: " + this.participantes +
                "\nEstá cancelada? " + this.cancelada;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;
        LocacaoDeSala locacaoDeSala = (LocacaoDeSala) obj;
        if (!locacaoDeSala.codigo.equals(this.codigo)) return false;
        if (!locacaoDeSala.responsavel.equals(this.responsavel)) return false;
        if (!locacaoDeSala.data.equals(this.data)) return false;
        if (!locacaoDeSala.inicio.equals(this.inicio)) return false;
        if (!locacaoDeSala.fim.equals(this.fim)) return false;
        if (locacaoDeSala.capacidade != this.capacidade) return false;
        if (locacaoDeSala.participantes != this.participantes) return false;
        if (locacaoDeSala.cancelada != this.cancelada) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno*2+((String)this.codigo).hashCode();
        retorno = retorno*2+((String)this.responsavel).hashCode();
        retorno = retorno*2+(this.data).hashCode();
        retorno = retorno*2+(this.inicio).hashCode();
        retorno = retorno*2+(this.fim).hashCode();
        retorno = retorno*2+((Integer)this.capacidade).hashCode();
        retorno = retorno*2+((Integer)this.participantes).hashCode();
        retorno = retorno*2+((Boolean)this.cancelada).hashCode();
        if (retorno < 0) retorno = -retorno;
        return retorno;
    }

    @Override
    public int compareTo(LocacaoDeSala o) {
        if (this.data.compareTo(o.data) < 0) return -1;
        if (this.data.compareTo(o.data) > 0) return 1;
        if (this.inicio.compareTo(o.inicio) < 0) return -1;
        if (this.inicio.compareTo(o.inicio) > 0) return 1;
        if (this.fim.compareTo(o.fim) < 0) return -1;
        if (this.fim.compareTo(o.fim) > 0) return 1;
        return 0;
    }

    public LocacaoDeSala(LocacaoDeSala locacaoDeSala) throws Exception {
        if (locacaoDeSala == null) throw new Exception("Locação ausente");
        this.codigo = locacaoDeSala.codigo;
        this.responsavel = locacaoDeSala.responsavel;
        this.data = new Data(locacaoDeSala.data);
        this.inicio = new Horario(locacaoDeSala.inicio);
        this.fim = new Horario(locacaoDeSala.fim);
        this.capacidade = locacaoDeSala.capacidade;
        this.participantes = locacaoDeSala.participantes;
        this.cancelada = locacaoDeSala.cancelada;
    }

    @Override
    protected Object clone(){
        LocacaoDeSala retorno = null;
        try {
            retorno  = new LocacaoDeSala(this);
        } catch (Exception e) {}
        return retorno;
    }
}
