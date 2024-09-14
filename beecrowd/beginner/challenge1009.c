#include <stdio.h>
 
int main() {
    char sellerName[128];
    
    double baseIncome, monthlySales;

    scanf("%s", sellerName);
    scanf("%lf", &baseIncome);
    scanf("%lf", &monthlySales);

    double totalIncome = baseIncome + (monthlySales * 0.15);

    printf("TOTAL = R$ %.2lf\n", totalIncome);

    return 0;
}