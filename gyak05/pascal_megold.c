// Roland megoldása, feladat a negyedik hétről

#include <stdio.h>
#include <stdlib.h>


unsigned long long fact(int n, int m) {
    // rekurzió
    /*
    if (n > m) {
        return n*fact(n-1,m);
    } else {
        return 1;
    }
    */
    // iteráció
    unsigned long long x = 1;
    for (int i = n; i > m;i--) {
        x *= i;
    }
    return x;
}

unsigned long long nCr(int n,int k) {
    if (k > n/2) {
        return nCr(n,n-k);
    } else {
        return fact(n,n-k)/fact(k,0);
    }
}

int main(int argc, char * argv[]) {
    if (argc == 2) {
        printf("jo\n");
        int n = atoi(argv[1]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j<=i; j++) {
                printf("%lld ",nCr(i,j));
            }
            printf("\n");
        }
    } else {
        printf("Wrong number of arguments!");
    }

    return 0;
}