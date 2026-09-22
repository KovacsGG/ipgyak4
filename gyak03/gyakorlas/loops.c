/*
Írj while ciklust, aminek a viselkedése megegyezik a megadott for cikluséval,
írj for ciklust, aminek a viselkedése megegyezik a megadott while cikluséval.
Írj egy függvényt, aminek a viselkedése megegyezik a megadott while cikluséval.

A függvény hívását a while elé érdemes helyezni.
*/
#include <stdio.h>


// Függvény helye:


int main() {
    int a = 0, b = 1, c;
    for (int i = 1; i < 10; ++i) {
        printf("%i ", a);
        c = b;
        b += a;
        a = b;
    }
    printf("\n");
    // Ekvivalens while ciklus helye:
    

    while (1) {
        printf("buffalo ");
    }
    // Ekvivalens for ciklus helye:

    
    return 0;
}