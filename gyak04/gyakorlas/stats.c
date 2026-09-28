/*
Fejleszd tovább az órai programot,
a) hogy kiírja a legkisebb és legnagyobb számot is!
b) hogy kiírja a pozitív és a negatív számok előfordulásának számát!
c) hogy növekvő sorrendbe rendezze a számokat!
d) szervezd a rendezést külön függvénybe! 
*/
#include <stdio.h>
#include <stdlib.h>
 

int main(void) {

  char input[20];
  int sum = 0;
  int count = -1;

  do {
    scanf("%19s", input);
    sum += atoi(input);
    count++;
  } while (input[0] != 'q');

  printf("sum=%d\tcount=%d\tavg=%f\n",
    sum,
    count,
    sum / (float)count
  );
}
 