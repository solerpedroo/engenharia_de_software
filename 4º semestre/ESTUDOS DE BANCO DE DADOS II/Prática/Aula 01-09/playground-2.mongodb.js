/* global use, db */
// MongoDB Playground - controlefrequencia
// Execute com a conexão MongoDB ativa (botão Play).

use('controlefrequencia');

// Limpa coleções antes de reimportar (opcional)
db.professores.drop();
db.estudantes.drop();
db.disciplinas.drop();
db.chamadas.drop();

db.professores.insertMany([
  {
    "RP": "4567890",
    "nome": "Steve Jobs"
  },
  {
    "RP": "890392",
    "nome": "Ada Lovelace"
  },
  {
    "RP": "100001",
    "nome": "Alan Turing"
  },
  {
    "RP": "100002",
    "nome": "Grace Hopper"
  },
  {
    "RP": "100003",
    "nome": "Donald Knuth"
  },
  {
    "RP": "100004",
    "nome": "Barbara Liskov"
  },
  {
    "RP": "100005",
    "nome": "Linus Torvalds"
  },
  {
    "RP": "100006",
    "nome": "Margaret Hamilton"
  },
  {
    "RP": "100007",
    "nome": "James Gosling"
  },
  {
    "RP": "100008",
    "nome": "Dennis Ritchie"
  }
]);

