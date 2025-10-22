const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');

// porta do servidor backend
const port = 3000;

// define a aplicação express
const app = express();

// definir o dialeto de requisição/resposta
app.use(bodyParser.json());

// definir que o servidor vai aceitar requisições sendo do mesmo IP ou não, estando na mesma rede ou não, ou seja = de qualquer origem
app.use(cors());

// duas rotas, a default (/) e a rota de serviço chamada calcular imc

app.get('/', (req,res)=>{
    res.send("Tudo funcionando...");
});

app.post('/calcularIMC', (req,res)=>{
    // receber o pese e altura
    // calcular imc
    // devolver uma resposta
    const peso = req.body.peso;
    const altura = req.body.altura;

    if(peso !== undefined && altura !== undefined){
        if(typeof peso === 'number' && typeof altura === 'number'){
            console.log(`Peso: ${peso}`);
            console.log(`Altura: ${altura}`);

            const imc = (peso / Math.pow(altura,2));
            console.log(`IMC calculado: ${imc}`);
            res.send(imc);
        }else{
            res.send('Peso e altura precisam ser números');
        }
    }else{
        res.send('Faltando altura ou peso');
    }
});

app.listen(port);