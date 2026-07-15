##### ***Java Script***



\# Dicionário rápido (explicado passo-a-passo, com exemplos simples)



Vou explicar cada item da sua lista de forma simples — imaginar que você nunca viu isso antes. Para cada item: o que é, por que se usa e um exemplo mínimo. Vou manter tudo direto e com exemplos pequenos que você pode colar no console do navegador.



---



\*\*document.querySelector\*\*

O que é: função do DOM que encontra \*\*o primeiro\*\* elemento que combina com um seletor CSS.

Por que usar: pegar um botão, input, div etc. para ler/alterar.

Exemplo:



```js

// pega o primeiro elemento com a classe .btn

const botao = document.querySelector('.btn');

botao.textContent = 'Clique aqui';

```



---



\*\*async function\*\*

O que é: função marcada como `async` que permite usar `await` dentro dela. `async` faz a função sempre retornar uma `Promise`.

Por que usar: escrever código assíncrono (chamadas de rede, leituras) parecendo síncrono.

Exemplo:



```js

async function minhaFunc() {

&nbsp; const data = await fetch('/api/dados');

&nbsp; return data;

}

```



---



\*\*await\*\*

O que é: faz o JavaScript “esperar” a `Promise` resolver e retorna o valor resolvido. Só funciona dentro de `async`.

Exemplo:



```js

async function getJson() {

&nbsp; const res = await fetch('/api');

&nbsp; const json = await res.json();

&nbsp; console.log(json);

}

```



---



\*\*try / catch / finally\*\*

O que é: bloco para tratar erros. `try` executa; se der erro, pula para `catch(err)`; `finally` executa sempre (erro ou não).

Exemplo:



```js

try {

&nbsp; riskyOperation();

} catch (err) {

&nbsp; console.error('Deu ruim:', err);

} finally {

&nbsp; console.log('sempre roda');

}

```



---



\*\*throw new\*\*

O que é: cria (lança) um erro. Normalmente `throw new Error('mensagem')`.

Por que usar: forçar um erro quando algo errado acontece.

Exemplo:



```js

if (!user) throw new Error('Usuário não encontrado');

```



---



\*\*if(!res.ok)\*\*

O que é: usado com `fetch` — `res.ok` é `true` quando status HTTP está entre 200–299. `if(!res.ok)` significa “se não for sucesso”.

Exemplo:



```js

const res = await fetch('/api');

if (!res.ok) throw new Error('Erro HTTP: ' + res.status);

```



---



\*\*if(!res)\*\*

O que é: verifica se `res` é "falsy" (null, undefined, 0, "", false). Útil para checar ausência.

Exemplo:



```js

const res = getSomething();

if (!res) return; // para função se não existe

```



---



\*\*await res.json\*\* / \*\*res.json()\*\*

O que é: método da `Response` do `fetch` que lê o corpo e converte para objeto JS. É assíncrono — faça `await res.json()`.

Exemplo:



```js

const res = await fetch('/api');

const data = await res.json();

```



---



\*\*fetch\*\*

O que é: função nativa para fazer requisições HTTP (GET, POST, PUT...). Retorna uma `Promise` com um objeto `Response`.

Exemplo GET:



```js

const res = await fetch('/api/usuarios');

const json = await res.json();

```



Exemplo POST:



```js

await fetch('/api', {

&nbsp; method: 'POST',

&nbsp; headers: {'Content-Type': 'application/json'},

&nbsp; body: JSON.stringify({nome: 'Ana'})

});

```



---



\*\*headers: {'Content-Type':'application/json'}\*\*

O que é: cabeçalho HTTP que diz ao servidor que o corpo da requisição está em JSON. Use quando enviar JSON.



---



\*\*method: 'PUT'\*\*

O que é: indica o método HTTP (GET, POST, PUT, DELETE...). `PUT` costuma significar “atualizar/substituir” um recurso.



---



\*\*body: JSON.stringify({ nome, idTurma })\*\* / \*\*JSON.stringify\*\*

O que é: `JSON.stringify` converte um objeto JS em string JSON — necessário ao enviar no corpo (`body`) de requisições.

Exemplo:



```js

const payload = JSON.stringify({nome: 'Pedro', idTurma: 5});

```



---



\*\*await\*\* (já explicado) — lembre: só dentro de `async`.



---



\*\*.forEach\*\*

