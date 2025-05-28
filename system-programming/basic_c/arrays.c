#include <stdio.h>
#include <stdlib.h>
int main()
{

    int array[5] = {1, 2, 3, 4, 5};

    // Total 32 bytes
    int *arrays = malloc(sizeof(int) * 8);

    for (int i = 0; i < 8; i++)
    {
        arrays[i] = i + 1;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("Value: %i \n", arrays[i]);
    }
    // SegFault
    // arrays[100000] = 10;
    free(arrays);
    return 0;
}
// Video 4 Empezar