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

    printf("%d\n%d\n", greatest_entry.number, greatest_entry.index);

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

    for (int i = 0; i < INPUT_COUNT; i++) {
        if ((i - 1) < 0 
            || (i + 1) > INPUT_COUNT) continue;

        current_is_greater = (inputs[i] > inputs[i - 1]) 
                                && (inputs[i] > inputs[i + 1])
                                && (inputs[i] > greatest_value);

        previous_is_greater = (inputs[i - 1] > inputs[i])
                                && (inputs[i - 1] > inputs[i + 1])
                                && (inputs[i - 1] > greatest_value);

        next_is_greater = (inputs[i + 1] > inputs[i])
                            && (inputs[i + 1] > inputs[i - 1])
                            && (inputs[i - 1] > greatest_value);

        if (current_is_greater) {
            greatest_value = inputs[i];
            greatest_index = i;
        }
        else if (previous_is_greater) {
            greatest_value = inputs[i - 1];
            greatest_index = i - 1;
        } else if (next_is_greater) {
            greatest_value = inputs[i + 1];
            greatest_index = i + 1;
        }


        if (!current_is_greater && !previous_is_greater && !next_is_greater) continue;

        greatest_values[i] = greatest_value;
        greatest_indexes[i] = greatest_index;
    }

    ArrayEntry result = {
        greatest_value,
        greatest_index
    };

    return result;
}