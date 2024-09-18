#include <stdio.h>
 
char * list_consecutive_sum(int test_cases);
int sum_odd_interval(int start, int end);

int main() {
    static char read_buffer[128];

    int invalid_input = !fgets(read_buffer, 
                               sizeof(read_buffer), 
                               stdin);

    if (invalid_input) return 1;

    int test_cases;
    sscanf(read_buffer, "%d", &test_cases);

    char * result = list_consecutive_sum(test_cases);
    fputs(result, stdout);

    return 0;
}

char * list_consecutive_sum(int test_cases) {
    static char read_buffer[128];

    static char result_buffer[2048];
    char *result_position = result_buffer,
         *result_end = result_buffer + sizeof(result_buffer);

    int start, end, odd_totals;

    for (int i = 0; i < test_cases; i++) {
        int invalid_input = !fgets(read_buffer, sizeof(read_buffer), stdin);

        if (invalid_input) break;

        sscanf(read_buffer, "%d %d", &start, &end);
        odd_totals = sum_odd_interval(start, end);

        result_position += snprintf(result_position,
                                    result_end - result_position,
                                    "%d\n",
                                    odd_totals);
    }

    return result_buffer;
}

int sum_odd_interval(int start, int end) {
    if (start > end) {
        int tmp = start;
        start = end;
        end = tmp;
    }
    
    if ((start == end) || (end - start < 2)) 
        return 0;

    if (start % 2 != 0) start++;
    if (end % 2 != 0) end--;

    int current = start + 1,
        result = 0;

    while (current < end) {
        result += current;
        current += 2;    
    }

    return result;  
}

