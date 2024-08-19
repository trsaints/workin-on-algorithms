#include <stdio.h>
 
int main() {
    int time_spent, average_speed;

    scanf("%d", &time_spent);
    scanf("%d", &average_speed);

    int distance = time_spent * average_speed;
    float estimated_fuel_amount = distance / 12.0f;

    printf("%.3f\n", estimated_fuel_amount);
 
    return 0;
}