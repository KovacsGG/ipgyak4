/*
a)
Írd ki egy szám összes osztóját.

b)
Határozd meg két egész számról, hogy barátságosak-e. Két egész szám barátságos, 
ha az egyik önmagánál kisebb osztóinak összege megegyezik a másikkal, 
és fordítva. Pl.: 220 és 284
*/
#include <stdio.h>

#define MAX_DIV_COUNT 100


// sol-ban el kell férnie legalább floor(sqrt(n)) elemnek
size_t divisors(unsigned n, unsigned * sol) {
    size_t count = 0;
    // i <= sqrt(n) -> i**2 <= n
    for (unsigned i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            sol[count++] = n / i;
            if (n / i != i) sol[count++] = i;
        }
    return count;
}

void read_uint_le(unsigned * p, unsigned max) {
    do {
        printf("uint (<= %u): ", max);
        scanf("%u", p);
    } while (*p > max || *p == 0);
}

void print_divs(unsigned * p, size_t len) {
    for (size_t i = 0; i < len; i += 2)
        if (i + 1 < len) printf("%u - %u\n", p[i + 1], p[i]);
        else printf("%u\n", p[i]);
}

// Tudjuk, hogy a divs első eleme == n, a többi kisebb
unsigned sum_divs(unsigned * divs, size_t len) {
    unsigned sum = 0;
    for (size_t i = 1; i < len; ++i)
        sum += divs[i];
    return sum;
}

int main() {
    unsigned a, b;
    unsigned divs_a[MAX_DIV_COUNT], divs_b[MAX_DIV_COUNT];
    read_uint_le(&a, MAX_DIV_COUNT * MAX_DIV_COUNT);
    read_uint_le(&b, MAX_DIV_COUNT * MAX_DIV_COUNT);

    size_t ndivs_a = divisors(a, divs_a);
    size_t ndivs_b = divisors(b, divs_b);

    printf("Divisors of %u:\n", a);
    print_divs(divs_a, ndivs_a);
    printf("Divisors of %u:\n", b);
    print_divs(divs_b, ndivs_b);

    unsigned sum_divs_a = sum_divs(divs_a, ndivs_a);
    unsigned sum_divs_b = sum_divs(divs_b, ndivs_b);
    printf("Sum of divisors < %u: %u\n", a, sum_divs_a);
    printf("Sum of divisors < %u: %u\n", b, sum_divs_b);
    if (sum_divs_a == b && sum_divs_b == a) printf("They are amicable\n");

    return 0;
}