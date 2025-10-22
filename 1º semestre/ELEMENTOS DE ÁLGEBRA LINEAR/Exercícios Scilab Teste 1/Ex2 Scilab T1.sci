// Matriz A - componentes por produto (3x3)
A = [30 20 15;
     20 25 15;
     30 10 20];

// Matriz B - produção por modelo (3x2)
// Coluna 1: Simples (4 bicicletas, 1 triciclo, 3 patinetes)
// Coluna 2: Luxo    (5 bicicletas, 2 triciclos, 2 patinetes)
B = [4 5;
     1 2;
     3 2];

// Multiplicação: C = A * B
C = A * B;

// Soma dos elementos da 2ª coluna de C
soma = C(1,2) + C(2,2) + C(3,2);

// Mostrar resultado
disp("Matriz C:");
disp(C);
disp("Soma dos elementos da 2a coluna de C:");
disp(soma);
