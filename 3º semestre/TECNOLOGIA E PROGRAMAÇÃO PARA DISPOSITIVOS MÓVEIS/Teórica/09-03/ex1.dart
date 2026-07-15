// Passo 1: do todo para o detalhe 
/* Quando precisamos analisar o código de algum projeto, começamos a ler este código do todo para o detalhe: ENTENDER O QUE CADA PEDAÇO FAZ, NÃO COMO ELE FAZ. */

// Passo 2: panorama de responsabilidades
/* Devemos saber o que cada classe faz, mesmo sem entender, a princípio, a lógica. */

// Passo 3: executar o programa
/* Observar um programa pela execução dele e em conjunto ler o código do ponto de entrada pode facilitar o entendimento do conjunto todo (não das partes). */

// Passo 4: ler, não supor
/* Quando lemos um código, não é um exercício de imaginação louca, é pura leitura. */

// Passo 5: ordem de análise
/* Classes menores e menos complexas primeiro. Geralmente, classes menores são as mais simples. */

// atributo privado precisa ser manipulado através de um método (get / set...), tudo que tem abre e fecha parenteses é um metodo, ao contrário é um atributo, _nomedometodo, é um método privado, chamada encadeada de método: chamar vários métodos juntos em uma única chamada ao invés de chamar diversas vezes, ex: return s.replaceAll('×', 'x').replaceAll('X', 'x').trim();