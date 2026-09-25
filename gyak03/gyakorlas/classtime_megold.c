/*
Írj programot, ami bekéri, hogy hány perccel korábban kell befejezni az órát
és a pillanatnyi időt, majd kiírja, hogy mennyivel korábban kell befejezni
a következő órát!
*/
#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Time: ");
    int h, m;
    scanf("%i:%i", &h, &m);
    printf("Class is shorter by: ");
    int d;
    scanf("%i", &d);

    int actualDuration = (h - 8) * 60 + m - 30 - 5;
    int supposedDuration = 3 * 45 - d;
    int delta = actualDuration - supposedDuration; // Ennyivel rövidebb a kövi

    printf("Next class is %i minutes %s!\n",
        abs(delta), delta < 0 ? "longer" : "shorter");

}