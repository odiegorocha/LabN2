#include <stdio.h>

int main() {
    int opcao;
    float n1 = 0.0, n2 = 0.0;

    printf("LABORATÓRIO DE PROGRAMAÇÃO\n");
    printf("Escolha o tipo de avaliação (1 - Laboratórios e provas, 2 - Projeto): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        float lab1, lab2, lab3, lab4, revisaoAnalitica, competicao1;
        float prova3, desafio3, desafio4, pratica, competicao2;
        float lab5, lab6, lab7, lab8, revisaoAnaliticaFinal, competicao3;

        printf("\nNotas da N1\n");
        printf("Digite a nota do Laboratório 1 (0 a 5): ");
        scanf("%f", &lab1);
        printf("Digite a nota do Laboratório 2 (0 a 5): ");
        scanf("%f", &lab2);
        printf("Digite a nota do Laboratório 3 (0 a 5): ");
        scanf("%f", &lab3);
        printf("Digite a nota do Laboratório 4 (0 a 5): ");
        scanf("%f", &lab4);
        printf("Digite a nota da Revisão Analítica (0 a 10): ");
        scanf("%f", &revisaoAnalitica);
        printf("Digite a nota da Competição 1 (0 a 8): ");
        scanf("%f", &competicao1);

        n1 = (lab1 + lab2 + lab3 + lab4 + revisaoAnalitica) / 4;

        printf("\nNotas da N2\n");
        printf("Digite a nota da Prova 3 (0 a 10): ");
        scanf("%f", &prova3);
        printf("Digite a nota do Desafio 3 (0 a 1): ");
        scanf("%f", &desafio3);
        printf("Digite a nota do Desafio 4 (0 a 1): ");
        scanf("%f", &desafio4);
        printf("Digite a nota da Prática (0 a 10): ");
        scanf("%f", &pratica);
        printf("Digite a nota da Competição 2 (0 a 2): ");
        scanf("%f", &competicao2);
        printf("Digite a nota do Laboratório 5 (0 a 5): ");
        scanf("%f", &lab5);
        printf("Digite a nota do Laboratório 6 (0 a 5): ");
        scanf("%f", &lab6);
        printf("Digite a nota do Laboratório 7 (0 a 5): ");
        scanf("%f", &lab7);
        printf("Digite a nota do Laboratório 8 (0 a 5): ");
        scanf("%f", &lab8);
        printf("Digite a nota da Revisão Analítica Final (0 a 10): ");
        scanf("%f", &revisaoAnaliticaFinal);
        printf("Digite a nota da Competição 3 (0 a 6): ");
        scanf("%f", &competicao3);

        n2 = (prova3 + desafio3 + desafio4 + pratica + lab5 + lab6 + lab7 + lab8 + revisaoAnaliticaFinal + competicao2 + competicao3) / 6;

    } else if (opcao == 2) {
        float prova2, projetoN1, projetoN2, apresentacao;

        printf("\nNotas da N1\n");
        printf("Digite a nota da Prova 2 (0 a 20): ");
        scanf("%f", &prova2);
        printf("Digite a nota do Projeto N1 (0 a 10): ");
        scanf("%f", &projetoN1);

        n1 = (prova2 + projetoN1) / 3;

        printf("\nNotas da N2\n");
        printf("Digite a nota do Projeto Final (0 a 20): ");
        scanf("%f", &projetoN2);
        printf("Digite a nota da Apresentação (0 a 10): ");
        scanf("%f", &apresentacao);

        n2 = (projetoN2 + apresentacao) / 3;

    } else {
        printf("Opção inválida\n");
        return 1;
    }

    float mediaFinal = ((2 * n1) + (3 * n2)) / 5;

    printf("\nMédia Final\n");
    printf("Nota N1: %.2f\n", n1);
    printf("Nota N2: %.2f\n", n2);
    printf("Média final: %.2f\n", mediaFinal);

    return 0;
}
