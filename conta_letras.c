#include <stdio.h>

char* get_distinct_characters(char* base_text);

int main() {
    char input_buffer[512];

    scanf("%[^\n]", input_buffer); // Read the entire line including spaces

    char *distinct_characters = get_distinct_characters(input_buffer);

    printf("%s\n", distinct_characters);
    
    return 0;
}

char* get_distinct_characters(char* base_text) {
    char *position = base_text;

    static char output_buffer[65536];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);

    while (*position != '\0' && output_position < output_end) {
        char *check_position = output_buffer;
        int found = 0;
        while (check_position < output_position) {
            if (*check_position == *position) {
                found = 1;
                break;
            }
            check_position++;
        }

        if (!found) {
            *output_position = *position;
            output_position++;
            if (output_position < output_end) {
                *output_position = ',';
                output_position++;
            }
        }
        position++;
    }

    if (output_position > output_buffer && *(output_position - 1) == ',') {
        *(output_position - 1) = '\0';
    } else {
        *output_position = '\0';
    }

    return output_buffer;
}