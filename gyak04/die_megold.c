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


int ndie(int n){
    // Véletlen egész tartományból: a <= rand() % (b - a + 1) + a <= b
    // Vagy a <= rand() % (b - a) + a < b
    return rand() % n + 1;
}

int main(int argc, char * argv[]){
    
    // void srand(unsigned int);
    // time_t time(time_t *);
    // typedef long int time_t;
    // Pontosságot veszítő konverzió lehet, de nekünk itt pont nem számít az sem.
    srand(time(NULL));
    int max;
    if (argc > 1){
        max = atoi(argv[1]);
    } else {
        max = 6;
    }

    printf("\n10 random dobas\n");
    for (int i = 0; i < 10; ++i){
        printf("%i ", ndie(max));
    }

    // b)
    int target = ndie(max);
    printf("\nTalald ki a 11.-ik dobast:\n");
    int guess;
    int delta = max;
    bool optimal = true;
    do{
        scanf("%i", &guess);
        // optimal = optimal & ... (bitwise!)
        optimal &= abs(target - guess) * 2 <= delta; 
        delta = abs(target - guess);
        if (guess > max || guess < 1){
            printf("Out of bounds.\n");
        } else if (guess > target){
            printf("A szam kisebb.\n");
        } else if (guess < target){
            printf("A szam nagyobb.\n");
        }
    } while (guess != target);

    printf("Gratulalok, kitalaltad!\n");
    // Ehhez szerencse is kell. Az igazán stratégikus tippelés az lenne, ha mindig az addig nem kizárt tartományt felezné a tipp!
    if (optimal) printf("Strategikus tippeles!\n");

    return 0;
}