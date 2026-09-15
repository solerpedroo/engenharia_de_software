package P1;

public class Main {
    public static void main(String[] args) {

        Complexo c1 = new Complexo(4, 3);
        Complexo c2 = new Complexo(2, 1);

        System.out.println("c1 = " + c1);
        System.out.println("c2 = " + c2);

        Complexo soma = c1.mais(c2);
        System.out.println("c1 + c2 = " + soma);

        Complexo subtracao = c1.menos(c2);
        System.out.println("c1 - c2 = " + subtracao);

        Complexo multiplicacao = c1.vezes(c2);
        System.out.println("c1 * c2 = " + multiplicacao);

        Complexo divisao = c1.divididoPor(c2);
        System.out.println("c1 / c2 = " + divisao);

        Complexo c3 = new Complexo(4, 3);

        System.out.println("c1.equals(c2) = " + c1.equals(c2));
        System.out.println("c1.equals(c3) = " + c1.equals(c3));

        System.out.println("hashCode de c1 = " + c1.hashCode());
        System.out.println("hashCode de c3 = " + c3.hashCode());
    }
}