#include <stdio.h>
 
int main() {
    float x, y;
    int quadrant = 0;

    scanf("%f %f", &x, &y);

    if (x > 0 && y > 0)
        quadrant = 1;
    else if (x < 0 && y > 0)
        quadrant = 2;
    else if (x < 0 && y < 0)
        quadrant = 3;
    else if (x > 0 && y < 0)
        quadrant = 4;

    if (quadrant != 0) {
        printf("Q%d\n", quadrant);

        return 0;
    }

    char axis;

    if (x != 0 && y == 0)
        axis = 'X';
    else if (x == 0 && y != 0)
        axis = 'Y';
    else if (x == 0 && y == 0)
        axis = 'O';

    if (axis != 'O') {    
        printf("Eixo %c\n", axis);
        
        return 0;
    }

    printf("Origem\n");
    
    return 0;
}