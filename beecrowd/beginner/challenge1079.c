#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WEIGHT_1 0.2
#define WEIGHT_2 0.3
#define WEIGHT_3 0.5

int main() {
    char line_buffer[1024];

    if (!fgets(line_buffer, sizeof(line_buffer), stdin))
        return 1;

    int n = (int) strtol(line_buffer, NULL, 10);

    char result_buffer[1024 * n];
    char *buffer_position = result_buffer;
    char *buffer_end = result_buffer + sizeof(result_buffer);

    float first_input, second_input, third_input, average;

    for (int i = 0; 
         (i < n) && (buffer_position < buffer_end); 
         i++) 
    {

        if (!fgets(line_buffer, sizeof(line_buffer), stdin)) 
            continue;

        sscanf(line_buffer, 
               "%f %f %f", 
               &first_input,
               &second_input,
               &third_input);

        average = ((first_input * WEIGHT_1)
                  + (second_input * WEIGHT_2)
                  + (third_input * WEIGHT_3));

        buffer_position += 
            snprintf(buffer_position,
                     buffer_end - buffer_position,
                     "%.1f\n",
                     average);
    }
    
    fputs(result_buffer, stdout);

    return 0;
}