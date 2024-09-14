#include <stdio.h>
#include <math.h> 

int main() {
    double A, B, C;

    scanf("%lf %lf %lf", &A, &B, &C);

    if (A >= (B + C)
        || B >= (A + C)
        || C >= (A + B)) {
        printf("NAO FORMA TRIANGULO\n");
    } else if (pow(A, 2) == (pow(B, 2) + pow(C, 2))
               || pow(C, 2) == (pow(A, 2) + pow(B, 2))
               || pow(B, 2) == (pow(A, 2) + pow(C, 2))) {
        printf("TRIANGULO RETANGULO\n");
    } else if (pow(A, 2) > (pow(B, 2) + pow(C, 2))
               || pow(B, 2) > (pow(A, 2) + pow(C, 2))
               || pow(C, 2) > (pow(A, 2) + pow(B, 2))) {
        printf("TRIANGULO OBTUSANGULO\n");
    } else if (pow(A, 2) < (pow(B, 2) + pow(C, 2))
               || pow(B, 2) < (pow(A, 2) + pow(C, 2))
               || pow(C, 2) < (pow(A, 2) + pow(B, 2))) {
        printf("TRIANGULO ACUTANGULO\n");
    }
    
    if (A == B && B == C) {
        printf("TRIANGULO EQUILATERO\n");
    } else if ((A == B && B != C) 
               || (A != B && B == C) 
               || (A == C && B != C)) {
        printf("TRIANGULO ISOSCELES\n");
    }
 
    return 0;
}