//ela obriga a classe que herda ela a receber esses comportamentos complementares
abstract class Animal {
  void show() {
    print('Tocar música... tambores...');
  }

  void hide() {
    print('Fumacinha... puufff... sumiu....');
  }
}

class Dog extends Animal {
  @override
  void show() {
    super.show();
    print('Cachorro se desloca até o centro da tela');
  }

  void bark() {
    print('Au Au...');
  }
}

class Cat extends Animal {
  @override
  void show() {
    super.show();
    print('Gato vem pulando pelas árvores até o chão');
  }

  void meow() {
    print('Meeeeoooowwww...');
  }
}

void main() {
  print('Jogo iniciado');
  Cat c1 = Cat();
  c1.show();
  c1.meow();
  c1.hide();
  print('Quiz de palavras');

  Dog d1 = Dog();
  d1.show();
  d1.bark();
  d1.hide();
  print('Quiz de palavras');
}
