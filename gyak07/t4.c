// 4. Készíts egy alprogramot, mely feltölt egy kapott tömböt 0 és 100 közötti véletlen **valós** értékekkel (azaz törtszámok legyenek benne). Ezután a főprogram állapítsa meg a tömbről, hogy hány eleme nagyobb 50-nél.
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define N 10


// double[]-t feltölt véletlen számokkal
void fill_d_arr(size_t size, double * a) {
    for (size_t i = 0; i < size; ++i) {
        // Egyenletes eloszlás 0-tól a felső határig
        //     |------- [0-1] ---------|   |Felső határ|
        a[i] = (double)rand() / RAND_MAX * (DBL_MAX / N);
        /*
        // Logaritmikusan egyenletes, ugyanakkora valószínűséggel lesz 0-1 között, mint 1-max között
        double mantissa = (double)rand() / RAND_MAX;
        int exp_range = (DBL_MAX_EXP - N) - DBL_MIN_EXP;
        int exponent = rand() % exp_range + DBL_MIN_EXP;
        //a[i] = mantissa * pow(2, exponent);
        a[i] = ldexp(mantissa, exponent);
        */
    }
}

// Összegez egy double[]-t 0-tól a végéig
double sum(size_t size, double * a) {
    double acc = 0;
    for (size_t i = 0; i < size; ++i) {
        acc += a[i];
    }
    return acc;
}

// Összegez egy double[]-t indexek tömbjével megadott sorrendben
double sum_rand(size_t size, double * a, size_t * perm) {
    double acc = 0;
    for (size_t i = 0; i < size; ++i) {
        acc += a[perm[i]];
    }
    return acc;
}

// Tömböt feltölt indexekkel
void fill_range(size_t size, size_t * a) {
    for(size_t i = 0; i < size; i++) {
        a[i] = i;
    }
}

// Indexek tömbjét véletlenszerűen permutálja
void shuffle(size_t size, size_t * a) {
    for(size_t i = 0; i < size-1; i++) {
        int j = rand() % (size-1-i) + i;
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

int countgt50(int size, double * tomb) {
    int db = 0;
    for (int i = 0; i < size; i++)
        if (tomb[i] > 50)
            db++;
    return db;
}

int main() {
    srand(21);
    
    double f[N];
    fill_d_arr(N, f);

    for (size_t i = 0; i < N; ++i) {
        printf("%g ", f[i]);
    }
    printf("\n");
    printf("50-nel nagyobb elemek szama: %d\n", countgt50(N, f));
    
    size_t idx[N];
    fill_range(N, idx);
    shuffle(N, idx);

    if (sum(N, f) != sum_rand(N, f, idx)) {
        printf("Az összeadás nem kommutatív!\n");
        printf("%f\n", sum(N, f));
        printf("%f\n", sum_rand(N, f, idx));
    }

    for (double acc = 1e15; acc < 1e16; acc += 1e14) {
        // Ezzel az inkrementációval végtelenes ciklust csinálnánk, nem csak nagyon hosszút
        if (acc == acc + 1) printf("%g == %g + 1\n", acc, acc + 1);
    }
    printf("Ciklus vége\n");
    
    return 0;
}