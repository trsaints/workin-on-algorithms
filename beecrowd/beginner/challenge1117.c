#include <stdio.h>
 
int main() {
    static char input_buffer[512];
    static char output_buffer[65536];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);

    float grade1;
    float grade2 = -1;

    if (!fgets(input_buffer, sizeof(input_buffer), stdin))
        return 1;

    sscanf(input_buffer, "%f", &grade1);

    int valid_grade1 = grade1 >= 0 && grade1 <= 10,
        valid_grade2 = 0,
        valid_input = 0;

    while (output_position < output_end && !valid_input) {
        if (!fgets(input_buffer, sizeof(input_buffer), stdin))
            continue;

        if (!valid_grade1) 
            sscanf(input_buffer, "%f", &grade1);
        else if (!valid_grade2)
            sscanf(input_buffer, "%f", &grade2);

        valid_grade1 = grade1 >= 0 && grade1 <= 10;

        if (!valid_grade1) {
            output_position += snprintf(output_position,
                                        output_end - output_position,
                                        "nota invalida\n");

            continue;
        }

        valid_grade2 = grade2 >= 0 && grade2 <= 10;

        if (!valid_grade2) {
            output_position += snprintf(output_position,
                                    output_end - output_position,
                                    "nota invalida\n");

            continue;
        }

        valid_input = valid_grade1 && valid_grade2;
    }

    float mean = (grade1 + grade2) / 2.0f;


    output_position += snprintf(output_position,
                                output_end - output_position,
                                "media = %.2f\n",
                                mean);

    fputs(output_buffer, stdout);

    return 0;
}