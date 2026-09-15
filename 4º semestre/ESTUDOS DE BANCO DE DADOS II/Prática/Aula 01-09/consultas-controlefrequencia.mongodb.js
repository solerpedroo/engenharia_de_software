/* global use, db */
// =============================================================================
// CONSULTAS — Banco: controlefrequencia | MongoDB Atlas
// =============================================================================
// Como usar no VS Code / Cursor (extensão MongoDB):
//   1. Conecte-se ao cluster Atlas
//   2. Selecione o bloco da consulta desejada
//   3. Clique em ▶ Play (ou Ctrl+Enter na seleção)
//
// Coleções: professores | estudantes | disciplinas | chamadas | relatorio_frequencia
//
// Seções:
//   1-4  Consultas por coleção (CRUD + agregações)
//   5    Consultas cruzadas ($lookup)
//   6    Cenários de negócio
//   7    Consultas complexas e avançadas  ← $facet, $setWindowFields, $merge, etc.
//   8    Transações
//   9    Utilitários
// =============================================================================

use('controlefrequencia');


// =============================================================================
// 0. ÍNDICES RECOMENDADOS (execute uma vez no Atlas)
// =============================================================================

db.professores.createIndex({ RP: 1 }, { unique: true });
db.professores.createIndex({ nome: 1 });

db.estudantes.createIndex({ RA: 1 }, { unique: true });
db.estudantes.createIndex({ nome: 1 });
db.estudantes.createIndex({ curso: 1, periodo: 1 });
db.estudantes.createIndex({ 'matriculas.disciplinaCodigo': 1 });
db.estudantes.createIndex({ 'matriculas.turmaCodigo': 1 });
db.estudantes.createIndex({ 'matriculas.situacao': 1 });
db.estudantes.createIndex({
  'matriculas.disciplinaCodigo': 1,
  'matriculas.turmaCodigo': 1,
  'matriculas.anoCalendario': 1,
  'matriculas.semestreCalendario': 1
});

db.disciplinas.createIndex({ codigo: 1 }, { unique: true });
db.disciplinas.createIndex({ curso: 1, periodo: 1 });
db.disciplinas.createIndex({ anoCalendario: 1, semestreCalendario: 1 });
db.disciplinas.createIndex({ 'turmas.codigo': 1 });
db.disciplinas.createIndex({ 'turmas.docente.RP': 1 });

db.chamadas.createIndex({ _id: 1 });
db.chamadas.createIndex({ data: 1 });
db.chamadas.createIndex({ 'disciplina.codigo': 1, data: 1 });
db.chamadas.createIndex({ 'turma.codigo': 1 });
db.chamadas.createIndex({ 'docente.RP': 1 });
db.chamadas.createIndex({ 'alunos.RA': 1 });
db.chamadas.createIndex({
  'disciplina.codigo': 1,
  'turma.codigo': 1,
  data: 1
});


// =============================================================================
// 1. PROFESSORES
// =============================================================================

// --- 1.1 Leitura básica ---

// Listar todos os professores
db.professores.find();

// Buscar professor por RP (chave natural)
db.professores.findOne({ RP: '4567890' });

// Buscar por nome exato
db.professores.findOne({ nome: 'Steve Jobs' });

// Buscar por parte do nome (case-insensitive)
db.professores.find({ nome: { $regex: 'ada', $options: 'i' } });

// Buscar professores cujo nome começa com determinada letra
db.professores.find({ nome: { $regex: '^A', $options: 'i' } });

// Projeção: retornar apenas RP e nome
db.professores.find({}, { _id: 0, RP: 1, nome: 1 });

// Ordenar professores por nome (A-Z)
db.professores.find().sort({ nome: 1 });

// Paginação: 2º lote de 5 professores
db.professores.find().sort({ nome: 1 }).skip(5).limit(5);

// Contar total de professores
db.professores.countDocuments();

// Listar RPs distintos
db.professores.distinct('RP');

// Verificar existência de professor
db.professores.exists({ RP: '100001' });


// --- 1.2 Inserção ---

// Inserir um novo professor
db.professores.insertOne({
  RP: '100099',
  nome: 'Guido van Rossum'
});

// Inserir vários professores
db.professores.insertMany([
  { RP: '100097', nome: 'Brendan Eich' },
  { RP: '100098', nome: 'Anders Hejlsberg' }
]);


// --- 1.3 Atualização ---

// Atualizar nome de um professor
db.professores.updateOne(
  { RP: '100099' },
  { $set: { nome: 'Guido van Rossum (Python)' } }
);

// Renomear campo (raro, mas possível)
db.professores.updateOne(
  { RP: '100097' },
  { $rename: { nome: 'nomeCompleto' } }
);

// Reverter rename do exemplo acima
db.professores.updateOne(
  { RP: '100097' },
  { $rename: { nomeCompleto: 'nome' } }
);


// --- 1.4 Remoção ---

// Remover professor por RP
db.professores.deleteOne({ RP: '100099' });

// Remover professores inseridos em lote (exemplo)
db.professores.deleteMany({ RP: { $in: ['100097', '100098'] } });


// --- 1.5 Agregações — professores ---

// Professores ordenados alfabeticamente com contagem total
db.professores.aggregate([
  { $sort: { nome: 1 } },
  {
    $group: {
      _id: null,
      total: { $sum: 1 },
      professores: { $push: { RP: '$RP', nome: '$nome' } }
    }
  }
]);

// Quantidade de turmas por professor (via $lookup em disciplinas)
db.professores.aggregate([
  {
    $lookup: {
      from: 'disciplinas',
      let: { rpProfessor: '$RP' },
      pipeline: [
        { $unwind: '$turmas' },
        { $match: { $expr: { $eq: ['$turmas.docente.RP', '$$rpProfessor'] } } },
        {
          $project: {
            _id: 0,
            disciplinaCodigo: '$codigo',
            disciplinaNome: '$nome',
            turmaCodigo: '$turmas.codigo'
          }
        }
      ],
      as: 'turmasMinistradas'
    }
  },
  {
    $project: {
      _id: 0,
      RP: 1,
      nome: 1,
      qtdeTurmas: { $size: '$turmasMinistradas' },
      turmasMinistradas: 1
    }
  },
  { $sort: { qtdeTurmas: -1, nome: 1 } }
]);


// =============================================================================
// 2. ESTUDANTES
// =============================================================================

// --- 2.1 Leitura básica ---

// Listar todos os estudantes
db.estudantes.find();

// Buscar estudante por RA
db.estudantes.findOne({ RA: '1234' });

// Buscar por nome (regex parcial)
db.estudantes.find({ nome: { $regex: 'Silva|Souza|Lima', $options: 'i' } });

// Estudantes do curso de Engenharia de Software
db.estudantes.find({ curso: 'Engenharia de Software' });

// Estudantes do 4º período
db.estudantes.find({ periodo: 4 });

// Estudantes do curso e período específicos
db.estudantes.find({ curso: 'Engenharia de Software', periodo: 4 });

// Projeção: RA e nome apenas
db.estudantes.find({}, { _id: 0, RA: 1, nome: 1 });

// Ordenar por RA
db.estudantes.find().sort({ RA: 1 });

// Contar estudantes
db.estudantes.countDocuments({ curso: 'Engenharia de Software' });


// --- 2.2 Consultas em arrays (matriculas) ---

// Estudantes matriculados em uma disciplina específica
db.estudantes.find({
  matriculas: {
    $elemMatch: {
      disciplinaCodigo: '12490-P',
      situacao: 'matriculado'
    }
  }
});

// Estudantes na turma 0101 da disciplina 12490-P
db.estudantes.find({
  matriculas: {
    $elemMatch: {
      disciplinaCodigo: '12490-P',
      turmaCodigo: '0101'
    }
  }
});

// Estudantes matriculados no semestre 2/2026
db.estudantes.find({
  matriculas: {
    $elemMatch: {
      anoCalendario: 2026,
      semestreCalendario: 2,
      situacao: 'matriculado'
    }
  }
});

// Estudantes com matrícula em Bancos de Dados (prática OU teoria)
db.estudantes.find({
  'matriculas.disciplinaCodigo': { $in: ['12490-P', '12490-T'] }
});

// Estudantes matriculados em Métodos Ágeis
db.estudantes.find({
  'matriculas.disciplinaCodigo': '12930-T'
});

// Estudantes com exatamente 3 matrículas
db.estudantes.find({ matriculas: { $size: 3 } });

// Estudantes com mais de 2 matrículas
db.estudantes.find({ matriculas: { $not: { $size: 2 } } });

// Estudantes matriculados em 12490-P E 12501-P (mesmo documento)
db.estudantes.find({
  $and: [
    { 'matriculas.disciplinaCodigo': '12490-P' },
    { 'matriculas.disciplinaCodigo': '12501-P' }
  ]
});

// Retornar apenas as matrículas de um semestre (projeção com $filter)
db.estudantes.aggregate([
  { $match: { RA: '1234' } },
  {
    $project: {
      _id: 0,
      RA: 1,
      nome: 1,
      matriculas2026_2: {
        $filter: {
          input: '$matriculas',
          as: 'm',
          cond: {
            $and: [
              { $eq: ['$$m.anoCalendario', 2026] },
              { $eq: ['$$m.semestreCalendario', 2] }
            ]
          }
        }
      }
    }
  }
]);


// --- 2.3 Inserção ---

