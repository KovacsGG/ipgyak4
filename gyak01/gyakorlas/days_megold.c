/*
Írj programot, amely adott számú napot átszámol évekre, hetekre és napokra.
Pl  375 nap:
Kimenet:
1 év 1 hét 3 nap.

Hint: a % (modulo) operátor az osztás maradékát adja eredményül. 12 % 5 == 2
*/
 
#include <stdio.h>

int main() {
    int days = 375;

    // egész osztás
    int years = days / 365;

    // azaz days = days % 365
    days %= 365;

    int weeks = days / 7;
    days %= 7;

    // Előfordulhat, hogy az ékezetes karakterek Windowson nem jól kerülnek
    // kiírásra. Ezt a forrásfájl (és így a string literal) kódolása
    // és a CLI által használt kódolás közötti eltérés okoz.
    // Az előbbi alapértelmezése VSCode-ban az ipari standard UTF8, az utóbbié
    // Windowson Windows1250 (vagy CP852, nem emlékszem). Mindkettő állítható.
    // A labor gépeken nem állítható a CLI által használt karakterkódolás.
    printf("%d év, %d hét, %d nap\n", years, weeks, days);

    /* modulo nélkül */

    int days_ = 375;
    int years_ = days_ / 365;
    days_ -= years_ * 365;
    int weeks_ = days_ / 7;
    days_ -= weeks_ * 7;

    printf("%d év, %d hét, %d nap\n", years_, weeks_, days_);

    // Bónusz finomság a printf dokumentációjából:
    /*
    `.` followed by integer number or `*`, or neither that specifies precision
    of the conversion. In the case when `*` is used, the precision is specified
    by an additional argument of type `int`, which appears before the argument
    to be converted [...]
    [...]
    s: Writes a character string.
    - Precision specifies the maximum number of bytes to be written.
      If Precision is not specified, writes every byte up to and not including
      the first null terminator.
    */
    char pl[] = "s"; // pl mint plural
    printf("%d year%.*s, %d week%.*s, %d day%.*s\n",
        years_, years_ != 1, pl, 
        weeks_, weeks_ != 1, pl,
        days_, days_ != 1, pl);

    // A logikai és (itt) összehasonlító műveletek eredménye
    // (int) 1, ha igaz, és (int) 0 ha nem.

    return 0;
}