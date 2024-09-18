#include <stdio.h>
#include <string.h>

int main() {
    static char read_buffer[512];
    static char output_buffer[4096];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);

    int x, y;
    char quadrant[10];

    while (output_position < output_end) {
        if (!fgets(read_buffer, sizeof(read_buffer), stdin))
            continue;

        sscanf(read_buffer, "%d %d", &x, &y);

        if (x == 0 || y == 0) break;

        if (x > 0 && y > 0)
            strcpy(quadrant, "primeiro");
        else if (x < 0 && y > 0)
            strcpy(quadrant, "segundo");
        else if (x < 0 && y < 0)
            strcpy(quadrant, "terceiro");
        else if (x > 0 && y < 0)
            strcpy(quadrant, "quarto");

        output_position += snprintf(output_position,
                                    output_end - output_position,
                                    "%s\n",
                                    quadrant);
    }

    fputs(output_buffer, stdout);
 
    return 0;
}