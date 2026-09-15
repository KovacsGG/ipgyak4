#include <stdio.h>
#include <stdbool.h>


int main() {
    // egész típusok
    // min. 8 bit
    char c = 4;
    unsigned char uc;
    signed char sc;

    // min. 16 bit
    short s; // short int, signed short int...
    unsigned short us;

    // min. 16 bit
    int i = 5; // signed int
    unsigned int ui; // unsigned

    // min. 32 bit
    long l;
    unsigned long ul;

    // min. 64 bit
    long long ll;
    unsigned long long ull;
    // sorrend compilert nem érdekli, de másokat igen
    long int long unsigned ull2;
    
    printf("sizeof c (%hhi): %zu\n", c, sizeof c); // sizeof (char)
    printf("sizeof sc (%hhi): %zu\n", sc, sizeof sc); // sizeof (signed char)
    printf("sizeof uc (%hhu): %zu\n", uc, sizeof uc); // sizeof (unsigned char)

    printf("sizeof s (%hi): %zu\n", s, sizeof s);
    printf("sizeof us (%hu): %zu\n", us, sizeof us);

    printf("sizeof i (%i): %zu\n", i, sizeof i);
    printf("sizeof ui (%u): %zu\n", ui, sizeof ui);

    printf("sizeof l (%li): %zu\n", l, sizeof l);
    printf("sizeof ul (%lu): %zu\n", ul, sizeof ul);

    printf("sizeof ll (%lli): %zu\n", ll, sizeof ll);
    printf("sizeof ull (%llu): %zu\n", ull, sizeof ull);
    printf("sizeof ull2 (%llu): %zu\n", ull2, sizeof ull2);

    // lebegőpontos típusok
    float f;
    double d;
    long double ld;

    // printf-ben mindegy, hogy %f vagy %lf, de scanf-ben nem
    printf("sizeof f (%f): %zu\n", f, sizeof f);
    printf("sizeof d (%lf): %zu\n", d, sizeof d);
    printf("sizeof ld (%Lf): %zu\n", ld, sizeof ld);

    // [C99-C23): #include <stdbool.h> vagy _Bool és 0/1
    // C23: just works
    bool b = true;

    // Tömb típusok
    int ia[5] = {0}; // típusa int[5]

    // Warning: int < unsigned long összehasonlítás a for fejében.
    // size_t: sizeof kifejezés típusa, reprezentálni tudja a legnagyobb
    // objektum méretét (size_t i = 0;)
    for (int i = 0; i < sizeof ia / sizeof ia[0]; ++i)
        printf("%i\n", ia[i]);

    printf("sizeof ia: %zu\n", sizeof ia);
    
    char ca1[] = "shell";
    char ca2[] = {'s', 'h', 'e', 'l', 'l', 0};
    printf("sizeof ca1: %zu\n", sizeof ca1);
    printf("sizeof ca2: %zu\n", sizeof ca2);

    // Pointer típusok
    int * ip = &i; // & : int -> int *
    printf("%p -> %i\n", (void *)ip, *ip); // * : int * -> int
    *ip = 7;
    printf("%p -> %i(%i)\n", (void *)ip, *ip, i);


    return 0;
}