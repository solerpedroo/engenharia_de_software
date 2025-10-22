// --- 1. Definição da matriz codificadora ---
K = [4 3; 1 2]; // matriz 2x2
disp("Matriz K:");
disp(K);

// --- 2. Determinante de K ---
detK = round(det(K)); // determinante
disp("Determinante de K:");
disp(detK);

// --- 3. Inverso do determinante módulo 26 ---
function x = invmodulo(a, m)
    for x=1:m
        if modulo(a*x, m) == 1 then
            return
        end
    end
    error("Não existe inverso para este determinante!")
endfunction

inv_detK = invmodulo(detK, 26);
disp("Inverso do determinante mod 26:");
disp(inv_detK);

// --- 4. Matriz adjunta de K ---
adjK = [K(2,2), -K(1,2); -K(2,1), K(1,1)];
adjK = modulo(adjK, 26);
disp("Matriz adjunta (mod 26):");
disp(adjK);

// --- 5. Inversa de K módulo 26 ---
K_inv = modulo(inv_detK * adjK, 26);
disp("Matriz inversa de K (mod 26):");
disp(K_inv);

// --- 6. Mensagem codificada (transformar letras em números) ---
alfabeto = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
msg = 'NYQQJLGC';
disp("Mensagem codificada:");
disp(msg);

// Transformar letras em números A=0,...Z=25
valores = [];
for i=1:length(msg)
    letra = part(msg, i);
    valor = strindex(alfabeto, letra) - 1; // index-1
    valores = [valores, valor];
end
disp("Mensagem codificada em números:");
disp(valores);

// --- 7. Dividir em blocos (pares) ---
blocos = matrix(valores, 2, length(valores)/2)';
disp("Blocos (pares):");
disp(blocos);

// --- 8. Decodificação ---
mensagem = '';
for i=1:size(blocos,1)
    bloco = blocos(i,:)';
    decodificado = modulo(K_inv * bloco, 26);
    for j=1:2
        letra = part(alfabeto, decodificado(j)+1);
        mensagem = strcat(mensagem, letra);
    end
end
disp("Mensagem decodificada:");
disp(mensagem);
