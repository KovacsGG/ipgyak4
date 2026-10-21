#include <stdio.h>
#include <limits.h>


void print_array(int * arr, size_t size) {
    for(size_t i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int a_sum(int * arr, size_t size) {
    int acc = 0;
    for (size_t i = 0; i < size; ++i)
        acc += arr[i];
    return acc;
}

// UB ha size < 1
size_t a_maxi(int * arr, size_t size) {
    int maxi = 0;
    for (size_t i = 1; i < size; ++i)
        if (arr[maxi] < arr[i]) maxi = i;
    return maxi;
}

int a_max(int * arr, size_t size) {
    return arr[a_maxi(arr, size)];
}

// https://en.wikipedia.org/wiki/Insertion_sort
void sort(int * arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (arr[i - 1] < arr[i]) continue;
        int temp = arr[i];
        arr[i] = arr[i - 1];
        size_t hole = i - 1;
        while (hole > 0 && temp < arr[hole - 1]) {
            arr[hole] = arr[hole - 1];
            --hole;
        }
        arr[hole] = temp;
    }
}

int main() {
    int tomb[] = {-1, -2, -3, -4, -5, -4, -3};
    const size_t len = sizeof(tomb) / sizeof(tomb[0]);
    
    print_array(tomb, len);

    int maxVal = a_max(tomb, len);
    int ossz = a_sum(tomb, len);
    sort(tomb, len);
    int secondMin = tomb[1];

    printf("Sum: %i\n", ossz);
    printf("Max: %i\n", maxVal);
    printf("2nd min: %i\n", secondMin);
    
    return 0;
}