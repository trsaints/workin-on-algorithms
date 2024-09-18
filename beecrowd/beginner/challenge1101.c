#include <stdio.h>

char * get_sequence(int start, int end);

int main() {
    static char read_buffer[1024];
    char *read_position = read_buffer,
         *read_end = read_buffer + sizeof(read_buffer);

    int start, end;

    static char result_buffer[4096];
    char *result_position = result_buffer,
         *result_end = result_buffer + sizeof(result_buffer);

    while (read_position < read_end) {
        if (!fgets(read_buffer, sizeof(read_buffer), stdin))
            break;

        sscanf(read_buffer, "%d %d", &start, &end);

        if (start <= 0 || end <= 0) break;

        char * sequence = get_sequence(start, end);

        result_position += snprintf(result_position,
                                    result_end - result_position,
                                    "%s",
                                    sequence);
    }

    fputs(result_buffer, stdout);

    return 0;
}

char * get_sequence(int s_start, int s_end) {
    static char sequence_buffer[4096];
    char *buffer_position = sequence_buffer,
         *buffer_end = sequence_buffer + sizeof(sequence_buffer);

    int current = s_start, 
        end = s_end;

    if (s_start > s_end) {
        int tmp = current;
        current = end;
        end = tmp;
    }

    int result = 0;

    while (current <= end) {
        buffer_position += snprintf(buffer_position,
                                    buffer_end - buffer_position,
                                    "%d ", current);

        result += current;
        current++;
    }

    buffer_position += snprintf(buffer_position,
                                buffer_end - buffer_position,
                                "Sum=%d\n", result);

    return sequence_buffer;
}
