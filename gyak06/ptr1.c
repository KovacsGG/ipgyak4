#include <stdio.h>


int main() {
    // 1. Változtasd meg egy változó értékét egy változóra mutató pointeren keresztül.
    int a = 5;
    int * p = &a;
    printf("a: %i\n", a);
    *p = 6;
    printf("a: %i\n", a);

    // 2. Változtasd meg egy pointer értékét egy pointerre mutató pointeren keresztül. Ezután változtasd meg a mutatott mutató által mutatott értéket is!
    int b = 7;
    printf("p (%p): %i\n", (void*)p, *p);
    int ** q = &p;
    *q = &b;
    printf("p (%p): %i\n", (void*)p, *p);
    **q = 8;
    printf("q (%p): %i\n", (void*)q, **q);

    // 3. Tudsz-e önmagára mutató mutatót létrehozni? Mi lenne a típusa? Miért (nem)? Hasonlítsd össze a különböző típusú változókra mutató mutatók méretét. Indokold meg miért logikus az eredmény!
    // int * inkompatibilis int ** -gal
    //int * r = &r;
    // DE! void * minden pointerrel kompatibilis, void **-gal is. (Ezért veszélyes, összekeverhetjük a típusainkat)
    void * woah = &woah;
}