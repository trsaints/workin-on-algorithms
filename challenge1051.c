#include <stdio.h>
 
#define TAX_TIER_1 0.08f
#define TAX_TIER_2 0.18f
#define TAX_TIER_3 0.28f


int main() {
    float base_income;

    scanf("%f", &base_income);

    float tax_total = 0;

    int has_overflow = (base_income - 2000.00f) > 1000;

    if (base_income >= 2000.01f) {
        if (has_overflow) {
            tax_total = 1000.00 * TAX_TIER_1;
        } else {
            tax_total = (base_income - 2000.00f) * TAX_TIER_1;
        }
    }

    has_overflow = (base_income - 3000.00f) > 1500;

    if (base_income >= 3000.01f) {
        if (has_overflow) {
            tax_total += 1500 * TAX_TIER_2;
        } else {
            tax_total += (base_income - 3000.00f) * TAX_TIER_2;
        }
    }

    if (base_income >= 4500.00f) {
        tax_total += (base_income - 4500.00f) * TAX_TIER_3;
    }

    if (tax_total == 0) {
        printf("Isento\n");
    } else {
        printf("R$ %.2f\n", tax_total);
    }

 
    return 0;
}