#ifndef MENSALIDADES_H
#define MENSALIDADES_H

#include "consultas.h"

enum Plano { NORMAL = 1, PRIORIDADE = 2, PLUS = 3 };

struct Mensalidade {
    char dataConta[9];
    char dataVencimento[9];
    float valor;
    float juros;
    enum Plano tipoPlano;
};

extern char dataAtual[9];

void cadastrarMensalidade(struct Mensalidade m[], int *qtd);
void mostrarMensalidades(struct Mensalidade m[], int n);
void mostrarMensalidadesAtualizadas(struct Mensalidade m[], int n);
void menuVisualizar(struct Consulta c[], int qtdC, struct Mensalidade m[], int qtdM);
void salvarDados(struct Consulta c[], int qtdC, struct Mensalidade m[], int qtdM);
void carregarDados(struct Consulta c[], int *qtdC, struct Mensalidade m[], int *qtdM);

#endif