O que é: método de arrays que executa uma função para cada item. Não retorna um novo array.

Exemplo:



```js

\[1,2,3].forEach(x => console.log(x));

```



---



\*\*.map\*\*

O que é: transforma cada item do array e retorna um novo array com os resultados.

Exemplo:



```js

const dobros = \[1,2,3].map(x => x\*2); // \[2,4,6]

```



---



\*\*.filter\*\* (não na sua lista, mas útil com map/forEach)

Filtra itens e cria novo array.



---



\*\*.appendChild\*\*

O que é: método DOM para anexar um nó filho a um elemento.

Exemplo:



```js

const ul = document.querySelector('ul');

const li = document.createElement('li');

li.textContent = 'Item';

ul.appendChild(li);

```



---



\*\*new\*\*

O que é: cria (instancia) um objeto a partir de uma função construtora ou classe.

Exemplo:



```js

const d = new Date();

const map = new Map();

```



---



\*\*new Map()\*\*

O que é: objeto que guarda pares chave→valor, semelhante a um objeto, mas com diferenças (chaves de qualquer tipo, iteração, tamanho).

Exemplo:



```js

const m = new Map();

m.set('a', 1);

console.log(m.get('a')); // 1

```



---



\*\*.get\*\*

O que é: depende do contexto. Em `Map` é `map.get(chave)`. Em bibliotecas HTTP (ex: axios) pode ser `axios.get(url)`.

Exemplo Map:



```js

map.get('chave');

```



Exemplo axios:



```js

axios.get('/api/users');

```



---



\*\*URLSearchParams\*\*

O que é: objeto para trabalhar com query string (parte após `?` na URL). Facilita ler e montar parâmetros.

Exemplo:



```js

const params = new URLSearchParams(window.location.search);

console.log(params.get('id')); // pega ?id=123

// construir:

const p = new URLSearchParams({q: 'busca', page: 2}).toString(); // q=busca\&page=2

```



---



\*\*window.location.search.match\*\*

O que é: `window.location.search` pega a query string, `.match(regex)` aplica regex e retorna resultados. Usado para extrair valores sem `URLSearchParams`.

Exemplo:



```js

// ?id=5

const m = window.location.search.match(/id=(\\d+)/);

if(m) console.log(m\[1]); // '5'

```



---



\*\*document.addEventListener\*\* / \*\*DOMContentLoaded\*\*

O que é: adiciona um ouvinte de eventos. `DOMContentLoaded` é disparado quando o HTML foi carregado e o DOM está pronto (antes de imagens).

Exemplo:



```js

document.addEventListener('DOMContentLoaded', () => {

&nbsp; console.log('DOM pronto');

});

```



---



\*\*.target\*\*

O que é: propriedade do objeto evento (`event.target`) — o elemento que disparou o evento (por exemplo, o botão clicado).

Exemplo:



```js

document.addEventListener('click', (e) => {

&nbsp; console.log('clicou em', e.target);

});

```



---



\*\*instanceof\*\*

O que é: operador que verifica se um objeto é instância de uma classe/constructor.

Exemplo:



```js

const d = new Date();

console.log(d instanceof Date); // true

```



---



\*\*parse / parseJSON / parseCSV\*\*

O que é: “parse” significa transformar texto em estrutura. `parseJSON` geralmente é `JSON.parse(text)` — transforma string JSON em objeto. `parseCSV` não é nativo (é função que alguém escreve) para transformar CSV em array/objeto.

Exemplo JSON:



```js

const obj = JSON.parse('{"nome":"Ana"}');

```



Exemplo CSV (conceito):



```js

function parseCSV(text) {

&nbsp; return text.trim().split('\\n').map(line => line.split(','));

}

```



---



\*\*parseJSON\*\*

Já dito: normalmente `JSON.parse()`.



---



\*\*.normalize\*\*

O que é: `String.prototype.normalize()` — normaliza acentuação/Unicode (útil para comparar textos acentuados).

Exemplo:



```js

'á'.normalize() === 'a\\u0301'.normalize(); // true

```



---



\*\*.trim()\*\*

O que é: remove espaços do início e fim de uma string.

Exemplo:



```js

'  oi  '.trim(); // 'oi'

```



---



\*\*.replace\*\*

O que é: substitui parte de uma string por outra. Pode usar string ou regex.

Exemplo:



