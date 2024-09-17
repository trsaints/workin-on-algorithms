#include <stdio.h>
 
int main() {
    static char line_buffer[144];
    char *buffer_position = line_buffer;
    char *buffer_end = line_buffer + sizeof(line_buffer);

    for (int i = 1, j = 60; 
         j >= 0; 
         j -= 5, i += 3) 
    {
        buffer_position += snprintf(buffer_position,
                                    buffer_end - buffer_position,
                                    "I=%d J=%d\n",
                                    i, j);
    }

    fputs(line_buffer, stdout);
 
    return 0;
}