// Inserir novo estudante com matrículas
db.estudantes.insertOne({
  RA: '9999',
  nome: 'Novo Aluno Teste',
  curso: 'Engenharia de Software',
  periodo: 4,
  matriculas: [
    {
      disciplinaCodigo: '12490-P',
      disciplinaNome: 'Estudos de Bancos de Dados 2 - Prática',
      turmaCodigo: '0101',
      anoCalendario: 2026,
      semestreCalendario: 2,
      situacao: 'matriculado'
    }
  ]
});


// --- 2.4 Atualização ---

// Adicionar nova matrícula a um estudante existente
db.estudantes.updateOne(
  { RA: '9999' },
  {
    $push: {
      matriculas: {
        disciplinaCodigo: '12930-T',
        disciplinaNome: 'Métodos Ágeis - Teoria',
        turmaCodigo: '0101',
        anoCalendario: 2026,
        semestreCalendario: 2,
        situacao: 'matriculado'
      }
    }
  }
);

// Alterar situação de uma matrícula específica (operador posicional $)
db.estudantes.updateOne(
  { RA: '9999', 'matriculas.disciplinaCodigo': '12490-P' },
  { $set: { 'matriculas.$.situacao': 'trancado' } }
);

// Alterar situação com arrayFilters (mais preciso quando há múltiplas condições)
db.estudantes.updateOne(
  { RA: '9999' },
  { $set: { 'matriculas.$[m].situacao': 'matriculado' } },
  {
    arrayFilters: [
      {
        'm.disciplinaCodigo': '12490-P',
        'm.turmaCodigo': '0101',
        'm.anoCalendario': 2026
      }
    ]
  }
);

// Remover uma matrícula específica
db.estudantes.updateOne(
  { RA: '9999' },
  {
    $pull: {
      matriculas: { disciplinaCodigo: '12930-T' }
    }
  }
);

// Atualizar período do estudante
db.estudantes.updateOne(
  { RA: '9999' },
  { $set: { periodo: 5 } }
);


// --- 2.5 Remoção ---

// Remover estudante de teste
db.estudantes.deleteOne({ RA: '9999' });


// --- 2.6 Agregações — estudantes ---

// Quantidade de matrículas por estudante
db.estudantes.aggregate([
  {
    $project: {
      _id: 0,
      RA: 1,
      nome: 1,
      qtdeMatriculas: { $size: '$matriculas' }
    }
  },
  { $sort: { qtdeMatriculas: -1, nome: 1 } }
]);

// Disciplinas mais procuradas (contagem de matrículas)
db.estudantes.aggregate([
  { $unwind: '$matriculas' },
  { $match: { 'matriculas.situacao': 'matriculado' } },
  {
    $group: {
      _id: {
        codigo: '$matriculas.disciplinaCodigo',
        nome: '$matriculas.disciplinaNome'
      },
      totalMatriculados: { $sum: 1 }
    }
  },
  { $sort: { totalMatriculados: -1 } }
]);

// Estudantes por turma de uma disciplina
db.estudantes.aggregate([
  { $unwind: '$matriculas' },
  {
    $match: {
      'matriculas.disciplinaCodigo': '12490-P',
      'matriculas.turmaCodigo': '0101',
      'matriculas.situacao': 'matriculado'
    }
  },
  {
    $project: {
      _id: 0,
      RA: 1,
      nome: 1,
      disciplina: '$matriculas.disciplinaNome',
      turma: '$matriculas.turmaCodigo'
    }
  },
  { $sort: { nome: 1 } }
]);


// =============================================================================
// 3. DISCIPLINAS
// =============================================================================

// --- 3.1 Leitura básica ---

// Listar todas as disciplinas
db.disciplinas.find();

// Buscar disciplina por código
db.disciplinas.findOne({ codigo: '12490-P' });

// Disciplinas do 4º período
db.disciplinas.find({ periodo: 4 });

// Disciplinas do semestre 2/2026
db.disciplinas.find({
  anoCalendario: 2026,
  semestreCalendario: 2
});

// Disciplinas de prática (código termina com -P)
db.disciplinas.find({ codigo: { $regex: '-P$' } });

// Disciplinas de teoria (código termina com -T)
db.disciplinas.find({ codigo: { $regex: '-T$' } });

// Disciplinas com carga horária >= 40
db.disciplinas.find({ cargaHorariaTotal: { $gte: 40 } });

// Projeção: código, nome e curso
db.disciplinas.find(
  { curso: 'Engenharia de Software' },
  { _id: 0, codigo: 1, nome: 1, cargaHorariaTotal: 1 }
);


// --- 3.2 Consultas em arrays aninhados (turmas) ---

// Disciplina que possui turma 0102
db.disciplinas.find({ 'turmas.codigo': '0102' });

// Turmas ministradas por um docente específico
db.disciplinas.find({ 'turmas.docente.RP': '4567890' });

// Turmas com transferências
db.disciplinas.find({
  turmas: {
    $elemMatch: { transferencias: { $gt: 0 } }
  }
});

// Turmas com desistências ou trancamentos
db.disciplinas.find({
  turmas: {
    $elemMatch: {
      $or: [
        { desistencias: { $gt: 0 } },
        { trancamentos: { $gt: 0 } }
      ]
    }
  }
});

// Disciplinas com mais de uma turma
db.disciplinas.find({ turmas: { $not: { $size: 1 } } });

// Detalhes de uma turma específica dentro da disciplina
db.disciplinas.findOne(
  { codigo: '12490-P', 'turmas.codigo': '0101' },
  { _id: 0, codigo: 1, nome: 1, 'turmas.$': 1 }
);


// --- 3.3 Agenda de aulas ---

// Disciplinas com aula em uma data específica
db.disciplinas.find({
  'turmas.agendaDeAulas.dataHoraInicio': {
    $regex: '^2026-08-01'
  }
});

// Aulas entre duas datas (agregação com $unwind)
db.disciplinas.aggregate([
  { $unwind: '$turmas' },
  { $unwind: '$turmas.agendaDeAulas' },
  {
    $match: {
      'turmas.agendaDeAulas.dataHoraInicio': {
        $gte: '2026-08-01T00:00:00',
        $lte: '2026-08-10T23:59:59'
      }
    }
  },
  {
    $project: {
      _id: 0,
      disciplinaCodigo: '$codigo',
      disciplinaNome: '$nome',
      turmaCodigo: '$turmas.codigo',
      docente: '$turmas.docente.nome',
      inicio: '$turmas.agendaDeAulas.dataHoraInicio',
      fim: '$turmas.agendaDeAulas.dataHoraFim',
      horas: '$turmas.agendaDeAulas.qtdeHorasAula'
    }
  },
  { $sort: { inicio: 1 } }
]);


// --- 3.4 Inserção ---

// Inserir nova disciplina com turma e agenda
db.disciplinas.insertOne({
  codigo: '99999-P',
  nome: 'Disciplina Teste - Prática',
  cargaHorariaTotal: 40,
  curso: 'Engenharia de Software',
  periodo: 4,
  anoCalendario: 2026,
  semestreCalendario: 2,
  turmas: [
    {
      codigo: '0101',
      qtdeInicialDeMatriculados: 0,
      qtdeAtualDeMatriculados: 0,
      trancamentos: 0,
      desistencias: 0,
      transferencias: 0,
      docente: { RP: '100001', nome: 'Alan Turing' },
      agendaDeAulas: [
        {
          dataHoraInicio: '2026-09-01T08:00:00',
          dataHoraFim: '2026-09-01T09:40:00',
          qtdeHorasAula: 2
        }
      ]
    }
  ]
});


// --- 3.5 Atualização ---

// Adicionar nova turma a uma disciplina
db.disciplinas.updateOne(
  { codigo: '99999-P' },
  {
    $push: {
      turmas: {
        codigo: '0102',
        qtdeInicialDeMatriculados: 0,
        qtdeAtualDeMatriculados: 0,
        trancamentos: 0,
        desistencias: 0,
        transferencias: 0,
        docente: { RP: '100002', nome: 'Grace Hopper' },
        agendaDeAulas: []
      }
    }
  }
);

// Adicionar aula na agenda de uma turma (arrayFilters)
db.disciplinas.updateOne(
  { codigo: '99999-P' },
  {
    $push: {
      'turmas.$[t].agendaDeAulas': {
        dataHoraInicio: '2026-09-08T08:00:00',
        dataHoraFim: '2026-09-08T09:40:00',
        qtdeHorasAula: 2
      }
    }
  },
  { arrayFilters: [{ 't.codigo': '0101' }] }
);

// Atualizar quantidade de matriculados em uma turma
db.disciplinas.updateOne(
  { codigo: '99999-P', 'turmas.codigo': '0101' },
  {
    $inc: {
      'turmas.$.qtdeAtualDeMatriculados': 1,
      'turmas.$.qtdeInicialDeMatriculados': 1
    }
  }
);

// Trocar docente de uma turma
db.disciplinas.updateOne(
  { codigo: '99999-P', 'turmas.codigo': '0102' },
  {
    $set: {
      'turmas.$.docente': { RP: '100003', nome: 'Donald Knuth' }
    }
  }
);


// --- 3.6 Remoção ---

// Remover disciplina de teste
db.disciplinas.deleteOne({ codigo: '99999-P' });


// --- 3.7 Agregações — disciplinas ---

// Total de turmas no sistema
db.disciplinas.aggregate([
  { $unwind: '$turmas' },
  { $count: 'totalTurmas' }
]);

