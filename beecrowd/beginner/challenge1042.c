#include <stdio.h>

int main() {
    int i;
    int inputs[3];

    scanf("%d %d %d", &inputs[0], &inputs[1], &inputs[2]);

    int sorted_inputs[3];

    for (i = 0; i < 3; i++) {
        sorted_inputs[i] = inputs[i];
    }

    int swap = sorted_inputs[0];

    for (i = 0; i < 3; i++) {
        if ((i - 1) < 0) continue;

        // -8 < -3
        if (sorted_inputs[i] < sorted_inputs[i - 1]) {
            swap = sorted_inputs[i - 1];
            sorted_inputs[i - 1] = sorted_inputs[i];
            sorted_inputs[i] = swap;
        }

        // -3 < -3
        if (sorted_inputs[i - 1] < sorted_inputs[0]) {
            swap = sorted_inputs[0];
            sorted_inputs[0] = sorted_inputs[i - 1];
            sorted_inputs[i - 1] = swap;
        }
    }

    for (i = 0; i < 3; i++)
        printf("%d\n", sorted_inputs[i]);

    printf("\n");

    for (i = 0; i < 3; i++)
        printf("%d\n", inputs[i]);
 
    return 0;
}

int ** sort_inputs() {
    
}