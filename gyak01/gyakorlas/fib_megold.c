/*
Haladóknak!
Írj programot, amely kiírja az első n Fibonacci-számot, ahol
fib(0) == 0, fib(1) == 1
*/
 
#include <stdio.h>

int main() {
    int n = 10;

    int a, b, c;
    a = b = 1;
    printf("%d\n%d\n", a, b);
    for (int i = 2; i < n; ++i) {
        c = a + b;
        a = b;
        b = c;
        printf("%d\n", c);
    }

    return 0;
}