// Carga horária total de aulas agendadas por disciplina
db.disciplinas.aggregate([
  { $unwind: '$turmas' },
  { $unwind: '$turmas.agendaDeAulas' },
  {
    $group: {
      _id: { codigo: '$codigo', nome: '$nome' },
      totalHorasAgendadas: { $sum: '$turmas.agendaDeAulas.qtdeHorasAula' },
      totalAulas: { $sum: 1 }
    }
  },
  { $sort: { totalHorasAgendadas: -1 } }
]);

// Relatório de ocupação das turmas (vagas utilizadas)
db.disciplinas.aggregate([
  { $unwind: '$turmas' },
  {
    $project: {
      _id: 0,
      disciplinaCodigo: '$codigo',
      disciplinaNome: '$nome',
      turmaCodigo: '$turmas.codigo',
      docente: '$turmas.docente.nome',
      matriculados: '$turmas.qtdeAtualDeMatriculados',
      trancamentos: '$turmas.trancamentos',
      desistencias: '$turmas.desistencias',
      transferencias: '$turmas.transferencias',
      taxaEvasao: {
        $cond: [
          { $eq: ['$turmas.qtdeInicialDeMatriculados', 0] },
          0,
          {
            $multiply: [
              {
                $divide: [
                  { $add: ['$turmas.desistencias', '$turmas.trancamentos'] },
                  '$turmas.qtdeInicialDeMatriculados'
                ]
              },
              100
            ]
          }
        ]
      }
    }
  },
  { $sort: { disciplinaCodigo: 1, turmaCodigo: 1 } }
]);


// =============================================================================
// 4. CHAMADAS (lista de presença)
// =============================================================================

// --- 4.1 Leitura básica ---

// Listar todas as chamadas
db.chamadas.find();

// Buscar chamada por _id composto
db.chamadas.findOne({ _id: 'CH-12490-P-0101-2026-08-01' });

// Chamadas de uma disciplina
db.chamadas.find({ 'disciplina.codigo': '12490-P' });

// Chamadas de uma turma específica
db.chamadas.find({
  'disciplina.codigo': '12490-P',
  'turma.codigo': '0101'
});

// Chamadas em uma data
db.chamadas.find({ data: '2026-08-01' });

// Chamadas em um intervalo de datas
db.chamadas.find({
  data: { $gte: '2026-08-01', $lte: '2026-08-10' }
});

// Chamadas ministradas por um docente
db.chamadas.find({ 'docente.RP': '4567890' });

// Chamadas do semestre 2/2026
db.chamadas.find({
  'disciplina.anoCalendario': 2026,
  'disciplina.semestreCalendario': 2
});

// Chamadas com pelo menos um ausente
db.chamadas.find({ 'resumo.ausentes': { $gt: 0 } });

// Chamadas com 100% de presença
db.chamadas.find({
  $expr: { $eq: ['$resumo.presentes', '$resumo.totalAlunos'] }
});

// Chamadas com conteúdo que menciona MongoDB ou documentos
db.chamadas.find({
  'aula.conteudo': { $regex: 'documento|MongoDB|NoSQL', $options: 'i' }
});


// --- 4.2 Consultas no array de alunos ---

// Chamadas em que um aluno específico esteve presente
db.chamadas.find({
  alunos: {
    $elemMatch: { RA: '1234', presente: true }
  }
});

// Chamadas em que um aluno faltou
db.chamadas.find({
  alunos: {
    $elemMatch: { RA: '1236', presente: false }
  }
});

// Chamadas com alunos sem justificativa de falta
db.chamadas.find({
  alunos: {
    $elemMatch: {
      presente: false,
      justificativa: 'Sem justificativa informada'
    }
  }
});

// Chamadas com faltas justificadas
db.chamadas.find({
  alunos: {
    $elemMatch: {
      presente: false,
      justificativa: { $exists: true, $ne: 'Sem justificativa informada' }
    }
  }
});


// --- 4.3 Inserção ---

// Criar nova chamada (snapshot completo)
db.chamadas.insertOne({
  _id: 'CH-TESTE-0101-2026-09-01',
  data: '2026-09-01',
  disciplina: {
    codigo: '12490-P',
    nome: 'Estudos de Bancos de Dados 2 - Prática',
    curso: 'Engenharia de Software',
    periodo: 4,
    anoCalendario: 2026,
    semestreCalendario: 2
  },
  turma: {
    codigo: '0101',
    qtdeAtualDeMatriculados: 29
  },
  docente: {
    RP: '4567890',
    nome: 'Steve Jobs'
  },
  aula: {
    dataHoraInicio: '2026-09-01T08:00:00',
    dataHoraFim: '2026-09-01T09:40:00',
    qtdeHorasAula: 2,
    conteudo: 'Aula de teste para validação de consultas.'
  },
  resumo: {
    totalAlunos: 2,
    presentes: 1,
    ausentes: 1
  },
  alunos: [
    { RA: '1234', nome: 'Ayrton Senna', presente: true },
    {
      RA: '1235',
      nome: 'Ana Clara Souza',
      presente: false,
      justificativa: 'Teste de falta'
    }
  ]
});


// --- 4.4 Atualização ---

// Marcar aluno como presente em uma chamada
db.chamadas.updateOne(
  { _id: 'CH-TESTE-0101-2026-09-01', 'alunos.RA': '1235' },
  {
    $set: {
      'alunos.$.presente': true,
      'alunos.$.justificativa': null
    },
    $inc: { 'resumo.presentes': 1, 'resumo.ausentes': -1 }
  }
);

// Adicionar justificativa a uma falta
db.chamadas.updateOne(
  { _id: 'CH-12490-P-0101-2026-08-01', 'alunos.RA': '1236' },
  {
    $set: {
      'alunos.$.justificativa': 'Atestado médico apresentado'
    }
  }
);

// Atualizar conteúdo da aula
db.chamadas.updateOne(
  { _id: 'CH-TESTE-0101-2026-09-01' },
  { $set: { 'aula.conteudo': 'Conteúdo atualizado da aula de teste.' } }
);

// Incluir novo aluno na chamada (após matrícula tardia)
db.chamadas.updateOne(
  { _id: 'CH-TESTE-0101-2026-09-01' },
  {
    $push: {
      alunos: { RA: '1236', nome: 'Bruno Henrique Lima', presente: true }
    },
    $inc: { 'resumo.totalAlunos': 1, 'resumo.presentes': 1 }
  }
);


// --- 4.5 Remoção ---

// Remover chamada de teste
db.chamadas.deleteOne({ _id: 'CH-TESTE-0101-2026-09-01' });


// --- 4.6 Agregações — chamadas ---

// Taxa de presença por disciplina
db.chamadas.aggregate([
  {
    $group: {
      _id: '$disciplina.codigo',
      disciplinaNome: { $first: '$disciplina.nome' },
      totalChamadas: { $sum: 1 },
      totalPresentes: { $sum: '$resumo.presentes' },
      totalAusentes: { $sum: '$resumo.ausentes' },
      totalRegistros: { $sum: '$resumo.totalAlunos' }
    }
  },
  {
    $project: {
      _id: 0,
      disciplinaCodigo: '$_id',
      disciplinaNome: 1,
      totalChamadas: 1,
      taxaPresenca: {
        $cond: [
          { $eq: ['$totalRegistros', 0] },
          0,
          {
            $round: [
              { $multiply: [{ $divide: ['$totalPresentes', '$totalRegistros'] }, 100] },
              2
            ]
          }
        ]
      }
    }
  },
  { $sort: { taxaPresenca: -1 } }
]);

// Frequência individual por aluno (consolidado)
db.chamadas.aggregate([
  { $unwind: '$alunos' },
  {
    $group: {
      _id: '$alunos.RA',
      nome: { $first: '$alunos.nome' },
      totalChamadas: { $sum: 1 },
      presencas: {
        $sum: { $cond: [{ $eq: ['$alunos.presente', true] }, 1, 0] }
      },
      faltas: {
        $sum: { $cond: [{ $eq: ['$alunos.presente', false] }, 1, 0] }
      }
    }
  },
  {
    $project: {
      _id: 0,
      RA: '$_id',
      nome: 1,
      totalChamadas: 1,
      presencas: 1,
      faltas: 1,
      percentualPresenca: {
        $round: [
          { $multiply: [{ $divide: ['$presencas', '$totalChamadas'] }, 100] },
          2
        ]
      }
    }
  },
  { $sort: { percentualPresenca: 1, nome: 1 } }
]);

// Faltas por aluno em uma disciplina específica
db.chamadas.aggregate([
  { $match: { 'disciplina.codigo': '12490-P' } },
  { $unwind: '$alunos' },
  { $match: { 'alunos.presente': false } },
  {
    $project: {
      _id: 0,
      data: 1,
      turma: '$turma.codigo',
      RA: '$alunos.RA',
      nome: '$alunos.nome',
      justificativa: '$alunos.justificativa'
    }
  },
  { $sort: { data: 1, nome: 1 } }
]);

// Ranking de docentes por aulas ministradas (chamadas registradas)
db.chamadas.aggregate([
  {
    $group: {
      _id: '$docente.RP',
      nome: { $first: '$docente.nome' },
      totalAulas: { $sum: 1 },
      totalHoras: { $sum: '$aula.qtdeHorasAula' }
    }
  },
  { $sort: { totalAulas: -1 } },
  {
    $project: {
      _id: 0,
      RP: '$_id',
      nome: 1,
      totalAulas: 1,
      totalHoras: 1
    }
  }
]);