db.estudantes.insertMany([
  {
    "RA": "1234",
    "nome": "Ayrton Senna",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12490-T",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12501-P",
        "disciplinaNome": "Engenharia de Software 2 - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "1235",
    "nome": "Ana Clara Souza",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12490-T",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12600-P",
        "disciplinaNome": "Sistemas Distribuídos - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "1236",
    "nome": "Bruno Henrique Lima",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12501-P",
        "disciplinaNome": "Engenharia de Software 2 - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12710-P",
        "disciplinaNome": "Interface Humano-Computador - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "1237",
    "nome": "Camila Ferreira Rocha",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12600-P",
        "disciplinaNome": "Sistemas Distribuídos - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12820-P",
        "disciplinaNome": "Gestão de Projetos de Software - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "1238",
    "nome": "Diego Martins Alves",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12710-P",
        "disciplinaNome": "Interface Humano-Computador - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12930-T",
        "disciplinaNome": "Métodos Ágeis - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "2234",
    "nome": "Eduarda Pereira Nunes",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0102",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12501-T",
        "disciplinaNome": "Engenharia de Software 2 - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12820-P",
        "disciplinaNome": "Gestão de Projetos de Software - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "2235",
    "nome": "Felipe Augusto Ribeiro",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0102",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12600-T",
        "disciplinaNome": "Sistemas Distribuídos - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12930-T",
        "disciplinaNome": "Métodos Ágeis - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "2236",
    "nome": "Giovana Costa Melo",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0102",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12710-T",
        "disciplinaNome": "Interface Humano-Computador - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12820-P",
        "disciplinaNome": "Gestão de Projetos de Software - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "2237",
    "nome": "Henrique Batista Gomes",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0102",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12501-T",
        "disciplinaNome": "Engenharia de Software 2 - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12600-P",
        "disciplinaNome": "Sistemas Distribuídos - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  },
  {
    "RA": "2238",
    "nome": "Isabela Moura Cardoso",
    "curso": "Engenharia de Software",
    "periodo": 4,
    "matriculas": [
      {
        "disciplinaCodigo": "12490-P",
        "disciplinaNome": "Estudos de Bancos de Dados 2 - Prática",
        "turmaCodigo": "0102",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12710-P",
        "disciplinaNome": "Interface Humano-Computador - Prática",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      },
      {
        "disciplinaCodigo": "12930-T",
        "disciplinaNome": "Métodos Ágeis - Teoria",
        "turmaCodigo": "0101",
        "anoCalendario": 2026,
        "semestreCalendario": 2,
        "situacao": "matriculado"
      }
    ]
  }
]);

db.disciplinas.insertMany([
  {
    "codigo": "12490-P",
    "nome": "Estudos de Bancos de Dados 2 - Prática",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 30,
        "qtdeAtualDeMatriculados": 29,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 1,
        "docente": {
          "RP": "4567890",
          "nome": "Steve Jobs"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-01T08:00:00",
            "dataHoraFim": "2026-08-01T09:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-07T08:00:00",
            "dataHoraFim": "2026-08-07T09:40:00",
            "qtdeHorasAula": 2
          }
        ]
      },
      {
        "codigo": "0102",
        "qtdeInicialDeMatriculados": 40,
        "qtdeAtualDeMatriculados": 40,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "890392",
          "nome": "Ada Lovelace"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-02T10:00:00",
            "dataHoraFim": "2026-08-02T11:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-08T10:00:00",
            "dataHoraFim": "2026-08-08T11:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12490-T",
    "nome": "Estudos de Bancos de Dados 2 - Teoria",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 35,
        "qtdeAtualDeMatriculados": 35,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "100001",
          "nome": "Alan Turing"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-04T14:00:00",
            "dataHoraFim": "2026-08-04T15:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-11T14:00:00",
            "dataHoraFim": "2026-08-11T15:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12501-P",
    "nome": "Engenharia de Software 2 - Prática",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 32,
        "qtdeAtualDeMatriculados": 31,
        "trancamentos": 1,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "100002",
          "nome": "Grace Hopper"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-05T08:00:00",
            "dataHoraFim": "2026-08-05T09:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-12T08:00:00",
            "dataHoraFim": "2026-08-12T09:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12501-T",
    "nome": "Engenharia de Software 2 - Teoria",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 38,
        "qtdeAtualDeMatriculados": 38,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "100003",
          "nome": "Donald Knuth"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-06T10:00:00",
            "dataHoraFim": "2026-08-06T11:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12600-P",
    "nome": "Sistemas Distribuídos - Prática",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 28,
        "qtdeAtualDeMatriculados": 28,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "100004",
          "nome": "Barbara Liskov"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-06T14:00:00",
            "dataHoraFim": "2026-08-06T15:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-13T14:00:00",
            "dataHoraFim": "2026-08-13T15:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12600-T",
    "nome": "Sistemas Distribuídos - Teoria",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 30,
        "qtdeAtualDeMatriculados": 30,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "100005",
          "nome": "Linus Torvalds"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-07T14:00:00",
            "dataHoraFim": "2026-08-07T15:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12710-P",
    "nome": "Interface Humano-Computador - Prática",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 25,
        "qtdeAtualDeMatriculados": 25,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "100006",
          "nome": "Margaret Hamilton"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-09T08:00:00",
            "dataHoraFim": "2026-08-09T09:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-16T08:00:00",
            "dataHoraFim": "2026-08-16T09:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12710-T",
    "nome": "Interface Humano-Computador - Teoria",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 27,
        "qtdeAtualDeMatriculados": 27,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "100007",
          "nome": "James Gosling"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-10T10:00:00",
            "dataHoraFim": "2026-08-10T11:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12820-P",
    "nome": "Gestão de Projetos de Software - Prática",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 33,
        "qtdeAtualDeMatriculados": 32,
        "trancamentos": 0,
        "desistencias": 1,
        "transferencias": 0,
        "docente": {
          "RP": "100008",
          "nome": "Dennis Ritchie"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-10T14:00:00",
            "dataHoraFim": "2026-08-10T15:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-17T14:00:00",
            "dataHoraFim": "2026-08-17T15:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  },
  {
    "codigo": "12930-T",
    "nome": "Métodos Ágeis - Teoria",
    "cargaHorariaTotal": 40,
    "curso": "Engenharia de Software",
    "periodo": 4,
    "anoCalendario": 2026,
    "semestreCalendario": 2,
    "turmas": [
      {
        "codigo": "0101",
        "qtdeInicialDeMatriculados": 36,
        "qtdeAtualDeMatriculados": 36,
        "trancamentos": 0,
        "desistencias": 0,
        "transferencias": 0,
        "docente": {
          "RP": "4567890",
          "nome": "Steve Jobs"
        },
        "agendaDeAulas": [
          {
            "dataHoraInicio": "2026-08-11T08:00:00",
            "dataHoraFim": "2026-08-11T09:40:00",
            "qtdeHorasAula": 2
          },
          {
            "dataHoraInicio": "2026-08-18T08:00:00",
            "dataHoraFim": "2026-08-18T09:40:00",
            "qtdeHorasAula": 2
          }
        ]
      }
    ]
  }
]);

db.chamadas.insertMany([
  {
    "_id": "CH-12490-P-0101-2026-08-01",
    "data": "2026-08-01",
    "disciplina": {
      "codigo": "12490-P",
      "nome": "Estudos de Bancos de Dados 2 - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 29
    },
    "docente": {
      "RP": "4567890",
      "nome": "Steve Jobs"
    },
    "aula": {
      "dataHoraInicio": "2026-08-01T08:00:00",
      "dataHoraFim": "2026-08-01T09:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Apresentação da disciplina e revisão de modelagem orientada a documentos."
    },
    "resumo": {
      "totalAlunos": 5,
      "presentes": 4,
      "ausentes": 1
    },
    "alunos": [
      {
        "RA": "1234",
        "nome": "Ayrton Senna",
        "presente": true
      },
      {
        "RA": "1235",
        "nome": "Ana Clara Souza",
        "presente": true
      },
      {
        "RA": "1236",
        "nome": "Bruno Henrique Lima",
        "presente": false,
        "justificativa": "Sem justificativa informada"
      },
      {
        "RA": "1237",
        "nome": "Camila Ferreira Rocha",
        "presente": true
      },
      {
        "RA": "1238",
        "nome": "Diego Martins Alves",
        "presente": true
      }
    ]
  },
  {
    "_id": "CH-12490-P-0101-2026-08-07",
    "data": "2026-08-07",
    "disciplina": {
      "codigo": "12490-P",
      "nome": "Estudos de Bancos de Dados 2 - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 29
    },
    "docente": {
      "RP": "4567890",
      "nome": "Steve Jobs"
    },
    "aula": {
      "dataHoraInicio": "2026-08-07T08:00:00",
      "dataHoraFim": "2026-08-07T09:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Discussão sobre agregação, referências e desnormalização controlada."
    },
    "resumo": {
      "totalAlunos": 5,
      "presentes": 5,
      "ausentes": 0
    },
    "alunos": [
      {
        "RA": "1234",
        "nome": "Ayrton Senna",
        "presente": true
      },
      {
        "RA": "1235",
        "nome": "Ana Clara Souza",
        "presente": true
      },
      {
        "RA": "1236",
        "nome": "Bruno Henrique Lima",
        "presente": true
      },
      {
        "RA": "1237",
        "nome": "Camila Ferreira Rocha",
        "presente": true
      },
      {
        "RA": "1238",
        "nome": "Diego Martins Alves",
        "presente": true
      }
    ]
  },
  {
    "_id": "CH-12490-P-0102-2026-08-02",
    "data": "2026-08-02",
    "disciplina": {
      "codigo": "12490-P",
      "nome": "Estudos de Bancos de Dados 2 - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0102",
      "qtdeAtualDeMatriculados": 40
    },
    "docente": {
      "RP": "890392",
      "nome": "Ada Lovelace"
    },
    "aula": {
      "dataHoraInicio": "2026-08-02T10:00:00",
      "dataHoraFim": "2026-08-02T11:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Introdução a bancos orientados a documentos e desenho de coleções."
    },
    "resumo": {
      "totalAlunos": 5,
      "presentes": 4,
      "ausentes": 1
    },
    "alunos": [
      {
        "RA": "2234",
        "nome": "Eduarda Pereira Nunes",
        "presente": true
      },
      {
        "RA": "2235",
        "nome": "Felipe Augusto Ribeiro",
        "presente": true
      },
      {
        "RA": "2236",
        "nome": "Giovana Costa Melo",
        "presente": true
      },
      {
        "RA": "2237",
        "nome": "Henrique Batista Gomes",
        "presente": false,
        "justificativa": "Atestado pendente"
      },
      {
        "RA": "2238",
        "nome": "Isabela Moura Cardoso",
        "presente": true
      }
    ]
  },
  {
    "_id": "CH-12490-P-0102-2026-08-08",
    "data": "2026-08-08",
    "disciplina": {
      "codigo": "12490-P",
      "nome": "Estudos de Bancos de Dados 2 - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0102",
      "qtdeAtualDeMatriculados": 40
    },
    "docente": {
      "RP": "890392",
      "nome": "Ada Lovelace"
    },
    "aula": {
      "dataHoraInicio": "2026-08-08T10:00:00",
      "dataHoraFim": "2026-08-08T11:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Modelagem de chamada por aula com snapshot de disciplina, turma e docente."
    },
    "resumo": {
      "totalAlunos": 5,
      "presentes": 5,
      "ausentes": 0
    },
    "alunos": [
      {
        "RA": "2234",
        "nome": "Eduarda Pereira Nunes",
        "presente": true
      },
      {
        "RA": "2235",
        "nome": "Felipe Augusto Ribeiro",
        "presente": true
      },
      {
        "RA": "2236",
        "nome": "Giovana Costa Melo",
        "presente": true
      },
      {
        "RA": "2237",
        "nome": "Henrique Batista Gomes",
        "presente": true
      },
      {
        "RA": "2238",
        "nome": "Isabela Moura Cardoso",
        "presente": true
      }
    ]
  },
  {
    "_id": "CH-12490-T-0101-2026-08-04",
    "data": "2026-08-04",
    "disciplina": {
      "codigo": "12490-T",
      "nome": "Estudos de Bancos de Dados 2 - Teoria",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 35
    },
    "docente": {
      "RP": "100001",
      "nome": "Alan Turing"
    },
    "aula": {
      "dataHoraInicio": "2026-08-04T14:00:00",
      "dataHoraFim": "2026-08-04T15:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Fundamentos de NoSQL: consistência eventual, particionamento e replicação."
    },
    "resumo": {
      "totalAlunos": 2,
      "presentes": 2,
      "ausentes": 0
    },
    "alunos": [
      {
        "RA": "1234",
        "nome": "Ayrton Senna",
        "presente": true
      },
      {
        "RA": "1235",
        "nome": "Ana Clara Souza",
        "presente": true
      }
    ]
  },
  {
    "_id": "CH-12501-P-0101-2026-08-05",
    "data": "2026-08-05",
    "disciplina": {
      "codigo": "12501-P",
      "nome": "Engenharia de Software 2 - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 31
    },
    "docente": {
      "RP": "100002",
      "nome": "Grace Hopper"
    },
    "aula": {
      "dataHoraInicio": "2026-08-05T08:00:00",
      "dataHoraFim": "2026-08-05T09:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Laboratório de padrões de projeto aplicados a microsserviços."
    },
    "resumo": {
      "totalAlunos": 2,
      "presentes": 1,
      "ausentes": 1
    },
    "alunos": [
      {
        "RA": "1234",
        "nome": "Ayrton Senna",
        "presente": true
      },
      {
        "RA": "1236",
        "nome": "Bruno Henrique Lima",
        "presente": false,
        "justificativa": "Compromisso acadêmico em outra instituição"
      }
    ]
  },
  {
    "_id": "CH-12600-P-0101-2026-08-06",
    "data": "2026-08-06",
    "disciplina": {
      "codigo": "12600-P",
      "nome": "Sistemas Distribuídos - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 28
    },
    "docente": {
      "RP": "100004",
      "nome": "Barbara Liskov"
    },
    "aula": {
      "dataHoraInicio": "2026-08-06T14:00:00",
      "dataHoraFim": "2026-08-06T15:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Implementação de comunicação assíncrona com filas de mensagens."
    },
    "resumo": {
      "totalAlunos": 2,
      "presentes": 2,
      "ausentes": 0
    },
    "alunos": [
      {
        "RA": "1235",
        "nome": "Ana Clara Souza",
        "presente": true
      },
      {
        "RA": "1237",
        "nome": "Camila Ferreira Rocha",
        "presente": true
      }
    ]
  },
  {
    "_id": "CH-12710-P-0101-2026-08-09",
    "data": "2026-08-09",
    "disciplina": {
      "codigo": "12710-P",
      "nome": "Interface Humano-Computador - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 25
    },
    "docente": {
      "RP": "100006",
      "nome": "Margaret Hamilton"
    },
    "aula": {
      "dataHoraInicio": "2026-08-09T08:00:00",
      "dataHoraFim": "2026-08-09T09:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Prototipação de interfaces com foco em acessibilidade e usabilidade."
    },
    "resumo": {
      "totalAlunos": 2,
      "presentes": 2,
      "ausentes": 0
    },
    "alunos": [
      {
        "RA": "1236",
        "nome": "Bruno Henrique Lima",
        "presente": true
      },
      {
        "RA": "1238",
        "nome": "Diego Martins Alves",
        "presente": true
      }
    ]
  },
  {
    "_id": "CH-12820-P-0101-2026-08-10",
    "data": "2026-08-10",
    "disciplina": {
      "codigo": "12820-P",
      "nome": "Gestão de Projetos de Software - Prática",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 32
    },
    "docente": {
      "RP": "100008",
      "nome": "Dennis Ritchie"
    },
    "aula": {
      "dataHoraInicio": "2026-08-10T14:00:00",
      "dataHoraFim": "2026-08-10T15:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Planejamento de sprint com estimativas e definição de backlog."
    },
    "resumo": {
      "totalAlunos": 3,
      "presentes": 2,
      "ausentes": 1
    },
    "alunos": [
      {
        "RA": "1237",
        "nome": "Camila Ferreira Rocha",
        "presente": true
      },
      {
        "RA": "2234",
        "nome": "Eduarda Pereira Nunes",
        "presente": true
      },
      {
        "RA": "2236",
        "nome": "Giovana Costa Melo",
        "presente": false,
        "justificativa": "Consulta médica"
      }
    ]
  },
  {
    "_id": "CH-12930-T-0101-2026-08-11",
    "data": "2026-08-11",
    "disciplina": {
      "codigo": "12930-T",
      "nome": "Métodos Ágeis - Teoria",
      "curso": "Engenharia de Software",
      "periodo": 4,
      "anoCalendario": 2026,
      "semestreCalendario": 2
    },
    "turma": {
      "codigo": "0101",
      "qtdeAtualDeMatriculados": 36
    },
    "docente": {
      "RP": "4567890",
      "nome": "Steve Jobs"
    },
    "aula": {
      "dataHoraInicio": "2026-08-11T08:00:00",
      "dataHoraFim": "2026-08-11T09:40:00",
      "qtdeHorasAula": 2,
      "conteudo": "Comparativo entre Scrum, Kanban e práticas de entrega contínua."
    },
    "resumo": {
      "totalAlunos": 3,
      "presentes": 3,
      "ausentes": 0
    },
    "alunos": [
      {
        "RA": "1238",
        "nome": "Diego Martins Alves",
        "presente": true
      },
      {
        "RA": "2235",
        "nome": "Felipe Augusto Ribeiro",
        "presente": true
      },
      {
        "RA": "2238",
        "nome": "Isabela Moura Cardoso",
        "presente": true
      }
    ]
  }
]);
// Verificação dos documentos importados
const resumo = {
  professores: db.professores.countDocuments(),
  estudantes: db.estudantes.countDocuments(),
  disciplinas: db.disciplinas.countDocuments(),
  chamadas: db.chamadas.countDocuments()
};

console.log('Importação concluída:', resumo);
resumo;
