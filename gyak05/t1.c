/*
Írj programot, amely egy (a programkódban) megadott méretű tömböt feltölt nullákkal!
*/
#include <stdio.h>

#define LEN 10


int main() {
    int tomb[LEN] = {0}; // 0 inicializált

    // Vagy így is lehet
    for(int i = 0; i < LEN; i++) {
        printf("%d ", tomb[i]);
    }
    return 0;
}