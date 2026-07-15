class Display {

  String _text;

  Display({String initialText = ""}) : _text = initialText;

  String get text => _text;

  void setText(String value) => _text = value;

  void clear() => _text = "";

  void append(String value) => _text += value;

  void backspace() {
    if (_text.isEmpty) return;
    _text = _text.substring(0, _text.length - 1);
  }
}