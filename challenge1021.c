#include <stdio.h>
 
int main() {
    double N;

    scanf("%lf", &N);

    int hundreds, fifties, twenies, tens, fives, twos, 
            ones, halves, quarters, dimes, nickels, pence;

    hundreds = N / 100;
    fifties = (N - (hundreds * 100)) / 50;
    twenies = (N - (hundreds * 100) - (fifties * 50)) / 20;

    tens = (N - (hundreds * 100) 
            - (fifties * 50) 
            - (twenies * 20)) 
            / 10;

    fives = (N - (hundreds * 100) 
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10)) 
            / 5;

    twos = (N - (hundreds * 100) 
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10) 
            - (fives * 5)) 
            / 2;

    ones = (N - (hundreds * 100) 
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10) 
            - (fives * 5) 
            - (twos * 2)) 
            / 1;

    halves = (N - (hundreds * 100)
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10) 
            - (fives * 5) 
            - (twos * 2)
            - ones) 
            / 0.5;

    quarters = (N - (hundreds * 100)
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10) 
            - (fives * 5) 
            - (twos * 2)
            - ones
            - (halves * 0.5)) 
            / 0.25;

    dimes = (N - (hundreds * 100)
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10) 
            - (fives * 5) 
            - (twos * 2)
            - ones
            - (halves * 0.5)
            - (quarters * 0.25)) 
            / 0.1;

    nickels = (N - (hundreds * 100)
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10) 
            - (fives * 5) 
            - (twos * 2)
            - ones
            - (halves * 0.5)
            - (quarters * 0.25)
            - (dimes * 0.1)) 
            / 0.05;
    
    pence = (N - (hundreds * 100)
            - (fifties * 50) 
            - (twenies * 20) 
            - (tens * 10) 
            - (fives * 5) 
            - (twos * 2)
            - ones
            - (halves * 0.5)
            - (quarters * 0.25)
            - (dimes * 0.1)
            - (nickels * 0.05)) 
            / 0.01;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", hundreds);
    printf("%d nota(s) de R$ 50.00\n", fifties);
    printf("%d nota(s) de R$ 20.00\n", twenies);
    printf("%d nota(s) de R$ 10.00\n", tens);
    printf("%d nota(s) de R$ 5.00\n", fives);
    printf("%d nota(s) de R$ 2.00\n", twos);

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", ones);
    printf("%d moeda(s) de R$ 0.50\n", halves);
    printf("%d moeda(s) de R$ 0.25\n", quarters);
    printf("%d moeda(s) de R$ 0.10\n", dimes);
    printf("%d moeda(s) de R$ 0.05\n", nickels);
    printf("%d moeda(s) de R$ 0.01\n", pence);

 
    return 0;
}