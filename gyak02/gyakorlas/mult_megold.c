/*
Írj ki egy 10x10-es szorzótáblát. Az egy sorban lévő számokat tabulátorral 
válaszd el.
*/
#include <stdio.h>


int main() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j)
            printf("%d\t", j * i);
        printf("\n");
    }
}