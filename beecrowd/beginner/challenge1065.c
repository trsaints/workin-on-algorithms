    #include <stdio.h>
    
    int main() {
        int user_inputs[5],
            even_count;

        char line_buffer[1024];

        for (int i = 0; i < 5; i++) {
            if (!fgets(line_buffer, sizeof(line_buffer), stdin))
                continue;

            sscanf(line_buffer, "%d", &user_inputs[i]);

            if (user_inputs[i] % 2 == 0)
                even_count++;
        }

        printf("%d valores pares\n", even_count);

        return 0;
    }