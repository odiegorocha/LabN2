#include <stdio.h>
#include <string.h>
#include "consultas.h"

void agendar(struct Consulta consultas[], int *qtd) {
    if (*qtd >= TAM) {
        printf("\nLimite atingido.\n");
        return;
    }

    printf("\nData (DDMMAAAA): ");
    scanf(" %8[^\n]", consultas[*qtd].data);

    int esp;
    do {
        printf("Especialidade:\n1 - Clinico\n2 - Pediatra\nOpcao: ");
        scanf("%d", &esp);
    } while (esp != 1 && esp != 2);

    if (esp == 1) strcpy(consultas[*qtd].especialidade, "Clinico");
    else strcpy(consultas[*qtd].especialidade, "Pediatra");

    int loc;
    do {
        printf("Localidade:\n1 - Ceara\n2 - Maranhao\nOpcao: ");
        scanf("%d", &loc);
    } while (loc != 1 && loc != 2);

    if (loc == 1) strcpy(consultas[*qtd].localidade, "Ceara");
    else strcpy(consultas[*qtd].localidade, "Maranhao");

    (*qtd)++;
}

void ordenarData(struct Consulta c[], int n) {
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(c[i].data, c[j].data) > 0) {
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
}

void ordenarEsp(struct Consulta c[], int n) {
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(c[i].especialidade, c[j].especialidade) > 0) {
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
}

void ordenarLoc(struct Consulta c[], int n) {
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(c[i].localidade, c[j].localidade) > 0) {
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
}

void agruparEspData(struct Consulta c[], int n) {
    ordenarEsp(c, n);
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(c[i].especialidade, c[j].especialidade) == 0)
                if (strcmp(c[i].data, c[j].data) > 0) {
                    aux = c[i];
                    c[i] = c[j];
                    c[j] = aux;
                }
}

void mostrarConsultas(struct Consulta c[], int n) {
    if (n == 0) {
        printf("\nSem consultas.\n");
        return;
    }

    printf("\nData      Especialidade       Localidade\n");
    for (int i = 0; i < n; i++)
        printf("%-9s %-18s %-10s\n", c[i].data, c[i].especialidade, c[i].localidade);
}

void menuConsultas(struct Consulta c[], int n) {
    int op;
    do {
        printf("\n1 - Por data\n2 - Por esp.\n3 - Por loc.\n4 - Agrupar\n0 - Voltar\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) ordenarData(c, n);
        else if (op == 2) ordenarEsp(c, n);
        else if (op == 3) ordenarLoc(c, n);
        else if (op == 4) agruparEspData(c, n);

        if (op >= 1 && op <= 4) mostrarConsultas(c, n);
    } while (op != 0);
}
