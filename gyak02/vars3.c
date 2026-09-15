/*
Próbálj meg értékül adni az int típusú változónak egy valós számot, 
egy karaktert, egy logikai ( bool ) értéket, és egy karakter láncot (stringet).
Ha sikerül az értékadás, akkor írd ki a változó értékét.
*/
#include <stdio.h>


int main() {
    int d = 2.72; // nulla felé kerekít: -2.72 -> -2
    printf("%i\n", d);
    // HIBA! unspecified
    printf("%f\n", d);

    int c = 'A';
    printf("%i\n", c);

    int t = true;
    int f = false;
    printf("%i\n", t);
    printf("%i\n", f);

    // Ennyire nem gyengén típusos a C
    //int s = "apple";
    char s[] = {'a', 'p', 'p'};
    // HIBA! %s: null-terminated string, de s nem ilyen -> unspecified
    // Compiler nem ad warningot, és ezt a gyakorlatban is könnyű elrontani.
    printf("%s\n", s);


    return 0;
}