```js

'banana'.replace('a', 'o'); // 'bonana' (só o 1º)

'banana'.replace(/a/g, 'o'); // 'bonono'

```



---



\*\*.map\*\* (já explicado acima)



---



\*\*.onload / .onerror / .readAsText\*\*

O que é: APIs do `FileReader` (quando você lê arquivos do usuário). `readAsText(file)` lê o arquivo e dispara `onload` quando termina, `onerror` se falhar.

Exemplo:



```js

const reader = new FileReader();

reader.onload = e => console.log('conteúdo', e.target.result);

reader.onerror = e => console.error('erro');

reader.readAsText(fileInput.files\[0]);

```



---



\*\*BroadcastChannel / .postMessage / .close\*\*

O que é: API para comunicar abas/janelas do mesmo site. Você cria `new BroadcastChannel('canal')`, usa `.postMessage` para mandar e ouve `channel.onmessage`. `.close()` fecha o canal.

Exemplo:



```js

const bc = new BroadcastChannel('chat');

bc.postMessage({txt: 'oi'});

bc.onmessage = e => console.log('recebi', e.data);

bc.close();

```



---



\*\*DOM\*\*

O que é: Document Object Model — estrutura em árvore que representa a página (elementos, atributos). Você mexe no DOM para mudar a página com JS.



---



\*\*window\*\*

O que é: objeto global no navegador que representa a janela. `window.alert`, `window.location`, `window.setTimeout`. No global você pode usar só `location` por convenção, mas `window` é explícito.



---



\*\*Promise\*\*

O que é: objeto que representa uma operação assíncrona que vai resolver com um valor ou rejeitar com um erro. Tem `.then()` e `.catch()`. `async/await` é "doce" por cima de Promises.

Exemplo:



```js

const p = new Promise((resolve, reject) => {

&nbsp; setTimeout(() => resolve(42), 1000);

});

p.then(value => console.log(value)); // 42 depois de 1s

```



---



\*\*showToast\*\*

O que é: não é nativo do JS — normalmente uma função da UI (biblioteca ou implementada por você) que mostra uma mensagem curta tipo “toast” (notificação). Se ver isso, procure onde foi definido/importado.

Exemplo conceitual:



```js

showToast('Salvo com sucesso!');

```



---



\*\*setLoading(false);\*\*

O que é: padrão em apps para controlar estado de carregamento. Em React seria `setLoading(false)` para atualizar estado. Não é nativo — é função criada pelo código.

Exemplo (React):



```js

const \[loading, setLoading] = useState(true);

setLoading(false);

```



---



\*\*<tr> / <td>\*\*

O que é: tags HTML usadas em `<table>` — `<tr>` é uma linha (table row) e `<td>` é uma célula (table data).

Exemplo:



```html

<table>

&nbsp; <tr><td>Nome</td><td>Idade</td></tr>

&nbsp; <tr><td>Ana</td><td>30</td></tr>

</table>

```



---



\*\*.JSON.stringify\*\* (já explicado em `JSON.stringify`) — transforma objeto em string JSON.



---



\*\*.target\*\* (já explicado como `event.target`) — elemento que disparou evento.



---



\*\*onload / onerror\*\* (já explicado com FileReader; também usados em imagens ou janelas):

Exemplo imagem:



```js

const img = new Image();

img.onload = () => console.log('pronto');

img.onerror = () => console.log('erro ao carregar');

img.src = 'foto.jpg';

```



---

# Operador Ternário em JavaScript

O código abaixo:

```js
(r.P3 === null || r.P3 === undefined) ? null : Number(r.P3)
```

usa o **operador ternário**, que é uma forma curta de escrever um `if/else`.

---

## 🧠 Estrutura do operador ternário

```js
condição ? valorSeVerdadeiro : valorSeFalso
```

* **`?`** → indica o valor retornado quando a condição é verdadeira
* **`:`** → indica o valor retornado quando a condição é falsa

---

## 🔍 Explicando o seu exemplo

### Condição:

```js
r.P3 === null || r.P3 === undefined
```

Verifica se `r.P3` é **null** ou **undefined**.

### Se for verdadeiro:

Retorna:

```js
null
```

### Se for falso:

Retorna:

```js
Number(r.P3)
```

---

## 🟦 Código equivalente usando if/else

