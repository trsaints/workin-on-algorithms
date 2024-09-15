#include <stdio.h>
#include <string.h>
 
int main() {
    int N;

    char line_buffer[32];
    static char result_buffer[262144];

    if (fgets(line_buffer, sizeof(line_buffer), stdin))
        sscanf(line_buffer, "%d", &N);

    for (int i = 1; i < 10000; i++) {
        if ((i % N) != 2) continue;

        char tmp_buffer[32];

        sprintf(tmp_buffer, "%d", i);
        strcat(result_buffer, tmp_buffer);
        strcat(result_buffer, "\n");
    }

    printf("%s", result_buffer);
    
    return 0;
}