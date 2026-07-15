import 'CalculatorController.dart';
import 'CalcAction.dart';
import 'Key.dart';
import 'KeyType.dart';

void main() {
  final calc = CalculatorController();

  final keys1 = <Key>[
    const Key(label: "2", type: KeyType.digit),
    const Key(label: "x", type: KeyType.operator, value: "x"),
    const Key(label: "2", type: KeyType.digit),
    const Key(label: "Enter", type: KeyType.action, action: CalcAction.enter),
  ];

  for (final k in keys1) {
    calc.press(k);
    print("Apertou '${k.label}' -> display: ${calc.display.text}");
  }

  print("\n--- Outro exemplo: 10/5 ---");
  calc.press(const Key(label: "C", type: KeyType.action, action: CalcAction.clear));
  calc.press(const Key(label: "1", type: KeyType.digit));
  calc.press(const Key(label: "0", type: KeyType.digit));
  calc.press(const Key(label: "/", type: KeyType.operator, value: "/"));
  calc.press(const Key(label: "5", type: KeyType.digit));
  calc.press(const Key(label: "Enter", type: KeyType.action, action: CalcAction.enter));
  print("Resultado: ${calc.display.text}");

  print("\n--- Erro: 2/0 ---");
  calc.press(const Key(label: "C", type: KeyType.action, action: CalcAction.clear));
  calc.press(const Key(label: "2", type: KeyType.digit));
  calc.press(const Key(label: "/", type: KeyType.operator, value: "/"));
  calc.press(const Key(label: "0", type: KeyType.digit));
  calc.press(const Key(label: "Enter", type: KeyType.action, action: CalcAction.enter));
  print("Resultado: ${calc.display.text}");
}