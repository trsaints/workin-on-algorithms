#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int first_result = (a + b + abs(a - b)) / 2;
    int second_result = (first_result + c + abs(first_result - c)) / 2;

    printf("%d eh o maior\n", second_result);

    return 0;
}