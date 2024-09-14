#include <stdio.h>
 
int main() {
    float N;

    scanf("%f", &N);

    if (N < 0 || N > 100) {
        printf("Fora de intervalo\n");

        return 0;
    }

    if (N > 75 && N <= 100) {
        printf("Intervalo (75,100]");
    }
    else if (N > 50 && N <= 75) {
        printf("Intervalo (50,75]");
    }
    else if (N > 25 && N <= 50) {
        printf("Intervalo (25,50]");
    }
    else {
        printf("Intervalo [0,25]");
    }

    printf("\n");

    return 0;
}