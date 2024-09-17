#include <stdio.h>
 
int main() {
    static char line_buffer[1024];
    char *buffer_position = line_buffer;
    char *buffer_end = line_buffer + sizeof(line_buffer);

    int c = 1;

    for (float i = 0, j = 1; 
         i <= 2.2; 
         c++) 
    {
        buffer_position += snprintf(buffer_position,
                                    buffer_end - buffer_position,
                                    "I=%g J=%g\n",
                                    i, j);

        j++;

        if (c % 3 != 0) continue;

        i += 0.2;
        j = 1 + i;
    }

    fputs(line_buffer, stdout);
 
    return 0;
}