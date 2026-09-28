/*
Készíts egy 6 oldalú dobókocka szimuláló alprogramot! A főprogramban dobj egymás után 10-szer a kockával és írasd ki az eredményeket.
https://en.cppreference.com/c/numeric/random/rand
a) Az alprogramot fejleszd függvénnyé, ami n oldalú kocákval dob. Ha argumentummal került meghívásra a program, legyen ez n.
Kiegészítések:
b) Dobj 11-edszer is, és addig kérj tippeket a felhasználótól, amíg ki nem találja a dobott számot. Minden tipp után közöld, hogy a célszám kisebb vagy nagyobb.
c) Dícsérd meg a felhasználót, ha minden tipp legalább felezte a céltól való távolságot az előző tipphez képest!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*
int rollDice(int n)
{
    return rand() % n + 1;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    if (argc == 1)
    {
        rollDice(10);
    }
    else
    {
        rollDice(atoi(argv[1]));
    }

    return 0;
}*/

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
    int delta = max;
    bool optimal = true;
    do{
        scanf("%i", &guess);
        // optimal = optimal & ... (bitwise!)
        optimal &= abs(roll - guess) <= ceil(delta / 2.); 
        delta = abs(roll - guess);
        if (guess > max || guess < 0){
            printf("Out of bounds.\n");
        } else if (guess > roll){
            printf("A szam kisebb.\n");
        } else if (guess < roll){
            printf("A szam nagyobb.\n");
        }
    } while (guess != roll);

    printf("Gratulalok, kitalaltad!\n");
    if (optimal) printf("Strategikus tippeles!\n");

    return 0;
}