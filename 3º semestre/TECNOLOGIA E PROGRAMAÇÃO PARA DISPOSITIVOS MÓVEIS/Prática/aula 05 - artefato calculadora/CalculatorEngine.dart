class CalculatorEngine {
  double evaluate(String expression) {
    final exp = _normalize(expression);

    final regex = RegExp(
      r'^\s*([+-]?\d+(?:\.\d+)?)\s*([+\-*/x])\s*([+-]?\d+(?:\.\d+)?)\s*$',
    );

    final match = regex.firstMatch(exp);
    if (match == null) {
      throw FormatException("Expressão inválida: '$expression'");
    }

    final a = double.parse(match.group(1)!);
    final op = match.group(2)!;
    final b = double.parse(match.group(3)!);

    return _apply(a, op, b);
  }

  String _normalize(String s) {
    return s.replaceAll('×', 'x').replaceAll('X', 'x').trim();
  }

  double _apply(double a, String op, double b) {
    switch (op) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
      case 'x':
        return a * b;
      case '/':
        if (b == 0) throw UnsupportedError("Divisão por zero");
        return a / b;
      default:
        throw UnsupportedError("Operador não suportado ou inexistente: $op");
    }
  }
}
