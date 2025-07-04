#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

char dataAtual[9];

enum Plano { NORMAL = 1, PRIORIDADE = 2, PLUS = 3 };

struct Consulta {
    char data[9];
    char especialidade[20];
    char localidade[20];
};

struct Mensalidade {
    char dataConta[9];
    char dataVencimento[9];
    float valor;
    float juros;
    enum Plano tipoPlano;
};

int extrairDia(char data[]) {
    char d[3];
    strncpy(d, data, 2);
    d[2] = '\0';
    return atoi(d);
}

int extrairMes(char data[]) {
    char m[3];
    strncpy(m, data + 2, 2);
    m[2] = '\0';
    return atoi(m);
}

int extrairAno(char data[]) {
    char a[5];
    strncpy(a, data + 4, 4);
    a[4] = '\0';
    return atoi(a);
}

int diasMes(int mes) {
    if (mes == 2) {
        return 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

int calcularDiferencaDias(char data1[], char data2[]) {
    int d1 = extrairDia(data1);
    int m1 = extrairMes(data1);
    int a1 = extrairAno(data1);

    int d2 = extrairDia(data2);
    int m2 = extrairMes(data2);
    int a2 = extrairAno(data2);

    if (a1 == a2 && m1 == m2) {
        return d2 - d1;
    }

    int dias = 0;

    dias += diasMes(m1) - d1;
    m1++;

    while (a1 < a2 || (a1 == a2 && m1 < m2)) {
        dias += diasMes(m1);
        m1++;
        if (m1 > 12) {
            m1 = 1;
            a1++;
        }
    }

    dias += d2;

    return dias;
}

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

    if (esp == 1) {
        strcpy(consultas[*qtd].especialidade, "Clinico");
    } else {
        strcpy(consultas[*qtd].especialidade, "Pediatra");
    }

    int loc;
    do {
        printf("Localidade:\n1 - Ceara\n2 - Maranhao\nOpcao: ");
        scanf("%d", &loc);
    } while (loc != 1 && loc != 2);

    if (loc == 1) {
        strcpy(consultas[*qtd].localidade, "Ceara");
    } else {
        strcpy(consultas[*qtd].localidade, "Maranhao");
    }

    (*qtd)++;
}

void editarConsulta(struct Consulta consultas[], int qtd) {
    if (qtd == 0) {
        printf("\nSem consultas.\n");
        return;
    }

    mostrarConsultas(consultas, qtd);
    int i;
    printf("Indice da consulta (0 a %d): ", qtd - 1);
    scanf("%d", &i);
    if (i < 0 || i >= qtd) {
        printf("Indice invalido.\n");
        return;
    }

    printf("Nova data (DDMMAAAA): ");
    scanf(" %8[^\n]", consultas[i].data);

    int esp;
    do {
        printf("Especialidade:\n1 - Clinico\n2 - Pediatra\nOpcao: ");
        scanf("%d", &esp);
    } while (esp != 1 && esp != 2);

    if (esp == 1) {
        strcpy(consultas[i].especialidade, "Clinico");
    } else {
        strcpy(consultas[i].especialidade, "Pediatra");
    }

    int loc;
    do {
        printf("Localidade:\n1 - Ceara\n2 - Maranhao\nOpcao: ");
        scanf("%d", &loc);
    } while (loc != 1 && loc != 2);

    if (loc == 1) {
        strcpy(consultas[i].localidade, "Ceara");
    } else {
        strcpy(consultas[i].localidade, "Maranhao");
    }
}

void deletarConsulta(struct Consulta consultas[], int *qtd) {
    if (*qtd == 0) {
        printf("\nSem consultas.\n");
        return;
    }

    mostrarConsultas(consultas, *qtd);
    int i;
    printf("Indice da consulta (0 a %d): ", *qtd - 1);
    scanf("%d", &i);
    if (i < 0 || i >= *qtd) {
        printf("Indice invalido.\n");
        return;
    }

    for (int j = i; j < *qtd - 1; j++) {
        consultas[j] = consultas[j + 1];
    }
    (*qtd)--;
}

void ordenarData(struct Consulta c[], int n) {
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(c[i].data, c[j].data) > 0) {
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
}

void ordenarEsp(struct Consulta c[], int n) {
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(c[i].especialidade, c[j].especialidade) > 0) {
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
}

void ordenarLoc(struct Consulta c[], int n) {
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(c[i].localidade, c[j].localidade) > 0) {
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
}

void agruparEspData(struct Consulta c[], int n) {
    ordenarEsp(c, n);
    struct Consulta aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(c[i].especialidade, c[j].especialidade) == 0) {
                if (strcmp(c[i].data, c[j].data) > 0) {
                    aux = c[i];
                    c[i] = c[j];
                    c[j] = aux;
                }
            }
        }
    }
}

