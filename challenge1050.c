#include <stdio.h>
#include <string.h>

int main() {
    unsigned int ddds[8] = {61, 71, 11, 21, 32, 19, 27, 31};
    char cities[9][15] = { 
        "Brasilia", 
        "Salvador", 
        "Sao Paulo", 
        "Rio de Janeiro", 
        "Juiz de Fora",
        "Campinas",
        "Vitoria",
        "Belo Horizonte"
    };

    unsigned int chosen_ddd;

    scanf("%d", &chosen_ddd);

    char chosen_city[15];

    unsigned short int is_chosen = 0;

    for (int i = 0; i < 9; i++) {
        if (chosen_ddd != ddds[i]) continue;
        
        strcpy(chosen_city, cities[i]);
        is_chosen = 1;
    }

    if (!is_chosen) printf("DDD nao cadastrado\n");
    else printf("%s\n", chosen_city);
 
    return 0;
}