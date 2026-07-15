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
}

void main(){
  // veículos não são iguais nem em conteúdo e nem em referência
  // v1 e v2 ocupam lugares diferentes na memória
  Veiculo v1 = Veiculo('123', 'ABC');
  Veiculo v2 = Veiculo('456', 'BCD');
  
  // quando se faz isso, ele pega um ponteiro e aponta para o endereço de memória de v1
  v2 = v1;
  // compara se são os mesmos objetos em referência de memória
  bool resultado = identical(v1, v2);

  if (resultado == true) print('mesmo objeto e mesma referência');
  else print('referências diferentes');
}