void mostrarConsultas(struct Consulta c[], int n) {
    if (n == 0) {
        printf("\nSem consultas.\n");
        return;
    }

    printf("\nData      Especialidade       Localidade\n");
    for (int i = 0; i < n; i++) {
        printf("%-9s %-18s %-10s\n", c[i].data, c[i].especialidade, c[i].localidade);
    }
}

void menuConsultas(struct Consulta c[], int *n) {
    int op;
    do {
        printf("\n1 - Por data\n2 - Por esp.\n3 - Por loc.\n4 - Agrupar\n5 - Editar\n6 - Deletar\n0 - Voltar\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            ordenarData(c, *n);
            mostrarConsultas(c, *n);
        } else if (op == 2) {
            ordenarEsp(c, *n);
            mostrarConsultas(c, *n);
        } else if (op == 3) {
            ordenarLoc(c, *n);
            mostrarConsultas(c, *n);
        } else if (op == 4) {
            agruparEspData(c, *n);
            mostrarConsultas(c, *n);
        } else if (op == 5) {
            editarConsulta(c, *n);
        } else if (op == 6) {
            deletarConsulta(c, n);
        }
    } while (op != 0);
}

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

void editarMensalidade(struct Mensalidade m[], int qtd) {
    if (qtd == 0) {
        printf("\nSem mensalidades.\n");
        return;
    }

    mostrarMensalidades(m, qtd);
    int i;
    printf("Indice da mensalidade (0 a %d): ", qtd - 1);
    scanf("%d", &i);
    if (i < 0 || i >= qtd) {
        printf("Indice invalido.\n");
        return;
    }

    printf("Nova data conta (DDMMAAAA): ");
    scanf(" %8[^\n]", m[i].dataConta);

    printf("Nova data venc. (DDMMAAAA): ");
    scanf(" %8[^\n]", m[i].dataVencimento);

    printf("Novo valor: ");
    scanf("%f", &m[i].valor);

    printf("Novo juros fixo: ");
    scanf("%f", &m[i].juros);

    int tipo;
    do {
        printf("Plano:\n1 - Normal\n2 - Prioridade\n3 - Plus\nOpcao: ");
        scanf("%d", &tipo);
    } while (tipo < 1 || tipo > 3);

    m[i].tipoPlano = tipo;
}

void deletarMensalidade(struct Mensalidade m[], int *qtd) {
    if (*qtd == 0) {
        printf("\nSem mensalidades.\n");
        return;
    }

    mostrarMensalidades(m, *qtd);
    int i;
    printf("Indice da mensalidade (0 a %d): ", *qtd - 1);
    scanf("%d", &i);
    if (i < 0 || i >= *qtd) {
        printf("Indice invalido.\n");
        return;
    }

    for (int j = i; j < *qtd - 1; j++) {
        m[j] = m[j + 1];
    }
    (*qtd)--;
}

