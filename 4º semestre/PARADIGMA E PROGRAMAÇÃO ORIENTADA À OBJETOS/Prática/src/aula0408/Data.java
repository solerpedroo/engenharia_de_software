package aula0408;

public class Data {
    private byte dia, mes;
    private short ano;

    private static int qtd = 0; // atributo estático

    private static int getQtd(){ // usa-se static no metodo por que esta mexendo em um atributo estatico
        return Data.qtd; // pode ser somente qtd (mas não é recomendado pois parece que está acessando uma variável local)
    }

    public static boolean isBissexto(short ano){ // é possível chamar essa função sem ter a instancia de um objeto, porque só precisa do parametro que está declarado

        // calendario juliano
        if (ano<1582){
            if (ano%4==0){
                return true;
            } else{
                return false;
            }
        }

        // calendario gregoriano
        if(ano%400==0) return true;
        if (ano%4==0 && ano%100!=0) return true;
        return false;
    }

    public static boolean isValida(byte b, byte b1, short i) {
        return false;
    }
}
