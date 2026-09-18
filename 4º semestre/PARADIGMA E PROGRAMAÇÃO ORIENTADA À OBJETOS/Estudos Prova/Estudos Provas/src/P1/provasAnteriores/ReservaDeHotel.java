package P1.provasAnteriores;

public class ReservaDeHotel {
    private Data entrada;
    private Data saida;
    private Moeda diaria;

    public ReservaDeHotel(Data entrada, Data saida, Moeda diaria) throws Exception {
        if(saida.compareTo(entrada) <= 0) throw new Exception("Saída deve ser posterior a entrada");

        this.entrada = entrada;
        this.saida = saida;
        this.diaria = diaria;
    }

    public Moeda getValorTotal(){
       Data atual = entrada.clone();
       int qtd = 0;
       while(atual.compareTo(saida)<0){
           atual.avanceUmDia();
           qtd++;
       }
        return diaria.multiplicar(qtd);
    }

    public Moeda converterValorTotal(String novaMoeda, double taxa){
        Moeda total = getValorTotal() * taxa;
        return total.converterPara(novaMoeda, taxa);
    }

    public void adiaSaida(Data nova) throws Exception {
        if (nova.compareTo(entrada) < 0) {
            throw new RuntimeException("Anterior à atual entrada");
        }
        if (nova.compareTo(saida) < 0) {
            throw new RuntimeException("Anterior à atualsaída");
        }
        saida = nova;
    }
}
