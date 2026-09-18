/*
Haladóknak!
Írj programot, amely megszakításig írja ki a prím sorszámú Fibonacci-számokat.
*/

#include <stdio.h>

// Keressünk osztókat a szám gyökéig
bool is_prime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int a, b, c;
    a = b = 1;
    printf("%d\n", b);
    int i = 3;
    while (true) {
        c = a + b;
        a = b;
        b = c;
        if (is_prime(i))
            printf("%d\n", c);
        ++i;
    }

}