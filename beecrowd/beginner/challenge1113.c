#include <stdio.h>
#include <string.h>

int main() {
    static char read_buffer[512];
    static char result_buffer[4096];
    
    char *result_position = result_buffer,
         *result_end = result_buffer + sizeof(result_buffer);

    int start, end;
    char message[14];

    while (result_position < result_end) {
        if (!fgets(read_buffer, sizeof(read_buffer), stdin)) 
        return 1;

        sscanf(read_buffer, "%d %d", &start, &end);

        if (start == end) break;
    
        if (start < end) 
            strcpy(message, "Crescente\n");
        else
            strcpy(message, "Decrescente\n");

        result_position += snprintf(result_position,
                                    result_end - result_position,
                                    "%s",
                                    message);
    }

    fputs(result_buffer, stdout);

    return 0;
}