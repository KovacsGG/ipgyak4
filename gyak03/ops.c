#include <stdio.h>


void printb(char b) {
    for (int i = 0; i < 8; ++i)
        printf("%i", (b >> i) % 2);
}

int main(){
    /*
    int a, b;

    scanf("%i %i", &a, &b);
    printf("%i\n", a + b);
    printf("%i\n", a - b);
    printf("%i\n", a * b);
    printf("%i\n", a / b);
    printf("%i\n", a % b);
    printf("%i\n", -a);
    printf("%i\n", +a);
    */

    /*
    a  b    a && b
    1  1    1
    1  0    0 
    0  1    0
    0  0    0
    */
    char a = 5, b = 100;
    //     a: 00000101
    //     b: 11000100
    // a & b: 00000100 == 4
    printf("%i\n", a && b); // 1
    printf("%i\n", a & b); // 4
    // C23-ban ilyen is van, de sok rendszeren még nem támogatott.
    //printf("%08b\n", a);
    // Írjunk egy sajátot
    printf("a:   "); printb(a);
    printf("\n");
    printf("b:   "); printb(b);
    printf("\n");
    printf("a|b: "); printb(a|b);  // Logikai: ||
    printf("\n");
    printf("a^b: "); printb(a^b);
    printf("\n");
    // Aritmetikai műveletekkel kifejezhető?
    printf("~a:  "); printb(~a); // Logikai: !
    
    //            a                 , b
    a = a + b; // a + b             , b
    b = b - a; // a + b             , b - a - b
    a = a + b; // a + b + b - a - b , b - a - b == -a
    b = -b;    // b                 , a

    // XOR azonosságai
    // (a ^ b) ^ c == a ^ (b ^ c)
    // x ^ 0 == x
    // x ^ x == 0 
    // x ^ y ^ y == x

    // Hasonlóan
    // a , b
    // a , a ^ b
    // a ^ a ^ b == b , a ^ b
    // b , a ^ b ^ b == a


    return 0;
}