// 4. Módosítsd a múlt órai összegző függvényt, hogy a `[]` operátor használata nélkül, pointer aritmetika segítségével működjön. Ki lehet találni a tömb méretét a függvényen belül a hosszt tartalmazó változó nélkül?
// 5. Írjuk meg az előző függvény egy változatát, ami első elemre mutató mutató, és utolsó elem után mutató mutató segítségével kapja meg a tömböt. Mi történik, ha túlindexelünk eggyel? Mi történik, ha többel indexelünk túl?
// 6. Írjunk függvényt, ami átlagot számol. Hogyan tudjuk kiszámolni a tömb méretét a mutatópárból?
// 7. Két azonos tömbön belülre mutató mutató közül melyik mutat kisebb indexű elemre?
#include <stdio.h>


int a_sum(int * arr, size_t size) {
    int acc = 0;
    for (size_t i = 0; i < size; ++i)
        acc += *(arr + i);
    return acc;
}

int a_sum2(int * begin, int * end) {
    int acc = 0;
    /*
    for (; begin < end; ++begin)
        acc += *begin;
    */
    // *++begin miért nem jó?
    while (begin < end)
        acc += *begin++;
    return acc;
}

int main() {
    int array[] = {3, 5, 4};
    printf("array (%p)\tarray+1 (%p)\n", (void*)array, (void*)(array + 1));
    // a[i] == *(a + i)
    printf("Sum: %i\n", a_sum(array, 3));
    printf("Sum: %i\n", a_sum2(array, array + 3));
    return 0;
}