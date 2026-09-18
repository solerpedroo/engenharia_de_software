package P1.provasAnteriores;

public class Reserva {
    private byte qtdPessoas;
    private double valor;
    private short codigo;
    private boolean status;

    public Reserva(byte qtdPessoas, double valor, short codigo, boolean status) throws Exception{
        if(qtdPessoas < 0) throw new Exception("Quantidade de pessoas é negativa");
        this.qtdPessoas = qtdPessoas;
        if(valor < 0) throw new Exception("Valor é negativo");
        this.valor = valor;
        this.codigo = codigo;
        this.status = status;
    }

    public void setQtdPessoas(byte qtdPessoas) throws Exception{
        if (status == false) throw new Exception("Reserva cancelada");
        this.qtdPessoas = qtdPessoas;
    }

    public void setValor(double valor){
        this.valor = valor;
    }

    public void confirmar() throws Exception{
        if(status == false) throw new Exception("Reserva cancelada");
        status = true;
    }
}