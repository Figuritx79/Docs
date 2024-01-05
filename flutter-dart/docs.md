# Dart

Dart es un lenguaje de programacion de propositio general. Al inicio su proposito era sustituir a JavaScript en los navegadores, incluyendo una maquina virtual en el navegador pero dart nunca tuve el exito que esperaba y se dejo de lado durante mucho tiempo. Pero eso cambio cuando se creo el framework de flutter, este lo uso como lenguaje principal.

```dart

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

```

Cualquier duda que tengas sobre dart puedes consultar la documentacion oficial de dart <a href="https://dart.dev/guides/language/language-tour">aqui</a>

# Flutter

Flutter es un framework para el desarrollo de aplicaciones multiplataforma que usa skia para el renderizado de sus interfaces 2d, tambien ocupa dart como lenguaje de programacion.

### Primer widget en flutter 
Vamos a crear un widget de texto que dira **Hello Flutter**. Para hacer esto vamos a escribir lo siguiente:

```dart

void main(){
	runApp(
	   const Center(

	     child:Text(
		'Hello Flutter',
		textDirection: TextDirection.ltr,
		
	     ),
	  ),	
	);
}

```
La funcion **runApp()** recibe dos widgets y un widget hijo. El primer widget es Center que  centra el contenido y dentro de este tiene un widget child que recibe un widget Text que nos permite crear un texto que es Hello Flutter en este caso.





### Primer error, Java Gradle migration

Con este error lo que sucede es que no te deja correr la app por que el gradle y groovy no corren con ciertas versiones de java. En mi caso tenia la version 21 del jdk de java y por defecto me ponia un gradle 7.5 pero este no corre con mi version de java(21). El 7.5 con el jdk18, la 7.6 con el jdk19 y el 8.4 es con el que corre el jdk21.

No se, si esta bien lo recomendable es tener las versiones de java y gradle que te solicta flutter pero como solucion preventiva se puede hacer lo siguiente:

```bash
# Tienes que ir a la carpeta android del proyecto de flutter
# Dentro de esta carpeta va a haber otra que es gradle, esta es la que nos interesa. Una vez dentro nos va interesar el fichero gradle-wrapper.properties
# Dentro del fichero que mencione vamos a ir a la ultima linea y vamos a modificarlo

distributionUrl=https\://services.gradle.org/distributions/gradle-8.4-all.zip

```

En mi caso yo puse la version gradle8.4 pero lo mas recomendable es utilizar la documentacion y tener las versiones de java adecuadas pero esto soluciona el problema un rato, para sacer el archivo gradle.8.4,vamos a ir a la siguiente url

<a href="https://services.gradle.org/distributions/">Dentro de esta url vamos a buscar la version que nos interesa siguiendo la nomenclatura que viene por defecto</a>
