#include <stdio.h>


int main() {
    int a[100] = {};
    // sizeof (x) típusa mindig size_t, ami alias valamilyen unsigned egész típusra. Használjuk!
    for (unsigned long i = sizeof(a) / sizeof a[0] + 1; i >= 1; --i)
        printf("%lu ", i - 1);
}