// Chamadas ordenadas cronologicamente com indicador de presença
db.chamadas.aggregate([
  { $sort: { data: 1, 'aula.dataHoraInicio': 1 } },
  {
    $project: {
      _id: 1,
      data: 1,
      disciplina: '$disciplina.codigo',
      turma: '$turma.codigo',
      docente: '$docente.nome',
      presentes: '$resumo.presentes',
      ausentes: '$resumo.ausentes',
      percentual: {
        $round: [
          {
            $multiply: [
              { $divide: ['$resumo.presentes', '$resumo.totalAlunos'] },
              100
            ]
          },
          1
        ]
      }
    }
  }
]);


// =============================================================================
// 5. CONSULTAS CRUZADAS ($lookup) — relacionamentos entre coleções
// =============================================================================

// Estudantes matriculados em disciplinas de um professor
db.professores.aggregate([
  { $match: { RP: '4567890' } },
  {
    $lookup: {
      from: 'disciplinas',
      let: { rp: '$RP' },
      pipeline: [
        { $unwind: '$turmas' },
        { $match: { $expr: { $eq: ['$turmas.docente.RP', '$$rp'] } } },
        { $project: { _id: 0, codigo: 1, nome: 1, turmaCodigo: '$turmas.codigo' } }
      ],
      as: 'disciplinasDoProfessor'
    }
  },
  { $unwind: '$disciplinasDoProfessor' },
  {
    $lookup: {
      from: 'estudantes',
      let: {
        discCodigo: '$disciplinasDoProfessor.codigo',
        turmaCodigo: '$disciplinasDoProfessor.turmaCodigo'
      },
      pipeline: [
        { $unwind: '$matriculas' },
        {
          $match: {
            $expr: {
              $and: [
                { $eq: ['$matriculas.disciplinaCodigo', '$$discCodigo'] },
                { $eq: ['$matriculas.turmaCodigo', '$$turmaCodigo'] },
                { $eq: ['$matriculas.situacao', 'matriculado'] }
              ]
            }
          }
        },
        { $project: { _id: 0, RA: 1, nome: 1 } }
      ],
      as: 'alunosMatriculados'
    }
  },
  {
    $project: {
      _id: 0,
      professor: '$nome',
      disciplina: '$disciplinasDoProfessor.nome',
      turma: '$disciplinasDoProfessor.turmaCodigo',
      alunos: '$alunosMatriculados'
    }
  }
]);

// Chamadas com dados atualizados do estudante (enriquecimento)
db.chamadas.aggregate([
  { $match: { 'disciplina.codigo': '12490-P' } },
  { $unwind: '$alunos' },
  {
    $lookup: {
      from: 'estudantes',
      localField: 'alunos.RA',
      foreignField: 'RA',
      as: 'dadosEstudante'
    }
  },
  { $unwind: { path: '$dadosEstudante', preserveNullAndEmptyArrays: true } },
  {
    $project: {
      _id: 0,
      chamadaId: '$_id',
      data: 1,
      RA: '$alunos.RA',
      nomeChamada: '$alunos.nome',
      nomeAtual: '$dadosEstudante.nome',
      presente: '$alunos.presente',
      curso: '$dadosEstudante.curso',
      periodo: '$dadosEstudante.periodo'
    }
  }
]);

// Disciplinas com contagem de chamadas já registradas por turma
db.disciplinas.aggregate([
  { $unwind: '$turmas' },
  {
    $lookup: {
      from: 'chamadas',
      let: { cod: '$codigo', turma: '$turmas.codigo' },
      pipeline: [
        {
          $match: {
            $expr: {
              $and: [
                { $eq: ['$disciplina.codigo', '$$cod'] },
                { $eq: ['$turma.codigo', '$$turma'] }
              ]
            }
          }
        },
        { $count: 'total' }
      ],
      as: 'chamadasRegistradas'
    }
  },
  {
    $project: {
      _id: 0,
      disciplinaCodigo: '$codigo',
      disciplinaNome: '$nome',
      turmaCodigo: '$turmas.codigo',
      aulasAgendadas: { $size: '$turmas.agendaDeAulas' },
      chamadasFeitas: {
        $ifNull: [{ $arrayElemAt: ['$chamadasRegistradas.total', 0] }, 0]
      }
    }
  },
  {
    $addFields: {
      aulasPendentes: { $subtract: ['$aulasAgendadas', '$chamadasFeitas'] }
    }
  },
  { $sort: { aulasPendentes: -1 } }
]);


// =============================================================================
// 6. CENÁRIOS DE NEGÓCIO — controle de frequência
// =============================================================================

// Alunos com frequência abaixo de 75% (em qualquer disciplina)
db.chamadas.aggregate([
  { $unwind: '$alunos' },
  {
    $group: {
      _id: {
        RA: '$alunos.RA',
        disciplina: '$disciplina.codigo'
      },
      nome: { $first: '$alunos.nome' },
      disciplinaNome: { $first: '$disciplina.nome' },
      total: { $sum: 1 },
      presencas: {
        $sum: { $cond: ['$alunos.presente', 1, 0] }
      }
    }
  },
  {
    $addFields: {
      percentual: { $multiply: [{ $divide: ['$presencas', '$total'] }, 100] }
    }
  },
  { $match: { percentual: { $lt: 75 } } },
  {
    $project: {
      _id: 0,
      RA: '$_id.RA',
      nome: 1,
      disciplinaCodigo: '$_id.disciplina',
      disciplinaNome: 1,
      presencas: 1,
      totalAulas: '$total',
      percentualPresenca: { $round: ['$percentual', 2] }
    }
  },
  { $sort: { percentualPresenca: 1 } }
]);

// Alunos matriculados em uma turma que NUNCA apareceram em chamada
db.estudantes.aggregate([
  {
    $match: {
      matriculas: {
        $elemMatch: {
          disciplinaCodigo: '12490-P',
          turmaCodigo: '0101',
          situacao: 'matriculado'
        }
      }
    }
  },
  {
    $lookup: {
      from: 'chamadas',
      let: { ra: '$RA' },
      pipeline: [
        {
          $match: {
            'disciplina.codigo': '12490-P',
            'turma.codigo': '0101'
          }
        },
        { $unwind: '$alunos' },
        { $match: { $expr: { $eq: ['$alunos.RA', '$$ra'] } } }
      ],
      as: 'registrosPresenca'
    }
  },
  { $match: { registrosPresenca: { $size: 0 } } },
  { $project: { _id: 0, RA: 1, nome: 1 } }
]);

// Aulas agendadas sem chamada registrada
db.disciplinas.aggregate([
  { $unwind: '$turmas' },
  { $unwind: '$turmas.agendaDeAulas' },
  {
    $addFields: {
      dataAula: {
        $substr: ['$turmas.agendaDeAulas.dataHoraInicio', 0, 10]
      },
      chamadaIdEsperado: {
        $concat: [
          'CH-',
          '$codigo',
          '-',
          '$turmas.codigo',
          '-',
          { $substr: ['$turmas.agendaDeAulas.dataHoraInicio', 0, 10] }
        ]
      }
    }
  },
  {
    $lookup: {
      from: 'chamadas',
      localField: 'chamadaIdEsperado',
      foreignField: '_id',
      as: 'chamada'
    }
  },
  { $match: { chamada: { $size: 0 } } },
  {
    $project: {
      _id: 0,
      disciplinaCodigo: '$codigo',
      disciplinaNome: '$nome',
      turmaCodigo: '$turmas.codigo',
      dataAula: 1,
      chamadaIdEsperado: 1,
      status: { $literal: 'CHAMADA_PENDENTE' }
    }
  },
  { $sort: { dataAula: 1 } }
]);

// Relatório diário de presença (todas as chamadas de um dia)
db.chamadas.aggregate([
  { $match: { data: '2026-08-01' } },
  {
    $project: {
      _id: 0,
      chamadaId: '$_id',
      disciplina: '$disciplina.nome',
      turma: '$turma.codigo',
      docente: '$docente.nome',
      horario: '$aula.dataHoraInicio',
      presentes: '$resumo.presentes',
      ausentes: '$resumo.ausentes',
      total: '$resumo.totalAlunos'
    }
  },
  { $sort: { horario: 1 } }
]);

// Alunos com mais faltas no semestre (ranking de ausências)
db.chamadas.aggregate([
  { $unwind: '$alunos' },
  { $match: { 'alunos.presente': false } },
  {
    $group: {
      _id: '$alunos.RA',
      nome: { $first: '$alunos.nome' },
      totalFaltas: { $sum: 1 },
      disciplinas: { $addToSet: '$disciplina.codigo' }
    }
  },
  { $sort: { totalFaltas: -1 } },
  {
    $project: {
      _id: 0,
      RA: '$_id',
      nome: 1,
      totalFaltas: 1,
      disciplinasComFalta: '$disciplinas'
    }
  }
]);

