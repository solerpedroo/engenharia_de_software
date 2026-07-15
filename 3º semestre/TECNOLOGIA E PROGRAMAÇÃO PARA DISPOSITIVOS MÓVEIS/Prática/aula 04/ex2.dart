enum Propoulsao { 
  eletrica, 
  combustao, 
  mecanica, 
  hibrida 
}

enum Combustivel {
  biodiesel,
  bunker,
  diesels500,
  diesels10,
  etanol,
  gnv,
  gasolina,
  querosene
}

class Veiculo {
  String renavam;
  String chassi;

  String? placa;
  String? marca;
  int? anoFabricacao;
  int? anoModelo;
  Propoulsao? tipoPropulsao;
  List<Combustivel>? combustiveis;

  Veiculo(this.renavam, this.chassi);

  // está comparando uma instância com a outra
  bool ehMesmoVeiculo(Veiculo outro){
    if(this.renavam == outro.renavam && this.chassi == outro.chassi){
       return true;
    }else{
        return false;
    }
  }
}

void main(){
  // veículos não são iguais nem em conteúdo e nem em referência
  // v1 e v2 ocupam lugares diferentes na memória
  Veiculo v1 = Veiculo('123', 'ABC'); 
  v1.tipoPropulsao = Propoulsao.combustao;
  v1.combustiveis = [
      Combustivel.etanol, 
      Combustivel.gasolina
  ];

  Veiculo v2 = Veiculo('456', 'BCD');
  v2.tipoPropulsao = Propoulsao.eletrica;

  // por padrão está comparando referências desde que não exista a modificação comportamental do operador de igualdade (==), em dart o podemos definir para cada classe o que o operador (==) deve fazer: comparar conteúdos ao ínves de referências
  /*if (v1 == v2)*/
  
  // v1 nesse caso é o this (ele que chama o método comparativo), v2 é o outro (vai como parâmatro), this é a instância na qual vai chamar o serviço do método
  if(v1.ehMesmoVeiculo(v2)){
    print('Veículos com mesmo renavam e chassi');
  }else{
    print("Veículos com chassi e renavam diferentes");
  }
}

  // comparação de valores (conteúdo)
  /*if(v1.renavam == v2.renavam && v1.chassi == v2.chassi){
      print("Para o detran é o memso carro");
  }else{
      print("Não é o mesmo carro");
  }*/