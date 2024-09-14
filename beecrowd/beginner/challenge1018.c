#include <stdio.h>
 
int main() {
    unsigned int N;

    scanf("%d", &N);

    printf("%d\n", N);

    unsigned int hundreds, fifties, twenies, tens, fives, twos, ones;

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

    printf("%d nota(s) de R$ 100,00\n", hundreds);
    printf("%d nota(s) de R$ 50,00\n", fifties);
    printf("%d nota(s) de R$ 20,00\n", twenies);
    printf("%d nota(s) de R$ 10,00\n", tens);
    printf("%d nota(s) de R$ 5,00\n", fives);
    printf("%d nota(s) de R$ 2,00\n", twos);
    printf("%d nota(s) de R$ 1,00\n", ones);
 
    return 0;
}