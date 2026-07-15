class Pessoa{
    final String nome;
    final double peso;
    final double altura;
    double? _imc;

    Pessoa(this.nome, this.peso, this.altura){
      this._calcularImc();
    }

    // metodo de acesso (getter) para o IMC
    double? get imc => _imc;

    void _calcularImc(){
        this._imc = (this.peso / (this.altura * this.altura));
    }
}