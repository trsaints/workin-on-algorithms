#include <stdio.h>
 
int main() {
    double X;

    static char input_buffer[100];

    if (! fgets(input_buffer, sizeof(input_buffer), stdin))
        return 1;

    sscanf(input_buffer, "%lf", &X);

    static char output_buffer[65536];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);


    double j = X;

    for (int i = 0; i < 100 && output_position < output_end; i++) {
        output_position += snprintf(output_position,
                                    output_end - output_position,
                                    "N[%d] = %.4lf\n",
                                    i, j);        

        j /= 2;
    }

    printf("%s", output_buffer);

    return 0;
}