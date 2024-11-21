#include <stdio.h>

int main()
{
    int even[5], odd[5];
    int even_count = 0, odd_count = 0;

    static char input_buffer[100];
    int X;

    static char output_buffer[65536];
    char *output_position = output_buffer,
         *output_end = output_buffer + sizeof(output_buffer);

    for (int i = 0; i < 15 && output_position < output_end; i++)
    {
        if (!fgets(input_buffer, sizeof(input_buffer), stdin))
            continue;

        if (!sscanf(input_buffer, "%d", &X))
            continue;

        if (X % 2 == 0)
            even[even_count++] = X;
        else
            odd[odd_count++] = X;

        if (even_count == 5)
        {
            for (int j = 0; j < 5; j++)
            {
                output_position += snprintf(output_position,
                                            output_end - output_position,
                                            "par[%d] = %d\n",
                                            j, even[j]);
            }

            even_count = 0;
        }

        if (odd_count == 5)
        {
            for (int j = 0; j < 5; j++)
            {
                output_position += snprintf(output_position,
                                            output_end - output_position,
                                            "impar[%d] = %d\n",
                                            j, odd[j]);
            }

            odd_count = 0;
        }
    }

    if (odd_count > 0)
    {
        for (int j = 0; j < odd_count; j++)
        {
            output_position += snprintf(output_position,
                                        output_end - output_position,
                                        "impar[%d] = %d\n",
                                        j, odd[j]);
        }
    }

    if (even_count > 0)
    {
        for (int j = 0; j < even_count; j++)
        {
            output_position += snprintf(output_position,
                                        output_end - output_position,
                                        "par[%d] = %d\n",
                                        j, even[j]);
        }
    }

    printf("%s", output_buffer);

    return 0;
}