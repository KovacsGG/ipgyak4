#include <stdio.h>
#include <stdlib.h>

#define N 10

// 1. Készíts egy alprogramot, amely egy paraméterben kapott nxn-es mátrixot feltölt az n-es szorzótábla értékeivel. Majd írasd ki a főprogramban az egészet a standard kimenetre a következő formátumban: *a x b = c*, ahol *a* és *b* a szorzandó elemek, *c* pedig a mátrixban tárolt érték.

//3. Írj programot, amely tárolja, majd kiírja egy számnak az első n darab hatványát (szám a 0.-ontól egészen a szám az n.-enig)! A számot olvasd be parancssori argumentumként. A program készüljön fel arra az esete is, ha nem érkezik külső argumentum.

typedef struct {
    int x, y;
} Pair;

// Itt A típusa int (*A)[cols], tehát *A-é int[cols], VLA
void multi_t(int rows, int cols, int A[rows][cols]) {
    for (int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            A[i][j] = (i+1) * (j+1);
}

void multi_t2(int rows, int cols, int * A) {
    for (int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            // Vegyük észre, hogy egymást követő elemeket veszünk a tömbből. Ez jelentősen gyorsabb nagy tömbök esetén, mintha lefelé haladva egy-egy oszlopon egy egész sornyi elem lenne két elérés között.
            A[i * cols + j] = (i+1) * (j+1);
}

/*
  x->
y 1 2 3
| 4 5 6
ˇ 7 8 9 
*/
int yx_to_i(size_t y, size_t x, size_t cols) {
  return y * cols + x;
}

Pair i_to_coords(size_t i, size_t cols) {
  return (Pair) {.y = i / cols, .x = i % cols};
}


// Írjuk át, hogy N elemű tömböt töltsön fel, aztán ezt írjuk ki!
void print_powers(int base, int n) {
  long long acc = 1;
  for (int i = 1; i <= n; ++i) {
    acc *= base;
    printf(" %lld", acc);
  }
}

int main(int argc, char *argv[]) {
  int x;
  if (argc > 1)
    x = atoi(argv[1]);
  else {
    //fprintf(stderr, "Not enough arguments\n");
    //return -1;
    x = 5;
  }

  print_powers(x, N);

  int a[N][N];
  int b[N * N];
  multi_t(N, N, a);
  multi_t2(N, N, b);

  /*
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      printf("%d * %d = %d\t", i+1, j+1, b[i * N + j]);
    printf("\n");
  }
  */

  return 0;

}