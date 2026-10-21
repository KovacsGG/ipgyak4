/*
Definiáld a Vector structot!
a) Írj függvényt, ami két Point * kap és visszaadja a különbségvektorukat
b) Írd meg az a) fv. változatát, ami kap egy Vector * is, és ebbe teszi a különbségvektort
*/
#include <stdio.h>
#include <math.h>


struct Point {
    int x;
    int y;
};

struct Vector {
    int x, y;
};

double dist(struct Point * p1, struct Point * p2) {
    // s->a == (*s).a
    int x2 = ((*p1).x - (*p2).x) * (p1->x - p2->x);
    int y2 = (p1->y - p2->y) * (p1->y - p2->y);
    return sqrt(x2 + y2);
}

struct Vector diff_vector_p1_to_p2_a(struct Point * p1, struct Point * p2) {
    struct Vector v;
    v.x = p2->x - p1->x;
    v.y = p2->y - p1->y;
    return v;
    //return (struct Vector) {p2->x - p1->x, p2->y - p1->y};
}

void diff_vector_p1_to_p2_b(struct Point * p1, struct Point * p2, struct Vector * v) {
    /*
    v->x = p2->x - p1->x;
    v->y = p2->y - p1->y;
    */
    // struct = struct esetén csak átmásolja a mezőket
    *v = diff_vector_p1_to_p2_a(p1, p2);
}

int main() {
    struct Point p1 = {2, 5};
    struct Point p2 = {.x = 2, .y = 3};
    printf("(%i, %i)\n", p1.x, p1.y);
    printf("sizeof Point: %zu\n", sizeof(struct Point));

    printf("dist: %f\n", dist(&p1, &p2));
    
    struct Vector v1 = diff_vector_p1_to_p2_a(&p1, &p2);
    struct Vector v2;
    diff_vector_p1_to_p2_b(&p1, &p2, &v2);

    printf("diff1: (%i, %i)\n", v1.x, v1.y);
    printf("diff2: (%i, %i)\n", v2.x, v2.y);

    return 0;
}