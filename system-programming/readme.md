# Programacion a nivel de sistema operativo

La herramienta para Programacion a nivel de sistema operativo sera c 
que es un lenguaje compilado y debajo nivel.

Para arrancar cualquier programa en c se necesita la funcion especial main

La funcion ```main``` retorna un int por que todos los programas tiene un codigo de salida

### Codigos de Salida

1. Codigo 0 : este codigo de salida representa que todo ha salido bien(asi lo interpreta linux)
2. Codigo 1 : este codigo de salida representa errores en el programa


### Librerias
1. stdio.h: Representa las salidas y entradas estandar(standard input/output)
nos permite imprimir o recibir cosas por consola

2. < >: Cuando utlizamos estas flechas represeta librerias del propio sistema

3. stdlib.h: Libreria estandard con esta podremos usar el heap para el uso de memoria dinamica

### Punteros
Un puntero en lugar de almacenar un valor guarda un direccion de memoria.Normalment las direcciones de memoria se representa con valores hexadecimales.
```c
int a = 5;
int *pointer_a = &a;

// De esta forma podremos cambiar el valor de la direccion de memeria a la que apunta dicho puntero
*pointer_a = 10
```

### Heap y stack

Normalmente un programa tiene asinado una zona de memoria. En esta pila es donde se almacenan las variables.El stack se asigna a cada funcion del program, el detalle es que el stack es muy limitado en cuanto a memoria que te da el sistema.

El heap es la zona de memorias que te asigna el sistema y vas tener disponible acceso a las variables o datos de cualquier funcion. En el heap podremos reservar espacios de memoria que normalmente seran punteros.

Para poder usar el heap, necesitamos la libreria ```stdlib.h```. Esta libreria nos permite el uso de funciones para utilzar memoria dinamicamente. UNa de esas funciones es ```malloc``` que **nos regresara un puntero a una direccion de memoria**, **ojo nosotros le tendremos que pasar el numero de bits que queremos que tenga ese espacio en memoria**
```c
#include<stdlib.h>
int main()
{
    // Mallo= Memory Allocator
    // sizeOf Nos regresa el tamano de un tipo, por ejemplo 4 bytes ocupa un int
    // Si lo multiplicamos por 8 nos dario un array de 8 espacios y un espacio de 32 bytes
    int *arrays[] = malloc(sizeof(int) *8);
        for (int i = 0; i < 8; i++)
    {
        arrays[i] = i + 1;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("Value: %i \n", arrays[i]);
    }

    free(arrays)
}
```
En el ejemplo de arriba se desplaza el puntero ya que estamos sumando le uno por el elemento
Tambien es obligatorio liberar memoria para que otros punteros en un futuro puedan tomar ese espacio, se usa la funcion ```free()`` .

### Segmentation Fault 
Esto es debedio a que estas tratando de acceder a un espacio en memoria que el sistema operativo no te ha dado.
The segmentation fault in C++ may occur in the case where the program tries to:
Access the memory that it does not own.
Dereference nullptr or NULL pointer.
Modify Read-Only memory.
