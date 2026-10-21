/*
Írj programot, amely egy egészeket tároló tömb második legkisebb elemét írja ki!
*/
#include <stdio.h>
#include <limits.h>
/*    
    int a[] = {-1, -2, -3, -4, -5};
    int n = sizeof(a) / sizeof(a[0]);

    // Rendezés után kiírjuk a második elemet
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("%d\n", a[1]);
*/

int main() {
    int tomb[] = {-1, -2, -3, -4, -5, -4, -3};
    const int len = sizeof(tomb) / sizeof(tomb[0]);
    
    for (int i = 0; i < len; i++) {
        printf("%d ", tomb[i]);
    }

    int maxVal = tomb[0];
    int minVal = tomb[0];
    int minInd = 0;
    int secondMin = INT_MAX;
    for (int i = 0; i < len; i++) {
        if(tomb[i] > maxVal) {
            maxVal = tomb[i];
        }
        if(tomb[i] < minVal) {
            minVal = tomb[i];
            minInd = i;
        }
    }
    // Ezzel nem ismerjük fel, amikor egy elemű a tömb, és nincs második min.
    // Ahogy Programozáson, egy logikai változóval jelezhetnénk, hogy érvényes-e az eredmény
    for (int i = 0; i < len; i++) {
        if(tomb[i] < secondMin && i != minInd) {
            secondMin = tomb[i];
        }
    }
    printf("Max: %i\n", maxVal);
    printf("2nd min: %i\n", secondMin);
    
    return 0;
}