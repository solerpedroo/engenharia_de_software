import 'Display.dart';
import 'CalculatorEngine.dart';
import 'Key.dart';
import 'KeyType.dart';
import 'CalcAction.dart';

class CalculatorController {
  final Display display;
  final CalculatorEngine engine;

  CalculatorController({Display? display, CalculatorEngine? engine})
      : display = display ?? Display(),
        engine = engine ?? CalculatorEngine();

  void press(Key key) {
    switch (key.type) {
      case KeyType.digit:
      case KeyType.operator:
        display.append(key.value ?? key.label);
        break;

      case KeyType.action:
        _handleAction(key.action);
        break;
    }
  }

  void _handleAction(CalcAction? action) {
    if (action == null) return;

    switch (action) {
      case CalcAction.clear:
        display.clear();
        break;
      case CalcAction.backspace:
        display.backspace();
        break;
      case CalcAction.enter:
        _compute();
        break;
    }
  }

  void _compute() {
    final input = display.text.trim();
    if (input.isEmpty) return;

    try {
      final result = engine.evaluate(input);

      final intCandidate = result.toInt();
      final formatted = (result == intCandidate) ? "$intCandidate" : "$result";

      display.setText(formatted);
    } catch (_) {
      display.setText("Erro");
    }
  }
}
