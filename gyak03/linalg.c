#include <stdio.h>

#define PI 3.1415


int main() {
    /*
    double r;
    scanf("%lf", &r);
    printf("Diameter: %.2f\n", 2 * r);
    printf("Perimeter: %.2f\n", 2 * r * PI);
    printf("Area: %.2f\n", r * r * PI);

    double px, py;
    scanf("%lf %lf", &px, &py);
    double d2 = px * px + py * py;

    if(d2 <= r * r) printf("Inside\n");
    else printf("Outside\n");
    */

    /*
    double qx;
    double qy;
    double px;
    double py;
    double ax;
    double ay;
    double bx;
    double by;
    scanf("%lf %lf", &qx, &qy);
    scanf("%lf %lf", &px, &py);
    scanf("%lf %lf", &ax, &ay);
    scanf("%lf %lf", &bx, &by);
 
    double v1x =qx-px;
    double v1y =qy-py;
 
    double v2x =ax-bx;
    double v2y =ay-by;
 
    if(v1x*v2x+v1y*v2y==0){
        printf("Merőleges\n");
    }
    else{
        printf("Nem merőleges\n");
 
    }
    */
 
    double px, py, qx, qy, rx, ry, sx, sy;
    double ax, ay, bx, by;
    double m1, m2;
 
    printf("Px Py Qx Qy: ");
    scanf("%lf %lf %lf %lf", &px, &py, &qx, &qy);
    printf("Rx Ry Sx Sy: ");
    scanf("%lf %lf %lf %lf", &rx, &ry, &sx, &sy);
 
    ax = qx - px;
    ay = qy - py;
    bx = sx - rx;
    by = sy - ry;
 
    // Ha ax vagy bx 0, akkor bajban vagyunk. Milyen hibát kapunk?
    m1 = ay / ax;
    m2 = by / bx;
 
    if (m1 * m2 == -1)
        printf("Merőlegesek.\n");
    else
        printf("Nem merőlegesek.\n");
 
 

    return 0;
}