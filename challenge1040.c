#include <stdio.h>
 
int main() {
    float N1, N2, N3, N4;

    scanf("%f %f %f %f", &N1, &N2, &N3, &N4);

    float score = (N1 * 0.2) + (N2 * 0.3) + (N3 * 0.4) + (N4 * 0.1);

    printf("Media: %.1f\n", score);

    if (score >= 7.0)
    {
        printf("Aluno aprovado.\n");

        return 0;
    }
    
    if (score < 5.0) {                
        printf("Aluno reprovado.\n");

        return 0;
    }

    printf("Aluno em exame.\n");

    float exam_score;

    scanf("%f", &exam_score);
    printf("Nota do exame: %.1f\n", exam_score);

    score = (score + exam_score) / 2;

    if (score >= 5.0)
        printf("Aluno aprovado.\n");
    else 
        printf("Aluno reprovado.\n");

    printf("Media final: %.1f\n", score);

    return 0;
}