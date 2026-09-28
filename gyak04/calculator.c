#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]) {
    // Úgynevezett őrfeltétel. Ha nem teljesül, inkább hagyjuk az egészet.
    if (argc != 4) {
        printf("Not enough arguments!\n");
        return -1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    // argv típusa char ** (mert fv paraméter deklarációban van, amúgy tömb is lehetne!)
    // *argv típusa char * (ilyenekben (és char[]-ban) tároljuk a stringeket)
    // **argv típusa char
    // argv[a] == *(argv + a)
    // argv[2][0] == *(argv[2] + 0) == *(*(argv + 2) + 0)
    char o = argv[2][0];

    switch (o) {
        case '+': printf("%i\n", a + b); break;
        case '-': printf("%d\n", a - b); break;
        case '*': printf("%i\n", a * b); break;
        // Vegyük észre, hogy az összes case együtt egy blokk, ezek csak címkék. Ezért csurog át a végrehajtás a következő case-be break nélkül.
        case '/':
            if (b == 0) return -2;
            printf("%i\n", a / b);
            break;
        case '%': printf("%i\n", a % b); break;
    }

    return 0;
}