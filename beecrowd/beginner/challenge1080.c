#include <stdio.h>
#include <stdlib.h>

#define INPUT_COUNT 100 
#define FALSE 0

typedef struct {
    int number,
        index;
} ArrayEntry;

ArrayEntry get_greatest_entry(int * inputs);

int main() {
    char line_buffer[11];

    int user_inputs[INPUT_COUNT];

    for (int i = 0; i < INPUT_COUNT; i++) {
        if (!fgets(line_buffer, sizeof(line_buffer), stdin))
            continue;

        user_inputs[i] = strtol(line_buffer, NULL, 10);
    }

    ArrayEntry greatest_entry = get_greatest_entry(user_inputs);

    printf("%d\n%d\n", greatest_entry.number, greatest_entry.index + 1);

    return 0;
}

ArrayEntry get_greatest_entry(int * inputs) {
    int greatest_value = inputs[0],
        greatest_index = 0;

    int greatest_values[INPUT_COUNT],
        greatest_indexes[INPUT_COUNT];

    greatest_values[0] = greatest_value;
    greatest_indexes[0] = greatest_index;

    for (int i = 1; i < INPUT_COUNT; i++) {
        greatest_values[i] = -1;
        greatest_indexes[i] = -1;
    }

    int current_is_greater = FALSE,
        previous_is_greater = FALSE,
        next_is_greater = FALSE;

    int current_equals = FALSE,
        previous_equals = FALSE,
        next_equals = FALSE;

    for (int i = 1; i < INPUT_COUNT; i++) {
        if (inputs[i] >= greatest_value) {
            greatest_value = inputs[i];
            greatest_index = i;
        }
    }

    ArrayEntry result = {
        greatest_value,
        greatest_index
    };

    return result;
}