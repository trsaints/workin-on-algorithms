#include <stdio.h>
 
int main() {
    int N;

    char line_buffer[1024];

    if (fgets(line_buffer, sizeof(line_buffer), stdin))
        sscanf(line_buffer, "%d", &N);

    for (int i = 1; i <= N; i++) {
        if ((i % 2) != 0) continue;

        printf("%d^2 = %d\n", i, (i * i));
    }

    return 0;
}