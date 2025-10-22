// Matriz de transição P
P = [1/2  0    1/2;
     1/2  0    1/2;
     1/2 1/2   0];

// Vetor de estado inicial (segunda-feira em R1)
v = [1 0 0];

// Transições
v1 = v * P;     // Terça
v2 = v1 * P;    // Quarta
v3 = v2 * P;    // Quinta

// Probabilidade de estar em R1 na quinta-feira
prob = v3(1);

// Mostrar resultado
disp("Probabilidade de estar em R1 na quinta-feira:");
disp(prob);

// Como a resposta deve estar em forma de numerador / 32:
numerador = prob * 32;
disp("Resposta final:");
disp(numerador + "/32");
