/*
Múlt hétről.
Fejlesszük tovább a függvényt, hogy ha kap egy parancssori argumentumot, a megadott dátumszámként értelmezi.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define START_YEAR 1900


int sum_days_until_month(int month) {
    // Miért nem kell december hossza?
    int month_lengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int sum = 0;
    for (int i = 0; i < month; ++i) {
        sum += month_lengths[i];
    }
    return sum;
}

bool is_leap_year(int year) {
    return year % 4 ? (year % 100 ? (year % 400 ? true : false) : true) : false;
}
/*
bool is_leap_year(int year) {
    if (year % 4) {
        if (year % 100) {
            return year % 400 ? true : false;
        }
        else return true;
    }
    else return false;
}
*/

long sum_days_until_year(int year) {
    long sum = 0;
    for (int i = START_YEAR; i < year; ++i)
        sum += is_leap_year(i) ? 366 : 365;
    return sum;
}

int main(int argc, char * argv[]) {
    long date;
    if (argc == 1) {
        printf("Date: ");
        scanf("%li", &date);
    } else {
        date = atol(argv[1]);
    }

    int delta_year = date / 10000 - START_YEAR;
    int delta_month = date / 100 % 100 - 1;
    int delta_day = date % 100 - 1;

    printf("a: %li\n", (long)(delta_year * 12 + delta_month) * 30 + delta_day);

    // b
    // Ezzel tömbbe fogunk indexelni, ezért tudnunk kell, hogy nem esik rossz tartományba.
    if (delta_month < 0 || delta_month > 11) return -1;
    // A többi bemenetet most nem ellenőrzöm, mert az csak annyira fog értelmetlen kimenetet okozni, amennyire a bemenet volt értelmetlen.
    printf("b: %li\n",
        365L * delta_year +
        sum_days_until_month(delta_month) +
        delta_day
    );

    // c
    int year = date / 10000;
    printf("c: %li\n",
        sum_days_until_year(year) +
        sum_days_until_month(delta_month) +
        // A legutolsó februárnak 28 napot számoltunk (ha számoltuk), ez pontos?
        (delta_month > 1 && is_leap_year(year) ? 1 : 0) +
        delta_day
    );

    return 0;
}