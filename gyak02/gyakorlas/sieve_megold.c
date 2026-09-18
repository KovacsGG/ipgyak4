/*
Írd ki 1000-ig a prímeket Eratoszthenész szitáját használva.
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/
#include <stdio.h>

#define N 1000


int main() {
    // Növekvő számsor [2, N]
    int nums[N - 1];
    for (int i = 2; i <= N; ++i)
        nums[i - 2] = i;
        
    // Szitálás
    for (int i = 0; i < N - 1; ++i) {
        if (nums[i] == 0) continue;
        for (int j = i + nums[i]; j < N - 1; j += nums[i])
            nums[j] = 0;
    }

    // Kiírás
    printf("%d", nums[0]);
    for (int i = 0; i < N - 2; ++i)
        if (nums[i] != 0) printf(", %d", nums[i]);
    printf("\n");
    
    return 0;
}