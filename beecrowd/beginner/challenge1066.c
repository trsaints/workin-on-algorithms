#include <stdio.h>
 
int main() {
    int user_inputs[5],
        even_count = 0,
        odd_count = 0,
        positive_count = 0,
        negative_count = 0;

    char line_buffer[1024];

    for (int i = 0; i < 5; i++) {
        if (!fgets(line_buffer, sizeof(line_buffer), stdin)) 
            continue;

        sscanf(line_buffer, "%d", &user_inputs[i]);

        if (user_inputs[i] % 2 == 0)
            even_count++;
        else
            odd_count++;

        if (user_inputs[i] > 0)
            positive_count++;
        else if (user_inputs[i] != 0)
            negative_count++;
    }

    printf("%d valor(es) par(es)\n", even_count);
    printf("%d valor(es) impar(es)\n", odd_count);
    printf("%d valor(es) positivo(s)\n", positive_count);
    printf("%d valor(es) negativo(s)\n", negative_count);

    return 0;
}