package aula1808;

public class Main
{
    public static void main (String[] args)
    {
        System.out.println(Data.getQtd()); // 0
        System.out.println(Data.isBissexto((short)2000)); // true
        System.out.println(Data.isValida((byte)10,(byte)8,(short)2026)); // true

        try
        {
            Data niverMaligno = new Data ((byte)19,(byte)1,(short)1966);
            System.out.println(niverMaligno); // 19/01/1966
            Data afterParty = niverMaligno.getDiaSeguinte();
            System.out.println(niverMaligno.getDia()+"/"+
                    niverMaligno.getMes()+"/"+
                    niverMaligno.getAno()); // 19/1/1966
            System.out.println(afterParty.getDia()+"/"+
                    afterParty.getMes()+"/"+
                    afterParty.getAno()); // 20/1/1966
            niverMaligno.avanceUmDia();
            System.out.println(niverMaligno.getDia()+"/"+
                    niverMaligno.getMes()+"/"+
                    niverMaligno.getAno()); // 20/1/1966
            niverMaligno.retrocedaUmDia();
            System.out.println(niverMaligno.getDia()+"/"+
                    niverMaligno.getMes()+"/"+
                    niverMaligno.getAno()); // 19/1/1966

        }
        catch (Exception erro)
        {
            System.err.println(erro.getMessage());
        }
    }
}

