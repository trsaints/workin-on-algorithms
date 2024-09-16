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