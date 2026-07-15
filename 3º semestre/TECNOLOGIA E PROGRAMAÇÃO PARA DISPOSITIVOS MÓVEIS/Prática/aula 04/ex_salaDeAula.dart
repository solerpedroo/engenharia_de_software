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

abstract class MeioDeTransporte{
  String id;
  String fabricante;
  String modelo;
  double capacidadeCargaKg;
  List<Combustivel>? combustiveis;

  void imprimir(){
    print("\nID: ${id}");
    print("Fabricante: ${fabricante}");
    print("Modelo: ${modelo}");
    print("Capacidade de Carga (KG): ${capacidadeCargaKg}");
    print("Combustíveis: ${combustiveis}\n");
  }

  MeioDeTransporte(this.id, this.fabricante, this.modelo, this.capacidadeCargaKg, this.combustiveis);
}

abstract class VeiculosTerrestres extends MeioDeTransporte{
  String placa;
  String chassi;
  String renavam;

  @override
  void imprimir(){
    super.imprimir();
    print("Placa: ${placa}");
    print("Chassi: ${chassi}");
    print("Renavam: ${renavam}");
  }

    VeiculosTerrestres(
    String id,
    String fabricante,
    String modelo,
    double capacidadeCargaKg,
    List<Combustivel>? combustiveis,
    this.placa,
    this.chassi,
    this.renavam,
  ) : super(id, fabricante, modelo, capacidadeCargaKg, combustiveis);
}

class Automovel extends VeiculosTerrestres{
  int numeroPortas;
  @override
  void imprimir(){
    super.imprimir();
    print("Número de portas: ${numeroPortas}");
  }

    Automovel(
    String id,
    String fabricante,
    String modelo,
    double capacidadeCargaKg,
    List<Combustivel>? combustiveis,
    String placa,
    String chassi,
    String renavam,
    this.numeroPortas,
  ) : super(
          id,
          fabricante,
          modelo,
          capacidadeCargaKg,
          combustiveis,
          placa,
          chassi,
          renavam,
        );
}

class Motocicleta extends VeiculosTerrestres {
  double cilindradas;

  Motocicleta(
    String id,
    String fabricante,
    String modelo,
    double capacidadeCargaKg,
    List<Combustivel>? combustiveis,
    String placa,
    String chassi,
    String renavam,
    this.cilindradas,
  ) : super(
          id,
          fabricante,
          modelo,
          capacidadeCargaKg,
          combustiveis,
          placa,
          chassi,
          renavam,
        );

  @override
  void imprimir() {
    super.imprimir();
    print("Cilindradas: $cilindradas");
  }
}

class Aeronave extends MeioDeTransporte {
  double envergaduraAsas;

  Aeronave(
    String id,
    String fabricante,
    String modelo,
    double capacidadeCargaKg,
    List<Combustivel>? combustiveis,
    this.envergaduraAsas,
  ) : super(id, fabricante, modelo, capacidadeCargaKg, combustiveis);

  @override
  void imprimir() {
    super.imprimir();
    print("Envergadura das Asas: $envergaduraAsas");
  }
}

class Embarcacao extends MeioDeTransporte {
  int quantidadeContainers;

  Embarcacao(
    String id,
    String fabricante,
    String modelo,
    double capacidadeCargaKg,
    List<Combustivel>? combustiveis,
    this.quantidadeContainers,
  ) : super(id, fabricante, modelo, capacidadeCargaKg, combustiveis);

  @override
  void imprimir() {
    super.imprimir();
    print("Quantidade de Containers suportados: $quantidadeContainers");
  }
}