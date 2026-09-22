#include <stdio.h>
#include <ctype.h>

// Ezek csak akkor működnek, ha a betűk összefüggő régiókat alkotnak
// ASCII esetén jó, de pl EBCDIC esetén nem.
// A ctype függvényei mindig jók, használjuk azokat.
bool is_lower(int c) {
    return 'a' <= c && c <= 'z';
}
bool is_upper(int c) {
    return 'A' <= c && c <= 'Z';
}

int main() {
    /*
    char c;
    do {
        scanf("%c", &c);
        if (c == '0') break;
        if (isupper(c))
            printf("%c\n", c + ('a' - 'A'));
        else if (islower(c))
            printf("%c\n", c + ('A' - 'a'));
        else printf("%c\n", c);
    } while (1);
    */

   int c;
   // Az értékadás kifejezés értéke a bal oldalon álló kifejezés értéke.
   while((c = getchar()) != EOF) {
        // A continue a breakhez hasonlóan befejezi az adott ciklust, de
        // nem ugrik a ciklus utánra. A következő ciklussal folytatja.
        // Hagyjuk figyelmen kívül az újsorokat.
        if (c == '\n') continue;
        if (islower(c)) printf("%c\n", toupper(c));
        else if (isupper(c)) printf("%c\n", tolower(c));
        else printf("%c\n", c);
    }

    return 0;
}