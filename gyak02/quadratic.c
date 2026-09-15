#include <stdio.h>
#include <math.h>


void solve(double a, double b, double c, double sol[2]) {
    // Tömb argumentumok kezelése speciális
    //printf("sizeof sol: %zu\n", sizeof sol);
    
    double d = b * b - 4 * a * c;
    sol[0] = (sqrt(d) - b) / (2 * a);
    if (d != 0)
        sol[1] = (-sqrt(d) - b) / (2 * a);
}

int main() {
    double a, b, c;
    printf("Coefficients [a b c]: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double sol[2] = {NAN, NAN};
    solve(a, b, c, sol);

    if (!isnan(sol[0]))
        printf("x1: %f\n", sol[0]);
    if (!isnan(sol[1]))
        printf("x2: %f\n", sol[1]);
    
    return 0;
}