package P1.extras;

public class Temperatura implements Comparable<Temperatura>, Cloneable {
    private short graus;

    public Temperatura(int graus) throws Exception{
        if(graus < -273) throw new Exception("Temperatura não pode ser menor que -273ºC");
        this.graus = (short)graus;
    }

    public Temperatura somar(Temperatura outra) throws Exception{
        return new Temperatura(this.graus + outra.graus);
    }

    public Temperatura subtrair(Temperatura outra) throws Exception{
        return new Temperatura(this.graus - outra.graus);
    }

    public Temperatura multiplicar(int fator) throws Exception{
        return new Temperatura(this.graus * outra.graus);
    }

    public boolean ehMaiorQue(Temperatura outra){
        return this.graus > outra.graus;
        // return this.compareTo(outra) >0;
    }

    public double converterParaFahrenheit(){
        return this.graus * (9.0 / 5.0) + 32;
    }

    @Override
    public String toString() {
        return "A temperatura é: " + this.graus + "º";
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj == null) return false;
        if(obj.getClass() != this.getClass()) return false;
        Temperatura temp = (Temperatura) obj;
        if(temp.graus != this.graus) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno*2+((Short)this.graus).hashCode();
        if(retorno < 0) retorno = -retorno;
        return retorno;
    }

    @Override
    public int compareTo(Temperatura temp) {
        if(this.graus < temp.graus) return -1;
        if(this.graus > temp.graus) return 1;
        return 0;
    }

    public Temperatura(Temperatura temp) throws Exception{
        if(temp == null) throw new Exception("Temperatura ausente");
        this.graus = temp.graus;
    }

    @Override
    protected Object clone(){
        Temperatura retorno = null;
        try{
            retorno = new Temperatura(this);
        } catch (Exception erro){}
        return retorno;
    }
}