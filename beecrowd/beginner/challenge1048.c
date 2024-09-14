#include <stdio.h>

const float READJUSTMENT_TIER_5 = 0.04;
const float READJUSTMENT_TIER_4 = 0.07;
const float READJUSTMENT_TIER_3 = 0.10;
const float READJUSTMENT_TIER_2 = 0.12;
const float READJUSTMENT_TIER_1 = 0.15;

int main() {
    float base_income;

    scanf("%f", &base_income);

    float readjustment;

    if (base_income > 2000) {
        readjustment = base_income * READJUSTMENT_TIER_5;
    } else if (base_income > 1200) {
        readjustment = base_income * READJUSTMENT_TIER_4;
    } else if (base_income > 800) {
        readjustment = base_income * READJUSTMENT_TIER_3;
    } else if (base_income > 400) {
        readjustment = base_income * READJUSTMENT_TIER_2;
    } else if (base_income > 0) {
        readjustment = base_income * READJUSTMENT_TIER_1;
    }

    printf("Novo salario: %.2f\n", base_income + readjustment);
    printf("Reajuste ganho: %.2f\n", readjustment);
    printf("Em percentual: %.0f \%\n", (readjustment * 100) / base_income);

    return 0;
}
