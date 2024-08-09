#include <stdio.h>
#include <math.h>

const long double PI = 3.14159;

int main() {
    long double R;

    scanf("%Lf", &R);

    long double sphereVolume = (4.0/3) * PI * pow(R, 3);

    printf("VOLUME = %.3Lf\n", sphereVolume);
 
    return 0;
}