#include <stdio.h>
 
int main() {
    unsigned int days;

    scanf("%d", &days);

    unsigned int years, months, remainder_days;

    years = days / 365;
    months = (days - (years * 365)) / 30;
    remainder_days = days - (years * 365) - (months * 30);

    printf("%d ano(s)\n", years);
    printf("%d mes(es)\n", months);
    printf("%d dia(s)\n", remainder_days);

    return 0;
}