/*
Írj programot, ami két módon kiszámítja az alábbi összeget.
(1 ≤ n ∈ N): 1 + 11 + 111 + ... + 1...1 = ?
ahol az utolsó tagban n darab 1-es szerepel.
*/
#include <stdio.h>
#include <math.h>


#define N 9


unsigned long ones(int n) {
    unsigned long res = 1;
    for (int i = 2; i <= n; ++i)
        res = res * 10 + 1;
    return res;
}

unsigned long f1(int n) {
    unsigned long sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += ones(i);
    return sum;
}

unsigned long f2(int n) {
    return ((unsigned long)pow(10, n + 1) - 9 * n - 10) / 81;
}


int main() {
    printf("f1(N): %li\n", f1(N));
    printf("f2(N): %li\n", f2(N));
}