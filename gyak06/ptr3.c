#include <stdio.h>


int * half6(int * arr) {
    int res[3];
    int i = 0;
    while(i < 6) {
        if (i % 2 == 1) res[i / 2] = arr[i];
        ++i;
    }
    // Ajjaj! A res tömb élettartama a függvény visszatérésekor véget ér, de erre mutató pointert adunk vissza. Ez a pointer használhatatlan lesz, 99.9%, hogy a kód hibás!
    return res;
}

int main() {
    // 8. Írj függvényt, ami egy int[]-et kap és visszaad egy tömböt, amiben minden második elem szerepel
    int a[] = {1, 2, 3, 4, 5, 6}; 
    int * h = half6(a);
    //printf("%i\n", h[1]);


    [[maybe_unused]] int * n = (int*)1;
    //*n = 3; // ok (szintaktikailag, persze ettől még hibás, erre a címre nem írhatunk)
    //*1 = 3; // rossz értékkategória
    

    // 9. Olvasd ki a 0 értékű memóriacímen lévő bájtokat!
    printf("%c", *(char*)NULL);

    return 0;
}