#include <stdio.h>
 
int main() {
    int product1Code,
        product1Units, 
        product2Code,
        product2Units;

    double product1Price, product2Price;

    scanf("%d", &product1Code);
    scanf("%d", &product1Units);
    scanf("%lf", &product1Price);
    
    scanf("%d", &product2Code);
    scanf("%d", &product2Units);
    scanf("%lf", &product2Price);

    double total = (product1Price * product1Units) + (product2Price * product2Units);

    printf("VALOR A PAGAR: R$ %.2lf\n", total);
 
    return 0;
}