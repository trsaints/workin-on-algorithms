#include <stdio.h>
 
int main() {
 
    int employeeNumber, workedHours;
    float valuePerHour;

    scanf("%d", &employeeNumber);
    scanf("%d", &workedHours);
    scanf("%f", &valuePerHour);
 
    float salary = workedHours * valuePerHour;

    printf("NUMBER = %d\n", employeeNumber);
    printf("SALARY = U$ %.2f\n", salary);

    return 0;
}