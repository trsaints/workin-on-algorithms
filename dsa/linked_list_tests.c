#include <stdio.h>
#include <stdlib.h>

// Função para contar números pares
int pair_count(int *lista, int tamanho)
{
    int c = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] % 2 == 0)
        {
            c++;
        }
    }
    return c;
}

// Função para criar nova lista contendo apenas pares
int *pair_filter(int *base_list, int length, int *new_size)
{
    int c = pair_count(base_list, length);
    int *new_list = (int *)malloc(c * sizeof(int));
    *new_size = 0;
    for (int i = 0; i < length; i++)
    {
        if (base_list[i] % 2 == 0)
        {
            new_list[(*new_size)++] = base_list[i];
        }
    }
    return new_list;
}

// Função para calcular a média
float list_average(int *base_list, int length)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += base_list[i];
    }
    return (float)total / length;
}

int main()
{
    int list[] = {1, 2, 3, 4, 5, 6};
    int list_length = sizeof(list) / sizeof(list[0]);

    // Contar pares
    int pairs = pair_count(list, list_length);
    printf("Números pares: %d\n", pairs);

    // Nova lista com números pares
    int new_length = 0;
    int *pairs_list = pair_filter(list, list_length, &new_length);
    printf("Nova lista com números pares: ");
    for (int i = 0; i < new_length; i++)
    {
        printf("%d ", pairs_list[i]);
    }
    printf("\n");

    // Média
    float average = list_average(list, list_length);
    printf("Média da lista: %.2f\n", average);

    // Liberar memória
    free(pairs_list);
    return 0;
}
