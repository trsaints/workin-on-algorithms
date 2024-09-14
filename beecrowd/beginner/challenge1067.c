#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    int x;
    char line_buffer[1024];
    char result_buffer[1024];

    if (fgets(line_buffer, sizeof(line_buffer), stdin))
        sscanf(line_buffer, "%d", &x);

    for (int i = 1; i <= x; i++) {
        if (i % 2 == 0) continue;

        char tmp_buffer[1024];

        sprintf(tmp_buffer, "%d", i);
        strcat(result_buffer, tmp_buffer);
        strcat(result_buffer, "\n");
    }

    printf("%s", result_buffer);

    return 0;
}