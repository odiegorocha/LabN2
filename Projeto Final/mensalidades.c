#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mensalidades.h"
#include "util.h"

void cadastrarMensalidade(struct Mensalidade m[], int *qtd) {
    if (*qtd >= TAM) {
        printf("\nLimite atingido.\n");
        return;
    }

    printf("\nData conta (DDMMAAAA): ");
    scanf(" %8[^\n]", m[*qtd].dataConta);

    printf("Data venc. (DDMMAAAA): ");
    scanf(" %8[^\n]", m[*qtd].dataVencimento);

    printf("Valor: ");
    scanf("%f", &m[*qtd].valor);

    printf("Juros fixo: ");
    scanf("%f", &m[*qtd].juros);

    int tipo;
    do {
        printf("Plano:\n1 - Normal\n2 - Prioridade\n3 - Plus\nOpcao: ");
        scanf("%d", &tipo);
    } while (tipo < 1 || tipo > 3);

    m[*qtd].tipoPlano = tipo;
    (*qtd)++;
}

void mostrarMensalidades(struct Mensalidade m[], int n) {
    if (n == 0) {
        printf("\nSem mensalidades.\n");
        return;
    }

    printf("\nData Conta Vencimento  Valor   Juros  Plano\n");
    for (int i = 0; i < n; i++) {
        char planoStr[15];
        if (m[i].tipoPlano == NORMAL) strcpy(planoStr, "Normal");
        else if (m[i].tipoPlano == PRIORIDADE) strcpy(planoStr, "Prioridade");
        else strcpy(planoStr, "Plus");

        printf("%-10s %-10s %.2f   %.2f   %s\n",
               m[i].dataConta,
               m[i].dataVencimento,
               m[i].valor,
               m[i].juros,
               planoStr);
    }
}

void mostrarMensalidadesAtualizadas(struct Mensalidade m[], int n) {
    if (n == 0) {
        printf("\nSem mensalidades.\n");
        return;
    }

    printf("\nData Conta Vencimento  Valor  Dias Plano       Atualizado\n");
    for (int i = 0; i < n; i++) {
        int atraso = calcularDiferencaDias(m[i].dataVencimento, dataAtual);
        float valorFinal = m[i].valor + m[i].juros;

        if (atraso > 0) valorFinal += m[i].valor * 0.01 * atraso;
        if (atraso < 0) atraso = 0;

        char planoStr[15];
        if (m[i].tipoPlano == NORMAL) strcpy(planoStr, "Normal");
        else if (m[i].tipoPlano == PRIORIDADE) strcpy(planoStr, "Prioridade");
        else strcpy(planoStr, "Plus");

        printf("%-10s %-10s %.2f  %4d %-10s %.2f\n",
               m[i].dataConta,
               m[i].dataVencimento,
               m[i].valor,
               atraso,
               planoStr,
               valorFinal);
    }
}

void menuVisualizar(struct Consulta c[], int qtdC, struct Mensalidade m[], int qtdM) {
    int op;
    do {
        printf("\n1 - Consultas\n2 - Mensalidades\n3 - Mensalidades atualizadas\n0 - Voltar\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) menuConsultas(c, qtdC);
        else if (op == 2) mostrarMensalidades(m, qtdM);
        else if (op == 3) mostrarMensalidadesAtualizadas(m, qtdM);
    } while (op != 0);
}

void salvarDados(struct Consulta c[], int qtdC, struct Mensalidade m[], int qtdM) {
    FILE *f1 = fopen("consultas.dat", "wb");
    if (f1 != NULL) {
        fwrite(&qtdC, sizeof(int), 1, f1);
        fwrite(c, sizeof(struct Consulta), qtdC, f1);
        fclose(f1);
    }

    FILE *f2 = fopen("mensalidades.dat", "wb");
    if (f2 != NULL) {
        fwrite(&qtdM, sizeof(int), 1, f2);
        fwrite(m, sizeof(struct Mensalidade), qtdM, f2);
        fclose(f2);
    }
}

void carregarDados(struct Consulta c[], int *qtdC, struct Mensalidade m[], int *qtdM) {
    FILE *f1 = fopen("consultas.dat", "rb");
    if (f1 != NULL) {
        fread(qtdC, sizeof(int), 1, f1);
        fread(c, sizeof(struct Consulta), *qtdC, f1);
        fclose(f1);
    }

    FILE *f2 = fopen("mensalidades.dat", "rb");
    if (f2 != NULL) {
        fread(qtdM, sizeof(int), 1, f2);
        fread(m, sizeof(struct Mensalidade), *qtdM, f2);
        fclose(f2);
    }
}
