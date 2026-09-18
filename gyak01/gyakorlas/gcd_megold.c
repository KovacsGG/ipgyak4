/*
Haladóknak!
Írj programot, amely kiszámolja két szám legnagyobb közös osztóját.
Hint: https://en.wikipedia.org/wiki/Euclidean_algorithm
*/
 
#include <stdio.h>

int main() {
    int a = 762;
    int b = 54;
    int r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    printf("%d\n", a);
    return 0;
}