/*
a)
Írj programot, ami bekér egy számot és megfordítja azt.
Csak aritmetikai műveleteket használj.
Pl.: 12345 -> 54321

b)
Vizsgáld meg egy számról, hogy palindrom-e. A megoldáshoz csak
aritmetikai műveleteket használj.
Pl.: 12321 palindrom, de 12345 nem az.
*/
#include <stdio.h>


int reverse(int n) {
    int res = 0;
    for (int i = 1; n / i != 0; i *= 10) {
        res *= 10;
        res += n / i % 10;
    }
    return res;
}

int digits(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        ++count;
    }
    return count;
}

bool is_palindrome(int n) {
    int hi;
    for (hi = 1; n / hi != 0; hi *= 10);
    hi /= 10;
    for (int lo = 1; hi >= lo; lo *= 10, hi /= 10) {
        if (n / lo % 10 != n / hi % 10) return false;
    }
    return true;
}

bool is_palindrome2(int n) {
    return n == reverse(n);
}

int main() {
    int n;
    printf("Pick a number: ");
    scanf("%i", &n);

    printf("Reverse: %0*i\n", digits(n), reverse(n));
    if (is_palindrome(n)) printf("Is a palindrome\n");
}