// Validar consistência: resumo vs contagem real no array alunos
db.chamadas.aggregate([
  {
    $project: {
      _id: 1,
      data: 1,
      disciplina: '$disciplina.codigo',
      resumoPresentes: '$resumo.presentes',
      resumoAusentes: '$resumo.ausentes',
      resumoTotal: '$resumo.totalAlunos',
      calculadoPresentes: {
        $size: {
          $filter: {
            input: '$alunos',
            as: 'a',
            cond: { $eq: ['$$a.presente', true] }
          }
        }
      },
      calculadoAusentes: {
        $size: {
          $filter: {
            input: '$alunos',
            as: 'a',
            cond: { $eq: ['$$a.presente', false] }
          }
        }
      },
      calculadoTotal: { $size: '$alunos' }
    }
  },
  {
    $match: {
      $expr: {
        $or: [
          { $ne: ['$resumoPresentes', '$calculadoPresentes'] },
          { $ne: ['$resumoAusentes', '$calculadoAusentes'] },
          { $ne: ['$resumoTotal', '$calculadoTotal'] }
        ]
      }
    }
  }
]);

// Painel geral do sistema (dashboard em uma única agregação facet)
db.chamadas.aggregate([
  {
    $facet: {
      totais: [
        {
          $group: {
            _id: null,
            totalChamadas: { $sum: 1 },
            totalPresentes: { $sum: '$resumo.presentes' },
            totalAusentes: { $sum: '$resumo.ausentes' }
          }
        }
      ],
      porDisciplina: [
        {
          $group: {
            _id: '$disciplina.codigo',
            nome: { $first: '$disciplina.nome' },
            chamadas: { $sum: 1 }
          }
        },
        { $sort: { chamadas: -1 } },
        { $limit: 5 }
      ],
      pioresTaxas: [
        {
          $project: {
            disciplina: '$disciplina.codigo',
            taxa: {
              $cond: [
                { $eq: ['$resumo.totalAlunos', 0] },
                0,
                { $divide: ['$resumo.presentes', '$resumo.totalAlunos'] }
              ]
            }
          }
        },
        {
          $group: {
            _id: '$disciplina',
            mediaTaxa: { $avg: '$taxa' }
          }
        },
        { $sort: { mediaTaxa: 1 } },
        { $limit: 3 }
      ]
    }
  }
]);


// =============================================================================
// 7. CONSULTAS COMPLEXAS E AVANÇADAS
// =============================================================================

// --- 7.1 Matriz de presença (pivot: aluno × disciplina) ---

db.chamadas.aggregate([
  { $unwind: '$alunos' },
  {
    $group: {
      _id: {
        RA: '$alunos.RA',
        disciplina: '$disciplina.codigo'
      },
      nome: { $first: '$alunos.nome' },
      disciplinaNome: { $first: '$disciplina.nome' },
      presencas: { $sum: { $cond: ['$alunos.presente', 1, 0] } },
      faltas: { $sum: { $cond: ['$alunos.presente', 0, 1] } },
      total: { $sum: 1 }
    }
  },
  {
    $group: {
      _id: '$_id.RA',
      nome: { $first: '$nome' },
      disciplinas: {
        $push: {
          codigo: '$_id.disciplina',
          nome: '$disciplinaNome',
          presencas: '$presencas',
          faltas: '$faltas',
          total: '$total',
          percentual: {
            $round: [{ $multiply: [{ $divide: ['$presencas', '$total'] }, 100] }, 2]
          }
        }
      },
      presencasGerais: { $sum: '$presencas' },
      faltasGerais: { $sum: '$faltas' },
      aulasGerais: { $sum: '$total' }
    }
  },
  {
    $addFields: {
      percentualGeral: {
        $round: [
          { $multiply: [{ $divide: ['$presencasGerais', '$aulasGerais'] }, 100] },
          2
        ]
      },
      mapaPresenca: {
        $arrayToObject: {
          $map: {
            input: '$disciplinas',
            as: 'd',
            in: {
              k: '$$d.codigo',
              v: {
                percentual: '$$d.percentual',
                presencas: '$$d.presencas',
                faltas: '$$d.faltas'
              }
            }
          }
        }
      }
    }
  },
  { $sort: { percentualGeral: 1, nome: 1 } },
  {
    $project: {
      _id: 0,
      RA: '$_id',
      nome: 1,
      percentualGeral: 1,
      resumo: {
        presencas: '$presencasGerais',
        faltas: '$faltasGerais',
        totalAulas: '$aulasGerais'
      },
      mapaPresenca: 1,
      detalhePorDisciplina: '$disciplinas'
    }
  }
]);


// --- 7.2 Ranking de alunos por turma com $setWindowFields ---

db.chamadas.aggregate([
  {
    $match: {
      'disciplina.codigo': '12490-P',
      'turma.codigo': '0101'
    }
  },
  { $unwind: '$alunos' },
  {
    $group: {
      _id: '$alunos.RA',
      nome: { $first: '$alunos.nome' },
      presencas: { $sum: { $cond: ['$alunos.presente', 1, 0] } },
      faltas: { $sum: { $cond: ['$alunos.presente', 0, 1] } },
      total: { $sum: 1 }
    }
  },
  {
    $setWindowFields: {
      sortBy: { presencas: -1, faltas: 1, nome: 1 },
      output: {
        posicaoRanking: { $rank: {} },
        presencasAcumuladasTurma: {
          $sum: '$presencas',
          window: { documents: ['unbounded', 'current'] }
        },
        mediaPresencasTurma: {
          $avg: '$presencas',
          window: { documents: ['unbounded', 'unbounded'] }
        }
      }
    }
  },
  {
    $addFields: {
      percentual: {
        $round: [{ $multiply: [{ $divide: ['$presencas', '$total'] }, 100] }, 2]
      },
      desempenhoVsMedia: {
        $round: [{ $subtract: ['$presencas', '$mediaPresencasTurma'] }, 2]
      },
      situacao: {
        $switch: {
          branches: [
            { case: { $gte: [{ $divide: ['$presencas', '$total'] }, 0.9] }, then: 'EXCELENTE' },
            { case: { $gte: [{ $divide: ['$presencas', '$total'] }, 0.75] }, then: 'REGULAR' },
            { case: { $gte: [{ $divide: ['$presencas', '$total'] }, 0.5] }, then: 'CRITICO' }
          ],
          default: 'REPROVACAO_FREQUENCIA'
        }
      }
    }
  },
  { $sort: { posicaoRanking: 1 } },
  {
    $project: {
      _id: 0,
      posicao: '$posicaoRanking',
      RA: '$_id',
      nome: 1,
      presencas: 1,
      faltas: 1,
      total: 1,
      percentual: 1,
      situacao: 1,
      desempenhoVsMedia: 1
    }
  }
]);


// --- 7.3 Tendência de presença (evolução aula a aula por aluno) ---

db.chamadas.aggregate([
  {
    $match: {
      'disciplina.codigo': '12490-P',
      'turma.codigo': '0101'
    }
  },
  { $sort: { data: 1, 'aula.dataHoraInicio': 1 } },
  { $unwind: '$alunos' },
  {
    $setWindowFields: {
      partitionBy: '$alunos.RA',
      sortBy: { data: 1 },
      output: {
        numeroAula: { $documentNumber: {} },
        presencasAcumuladas: {
          $sum: { $cond: ['$alunos.presente', 1, 0] },
          window: { documents: ['unbounded', 'current'] }
        },
        faltasAcumuladas: {
          $sum: { $cond: ['$alunos.presente', 0, 1] },
          window: { documents: ['unbounded', 'current'] }
        },
        percentualAcumulado: {
          $avg: { $cond: ['$alunos.presente', 100, 0] },
          window: { documents: ['unbounded', 'current'] }
        }
      }
    }
  },
  {
    $project: {
      _id: 0,
      RA: '$alunos.RA',
      nome: '$alunos.nome',
      data: 1,
      numeroAula: 1,
      presenteNestaAula: '$alunos.presente',
      presencasAcumuladas: 1,
      faltasAcumuladas: 1,
      percentualAcumulado: { $round: ['$percentualAcumulado', 2] }
    }
  },
  { $sort: { RA: 1, numeroAula: 1 } }
]);


// --- 7.4 Histograma de frequência com $bucket ---

db.chamadas.aggregate([
  { $unwind: '$alunos' },
  {
    $group: {
      _id: {
        RA: '$alunos.RA',
        disciplina: '$disciplina.codigo'
      },
      nome: { $first: '$alunos.nome' },
      presencas: { $sum: { $cond: ['$alunos.presente', 1, 0] } },
      total: { $sum: 1 }
    }
  },
  {
    $addFields: {
      percentual: { $multiply: [{ $divide: ['$presencas', '$total'] }, 100] }
    }
  },
  {
    $bucket: {
      groupBy: '$percentual',
      boundaries: [0, 50, 75, 90, 100.01],
      default: 'SEM_DADOS',
      output: {
        totalParesAlunoDisciplina: { $sum: 1 },
        alunos: {
          $push: {
            RA: '$_id.RA',
            nome: '$nome',
            disciplina: '$_id.disciplina',
            percentual: { $round: ['$percentual', 2] }
          }
        }
      }
    }
  },
  { $sort: { _id: 1 } }
]);


// --- 7.5 $unionWith: visão unificada de "eventos acadêmicos" ---

