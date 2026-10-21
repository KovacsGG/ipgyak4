/*
Írj programot, amely egy egészeket tároló tömb maximális elemét kiírja!
*/
#include <stdio.h>
#include <limits.h>


int main() {
    int tomb[] = {-1, -2, -3, -4, -5, -4, -3};
    // const típus nem lehet értékadás bal oldalán (Ez itt inicializáció.)
    // Erősebb optimalizációkat enged meg a compilernek.
    const int len = sizeof(tomb) / sizeof(tomb[0]);

    int osszeg = 0;
    int max = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        osszeg += tomb[i];

        if (tomb[i] > max) {
            max = tomb[i];
        }
    }

    printf("Sum: %i\n", osszeg);
    printf("Max: %i\n", max);

    return 0;
}