#include <stdio.h>

int main() {
    float av1, av2, av3, av4, av5;
    float soma, media;
    int av5_info;

    printf("= Calculadora de Notas - Laboratorio de Programação =\n\n");

    printf("- Etapa N1 -\n");
    printf("Digite a nota da AV1: ");
    scanf("%f", &av1);
    printf("Digite a nota da AV2: ");
    scanf("%f", &av2);

    printf("\n- Etapa N2 -\n");
    printf("Digite a nota da AV3: ");
    scanf("%f", &av3);
    printf("Digite a nota da AV4: ");
    scanf("%f", &av4);

    printf("Você já sabe a nota da AV5? (Sim - 1 // Não - 0): ");
    scanf("%d", &av5_info);

    if (av5_info == 1) {
        printf("Digite a nota da AV5: ");
        scanf("%f", &av5);

        soma = av1 * 1 + av2 * 3 + av3 * 2 + av4 * 1 + av5 * 3;
        media = soma / 10;

        printf("\nMédia final: %.1f\n", media);

        if (media >= 7.0) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }

    } else {
        soma = av1 * 1 + av2 * 3 + av3 * 2 + av4 * 1;
        float media_parcial = soma / 7;
        float falta = (7 * 10 - soma) / 3;

        printf("\nMédia parcial (sem AV5): %.1f\n", media_parcial);
        printf("Para atingir média 7.0, precisa tirar: %.1f na AV5\n", falta);
    }

    return 0;
}
