#include <stdio.h>
 
int main() {
    static char line_buffer[144];
    char *buffer_position = line_buffer;
    char *buffer_end = line_buffer + sizeof(line_buffer);

    for (int i = 1, j = 7; 
         i <= 9; 
         j--) 
    {
        buffer_position += snprintf(buffer_position,
                                    buffer_end - buffer_position,
                                    "I=%d J=%d\n",
                                    i, j);

        if (j > 5) continue;

        i += 2;
        j = 8;
    }

    fputs(line_buffer, stdout);
 
    return 0;
}