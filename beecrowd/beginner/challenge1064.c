#include <stdio.h>
 
int main() {
    float user_inputs[6],
          positive_inputs[6] = {0, 0, 0, 0, 0, 0};

    float positive_totals = 0;

    char line_buffer[1024];
    int positive_count = 0;
    
    for (int i = 0; i < 6; i++) {
        if (!fgets(line_buffer, sizeof(line_buffer), stdin)) 
            continue;

        sscanf(line_buffer, "%f", &user_inputs[i]);

        if ((int) user_inputs[i] < 0) 
            continue;

        positive_count++;
        positive_inputs[i] = user_inputs[i];
        positive_totals += user_inputs[i];
    }

    float positive_mean = positive_totals / positive_count;

    printf("%d valores positivos\n", positive_count);
    printf("%.1f\n", positive_mean);
 
    return 0;
}