```js
let resultado;

if (r.P3 === null || r.P3 === undefined) {
  resultado = null;
} else {
  resultado = Number(r.P3);
}
```


---

# Explicações Detalhadas de Conceitos do JavaScript

## 📌 1. Template Strings (`...${x}...`)

As *template strings* (ou *template literals*) são uma forma moderna e mais legível de criar strings no JavaScript.
Elas utilizam crases (**` `**) em vez de aspas.

### ✔ O que permitem:

* Inserir variáveis dentro da string usando `${ }`
* Quebrar linhas sem necessidade de `\n`
* Montar textos longos de maneira mais organizada

### ✔ Exemplo:

```js
const nome = "Pedro";
const idade = 22;

const mensagem = `Meu nome é ${nome} e eu tenho ${idade} anos.`;
```

### ✔ Sem template string (modo antigo):

```js
const mensagem = "Meu nome é " + nome + " e eu tenho " + idade + " anos.";
```

### ✔ Por que usar?

* Muito mais legível
* Evita concatenações confusas
* Útil para montar textos dinâmicos e URLs

---

## 📌 2. Optional Chaining (`?.`)

O **optional chaining** evita que o JavaScript gere erro quando você tenta acessar uma propriedade **de algo que pode ser `null` ou `undefined`**.

Sem ele, acessar algo inexistente dá erro:
❌ *"Cannot read property 'x' of undefined"*

### ✔ Como funciona:

```js
obj?.prop
obj?.metodo?.()
```

Se `obj` for `null` ou `undefined`, o resultado será **undefined**, e não erro.

### ✔ Exemplo:

```js
const usuario = {
  nome: "Pedro",
  endereco: {
    cidade: "Campinas"
  }
};

const cidade = usuario.endereco?.cidade;
```

Se `usuario.endereco` não existir, o código **não quebra**.

### ✔ Sem optional chaining (modo antigo):

```js
const cidade = usuario.endereco && usuario.endereco.cidade;
```

---

## 📌 3. Arrow Functions (`() => {}`)

As **arrow functions** são uma forma mais curta, moderna e expressiva de escrever funções.

### ✔ Exemplo básico:

```js
const soma = (a, b) => {
  return a + b;
};
```

### ✔ Forma mais curta ainda (retorno implícito):

```js
const soma = (a, b) => a + b;
```

### ✔ Onde são usadas?

Você verá muito esse formato em:

* callbacks
* funções passadas para `.map`, `.filter`, `.reduce`
* funções pequenas e rápidas
* APIs assíncronas como *fetch*, promessas e rotas

### ✔ Exemplo em callback:

```js
lista.map(item => item.nome);
```

### ✔ Diferenças importantes:

* `this` NÃO cria um novo contexto → herda do escopo externo
* código mais enxuto
* ideal para funções pequenas e funcionais


---


\*\*.readAsText\*\* (já explicado: FileReader)



---



\*\*replace / normalize / trim\*\* (já explicados)



---



\*\*parseCSV / parseJSON\*\* (já explicados: funções de parsing)



---



\*\*.map / .forEach\*\* (já explicados: diferença — `map` retorna novo array, `forEach` só itera)



---



\*\*instanceof\*\* (já explicado)



---



\*\*.postMessage\*\* (já explicado com BroadcastChannel; também existe `window.postMessage` para comunicação entre janelas com origem segura)



---



\*\*.close\*\* (fechar recursos — `BroadcastChannel.close()`, `WebSocket.close()`, etc.)



---



\*\*DOMContentLoaded\*\* (já explicado: evento que diz quando o DOM está pronto)



---



\### Dicas práticas rápidas (resumão)



\* `fetch` → sempre tratar erro: `const res = await fetch(...); if(!res.ok) throw ...; const data = await res.json();`

\* `async/await` é só "Promise com sintaxe mais limpa".

\* `.map` cria novo array; `.forEach` só faz algo por item.

\* `document.querySelector` pega um elemento; `appendChild` insere.

\* `JSON.stringify` ↔ `JSON.parse` são dupla direta: stringify = objeto → string; parse = string → objeto.

\* `new` cria instâncias (`new Date()`, `new Map()`), `instanceof` verifica.

\* `FileReader` usa `readAsText`, `onload`, `onerror` para ler arquivos locais.

\* `BroadcastChannel` comunica abas.

\* `URLSearchParams` é a forma moderna e segura de ler parâmetros de URL.

