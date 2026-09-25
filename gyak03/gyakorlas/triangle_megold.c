/*
Olvasd be egy egyenlő szárú háromszög oldalait, és amennyiben
a háromszög felrajzolható, számold ki a területét és kerületét!
*/
#include <stdio.h>
#include <math.h>


int main() {
    double a, b;
    printf("Base: ");
    scanf("%lf", &b);
    printf("Legs: ");
    scanf("%lf", &a);

    if (2 * a <= b) return -1;
    printf("Perimeter: %f\n", 2 * a + b);
    const double m = sqrt(a * a - b * b / 4);
    printf("Area: %f\n", b / 2 * m);

    return 0;
}