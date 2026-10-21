#include <stdio.h>

#define MAX_LEN 256


char * firstAlphabetical(char * a, char * b){
    int i = 0;
    // A harmadik feltételben már tudjuk, hogy a két karakter egyenlő és az egyik nem nulla. Akkor kell vizsgálni, hogy a másik 0-e?
    while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0') ++i;
    if (a[i] < b[i]){
        return a;
    }
    return b;
}

int main(){
    char a[MAX_LEN];
    char b[MAX_LEN];

    scanf("%s %s", a, b);
    printf("%s\n", firstAlphabetical(a, b));
    return 0;
}