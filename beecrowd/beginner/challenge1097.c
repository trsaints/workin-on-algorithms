#include <stdio.h>
 
int main() {
    static char line_buffer[165];
    char *buffer_position = line_buffer;
    char *buffer_end = line_buffer + sizeof(line_buffer);

    for (int i = 1, j = 7, c = 1; 
         i <= 9; 
         j--, c++) 
    {
        buffer_position += snprintf(buffer_position,
                                    buffer_end - buffer_position,
                                    "I=%d J=%d\n",
                                    i, j);

        if (c % 3 != 0) continue;

        i += 2;
        j += 5;
    }

    fputs(line_buffer, stdout);
 
    return 0;
}