package P2.extras.simulado1;

public class FilaConsultavel<T> extends Fila<T> implements Cloneable{
    public FilaConsultavel(int tamanhoInicial) throws Exception{
        super(tamanhoInicial);
    }

    public int getQuantidade(){
        return this.getUltimo()+1;
    }

    public boolean isVazia(){
        return this.getUltimo() == -1;
    }

    public boolean isCheia(){
        return this.getUltimo() + 1 == this.getCapacidade();
    }

    public void substituaPrimeiro(T novoItem) throws Exception{
        if (novoItem == null) throw new Exception("Item não pode ser nulo.");
        if (this.isVazia()) throw new Exception("Fila não pode estar vazia");
        this.setElemento(0, novoItem);
    }

    public FilaConsultavel(FilaConsultavel<T> filaConsultavel) throws Exception{
        super(filaConsultavel);
    }

    @Override
    public Object clone(){
        FIlaConsultavel<T> retorno = null;
        try {
            retorno = new FilaConsultavel<T>(this);
        } catch (Exception e) {}
        return retorno;
    }
}
