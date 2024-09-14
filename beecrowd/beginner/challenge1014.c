#include <stdio.h>

int main() {
    int x;
    float y;

    scanf("%d", &x);
    scanf("%f", &y);

    float result = (float) x / y;

    printf("%.3f km/l\n", result);

    return 0;
}