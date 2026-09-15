package aula0109;

public class Palavra implements Comparable<Palavra>
{
    private String texto;

    public Palavra (String texto) throws Exception
    {
        // verifica se o texto recebido é nulo ou então vazio,
        // ou seja, sem nenhum caractere, lançando exceção.
        // armazena o texto recebido em this.texto.
        if (texto == null || texto.isEmpty()) throw new Exception("texto inválido");
        this.texto = texto;
    }

    public int getQuantidade (char letra)
    {
        // percorre o String this.texto, conta e retorna
        // quantas letras existem nele iguais a letra fornecida
        int qtd = 0;
        for(int i =0; i<this.texto.length(); i++){
            if(this.texto.charAt(i) == letra) qtd++;
        }
        return qtd;
    }

    public int getPosicaoDaIezimaOcorrencia (int i, char letra) throws Exception
    {
        // se i==0, retorna a posicao em que ocorre a primeira
        // aparicao de letra fornecida em this.texto;
        // se i==1, retorna a posicao em que ocorre a segunda
        // aparicao de letra fornecida em this.texto;
        // se i==2, retorna a posicao em que ocorre a terceira
        // aparicao de letra fornecida em this.texto;
        // e assim por diante.
        // lançar excecao caso nao encontre em this.texto
        // a Iézima aparição da letra fornecida.

        int ocorrencias = 0;

        for (int posicao = 0; posicao < this.texto.length(); posicao++)
        {
            if (this.texto.charAt(posicao) == letra)
            {
                ocorrencias++;

                if (ocorrencias == i + 1)
                    return posicao;
            }
        }

        throw new Exception("ocorrencia nao encontrada");
    }

    public int getTamanho ()
    {
        return this.texto.length();
    }

    @Override
    public String toString ()
    {
        return this.texto;
    }

    @Override
    public boolean equals (Object obj)
    {
        // verificar se this e obj possuem o mesmo conteúdo, retornando
        // true no caso afirmativo ou false no caso negativo
        if(obj == this) return true;
        if(obj == null) return true;
        if(obj.getClass() != this.getClass()) return false;
        Palavra pala = (Palavra) obj;
        if(pala.texto != this.texto) return false;
        return true;
    }

    @Override
    public int hashCode ()
    {
        // calcular e retornar o hashcode de this
        int retorno = 1;
        retorno = retorno*2+(this.texto).hashCode();
        if(retorno<0) retorno = -retorno;
        return retorno;
    }

    @Override
    public int compareTo (Palavra palavra)
    {
        return this.texto.compareTo(palavra.texto);
    }
}
