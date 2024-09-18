#include <stdio.h>

unsigned long long fibonacci(int n);

int main() {
    static char output_buffer[2048];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);

    unsigned long long fib = fibonacci(46);

    output_position += snprintf(output_position,
                                output_position - output_end,
                                "Fibonacci series item %d is %lld\n",
                                46,
                                fib);

    fputs(output_buffer, stdout);
}

unsigned long long fibonacci(int n) {
    int last = 1,
        prev = 0,
        i;

    for (i = 1; i < n; ++i) {
        int next = prev + last;
        prev = last;
        last = next;
    }

    return last;
}