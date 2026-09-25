/*
Írj while ciklust, aminek a viselkedése megegyezik a megadott for cikluséval,
írj for ciklust, aminek a viselkedése megegyezik a megadott while cikluséval.
Írj egy függvényt, aminek a viselkedése megegyezik a megadott while cikluséval.

A függvény hívását a while elé érdemes helyezni.
*/
#include <stdio.h>


// Függvény helye:
void loop() {
    printf("buffalo ");
    loop();
}

void for_loop(int i, int a, int b, int c) {
    if (!(i < 10)) return;
    printf("%i ", a);
    c = b;
    b += a;
    a = c;
    for_loop(++i, a, b, c);
}

int main() {
    int a = 0, b = 1, c;
    for (int i = 1; i < 10; ++i) {
        printf("%i ", a);
        c = b;
        b += a;
        a = c;
    }
    printf("\n");
    // Ekvivalens while ciklus helye:
    int i = 1;
    while (i < 10) {
        printf("%i ", a);
        c = b;
        b += a;
        a = c;

        ++i;
    }
    printf("\n");

    for_loop(1, a, b, c);
    printf("\n");

    //loop();
    /*
    while (1) {
        printf("buffalo ");
    }
    */
    // Ekvivalens for ciklus helye:
    // for (;;) printf("buffalo ");
    
    return 0;
}