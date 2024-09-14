#include <stdio.h>
#include <math.h>

int main() {
    double x1, x2, y1, y2;

    scanf("%lf", &x1);
    scanf("%lf", &y1);

    scanf("%lf", &x2);
    scanf("%lf", &y2);

    double first_root = pow(x2 - x1, 2);
    double second_root = pow(y2 - y1, 2);

    double distance = sqrt(first_root + second_root);

    printf("%.4lf\n", distance);

    return 0;
}