/*
Módosítsd az órai programot, hogy ne használjon if kulcsszót!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int rolldie(int n){
    return rand() % n + 1;
}

int main(int argc, char * argv[]){
    
    srand(time(NULL));
    int max;
    if (argc == 1){
        max = 6;
    } else {
        max = atoi(argv[1]);
    }

    printf("\n10 random dobas\n");
    for (int i = 0; i < 10; ++i){
        printf("%i ", rolldie(max));
    }

    int roll = rolldie(max);
    printf("\nTalald ki a 11.-ik dobast:\n");
    int guess = 0;
    do{
        scanf("%i", &guess);
        if (guess > max || guess < 0){
            printf("Out of bounds.\n");
        } else if (guess > roll){
            printf("A szam kisebb.\n");
        } else if (guess < roll){
            printf("A szam nagyobb.\n");
        }
    } while (guess != roll);

    printf("Gratulalok, kitalaltad!\n");

    return 0;
}