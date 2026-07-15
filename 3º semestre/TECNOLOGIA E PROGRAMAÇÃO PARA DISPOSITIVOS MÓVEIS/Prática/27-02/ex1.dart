// uma classe que representa uma entidade do mundo real, diezemos que uma "Entity class"
class Pessoa {
  String? nome;
  String? dataNascimento;
  double? peso;
  double? altura;
  void imprimir() {
    print('\nNome: ${nome}');
    print('Data de nascimento: ${dataNascimento}');
    print('Altura: ${altura}');
    print('Peso: ${peso}');
  }
}

/*void imprimir(Pessoa p) {
  print('\nNome: ${p.nome}');
  print('Data de nascimento: ${p.dataNascimento}');
  print('Altura: ${p.altura}');
  print('Peso: ${p.peso}\n');
}*/

class Estudante extends Pessoa {
  String? registroAcademico;
  @override // significa sobreescrever uma função que já está em outra classe, não apaga o print anterior apenas complementa com o abaixo
  void imprimir() {
    super.imprimir();
    print('Registro Acadêmico: ${registroAcademico}');
  }
}

void main() {
  var p1 =
      Pessoa(); // primeiro instância depois aplica os dados nas demais linhas
  p1.nome = 'João';
  p1.dataNascimento = '1990-11-10';
  p1.altura = 1.76;
  p1.peso = 100.3;

  var p2 = Pessoa();
  p2.nome = 'Maria';
  p2.dataNascimento = '2000-10-10';
  p2.peso = 50;
  p2.altura = 1.65;

  // p2 = p1; // criou uma cópia de objeto -> endereçamento de ponteiro

  /*if (p1 == p2) {
    // == compara se as instâncias são diferentes
    print('São iguais');
  } else {
    print('São diferentes');
  }*/

  Estudante e1 = Estudante();
  e1.nome = 'Pedro';
  e1.dataNascimento = '2006-10-31';
  e1.altura = 1.81;
  e1.peso = 75;
  e1.registroAcademico = '25005592';
}
