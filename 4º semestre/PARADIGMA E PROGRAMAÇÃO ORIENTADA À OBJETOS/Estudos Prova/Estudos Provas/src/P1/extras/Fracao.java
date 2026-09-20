package P1.extras;

public class Fracao implements Comparable<Fracao>, Cloneable {
    private int numerador;
    private int denominador;

    public Fracao(int numerador, int denominador) throws Exception{
        if(denominador == 0) throw new Exception("Denominador nunca pode ser 0");
        this.denominador = denominador;
        this.numerador = numerador;
    }

    public Fracao somar(Fracao outra) throws Exception{
        Fracao aux = new Fracao(this.numerador, this.denominador);
        aux.numerador = (this.numerador * outra.denominador) + (outra.numerador * this.denominador);
        aux.denominador = this.denominador * outra.denominador;
        return aux;
    }

    public Fracao subtrair(Fracao outra) throws Exception{
        Fracao aux = new Fracao(this.numerador, this.denominador);
        if(this.denominador == outra.denominador){
            aux.numerador = this.numerador - outra.numerador;
            aux.denominador = this.denominador;
        } else{
            aux.denominador = this.denominador * outra.denominador;
            aux.numerador = (this.numerador * outra.denominador) - (outra.numerador * this.denominador);
        }
        return aux;
    }

    public Fracao multiplicar(Fracao outra) throws Exception{
        Fracao aux = new Fracao(this.numerador, this.denominador);
        aux.numerador = this.numerador * outra.numerador;
        aux.denominador = this.denominador * outra.denominador;
        return aux;
    }

    public Fracao dividir(Fracao outra) throws Exception{
        Fracao aux = new Fracao(this.numerador, this.denominador);
        if(outra.numerador == 0) throw new Exception("Numerador da fração recebida é zero");
        if(outra.denominador == 0) throw new Exception("Denominador da fração recebida é zero");
        aux.numerador = this.numerador * outra.denominador;
        aux.denominador = this.denominador * outra.numerador;
        return aux;
    }

    public double getValorDecimal() {
        return (double)this.numerador / this.denominador;
    }

    @Override
    public String toString() {
        return "Fração: " + this.numerador + "/" + this.denominador;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj == null) return false;
        if(obj.getClass() != this.getClass()) return false;
        Fracao fracao = (Fracao) obj;
        if(fracao.numerador != this.numerador) return false;
        if(fracao.denominador != this.denominador) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno*2+((Integer) this.numerador).hashCode();
        retorno = retorno*2+((Integer) this.denominador).hashCode();
        if(retorno < 0) retorno = -retorno;
        return retorno;
    }

    @Override
    public int compareTo(Fracao o) {
        if(this.numerador < o.numerador) return -1;
        if(this.numerador > o.numerador) return 1;
        if(this.denominador < o.denominador) return -1;
        if(this.denominador > o.denominador) return 1;
        return 0;
    }

    /*
    @Override
    public int compareTo(Fracao o) {

        int valorThis = this.numerador * o.denominador;
        int valorOutro = o.numerador * this.denominador;

        if(valorThis < valorOutro) return -1;
        if(valorThis > valorOutro) return 1;

        return 0;
    }
    */

    public Fracao(Fracao fracao) throws Exception{
        if(fracao == null) throw new Exception("Fração ausente");
        this.numerador = fracao.numerador;
        this.denominador = fracao.denominador;
    }

    @Override
    protected Object clone(){
        Fracao retorno = null;
        try{
            retorno = new Fracao(this);
        } catch (Exception e) {}
        return retorno;
    }
}
