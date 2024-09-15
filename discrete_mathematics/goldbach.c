#include <stdio.h>
// 1. Ler um número x
// 2. Verificar se x é par
// 3. Encontrar n° primo y menor que x 
// 4. Verificar se x - y resulta em um n° primo

int primo(int x);

int main() {
    int x, retorno;

    printf("Digite um número par: ");
    scanf("%d", &x);

    if (x < 4 || x % 2 != 0) 
        return -1;

    for(int i = 1; i <= x; i++) {
        if (primo(i) && primo(x - i)) {
            printf("%d + %d = %d\n", i, x - i, x);

            break;
        }
    }
}

int primo(int x) {
    if (x < 2)
        return 0;

    int divisor;

    for (divisor = 2; divisor <= x / 2; divisor++)
    {
        if (x % divisor == 0)
            return 0;
    }

    return 1;
}