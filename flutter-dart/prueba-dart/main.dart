// import 'dart:math';
// Importacion en dart
void main() {
  // Primer hello world
  print("Hello world");

  // Creacion de variables, hay dos formas explicita y  no explicita
  var name = 'Joe';
  String names = 'Enrique';

  // Controles de flujo

  if (1 < 5) {
    // Esto es la sintaxis de un if
    print('Hello');
  }

  for (var i = 0; i <= 5; i++) {
    print('Esto es la sintexis de un for');
  }

  // Creacion de funciones
  var plus = sytaxFun(2);
}

int sytaxFun(int number) {
  number = 1 + number;
  return number;
}
