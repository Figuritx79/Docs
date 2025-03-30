# Notas del libro eloquent **JS**

Las cadenas en js usan estandar UNICODE. Esto representa cada letra como un numero
es 2^16 * 2 el total que tiene este estandar UN emoji ocupa dos espacios de caracteres

```js
const hola = 'hola me llamo pedro, soy ingles';
```

Los otros operadores mostrados hasta ahora en este capítulo operaron sobre dos valores, pero typeof toma solo uno. Los operadores que utilizan dos valores se llaman operadores binarios, mientras que aquellos que toman uno se llaman operadores unarios. El operador menos se puede usar tanto como un operador binario como un operador unario

```js
console.log(typeof 12) // UNARIO
```

### Cosas raras que hace JS

```js
console.log(8 * null)
// → 0
console.log("5" - 1)
// → 4
console.log("5" + 1)
// → 51
console.log("five" * 2)
// → NaN
console.log(false == 0)
// → true
```
Cuando se aplica un operador al tipo de valor “incorrecto”, JavaScript convertirá silenciosamente ese valor al tipo que necesita, utilizando un conjunto de reglas que a menudo no son las que deseas o esperas. Esto se llama coerción de tipos. 

### Que sucede cuando realmente quieres comprobar el tipo de dato?
Cuando se comparan valores del mismo tipo usando el operador ==, el resultado es fácil de predecir: deberías obtener verdadero cuando ambos valores son iguales, excepto en el caso de NaN. Pero cuando los tipos difieren, JavaScript utiliza un conjunto de reglas complicado y confuso para determinar qué hacer. En la mayoría de los casos, simplemente intenta convertir uno de los valores al tipo del otro valor.
Cuando no deseas que ocurran conversiones de tipo, hay dos operadores adicionales: === y !==. El primero prueba si un valor es precisamente igual al otro, y el segundo prueba si no es precisamente igual. Por lo tanto, "" === false es falso como se espera. Recomiendo usar los operadores de comparación de tres caracteres defensivamente para evitar conversiones de tipo inesperadas que puedan complicarte las cosas. Pero cuando estés seguro de que los tipos en ambos lados serán los mismos, no hay problema en usar los operadores más cortos.

### Object.hasOwn()

Este metodo nos dice si un objeto tiene un atributo o propiedad

```js
const object1 = {

prop: "exists",

};


console.log(Object.hasOwn(object1, "prop"));

// Expected output: true


console.log(Object.hasOwn(object1, "toString"));

// Expected output: false


console.log(Object.hasOwn(object1, "undeclaredPropertyValue"));

// Expected output: falseQ
```
