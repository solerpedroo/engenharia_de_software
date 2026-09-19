package P1.extras;

public class ReservaDeVeiculo implements Cloneable {

    private Veiculo veiculo;
    private Data retirada;
    private Data devolucao;
    private double valorDiaria;
    private String codigoReserva;
    private boolean status;

    public ReservaDeVeiculo(
            Veiculo veiculo,
            Data retirada,
            Data devolucao,
            double diaria,
            String codigo) throws Exception {

        if (veiculo == null)
            throw new Exception("Veículo ausente");

        if (retirada == null)
            throw new Exception("Data de retirada ausente");

        if (devolucao == null)
            throw new Exception("Data de devolução ausente");

        if (diaria < 0)
            throw new Exception("Valor da diária não pode ser negativo");

        if (codigo == null)
            throw new Exception("Código da reserva ausente");

        if (devolucao.compareTo(retirada) <= 0)
            throw new Exception("Data de devolução deve ser posterior à retirada");

        this.veiculo = veiculo;
        this.retirada = retirada;
        this.devolucao = devolucao;
        this.valorDiaria = diaria;
        this.codigoReserva = codigo;

        // true = ativa
        // false = cancelada
        this.status = true;
    }

    public void cancelar() throws Exception {

        if (!this.status)
            throw new Exception("A reserva já está cancelada");

        this.status = false;
    }

    public void alterarDevolucao(Data novaData) throws Exception {

        if (novaData == null)
            throw new Exception("Nova data ausente");

        if (!this.status)
            throw new Exception(
                    "A reserva está cancelada, logo não é possível alterar a data"
            );

        if (novaData.compareTo(this.devolucao) <= 0)
            throw new Exception(
                    "A nova data deve ser posterior à data atual de devolução"
            );

        this.devolucao = novaData;
    }

    public int getQuantidadeDeDias() throws Exception {

        Data dataAuxiliar = new Data(this.retirada);
        int quantidadeDias = 0;

        while (!dataAuxiliar.equals(this.devolucao)) {
            dataAuxiliar.avanceUmDia();
            quantidadeDias++;
        }
        return quantidadeDias;
    }

    public double getValorTotal() throws Exception {

        return this.getQuantidadeDeDias() * this.valorDiaria;
    }

    public boolean isCancelada() throws Exception {

        return !this.status;
    }

    @Override
    public String toString() {

        return "O veículo alugado é: " + this.veiculo +
                "\nA data de retirada é: " + this.retirada +
                "\nA data de devolução é: " + this.devolucao +
                "\nO valor da diária é: R$" + this.valorDiaria +
                "\nO código da reserva é: " + this.codigoReserva +
                "\nO status está: " +
                (this.status ? "Ativa" : "Cancelada");
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == this) return true;
        if (obj == null) return false;
        if (obj.getClass() != this.getClass()) return false;

        ReservaDeVeiculo reserv = (ReservaDeVeiculo) obj;

        if (!reserv.retirada.equals(this.retirada)) return false;
        if (!reserv.devolucao.equals(this.devolucao)) return false;
        if (reserv.status != this.status) return false;
        if (!reserv.veiculo.equals(this.veiculo)) return false;
        if (!reserv.codigoReserva.equals(this.codigoReserva)) return false;
        if (reserv.valorDiaria != this.valorDiaria) return false;

        return true;
    }

    @Override
    public int hashCode() {

        int retorno = 1;

        retorno = retorno * 2 + this.veiculo.hashCode();
        retorno = retorno * 2 + this.retirada.hashCode();
        retorno = retorno * 2 + this.devolucao.hashCode();
        retorno = retorno * 2 + ((Double) this.valorDiaria).hashCode();
        retorno = retorno * 2 + this.codigoReserva.hashCode();
        retorno = retorno * 2 + ((Boolean) this.status).hashCode();

        if (retorno < 0)
            retorno = -retorno;

        return retorno;
    }

    public ReservaDeVeiculo(ReservaDeVeiculo reserv) throws Exception {

        if (reserv == null)
            throw new Exception("Reserva ausente");

        this.status = reserv.status;
        this.codigoReserva = reserv.codigoReserva;
        this.veiculo = reserv.veiculo;
        this.retirada = reserv.retirada;
        this.devolucao = reserv.devolucao;
        this.valorDiaria = reserv.valorDiaria;
    }

    @Override
    protected Object clone() {

        ReservaDeVeiculo retorno = null;

        try {
            retorno = new ReservaDeVeiculo(this);
        }
        catch (Exception erro) {
        }

        return retorno;
    }
}