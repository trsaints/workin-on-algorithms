#include <stdio.h>
 
int main() {
    unsigned int N;

    scanf("%d", &N);

    unsigned int hours, minutes, seconds;

    hours = N / 3600;
    minutes = N / 60 % 60;
    seconds = N % 60;

    printf("%d:%d:%d\n", hours, minutes, seconds);

    return 0;
}