/*
a) Rajzold ki a Pascal háromszög első n sorát (n-et kérd be)!
b) Módosítsd a programot, hogy parancssori argumentumokkal megadható legyen a szám. Figyelj oda, hogy a program akkor is jól működjön, ha nem érkezett külső argumentum, ilyenkor utólagos beolvasással pótolja a hiányt!
*/
#include <stdio.h>
#include <stdlib.h>


int product(int from, int to) {
    int res = 1;
    for (int i = from; i <= to; ++i)
        res *= i;
    return res;
}

int factorial(int n) {
    /*
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
    */
   return product(1, n);
}

int pascal(int n, int m) {
    // return factorial(n) / factorial(m) / factorial(n - m);
    if (m > n / 2) return product(m + 1, n) / factorial(n - m);
    else return product(n - m + 1, n) / factorial(m);
}

int main(int argc, char** argv) {
    int n;
    if (argc > 1)
        n = atoi(argv[1]);
    else
        scanf("%i", &n);
    
    for (int row = 0; row < n; ++row) {
        for (int i = 0; i <= row; ++i)
            printf("%i ",pascal(row, i));
        printf("\n");
    }
    
    return 0;
}