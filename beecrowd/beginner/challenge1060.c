#include <stdio.h>
 
int main() {
    float input_values[6];

    int i = 6;

    while (i--) {
        scanf("%f", &input_values[i]);
    }
 
    int positive_count = 0;

    for (i = 0; i < 6; i++) {
        if (input_values[i] <= 0) continue;

        positive_count++;
    }

    if (positive_count == 0) return 0;

    printf("%d valores positivos\n", positive_count);

    return 0;
}