#include <stdio.h>

const long double PI = 3.14159; 

int main() {
    double A, B, C;

    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    double rectangledTriangleArea = (A * C) / 2;
    double circleArea = PI * C * C;
    double trapezoidArea = ((A + B) / 2) * C;
    double squareArea = B * B;
    double rectangleArea = A * B;

    printf("TRIANGULO: %.3lf\n", rectangledTriangleArea);
    printf("CIRCULO: %.3lf\n", circleArea);
    printf("TRAPEZIO: %.3lf\n", trapezoidArea);
    printf("QUADRADO: %.3lf\n", squareArea);
    printf("RETANGULO: %.3lf\n", rectangleArea);
 
    return 0;
}