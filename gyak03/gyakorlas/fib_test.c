/*
Készítsd el a fib.h és fib.c forrásokat, hogy az alábbi program hiba nélkül
lefusson.
*/
#include <stdio.h>
#include "fib.h"


int main() {
    if (fib(0) != 0) return -1;
    if (fib(1) != 1) return -2;
    if (fib(90) != 2'880'067'194'370'816'120LL) return -3;
    for (int i = 0; i < 100; ++i)
        if (fib(i) + fib(i + 1) != fib(i + 2)) return -4;

    return 0;
}