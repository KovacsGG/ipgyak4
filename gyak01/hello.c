#include <stdio.h>


int main() {
    // https://en.cppreference.com/c/io/fprintf
    printf("Hello, World!\n");

    // Több sorban több módon
    // 1
    printf("Hello,\n");
    printf("World!\n");
    // 2, ezt preferáljuk
    printf("Hello,\nWorld!\n");

    return 0;
}