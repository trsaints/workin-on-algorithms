#include <stdio.h>
 
int main() {
    static char read_buffer[128];
    static char result_buffer[2048];

    char *result_position = result_buffer,
         *result_end = result_buffer + sizeof(result_buffer);

    int password_input;

    while (result_position < result_end) {
        if (!fgets(read_buffer, sizeof(read_buffer), stdin))
            continue;

        sscanf(read_buffer, "%d", &password_input);

        if (password_input == 2002) break;

        result_position += snprintf(result_position, 
                                    result_end - result_position,
                                    "%s",
                                    "Senha Invalida\n");
    }

    result_position += snprintf(result_position, 
                                result_end - result_position,
                                "%s",
                                "Acesso Permitido\n");

    fputs(result_buffer, stdout);

    return 0;
}