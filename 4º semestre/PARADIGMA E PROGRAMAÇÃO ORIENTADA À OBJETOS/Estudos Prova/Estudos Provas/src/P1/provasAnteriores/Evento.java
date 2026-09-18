package P1.provasAnteriores;

public class Evento {
    private Data data;
    private Horario inicio;
    private Horario fim;

    public Evento(Data data, Horario inicio, Horario fim) throws Exception{
        this.data = data;
        this.inicio = inicio;
        if(fim.compareTo(inicio) < 0) throw new Exception("Fim é anterior ao início");
        this.fim = fim;
    }

    public int getDuracaoEmMinutos(){
        return fim.diferenca(inicio);
    }

    public boolean contem(Horario h){
        if (h.comparteTo(incio) >= 0 && h.compareTo(fim) <= 0) return true;
        return false;
    }

    public boolean colide(Evento outro){
        if(!data.equals(outro.data)) return false;
        if(fim.compareTo(outro.inicio) < 0) return false;
        if(outro.fim.compareTo(inicio) < 0) return false;
        return true;
    }

    public Evento getIntersecao(Evento outro) throws Exception {
        if (!colide(outro)) {
            return null;
        }
        Horario inicioIntersecao;
        if (inicio.compareTo(outro.inicio) > 0) {
            inicioIntersecao = inicio;
        } else {
            inicioIntersecao = outro.inicio;
        }
        Horario fimIntersecao;
        if (fim.compareTo(outro.fim) < 0) {
            fimIntersecao = fim;
        } else {
            fimIntersecao = outro.fim;
        }
        return new Evento(data, inicioIntersecao, fimIntersecao);
    }
}
