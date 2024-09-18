#include <stdio.h>
 
int main() {
    static char read_buffer[512];

    if (!fgets(read_buffer, sizeof(read_buffer), stdin))
        return 1;

    int test_cases;

    sscanf(read_buffer, "%d", &test_cases);

    static char output_buffer[131072];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);
 
    int x, y;


    for (int i = 0;
         (i < test_cases) && (output_position < output_end);
         i++) 
    {
        if (!fgets(read_buffer, sizeof(read_buffer), stdin))
            continue;

        sscanf(read_buffer, "%d %d", &x, &y);

        if (y == 0) {
            output_position += snprintf(output_position,
                                        output_end - output_position,
                                        "divisao impossivel\n");

            continue;
        }

        output_position  += snprintf(output_position,
                                     output_end - output_position,
                                     "%.1f\n",
                                     (float) x / y);
    }

    fputs(output_buffer, stdout);

    return 0;
}