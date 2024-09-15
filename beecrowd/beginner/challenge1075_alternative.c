#include <stdlib.h>
#include <stdio.h>

int main() {
    char line_buffer[512];
    static char result_buffer[262144];

    if(!fgets(line_buffer,sizeof(line_buffer),stdin)){
        printf("Erro ao ler entrada!\n");
        return 1;
    }
    int n = (int)strtol(line_buffer,NULL,10);

    char *buffer_pos = result_buffer;
    char *buffer_end = result_buffer + sizeof(result_buffer);
    for (int i = 1; i < 10000 && buffer_pos < buffer_end; i++) {
        if ((i % n) != 2) continue;
        buffer_pos += snprintf(buffer_pos,buffer_end - buffer_pos,"%d\n", i);
    }

    //fputs é similar a printf("%s",result_buffer), ele simplesmente printa diretamente a string
    fputs(result_buffer,stdout);
    
    return 0;
}