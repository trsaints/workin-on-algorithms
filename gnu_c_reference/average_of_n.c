#include <stdio.h>

double avg_of_double(int length, double input_data[]);

int main() {
    double numbers[] = {58.7, 5.1, 7.7, 105.2, -3.14159};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);

    double numbers_avg = avg_of_double(numbers_length, numbers);

    printf("%lf\n", numbers_avg);

    return 0;
}

double avg_of_double(int length, double input_data[]) {
    double sum = 0;

    int i;

    for (i = 0; i < length; i++)
        sum += input_data[i];

    return sum / length;
}