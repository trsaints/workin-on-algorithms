#include <stdio.h>
 
int main() {
    int x, y, 
        odd_sum = 0;

    char line_buffer[1024];

    if (fgets(line_buffer, sizeof(line_buffer), stdin))
        sscanf(line_buffer, "%d", &x);

    if (fgets(line_buffer, sizeof(line_buffer), stdin))
        sscanf(line_buffer, "%d", &y);

    int i = 0;

    if (x > y) i = x - 1;
    else if (x < y) i = x + 1;

    while (x != y && i != y) {
       if (i % 2 != 0) odd_sum += i;

       if (x > y) i--;
       else i++;
    }

    printf("%d\n", odd_sum);

    return 0;
}