from trabalho_class_idade import verificar_elegibilidade
import unittest

class TestVerificarElegibilidade(unittest.TestCase):
    def test_todos_os_criterios_ok(self):
        resultado, motivos = verificar_elegibilidade("Maria Oliveira", 25, 3000, "SUPERIOR")
        self.assertTrue(resultado)
        self.assertEqual(motivos, [])

    def test_idade_inferior(self):
        resultado, motivos = verificar_elegibilidade("Maria Oliveira", 17, 3000, "SUPERIOR")
        self.assertFalse(resultado)
        self.assertIn("Idade inferior a 18 anos.", motivos)

    def test_renda_inferior(self):
        resultado, motivos = verificar_elegibilidade("Maria Oliveira", 25, 1500, "SUPERIOR")
        self.assertFalse(resultado)
        self.assertIn("Renda mensal inferior a R$ 2.000.", motivos)

    def test_escolaridade_inferior(self):
        resultado, motivos = verificar_elegibilidade("Maria Oliveira", 25, 3000, "MÉDIO")
        self.assertFalse(resultado)
        self.assertIn("Escolaridade não é de nível superior", motivos)

    def test_nome_inadimplente(self):
        resultado, motivos = verificar_elegibilidade("Carlos Silva", 25, 3000, "SUPERIOR")
        self.assertFalse(resultado)
        self.assertIn("Nome consta na lista de inadimplentes.", motivos)

    def test_multiplos_motivos(self):
        resultado, motivos = verificar_elegibilidade("Ana Souza", 16, 1500, "FUNDAMENTAL")
        self.assertFalse(resultado)
        self.assertIn("Idade inferior a 18 anos.", motivos)
        self.assertIn("Renda mensal inferior a R$ 2.000.", motivos)
        self.assertIn("Escolaridade não é de nível superior", motivos)
        self.assertIn("Nome consta na lista de inadimplentes.", motivos)

if __name__ == "__main__":
    unittest.main()