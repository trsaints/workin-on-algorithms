#include <stdio.h>
 
int main() {
    // inicio maior que 12, fim menor que 12 -> terminou no outro dia
    // inicio e fim na mesma hora -> 24 horas
    // inicio menor que 12 e fim maior que 12 -> terminou no mesmo dia
    int start_hours, start_minutes, end_hours, end_minutes;

    scanf("%d %d %d %d", 
          &start_hours, 
          &start_minutes, 
          &end_hours, 
          &end_minutes);

    int game_duration_hours, game_duration_minutes;

    if (start_hours > end_hours) {
        game_duration_hours = 24 - start_hours + end_hours;
    } 
    else if (start_hours < end_hours) {
        game_duration_hours = end_hours - start_hours;
    } else if (start_hours == end_hours && start_minutes < end_minutes) {
        game_duration_hours = 0;
    } else {
        game_duration_hours = 24;
    }

    if (start_minutes < end_minutes) {
        game_duration_minutes = end_minutes - start_minutes;
    } else if (start_minutes > end_minutes) {
        game_duration_minutes = 60 - (start_minutes - end_minutes);
        game_duration_hours--;
    } else {
        game_duration_minutes = 0;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", 
           game_duration_hours, 
           game_duration_minutes);
 
    return 0;
}