db.chamadas.aggregate([
  {
    $project: {
      _id: 0,
      tipo: { $literal: 'CHAMADA' },
      data: 1,
      referencia: '$_id',
      disciplinaCodigo: '$disciplina.codigo',
      disciplinaNome: '$disciplina.nome',
      turmaCodigo: '$turma.codigo',
      responsavelRP: '$docente.RP',
      responsavelNome: '$docente.nome',
      metrica: '$resumo.presentes',
      detalhe: '$aula.conteudo'
    }
  },
  {
    $unionWith: {
      coll: 'disciplinas',
      pipeline: [
        { $unwind: '$turmas' },
        { $unwind: '$turmas.agendaDeAulas' },
        {
          $project: {
            _id: 0,
            tipo: { $literal: 'AULA_AGENDADA' },
            data: {
              $substr: ['$turmas.agendaDeAulas.dataHoraInicio', 0, 10]
            },
            referencia: {
              $concat: [
                'AG-',
                '$codigo',
                '-',
                '$turmas.codigo',
                '-',
                { $substr: ['$turmas.agendaDeAulas.dataHoraInicio', 0, 10] }
              ]
            },
            disciplinaCodigo: '$codigo',
            disciplinaNome: '$nome',
            turmaCodigo: '$turmas.codigo',
            responsavelRP: '$turmas.docente.RP',
            responsavelNome: '$turmas.docente.nome',
            metrica: '$turmas.agendaDeAulas.qtdeHorasAula',
            detalhe: '$turmas.agendaDeAulas.dataHoraFim'
          }
        }
      ]
    }
  },
  { $sort: { data: 1, tipo: 1, disciplinaCodigo: 1 } }
]);


// --- 7.6 $graphLookup: carga horária em cascata por professor ---

db.professores.aggregate([
  { $match: { RP: '4567890' } },
  {
    $graphLookup: {
      from: 'disciplinas',
      startWith: '$RP',
      connectFromField: 'turmas.docente.RP',
      connectToField: 'turmas.docente.RP',
      as: 'redeDisciplinas',
      maxDepth: 2,
      restrictSearchWithMatch: {
        anoCalendario: 2026,
        semestreCalendario: 2
      }
    }
  },
  {
    $lookup: {
      from: 'chamadas',
      let: { rp: '$RP' },
      pipeline: [
        { $match: { $expr: { $eq: ['$docente.RP', '$$rp'] } } },
        {
          $group: {
            _id: null,
            totalChamadas: { $sum: 1 },
            totalHorasMinistradas: { $sum: '$aula.qtdeHorasAula' },
            disciplinasAtendidas: { $addToSet: '$disciplina.codigo' }
          }
        }
      ],
      as: 'estatisticasChamadas'
    }
  },
  {
    $project: {
      _id: 0,
      RP: 1,
      nome: 1,
      disciplinasRelacionadas: {
        $map: {
          input: '$redeDisciplinas',
          as: 'd',
          in: {
            codigo: '$$d.codigo',
            nome: '$$d.nome',
            turmas: {
              $map: {
                input: '$$d.turmas',
                as: 't',
                in: {
                  codigo: '$$t.codigo',
                  docente: '$$t.docente.nome',
                  aulasAgendadas: { $size: '$$t.agendaDeAulas' }
                }
              }
            }
          }
        }
      },
      estatisticas: { $arrayElemAt: ['$estatisticasChamadas', 0] }
    }
  }
]);


// --- 7.7 Relatório 360° do aluno (multi-$lookup + $facet interno) ---

db.estudantes.aggregate([
  { $match: { RA: '1234' } },
  {
    $lookup: {
      from: 'chamadas',
      let: { ra: '$RA' },
      pipeline: [
        { $unwind: '$alunos' },
        { $match: { $expr: { $eq: ['$alunos.RA', '$$ra'] } } },
        {
          $facet: {
            resumo: [
              {
                $group: {
                  _id: null,
                  totalChamadas: { $sum: 1 },
                  presencas: { $sum: { $cond: ['$alunos.presente', 1, 0] } },
                  faltas: { $sum: { $cond: ['$alunos.presente', 0, 1] } }
                }
              }
            ],
            porDisciplina: [
              {
                $group: {
                  _id: '$disciplina.codigo',
                  disciplinaNome: { $first: '$disciplina.nome' },
                  presencas: { $sum: { $cond: ['$alunos.presente', 1, 0] } },
                  faltas: { $sum: { $cond: ['$alunos.presente', 0, 1] } },
                  total: { $sum: 1 }
                }
              },
              { $sort: { _id: 1 } }
            ],
            ultimasFaltas: [
              { $match: { 'alunos.presente': false } },
              { $sort: { data: -1 } },
              { $limit: 5 },
              {
                $project: {
                  _id: 0,
                  data: 1,
                  disciplina: '$disciplina.codigo',
                  justificativa: '$alunos.justificativa'
                }
              }
            ]
          }
        }
      ],
      as: 'historicoChamadas'
    }
  },
  {
    $lookup: {
      from: 'disciplinas',
      let: {
        matriculas: '$matriculas'
      },
      pipeline: [
        {
          $match: {
            $expr: {
              $in: [
                '$codigo',
                {
                  $map: {
                    input: '$$matriculas',
                    as: 'm',
                    in: '$$m.disciplinaCodigo'
                  }
                }
              ]
            }
          }
        },
        {
          $project: {
            _id: 0,
            codigo: 1,
            nome: 1,
            cargaHorariaTotal: 1,
            turmas: {
              $filter: {
                input: '$turmas',
                as: 't',
                cond: {
                  $in: [
                    '$$t.codigo',
                    {
                      $map: {
                        input: {
                          $filter: {
                            input: '$$matriculas',
                            as: 'm',
                            cond: { $eq: ['$$m.disciplinaCodigo', '$codigo'] }
                          }
                        },
                        as: 'mm',
                        in: '$$mm.turmaCodigo'
                      }
                    }
                  ]
                }
              }
            }
          }
        }
      ],
      as: 'disciplinasMatriculadas'
    }
  },
  {
    $project: {
      _id: 0,
      RA: 1,
      nome: 1,
      curso: 1,
      periodo: 1,
      matriculas: 1,
      disciplinasMatriculadas: 1,
      historico: { $arrayElemAt: ['$historicoChamadas', 0] }
    }
  }
]);


// --- 7.8 Detecção de inconsistências entre snapshot e dados atuais ---

db.chamadas.aggregate([
  { $unwind: '$alunos' },
  {
    $lookup: {
      from: 'estudantes',
      localField: 'alunos.RA',
      foreignField: 'RA',
      as: 'estudanteAtual'
    }
  },
  { $unwind: { path: '$estudanteAtual', preserveNullAndEmptyArrays: true } },
  {
    $addFields: {
      nomeDivergente: {
        $and: [
          { $ne: [{ $type: '$estudanteAtual' }, 'missing'] },
          { $ne: ['$alunos.nome', '$estudanteAtual.nome'] }
        ]
      },
      alunoInexistente: { $eq: [{ $type: '$estudanteAtual' }, 'missing'] },
      matriculaAtivaNaDisciplina: {
        $gt: [
          {
            $size: {
              $filter: {
                input: { $ifNull: ['$estudanteAtual.matriculas', []] },
                as: 'm',
                cond: {
                  $and: [
                    { $eq: ['$$m.disciplinaCodigo', '$disciplina.codigo'] },
                    { $eq: ['$$m.turmaCodigo', '$turma.codigo'] },
                    { $eq: ['$$m.situacao', 'matriculado'] }
                  ]
                }
              }
            }
          },
          0
        ]
      }
    }
  },
  {
    $match: {
      $or: [
        { nomeDivergente: true },
        { alunoInexistente: true },
        { matriculaAtivaNaDisciplina: false }
      ]
    }
  },
  {
    $project: {
      _id: 0,
      chamadaId: '$_id',
      data: 1,
      disciplina: '$disciplina.codigo',
      turma: '$turma.codigo',
      RA: '$alunos.RA',
      nomeNaChamada: '$alunos.nome',
      nomeAtual: '$estudanteAtual.nome',
      inconsistencias: {
        nomeDivergente: '$nomeDivergente',
        alunoInexistente: '$alunoInexistente',
        semMatriculaAtiva: { $not: ['$matriculaAtivaNaDisciplina'] }
      }
    }
  }
]);


// --- 7.9 Comparar taxa de presença real vs capacidade da turma ---

