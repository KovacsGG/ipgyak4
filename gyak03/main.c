#include <stdio.h>


int main() {
    
    char c = '0';
    printf("%i: %c -> %i\n", c, c, '0' - '0');
    scanf("%c", &c);
    printf("%i: %c -> %i\n", c, c, c - '0');
    int a = getchar();
    
    // A lebegőpontos számoktól numerikus számolási hibákra kell számítani.
    for (double i; i != 1; i += 0.1)
        printf("%f\n", i);
        
    return 0;
}