import 'KeyType.dart';
import 'CalcAction.dart';

class Key {
  final String label;
  final KeyType type;

  final String? value;

  final CalcAction? action;

  const Key({
    required this.label,
    required this.type,
    this.value,
    this.action,
  });
}