void mostrarMensalidades(struct Mensalidade m[], int n) {
    if (n == 0) {
        printf("\nSem mensalidades.\n");
        return;
    }

    printf("\nData Conta Vencimento  Valor   Juros  Plano\n");
    for (int i = 0; i < n; i++) {
        char planoStr[15];

        if (m[i].tipoPlano == NORMAL) {
            strcpy(planoStr, "Normal");
        } else if (m[i].tipoPlano == PRIORIDADE) {
            strcpy(planoStr, "Prioridade");
        } else {
            strcpy(planoStr, "Plus");
        }

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

        if (atraso > 0) {
            valorFinal += m[i].valor * 0.01 * atraso;
        }

        char planoStr[15];

        if (m[i].tipoPlano == NORMAL) {
            strcpy(planoStr, "Normal");
        } else if (m[i].tipoPlano == PRIORIDADE) {
            strcpy(planoStr, "Prioridade");
        } else {
            strcpy(planoStr, "Plus");
        }

        if (atraso < 0) {
            atraso = 0;
        }

        printf("%-10s %-10s %.2f  %4d %-10s %.2f\n",
               m[i].dataConta,
               m[i].dataVencimento,
               m[i].valor,
               atraso,
               planoStr,
               valorFinal);
    }
}

void menuVisualizar(struct Consulta c[], int *qtdC, struct Mensalidade m[], int *qtdM) {
    int op;
    do {
        printf("\n1 - Consultas\n2 - Mensalidades\n3 - Mensalidades atualizadas\n4 - Editar mensalidade\n5 - Deletar mensalidade\n0 - Voltar\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            menuConsultas(c, qtdC);
        } else if (op == 2) {
            mostrarMensalidades(m, *qtdM);
        } else if (op == 3) {
            mostrarMensalidadesAtualizadas(m, *qtdM);
        } else if (op == 4) {
            editarMensalidade(m, *qtdM);
        } else if (op == 5) {
            deletarMensalidade(m, qtdM);
        }
    } while (op != 0);
}

void salvarDados(struct Consulta consultas[], int qtdC, struct Mensalidade mensalidades[], int qtdM) {
    FILE *f1 = fopen("consultas.dat", "wb");
    if (f1 != NULL) {
        fwrite(&qtdC, sizeof(int), 1, f1);
        fwrite(consultas, sizeof(struct Consulta), qtdC, f1);
        fclose(f1);
    }

    FILE *f2 = fopen("mensalidades.dat", "wb");
    if (f2 != NULL) {
        fwrite(&qtdM, sizeof(int), 1, f2);
        fwrite(mensalidades, sizeof(struct Mensalidade), qtdM, f2);
        fclose(f2);
    }
}

void carregarDados(struct Consulta consultas[], int *qtdC, struct Mensalidade mensalidades[], int *qtdM) {
    FILE *f1 = fopen("consultas.dat", "rb");
    if (f1 != NULL) {
        fread(qtdC, sizeof(int), 1, f1);
        fread(consultas, sizeof(struct Consulta), *qtdC, f1);
        fclose(f1);
    }

    FILE *f2 = fopen("mensalidades.dat", "rb");
    if (f2 != NULL) {
        fread(qtdM, sizeof(int), 1, f2);
        fread(mensalidades, sizeof(struct Mensalidade), *qtdM, f2);
        fclose(f2);
    }
}

int main() {
    struct Consulta consultas[TAM];
    struct Mensalidade mensalidades[TAM];
    int qtdC = 0, qtdM = 0, op;

    carregarDados(consultas, &qtdC, mensalidades, &qtdM);

    printf("\nData atual (DDMMAAAA): ");
    scanf(" %8[^\n]", dataAtual);

    do {
        printf("\n1 - Agendar\n2 - Financeiro\n3 - Visualizar\n0 - Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            agendar(consultas, &qtdC);
        } else if (op == 2) {
            cadastrarMensalidade(mensalidades, &qtdM);
        } else if (op == 3) {
            menuVisualizar(consultas, &qtdC, mensalidades, &qtdM);
        }
    } while (op != 0);

    salvarDados(consultas, qtdC, mensalidades, qtdM);

    return 0;
}
