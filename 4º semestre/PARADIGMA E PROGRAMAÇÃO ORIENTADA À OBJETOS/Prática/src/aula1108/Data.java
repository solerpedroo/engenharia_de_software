package aula1108;

public class Data
{
    private byte  dia, mes;
    private short ano;

    private static int qtd=0;

    private static int getQtd ()
    {
        return Data.qtd;
    }

    public static boolean isBissexto (short ano)
    {
        // Calendario Juliano
        if (ano<1582)
            if (ano%4==0)
                return true;
            else
                return false;

        // Calendario Gregoriano
        if (ano%400==0) return true;
        if (ano%  4==0 && ano%100!=0) return true;
        return false;
    }

    public static boolean isValida (byte dia, byte mes, short ano)
    {
        if (ano<-45) return false; // antes do Calendario Juliano
        if (ano== 0) return false; // nao existiu ano 0; do ano 1ac foi direto para o ano 1dc
        if (ano==1582 && mes==10 && dia>=5 && dia<=14) return false; // dias cortados dos calendario pelo Papa Gregorio

        if (dia<1 || dia>31 || mes<1 || mes>12) return false;

        if (dia>30 && (mes==4 || mes==6 || mes==9 || mes==11)) return false;
        if (dia>29 && mes==2) return false;
        if (dia>28 && mes==2 && !Data.isBissexto(ano)) return false;

        return true;
    }

    public /*void*/ Data (byte dia, byte mes, short ano) throws Exception
    {
        if (!Data.isValida(dia,mes,ano))
            throw new Exception ("aula1108.Data invalida");

        this.dia=dia;
        this.mes=mes;
        this.ano=ano;

        Data.qtd++;
    }

    public void setDia (byte dia) throws Exception
    {
        if (!Data.isValida(dia,this.mes,this.ano))
            throw new Exception ("Dia invalido");

        this.dia=dia;
    }

    public byte getDia ()
    {
        return this.dia;
    }

    public void setMes (byte mes) throws Exception
    {
        if (!Data.isValida(this.dia,mes,this.ano))
            throw new Exception ("Mes invalido");

        this.mes=mes;
    }

    public byte getMes ()
    {
        return this.mes;
    }

    public void setAno (short ano) throws Exception
    {
        if (!Data.isValida(this.dia,this.mes,ano))
            throw new Exception ("Ano invalido");

        this.ano=ano;
    }

    public short getAno ()
    {
        return this.ano;
    }

    public void avanceUmDia () // altera o this
    {
        if (Data.isValida((byte)(this.dia+1),this.mes,this.ano))
            this.dia++;
        else if (Data.isValida((byte)1,(byte)(this.mes+1),this.ano))
        {
            this.dia=(byte)1;
            this.mes++;
        }
        else if (Data.isValida((byte)1,(byte)1,(short)(this.ano+1)))
        {
            this.dia=(byte)1;
            this.mes=(byte)1;
            this.ano++;
        }
        else if (Data.isValida((byte)1,(byte)1,(short)(this.ano+2))) // ano -1
        {
            this.dia=(byte)1;
            this.mes=(byte)1;
            this.ano=(short)(this.ano+2);
        }
        else // ano==1582 && mes==10 && dia==4
            this.dia=(byte)15;
    }

    public void avanceVariosDias (int qtd) throws Exception // altera o this
    {
        if (qtd <= 0) throw new Exception("Quantidade inválida");
        for (int i = 0; i<qtd; i++) this.avanceUmDia();
    }

    public Data getDiaSeguinte () // não altera o this
    {
        // não é o mais adequado, pois se der erro no construtor o metodo vai entender que a função não tem retorno
        // ele compila, porém não é performatico pois tem dois retornosS
        /*try{
            aula1108.Data nova = new aula1108.Data(this.dia, this.mes, this.ano);
            nova.avanceUmDia();
            return nova;
        } catch (Exception erro) {
            return null;
        }*/

        // adequado

        Data retorno = null;
        try{
            retorno = new Data(this.dia, this.mes, this.ano);
        } catch (Exception e) { }
        retorno.avanceUmDia();
        return retorno;
    }

    public Data getVariosDiasAdiante (int qtd) throws Exception // não altera o this
    {
        if (qtd <= 0) throw new Exception("Quantidade inválida");
        Data nova = new Data(this.dia, this.mes, this.ano);
        nova.avanceVariosDias(qtd);
        return nova;
    }

    public void retrocedaUmDia () // altera o this
    {
        if (Data.isValida((byte)this.dia, (byte) this.mes, (short) this.ano)){
            this.dia--;
        } else if(Data.isValida((byte)this.dia, (byte) this.mes, (short) this.ano)){
            this.mes--;
            byte dia = 31;
            while(!Data.isValida(dia, this.mes, this.ano)){
                dia--;
            }
            this.dia = dia;
        } else if(Data.isValida((byte) 1, (byte) 12, (short)(this.ano-1))){
            this.dia = 31;
            this.mes = 12;
            this.ano--;
        } else if(Data.isValida((byte)1, (byte)12, (short)(this.ano-2))){
            // ano 1 DC -> ano 1 AC
            this.dia = 31;
            this.mes = 12;
            this.ano = (short)(this.ano - 2);
        } else{
            // 15/10/1582
            this.dia = 4;
            this.mes = 10;
        }
    }

    public void retrocedaVariosDias (int qtd) throws Exception // altera o this
    {
        if (qtd <= 0) throw new Exception("Quantidade inválida");
        for (int i =0; i<qtd; i++) retrocedaUmDia();
    }

    public Data getDiaAnterior () // não altera o this
    {
        Data retorno = null;
        try{
            retorno = new Data(this.dia, this.mes, this.ano);
        } catch (Exception e){ }
        retorno.retrocedaUmDia();;
        return retorno;
    }

    public Data getVariosDiasAtras (int qtd) throws Exception // não altera o this
    {
        if (qtd <= 0) throw new Exception("Quantidade inválida");
        Data nova = new Data(this.dia, this.mes, this.ano);
        nova.retrocedaVariosDias(qtd);
        return nova;
    }
}

