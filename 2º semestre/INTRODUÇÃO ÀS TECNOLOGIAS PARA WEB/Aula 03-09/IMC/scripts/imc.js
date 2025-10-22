/*function calcularIMC(peso, altura){
    const imc = peso / (altura * altura);
    return imc;
}

function main(){
    // Passo 1 - obter os dados peso e altura (digitados pelo usuário)
    const p = document.getElementById("txtPeso").value;
    const a = document.getElementById("txtAltura").value;

    //console.log(a);
    //console.log(p);

    // Fazer em casa - Passo 2 - verificar validar os dados

    // Passo 3 - fazer o cálculo (chamando a função calcularIMC)
    const imcResultante = calcularIMC(p, a);

    // Passo 4 - imprimir o resultado
    console.log(imcResultante);
    // tarefa: além de imprimir o valor no console como está acima, mostrar na tela o valor para o usuário
}*/

// Função que calcula o IMC
function calcularIMC(peso, altura){
    return peso / (altura * altura);
}

// Função principal
function main(){
    // Passo 1 - obter os dados peso e altura (digitados pelo usuário)
    const p = parseFloat(document.getElementById("txtPeso").value);
    const a = parseFloat(document.getElementById("txtAltura").value);

    // Passo 2 - validar os dados
    if (isNaN(p) || isNaN(a) || p <= 0 || a <= 0) {
        alert("Por favor, insira valores válidos de peso e altura.");
        return;
    }

    // Passo 3 - calcular IMC
    const imcResultante = calcularIMC(p, a);

    // Passo 4 - mostrar o resultado no console e na tela
    console.log(imcResultante);
    const resultadoElemento = document.getElementById("resultadoIMC");
    resultadoElemento.textContent = "Seu IMC é: " + imcResultante.toFixed(2);
}