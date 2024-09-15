#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main() {
    char line_buffer[5];
    char result_buffer[171];

    if (!fgets(line_buffer, sizeof(line_buffer), stdin))
        return 1;

    int n = (int) strtol(line_buffer, NULL, 10);

    char *buffer_position = result_buffer;
    char *buffer_end = result_buffer + sizeof(result_buffer);

    for (int i = 1; 
        (i <= 10) && (buffer_position < buffer_end); 
        i++) 
    {
        int product = i * n;
  
        buffer_position += 
            snprintf(buffer_position,
                    buffer_end - buffer_position, 
                    "%d x %d = %d\n", i, n, product);
    }

    fputs(result_buffer, stdout);

    return 0;
}