#include <stdio.h>
#include <string.h>
 
char first_class[14], 
     second_class[9], 
     third_class[11];

int is_classified(char * first_option,
                  char * second_option,
                  char * third_option);

int main() {
    scanf("%13s", first_class);
    scanf("%8s", second_class);
    scanf("%10s", third_class);

    char animal_name[13];

    if (is_classified("vertebrado", "ave", "carnivoro")) {
        strcpy(animal_name, "aguia");
    } else if (is_classified("vertebrado", "ave", "onivoro")) {
        strcpy(animal_name, "pomba");
    }  else if (is_classified("vertebrado", "mamifero", "onivoro")) {
        strcpy(animal_name, "homem");
    }  else if (is_classified("vertebrado", "mamifero", "herbivoro")) {
        strcpy(animal_name, "vaca");
    } else if (is_classified("invertebrado", "inseto", "hematofago")) {
        strcpy(animal_name, "pulga");
    } else if (is_classified("invertebrado", "inseto", "herbivoro")) {
        strcpy(animal_name, "lagarta");
    }  else if (is_classified("invertebrado", "anelideo", "hematofago")) {
        strcpy(animal_name, "sanguessuga");
    }  else if (is_classified("invertebrado", "anelideo", "onivoro")) {
        strcpy(animal_name, "minhoca");
    } 

    printf("%s\n", animal_name);
}

int is_classified(char * first_option,
                  char * second_option,
                  char * third_option) {
    return (strcmp(first_class, first_option) == 0)
        && (strcmp(second_class, second_option) == 0)
        && (strcmp(third_class, third_option) == 0);
}