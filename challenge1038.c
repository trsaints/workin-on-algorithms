#include <stdio.h>
 
int main() {
    int X, Y;

    float unit_cost;

    scanf("%d %d", &X, &Y);

    switch (X)
    {
        case 1:
            unit_cost = 4.00;

            break;

        case 2:
            unit_cost = 4.50;

            break;

        case 3:
            unit_cost = 5.00;

            break;

        case 4:
            unit_cost = 2.00;

            break;

        case 5:
            unit_cost = 1.50;

            break;
    }

    float total = unit_cost * Y;

    printf("Total: R$ %.2f\n", total);

    return 0;
}