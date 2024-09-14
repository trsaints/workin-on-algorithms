#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    int x,
        odd_count = 0;

    char input_buffer[1024];
    char result_buffer[1024];


    if (fgets(input_buffer, sizeof(input_buffer), stdin))
        sscanf(input_buffer, "%d", &x);

    for (int i = x; odd_count < 6; i++) {
        if (i % 2 == 0) continue;

        char tmp_buffer[1024];

        sprintf(tmp_buffer, "%d", i);
        strcat(result_buffer, tmp_buffer);
        strcat(result_buffer, "\n");

        odd_count++;
    }

    printf("%s", result_buffer);
 
    return 0;
}