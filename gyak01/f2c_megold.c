/*
Készíts egy Fahrenheit-Celsius átalakító programot.
Írd ki a [-20; 200] intervallum Fahrenheit értékeit 10-es léptékkel,
és a hozzájuk tartozó Celsius-fokot.
(F - 32) * 5 / 9 = C
*/
 
#include <stdio.h>

int main() {
    double also_h = -2;
    // deklaráljuk, definiáljuk, inicializáljuk
    double felso_h = 20;
    // deklaráljuk, definiáljuk
    double c;

    // i = i + a <=> i += a
    // i += 1 <=> ++i ~= i++ (++i és i++ mindkettő megnöveli i értékét, de van köztük különbség. Mi lehet az?)
    for (int i = also_h; i <= felso_h; i++) {
        // A műveletek sorrendje miatt fontos, hogy ne int 9-cel osszunk. Mi történne, ha mégis?
        c = (((i * 10) - 32) * 5 / 9.0);
        // \t: tabulátor karakter
        // %.2f : 2 tizedesjegy pontosság a kiírásban
        // %.2d : minimum 2 számjegy kiírása
        printf("°F: %.2f\t°C: %.2f\n", i * 10.0, c);
    }

    return 0;
}