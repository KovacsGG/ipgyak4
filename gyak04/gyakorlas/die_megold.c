/*
Módosítsd az órai programot, hogy ne használjon if kulcsszót!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int ndie(int n){
    return rand() % n + 1;
}

int main(int argc, char * argv[]){
    
    srand(time(NULL));
    int max;
    argc == 1 ? (max = 6) : (max = atoi(argv[1]));

    printf("\n10 random dobas\n");
    for (int i = 0; i < 10; ++i){
        printf("%i ", ndie(max));
    }

    int roll = ndie(max);
    printf("\nTalald ki a 11.-ik dobast:\n");
    int guess = 0;
    do{
        scanf("%i", &guess);
        guess > max || guess < 1 ? printf("Out of bounds.\n") :
        guess > roll ? printf("A szam kisebb.\n") :
        guess < roll ? printf("A szam nagyobb.\n") : 0;
    } while (guess != roll);

    printf("Gratulalok, kitalaltad!\n");

    return 0;
}