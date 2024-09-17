#include <stdio.h>

typedef struct {
    int rabbit_count,
        rat_count,
        frog_count,
        total_count;

    float rabbit_rate,
          rat_rate,
          frog_rate;
} AnimalStatistics;

AnimalStatistics get_animal_report(int test_count);

float get_count_rate(int animal_count, int total_count);

char * get_reports(AnimalStatistics statistics);

int main() {
    int test_count;

    char count_buffer[256];

    if (!fgets(count_buffer, sizeof(count_buffer), stdin))
        return 1;

    sscanf(count_buffer, "%d", &test_count);

    AnimalStatistics statistics = get_animal_report(test_count);

    char * reports = get_reports(statistics);

    fputs(reports, stdout);

    return 0;
}

AnimalStatistics get_animal_report(int test_count) {
    char case_buffer[5 * test_count];

    char current_animal;
    int current_count,
        rabbit_count = 0,
        rat_count = 0,
        frog_count = 0;

    for (int i = 0; i < test_count; i++) {
        if (!fgets(case_buffer, sizeof(case_buffer), stdin))
            continue;

        sscanf(case_buffer, 
               "%d %c", 
               &current_count, 
               &current_animal);

        switch (current_animal) {
            case 'C':
                rabbit_count += current_count;

                break;

            case 'R':
                rat_count += current_count;

                break;

            case 'S':
                frog_count += current_count;

                break;
        }   
    }

    int total_count = rabbit_count + rat_count + frog_count;
    float rabbit_rate = get_count_rate(rabbit_count, total_count),
          rat_rate = get_count_rate(rat_count, total_count),
          frog_rate = get_count_rate(frog_count, total_count);
    

    AnimalStatistics statistics = {
        rabbit_count, 
        rat_count,
        frog_count,
        total_count,
        rabbit_rate,
        rat_rate,
        frog_rate
    };

    return statistics;
}

float get_count_rate(int animal_count, int total_count) {
    return animal_count / (float) total_count * 100;
}

char * get_reports(AnimalStatistics statistics) {
    static char result_buffer[2048];
    char *buffer_position = result_buffer,
         *buffer_end = result_buffer + sizeof(result_buffer);

    buffer_position += snprintf(buffer_position, 
                                buffer_end - buffer_position,
                                "Total: %d cobaias\n", 
                                statistics.total_count);

    buffer_position += snprintf(buffer_position, 
                                buffer_end - buffer_position,
                                "Total de coelhos: %d\n", 
                                statistics.rabbit_count);

    buffer_position += snprintf(buffer_position, 
                                buffer_end - buffer_position,
                                "Total de ratos: %d\n", 
                                statistics.rat_count);

    buffer_position += snprintf(buffer_position, 
                                buffer_end - buffer_position,
                                "Total de sapos: %d\n", 
                                statistics.frog_count);

    buffer_position += snprintf(buffer_position, 
                                buffer_end - buffer_position,
                                "Percentual de coelhos: %.2f %%\n", 
                                statistics.rabbit_rate);

    buffer_position += snprintf(buffer_position, 
                                buffer_end - buffer_position,
                                "Percentual de ratos: %.2f %%\n", 
                                statistics.rat_rate);

    buffer_position += snprintf(buffer_position, 
                                buffer_end - buffer_position,
                                "Percentual de sapos: %.2f %%\n", 
                                statistics.frog_rate);

    return result_buffer;                            
}