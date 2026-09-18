/*
Készíts programot, amely kiír egy `levels` szintből álló piramist.
a) A piramis legyen balra igazítva, pl ha levels == 3:
Kimenet:
*
**
***

b) A piramis legyen kiegyensúlyozva, pl ha levels == 3:
Kimenet:
  *
 ***
*****
*/
 
#include <stdio.h>

int main() {
    int levels = 8;

    printf("a)\n");
    for (int i = 0; i < levels; ++i) {
        for (int j = 0; j <= i; ++j)
            printf("*");
        printf("\n");
    }

    printf("b)\n");
    // Mindig érdemes végiggondolni a matematikai összefüggéseket kódolás előtt!
    for (int i = 0; i < levels; ++i) {
        for (int j = 0; j < levels - i - 1; ++j)
            printf(" ");
        for (int j = 0; j < i * 2 + 1; ++j)
            printf("*");
        printf("\n");
    }

    return 0;
}