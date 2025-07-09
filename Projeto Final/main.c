#include <stdio.h>
#include "consultas.h"
#include "mensalidades.h"

char dataAtual[9];

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

        if (op == 1) agendar(consultas, &qtdC);
        else if (op == 2) cadastrarMensalidade(mensalidades, &qtdM);
        else if (op == 3) menuVisualizar(consultas, qtdC, mensalidades, qtdM);
    } while (op != 0);

    salvarDados(consultas, qtdC, mensalidades, qtdM);

    return 0;
}