db.disciplinas.aggregate([
  { $unwind: '$turmas' },
  {
    $lookup: {
      from: 'chamadas',
      let: { cod: '$codigo', turma: '$turmas.codigo' },
      pipeline: [
        {
          $match: {
            $expr: {
              $and: [
                { $eq: ['$disciplina.codigo', '$$cod'] },
                { $eq: ['$turma.codigo', '$$turma'] }
              ]
            }
          }
        },
        {
          $group: {
            _id: null,
            mediaPresentesPorAula: { $avg: '$resumo.presentes' },
            mediaAusentesPorAula: { $avg: '$resumo.ausentes' },
            totalChamadas: { $sum: 1 },
            taxaPresencaMedia: {
              $avg: {
                $cond: [
                  { $eq: ['$resumo.totalAlunos', 0] },
                  0,
                  { $divide: ['$resumo.presentes', '$resumo.totalAlunos'] }
                ]
              }
            }
          }
        }
      ],
      as: 'indicadoresChamada'
    }
  },
  {
    $lookup: {
      from: 'estudantes',
      let: { cod: '$codigo', turma: '$turmas.codigo' },
      pipeline: [
        { $unwind: '$matriculas' },
        {
          $match: {
            $expr: {
              $and: [
                { $eq: ['$matriculas.disciplinaCodigo', '$$cod'] },
                { $eq: ['$matriculas.turmaCodigo', '$$turma'] },
                { $eq: ['$matriculas.situacao', 'matriculado'] }
              ]
            }
          }
        },
        { $count: 'matriculadosAtivos' }
      ],
      as: 'matriculasAtivas'
    }
  },
  {
    $project: {
      _id: 0,
      disciplinaCodigo: '$codigo',
      disciplinaNome: '$nome',
      turmaCodigo: '$turmas.codigo',
      docente: '$turmas.docente.nome',
      capacidadeRegistrada: '$turmas.qtdeAtualDeMatriculados',
      matriculadosAtivos: {
        $ifNull: [{ $arrayElemAt: ['$matriculasAtivas.matriculadosAtivos', 0] }, 0]
      },
      aulasAgendadas: { $size: '$turmas.agendaDeAulas' },
      chamadas: { $ifNull: [{ $arrayElemAt: ['$indicadoresChamada.totalChamadas', 0] }, 0] },
      mediaPresentesPorAula: {
        $round: [{ $ifNull: [{ $arrayElemAt: ['$indicadoresChamada.mediaPresentesPorAula', 0] }, 0] }, 2]
      },
      taxaPresencaMedia: {
        $round: [
          {
            $multiply: [
              { $ifNull: [{ $arrayElemAt: ['$indicadoresChamada.taxaPresencaMedia', 0] }, 0] },
              100
            ]
          },
          2
        ]
      },
      divergenciaMatriculas: {
        $subtract: [
          '$turmas.qtdeAtualDeMatriculados',
          { $ifNull: [{ $arrayElemAt: ['$matriculasAtivas.matriculadosAtivos', 0] }, 0] }
        ]
      }
    }
  },
  { $sort: { disciplinaCodigo: 1, turmaCodigo: 1 } }
]);


// --- 7.10 Sequência de faltas consecutivas por aluno (streak real) ---

db.chamadas.aggregate([
  { $match: { 'disciplina.codigo': '12490-P' } },
  { $sort: { data: 1 } },
  { $unwind: '$alunos' },
  {
    $project: {
      RA: '$alunos.RA',
      nome: '$alunos.nome',
      disciplina: '$disciplina.codigo',
      data: 1,
      falta: { $cond: ['$alunos.presente', 0, 1] }
    }
  },
  {
    $setWindowFields: {
      partitionBy: { RA: '$RA', disciplina: '$disciplina' },
      sortBy: { data: 1 },
      output: {
        faltaAnterior: {
          $shift: { output: '$falta', by: -1, default: 0 }
        }
      }
    }
  },
  {
    $addFields: {
      inicioNovaSequencia: {
        $cond: [
          { $and: [{ $eq: ['$falta', 1] }, { $ne: ['$faltaAnterior', 1] }] },
          1,
          0
        ]
      }
    }
  },
  {
    $setWindowFields: {
      partitionBy: { RA: '$RA', disciplina: '$disciplina' },
      sortBy: { data: 1 },
      output: {
        grupoSequencia: {
          $sum: '$inicioNovaSequencia',
          window: { documents: ['unbounded', 'current'] }
        }
      }
    }
  },
  { $match: { falta: 1 } },
  {
    $group: {
      _id: {
        RA: '$RA',
        disciplina: '$disciplina',
        grupo: '$grupoSequencia'
      },
      nome: { $first: '$nome' },
      tamanhoSequencia: { $sum: 1 },
      datas: { $push: '$data' }
    }
  },
  {
    $group: {
      _id: { RA: '$_id.RA', disciplina: '$_id.disciplina' },
      nome: { $first: '$nome' },
      maiorSequenciaFaltas: { $max: '$tamanhoSequencia' },
      faltasTotais: { $sum: '$tamanhoSequencia' },
      sequencias: {
        $push: {
          tamanho: '$tamanhoSequencia',
          inicio: { $arrayElemAt: ['$datas', 0] },
          fim: { $arrayElemAt: ['$datas', -1] }
        }
      }
    }
  },
  { $match: { maiorSequenciaFaltas: { $gte: 2 } } },
  {
    $project: {
      _id: 0,
      RA: '$_id.RA',
      nome: 1,
      disciplina: '$_id.disciplina',
      maiorSequenciaFaltas: 1,
      faltasTotais: 1,
      sequenciasDeFalta: '$sequencias',
      alerta: {
        $switch: {
          branches: [
            { case: { $gte: ['$maiorSequenciaFaltas', 4] }, then: 'ALTO' },
            { case: { $gte: ['$maiorSequenciaFaltas', 2] }, then: 'MEDIO' }
          ],
          default: 'BAIXO'
        }
      }
    }
  },
  { $sort: { maiorSequenciaFaltas: -1, nome: 1 } }
]);


// --- 7.11 $reduce: consolidar horas-aula por docente a partir de disciplinas ---

db.professores.aggregate([
  {
    $lookup: {
      from: 'disciplinas',
      let: { rp: '$RP' },
      pipeline: [
        { $unwind: '$turmas' },
        { $match: { $expr: { $eq: ['$turmas.docente.RP', '$$rp'] } } },
        {
          $project: {
            codigo: 1,
            nome: 1,
            turmaCodigo: '$turmas.codigo',
            horasAgendadas: {
              $reduce: {
                input: '$turmas.agendaDeAulas',
                initialValue: 0,
                in: { $add: ['$$value', '$$this.qtdeHorasAula'] }
              }
            }
          }
        }
      ],
      as: 'turmasDoProfessor'
    }
  },
  {
    $lookup: {
      from: 'chamadas',
      let: { rp: '$RP' },
      pipeline: [
        { $match: { $expr: { $eq: ['$docente.RP', '$$rp'] } } },
        {
          $group: {
            _id: null,
            horasMinistradas: { $sum: '$aula.qtdeHorasAula' }
          }
        }
      ],
      as: 'horasMinistradas'
    }
  },
  {
    $project: {
      _id: 0,
      RP: 1,
      nome: 1,
      totalTurmas: { $size: '$turmasDoProfessor' },
      horasAgendadas: {
        $reduce: {
          input: '$turmasDoProfessor',
          initialValue: 0,
          in: { $add: ['$$value', '$$this.horasAgendadas'] }
        }
      },
      horasMinistradas: {
        $ifNull: [{ $arrayElemAt: ['$horasMinistradas.horasMinistradas', 0] }, 0]
      },
      turmas: '$turmasDoProfessor'
    }
  },
  {
    $addFields: {
      horasPendentes: { $subtract: ['$horasAgendadas', '$horasMinistradas'] },
      percentualCumprimento: {
        $cond: [
          { $eq: ['$horasAgendadas', 0] },
          0,
          {
            $round: [
              {
                $multiply: [
                  { $divide: ['$horasMinistradas', '$horasAgendadas'] },
                  100
                ]
              },
              2
            ]
          }
        ]
      }
    }
  },
  { $sort: { percentualCumprimento: 1, nome: 1 } }
]);


// --- 7.12 Materializar relatório com $merge (cria/atualiza coleção relatorio_frequencia) ---

db.chamadas.aggregate([
  { $unwind: '$alunos' },
  {
    $group: {
      _id: {
        RA: '$alunos.RA',
        disciplinaCodigo: '$disciplina.codigo',
        turmaCodigo: '$turma.codigo',
        ano: '$disciplina.anoCalendario',
        semestre: '$disciplina.semestreCalendario'
      },
      nome: { $first: '$alunos.nome' },
      disciplinaNome: { $first: '$disciplina.nome' },
      docenteNome: { $first: '$docente.nome' },
      totalChamadas: { $sum: 1 },
      presencas: { $sum: { $cond: ['$alunos.presente', 1, 0] } },
      faltas: { $sum: { $cond: ['$alunos.presente', 0, 1] } },
      faltasSemJustificativa: {
        $sum: {
          $cond: [
            {
              $and: [
                { $eq: ['$alunos.presente', false] },
                {
                  $in: [
                    { $ifNull: ['$alunos.justificativa', 'Sem justificativa informada'] },
                    ['Sem justificativa informada', null]
                  ]
                }
              ]
            },
            1,
            0
          ]
        }
      },
      ultimaChamada: { $max: '$data' }
    }
  },
  {
    $addFields: {
      percentualPresenca: {
        $round: [
          { $multiply: [{ $divide: ['$presencas', '$totalChamadas'] }, 100] },
          2
        ]
      },
      status: {
        $switch: {
          branches: [
            {
              case: { $gte: [{ $divide: ['$presencas', '$totalChamadas'] }, 0.75] },
              then: 'APROVADO_FREQUENCIA'
            },
            {
              case: { $gte: [{ $divide: ['$presencas', '$totalChamadas'] }, 0.5] },
              then: 'RECUPERACAO_FREQUENCIA'
            }
          ],
          default: 'REPROVADO_FREQUENCIA'
        }
      },
      atualizadoEm: '$$NOW'
    }
  },
  {
    $project: {
      _id: 0,
      chave: {
        $concat: [
          '$_id.RA',
          '|',
          '$_id.disciplinaCodigo',
          '|',
          '$_id.turmaCodigo',
          '|',
          { $toString: '$_id.ano' },
          '-',
          { $toString: '$_id.semestre' }
        ]
      },
      RA: '$_id.RA',
      nome: 1,
      disciplinaCodigo: '$_id.disciplinaCodigo',
      disciplinaNome: 1,
      turmaCodigo: '$_id.turmaCodigo',
      anoCalendario: '$_id.ano',
      semestreCalendario: '$_id.semestre',
      docenteNome: 1,
      totalChamadas: 1,
      presencas: 1,
      faltas: 1,
      faltasSemJustificativa: 1,
      percentualPresenca: 1,
      status: 1,
      ultimaChamada: 1,
      atualizadoEm: 1
    }
  },
  {
    $merge: {
      into: 'relatorio_frequencia',
      on: 'chave',
      whenMatched: 'replace',
      whenNotMatched: 'insert'
    }
  }
]);

