#include <stdio.h>
 
int main() {
    int N;

    static char input_buffer[100];

    if (! fgets(input_buffer, sizeof(input_buffer), stdin))
        return 1;

    sscanf(input_buffer, "%d", &N);

    static char output_buffer[65536];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);


    for (int i = 0; i < 1000 && output_position < output_end; i++) {
        int j = (i % N);

        output_position += snprintf(output_position,
                                    output_end - output_position,
                                    "N[%d] = %d\n",
                                    i, j);
        
        if (j == N) j = 0;
    }

    printf("%s", output_buffer);

    return 0;
}