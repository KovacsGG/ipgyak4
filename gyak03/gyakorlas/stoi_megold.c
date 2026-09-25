/*
Írj programot, ami bekér egy *szöveget* és
a) decimális számként értelmezve
b) hexadecimális számként értelmezve
értékül adja egy int típusú változónak.

Hibás bemenet esetén adj vissza -1-et, egyébként 0-t. 
*/
#include <stdio.h>
#include <ctype.h>


int ishexdigit(char c) {
    c = tolower(c);
    return ('0' <= c && c <= '9') || ('a' <= c && c <= 'f');
}

int abs(int n) {
    if (n < 0) return n * -1;
    else return n;
}

char hextodec(char n) {
    n = tolower(n);
    return '0' <= n && n <= '9' ? n - '0' : n - 'a' + 10;
}

int main() {
    char s[64];
    // Max 63 karakter fér a stringbe. Ennyi számjegyű számot egyébként valószínűleg nem tudunk betenni egy intbe.
    scanf("%63s", s);
    // https://en.cppreference.com/c/io/fscanf
    // scanf("%63[0-9+-]", s);

    char sign = 0;
    if (s[0] == '-') sign = -1;
    if (s[0] == '+') sign = +1;

    // b
    // Ezt előrébb írom, mert több bemenetet elfogad. A megértést az "a" résztől érdemes kezdeni.
    for (int i = abs(sign); s[i] != '\0'; ++i)
        if (!ishexdigit(s[i])) return -1;
    
    int val_b = 0;
    for (int i = abs(sign); s[i] != '\0'; ++i) {
        val_b *= 16;
        val_b += hextodec(s[i]);
    }
    val_b *= sign ? sign : 1;
    printf("b: %i (%X)\n", val_b, val_b);


    // a
    for (int i = abs(sign); s[i] != '\0'; ++i)
        // Az első nem számjegy karakter helyére betehetnénk egy \0-t, és folytathatnánk
        if (!isdigit(s[i])) return -1;

    int val_a = 0;
    for (int i = abs(sign); s[i] != '\0'; ++i) {
        val_a *= 10;
        val_a += s[i] - '0';
    }
    val_a *= sign ? sign : 1;
    printf("a: %i (%X)\n", val_a, val_a);

    return 0;
}