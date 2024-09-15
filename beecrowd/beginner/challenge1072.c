#include <stdio.h>
 
int main() {
    int N;

    char line_buffer[1024];

    if (fgets(line_buffer, sizeof(line_buffer), stdin)) {
        sscanf(line_buffer, "%d", &N);
    }

    int user_inputs[N];

    for (int i = 0; i < N; i++) {
        if (!fgets(line_buffer, sizeof(line_buffer), stdin))
            continue;

        sscanf(line_buffer, "%d", &user_inputs[i]);
    }

    int in_count = 0,
        out_count = 0;

    for (int i = 0; i < N; i++) {
        if (user_inputs[i] >= 10 && user_inputs[i] <= 20) 
            in_count++;
        else
            out_count++;
    }
 
    printf("%d in\n", in_count);
    printf("%d out\n", out_count);

    return 0;
}