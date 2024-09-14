#include <stdio.h>
 
int main() {
    float A, B, C;
    int is_triangle;

    scanf("%f %f %f", &A, &B, &C);


    if ((A + B <= C) || (A + C <= B) || (B + C <= A)) {
        is_triangle = 0;
    }
    else {
        is_triangle = 1;
    }


    if (is_triangle) {
        float perimeter = A + B + C;

        printf("Perimetro = %.1f\n", perimeter);
    }
    else {
        float trapezoid_area = ((A + B) * C) / 2;

        printf("Area = %.1f\n", trapezoid_area);
    }
 
    return 0;
}