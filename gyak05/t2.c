/*
Írj programot, amely összeadja egy egészeket tároló tömbben az összes elemet!
*/
#include <stdio.h>

#define LEN 5


int main() {
    // Az inicializátorban nem lehet több elem, mint LEN
    int tomb[LEN] = {1, 2, 3, 4, 5};

    // progalap
    int osszeg = 0;
    for (int i = 0; i < sizeof(tomb) / sizeof(tomb[0]); i++)
    {
        osszeg += tomb[i];
    }

    printf("Sum: %i\n", osszeg);

    return 0;
}