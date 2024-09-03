#include <stdio.h>
 
int main() {
    int inputs[3];

    scanf("%d %d %d", &inputs[0], &inputs[1], &inputs[2]);

    for (int i = 0; i < 3; i++)
        printf("%d\n", inputs[i]);

    int tmp = inputs[0];

    for (int i = 0; i < 3; i++) {
        if ((i - 1) < 0) continue;

        if (inputs[i] < inputs[i - 1]) {
            // -14 < 21
            tmp = inputs[i - 1];

            // 21 -> 14
            inputs[i - 1] = inputs[i];
            inputs[i] = tmp;
        }

        if (inputs[i - 1] < inputs[0]) {
            tmp = inputs[0];
            inputs[0] = inputs[i - 1];
            inputs[i - 1] = tmp;
        }
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
        printf("%d\n", inputs[i]);
 
    return 0;
}