// Consultar o relatório materializado
db.relatorio_frequencia.find().sort({ percentualPresenca: 1, nome: 1 });


// --- 7.13 $densify + $fill: série temporal de chamadas por disciplina ---

db.chamadas.aggregate([
  { $match: { 'disciplina.codigo': '12490-P' } },
  {
    $group: {
      _id: '$data',
      disciplina: { $first: '$disciplina.codigo' },
      chamadasNoDia: { $sum: 1 },
      presentesNoDia: { $sum: '$resumo.presentes' },
      ausentesNoDia: { $sum: '$resumo.ausentes' }
    }
  },
  { $sort: { _id: 1 } },
  {
    $densify: {
      field: '_id',
      range: {
        step: 1,
        unit: 'day',
        bounds: ['2026-08-01', '2026-08-15']
      }
    }
  },
  {
    $fill: {
      output: {
        chamadasNoDia: { value: 0 },
        presentesNoDia: { value: 0 },
        ausentesNoDia: { value: 0 }
      }
    }
  },
  {
    $setWindowFields: {
      sortBy: { _id: 1 },
      output: {
        presentesAcumulados: {
          $sum: '$presentesNoDia',
          window: { documents: ['unbounded', 'current'] }
        },
        mediaMovel3Dias: {
          $avg: '$presentesNoDia',
          window: { range: [-2, 0] }
        }
      }
    }
  },
  {
    $project: {
      _id: 0,
      data: '$_id',
      disciplina: 1,
      chamadasNoDia: 1,
      presentesNoDia: 1,
      ausentesNoDia: 1,
      presentesAcumulados: 1,
      mediaMovel3Dias: { $round: ['$mediaMovel3Dias', 2] }
    }
  }
]);


// --- 7.14 Consulta recursiva manual: alunos que compartilham 2+ disciplinas ---

db.estudantes.aggregate([
  { $unwind: '$matriculas' },
  { $match: { 'matriculas.situacao': 'matriculado' } },
  {
    $group: {
      _id: '$matriculas.disciplinaCodigo',
      alunos: { $addToSet: { RA: '$RA', nome: '$nome' } }
    }
  },
  { $unwind: '$alunos' },
  {
    $group: {
      _id: '$alunos.RA',
      nome: { $first: '$alunos.nome' },
      disciplinas: { $addToSet: '$_id' }
    }
  },
  {
    $lookup: {
      from: 'estudantes',
      let: { ra: '$_id', disciplinas: '$disciplinas' },
      pipeline: [
        { $match: { $expr: { $ne: ['$RA', '$$ra'] } } },
        { $unwind: '$matriculas' },
        {
          $match: {
            $expr: {
              $and: [
                { $eq: ['$matriculas.situacao', 'matriculado'] },
                { $in: ['$matriculas.disciplinaCodigo', '$$disciplinas'] }
              ]
            }
          }
        },
        {
          $group: {
            _id: '$RA',
            nome: { $first: '$nome' },
            disciplinasEmComum: { $addToSet: '$matriculas.disciplinaCodigo' }
          }
        },
        {
          $match: {
            $expr: { $gte: [{ $size: '$disciplinasEmComum' }, 2] }
          }
        }
      ],
      as: 'colegasComDuasOuMaisDisciplinas'
    }
  },
  { $match: { colegasComDuasOuMaisDisciplinas: { $ne: [] } } },
  {
    $project: {
      _id: 0,
      RA: '$_id',
      nome: 1,
      disciplinas: 1,
      colegas: '$colegasComDuasOuMaisDisciplinas'
    }
  }
]);


// --- 7.15 Pipeline completo: boletim de frequência do semestre com $facet ---

db.chamadas.aggregate([
  {
    $match: {
      'disciplina.anoCalendario': 2026,
      'disciplina.semestreCalendario': 2
    }
  },
  {
    $facet: {
      indicadoresGerais: [
        {
          $group: {
            _id: null,
            chamadas: { $sum: 1 },
            presentes: { $sum: '$resumo.presentes' },
            ausentes: { $sum: '$resumo.ausentes' },
            alunosUnicos: { $addToSet: '$alunos.RA' }
          }
        },
        {
          $project: {
            _id: 0,
            chamadas: 1,
            presentes: 1,
            ausentes: 1,
            alunosUnicos: { $size: '$alunosUnicos' },
            taxaGeral: {
              $round: [
                {
                  $multiply: [
                    {
                      $divide: [
                        '$presentes',
                        { $add: ['$presentes', '$ausentes'] }
                      ]
                    },
                    100
                  ]
                },
                2
              ]
            }
          }
        }
      ],
      pioresTurmas: [
        {
          $group: {
            _id: {
              disciplina: '$disciplina.codigo',
              turma: '$turma.codigo'
            },
            disciplinaNome: { $first: '$disciplina.nome' },
            presentes: { $sum: '$resumo.presentes' },
            total: { $sum: '$resumo.totalAlunos' }
          }
        },
        {
          $addFields: {
            taxa: {
              $cond: [
                { $eq: ['$total', 0] },
                0,
                { $divide: ['$presentes', '$total'] }
              ]
            }
          }
        },
        { $sort: { taxa: 1 } },
        { $limit: 5 },
        {
          $project: {
            _id: 0,
            disciplina: '$_id.disciplina',
            turma: '$_id.turma',
            disciplinaNome: 1,
            taxaPresenca: { $round: [{ $multiply: ['$taxa', 100] }, 2] }
          }
        }
      ],
      alunosEmRisco: [
        { $unwind: '$alunos' },
        {
          $group: {
            _id: {
              RA: '$alunos.RA',
              disciplina: '$disciplina.codigo'
            },
            nome: { $first: '$alunos.nome' },
            presencas: { $sum: { $cond: ['$alunos.presente', 1, 0] } },
            total: { $sum: 1 }
          }
        },
        {
          $addFields: {
            percentual: {
              $multiply: [{ $divide: ['$presencas', '$total'] }, 100]
            }
          }
        },
        { $match: { percentual: { $lt: 75 } } },
        { $sort: { percentual: 1 } },
        { $limit: 10 },
        {
          $project: {
            _id: 0,
            RA: '$_id.RA',
            nome: 1,
            disciplina: '$_id.disciplina',
            percentualPresenca: { $round: ['$percentual', 2] }
          }
        }
      ],
      docentesMaisAtivos: [
        {
          $group: {
            _id: '$docente.RP',
            nome: { $first: '$docente.nome' },
            aulas: { $sum: 1 },
            horas: { $sum: '$aula.qtdeHorasAula' }
          }
        },
        { $sort: { aulas: -1, horas: -1 } },
        { $limit: 5 },
        {
          $project: {
            _id: 0,
            RP: '$_id',
            nome: 1,
            aulas: 1,
            horas: 1
          }
        }
      ]
    }
  }
]);


// =============================================================================
// 8. TRANSAÇÕES (MongoDB Atlas — replica set obrigatório)
// =============================================================================

// Matricular aluno e incrementar contador da turma atomicamente
const sessao = db.getMongo().startSession();
sessao.startTransaction();

try {
  const estudantesCol = sessao.getDatabase('controlefrequencia').estudantes;
  const disciplinasCol = sessao.getDatabase('controlefrequencia').disciplinas;

  estudantesCol.updateOne(
    { RA: '1234' },
    {
      $push: {
        matriculas: {
          disciplinaCodigo: '12710-T',
          disciplinaNome: 'Interface Humano-Computador - Teoria',
          turmaCodigo: '0101',
          anoCalendario: 2026,
          semestreCalendario: 2,
          situacao: 'matriculado'
        }
      }
    }
  );

  disciplinasCol.updateOne(
    { codigo: '12710-T', 'turmas.codigo': '0101' },
    {
      $inc: {
        'turmas.$.qtdeAtualDeMatriculados': 1,
        'turmas.$.qtdeInicialDeMatriculados': 1
      }
    }
  );

  sessao.commitTransaction();
  console.log('Transação concluída com sucesso.');
} catch (erro) {
  sessao.abortTransaction();
  console.error('Transação revertida:', erro);
} finally {
  sessao.endSession();
}


// =============================================================================
// 9. UTILITÁRIOS
// =============================================================================

// Estatísticas rápidas de todas as coleções
({
  professores: db.professores.countDocuments(),
  estudantes: db.estudantes.countDocuments(),
  disciplinas: db.disciplinas.countDocuments(),
  chamadas: db.chamadas.countDocuments()
});

// Listar índices de todas as coleções
({
  professores: db.professores.getIndexes(),
  estudantes: db.estudantes.getIndexes(),
  disciplinas: db.disciplinas.getIndexes(),
  chamadas: db.chamadas.getIndexes()
});

// Explicar plano de execução de uma consulta frequente
db.estudantes.find({
  matriculas: {
    $elemMatch: {
      disciplinaCodigo: '12490-P',
      turmaCodigo: '0101',
      situacao: 'matriculado'
    }
  }
}).explain('executionStats');
