package P1.provasAnteriores;

public class PartidaDeFutebol {
    private Data data;
    private Placar placar;

    public PartidaDeFutebol(Data data, String timeA, String timeB){
        this.data = data;
        this.placar = new Placar(timeA, timeB);
    }

    public void registrarGol(String time){
        placar.marcarGol(time);
    }

    public void encerrar(){
        placar.encerrar();
    }

    public String getVencedor(){
        return placar.encerrar();
    }
}
