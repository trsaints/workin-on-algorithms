#include <stdio.h>
 
int main() {
    long double A, B;
    
    scanf("%Lf", &A);
    scanf("%Lf", &B);
    
    long double MEDIA = ((A * 3.5f) + (B * 7.5f)) / 11;
    
    printf("MEDIA = %.5Lf\n", MEDIA);
 
    return 0;
}