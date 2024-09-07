#include <stdio.h>
 
int main() {
    char months[12][10] = {
        "January", 
        "February", 
        "March", 
        "April", 
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int user_option;

    scanf("%d", &user_option);

    if (user_option > 12 || user_option < 1) return 0;

    printf("%s\n", months[user_option - 1]);

    return 0;
}