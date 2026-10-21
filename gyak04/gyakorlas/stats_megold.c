/*
Fejleszd tovább az órai programot,
a) hogy kiírja a legkisebb és legnagyobb számot is!
b) hogy kiírja a pozitív és a negatív számok előfordulásának számát!
c) hogy növekvő sorrendbe rendezze a számokat!
d) szervezd a rendezést külön függvénybe! 
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
#define MAX_COUNT 32


void bubble_sort(int * array, size_t size) {
  for (size_t j = size - 1; j > 0; --j)
    for (size_t i = 0; i < j; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
}

int main(void) {

  char input[20];
  int sum = 0;
  int min = INT_MAX;
  int max = INT_MIN;
  int count, pos_count, neg_count;
  pos_count = neg_count = 0; 

  int nums[MAX_COUNT];

  for (count = 0; count < MAX_COUNT; ++count) {
    scanf("%19s", input);
    if (input[0] == 'q') break;
    const int n = atoi(input);
    
    sum += n;
    if (n < min) min = n;
    if (max < n) max = n;

    if (n < 0) ++neg_count;
    if (0 < n) ++pos_count;

    nums[count] = n;
  }

  printf("sum=%d\tmin=%d\tmax=%d\tcount=%d\tpos=%d\tneg=%d\tavg=%f\n",
    sum, min, max,
    count, pos_count, neg_count,
    sum / (float)count
  );
  bubble_sort(nums, count);
  for (int i = 0; i < count; ++i)
    printf("%i ", nums[i]);
  printf("\n");

  return 0;
}
 