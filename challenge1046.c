#include <stdio.h>
 
int main() {
    // inicio maior que 12, fim menor que 12 -> terminou no outro dia
    // inicio e fim na mesma hora -> 24 horas
    // inicio menor que 12 e fim maior que 12 -> terminou no mesmo dia
    int start_time, end_time;

    scanf("%d %d", &start_time, &end_time);

    int game_duration;

    if (start_time > 12 && end_time < 12) {
        game_duration = 24 - start_time + end_time;
    } else if (start_time == end_time) {
        game_duration = 24;
    } else if (start_time < 12 && end_time > 12) {
        game_duration = end_time - start_time;
    }

    printf("O JOGO DUROU %d HORA(S)\n", game_duration);
 
    return 0;
}