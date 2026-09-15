#include <stdio.h>


// fv. deklaráció
int is_even(int n);

int main() {
    // Csak deklaráció. Ilyenkor statikus élettartamú is lesz (l. majd előadás)
    // extern int n;

    // változó deklaráció és definíció
    int n;

    // inicializálatlan változó használata. HIBA!
    printf("%d", n);

    scanf("%d", &n);
    if (is_even(n))
        printf("Even\n");
    else
        printf("Odd\n");
    
    return 0;
}