#include <stdio.h>
 
int main() {
    double A, B, C;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
    
    double MEDIA = (A * 0.2f) + (B * 0.3f) + (C * 0.5f); 
    
    printf("MEDIA = %.1lf\n", MEDIA);
 
    return 0;
}