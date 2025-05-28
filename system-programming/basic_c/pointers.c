#include <stdio.h>

int main()
{

    // Pointers
    int z = 5;
    int *pointer_z = &z;
    // Este puntero aputara a la misma direccion de memerio que pointer_z porque pointer_z apunta a una direccion de memeria
    int *another_pointer = &pointer_z;
    *pointer_z = 10;
    printf("Value of pointer: %p", pointer_z);
    printf("Value of  z: %i", z);
    printf("Values of another pointer: %p", another_pointer);
    return 0;
}