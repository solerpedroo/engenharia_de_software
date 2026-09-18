package P1.simulado;

public class Complexo {
    private int a;
    private int b;

    public Complexo(int a, int b){
        this.a = a;
        this.b = b;
    }

    public Complexo mais(Complexo c){
        return new Complexo(this.a + c.a, this.b + c.b);
    }

    public Complexo menos(Complexo c){
        return new Complexo(this.a - c.a, this.b - c.b);
    }

    public Complexo vezes(Complexo c){
        return new Complexo((this.a * c.a) - (this.b * c.b),(this.a * c.b) + (this.b * c.a));
    }

    public Complexo divididoPor(Complexo c){
        int denominador = (c.a * c.a) + (c.b * c.b);

        return new Complexo(((this.a * c.a) + (this.b * c.b)) / denominador,((c.a * this.b) - (this.a * c.b)) / denominador);
    }

    @Override
    public String toString() {
        return this.a + " + " + this.b + "i";
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this) return true;
        if(obj == null) return false;
        if(obj.getClass() != this.getClass()) return false;
        Complexo c = (Complexo) obj;
        if(c.a != this.a) return false;
        if(c.b != this.b) return false;
        return true;
    }

    @Override
    public int hashCode() {
        int retorno = 1;
        retorno = retorno*2+((Integer)this.a).hashCode();
        retorno = retorno*2+((Integer)this.b).hashCode();
        if(retorno < 0) retorno = -retorno;
        return retorno;
    }
}
