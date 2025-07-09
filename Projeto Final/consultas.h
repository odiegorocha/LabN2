#ifndef CONSULTAS_H
#define CONSULTAS_H

#define TAM 5

struct Consulta {
    char data[9];
    char especialidade[20];
    char localidade[20];
};

void agendar(struct Consulta consultas[], int *qtd);
void ordenarData(struct Consulta c[], int n);
void ordenarEsp(struct Consulta c[], int n);
void ordenarLoc(struct Consulta c[], int n);
void agruparEspData(struct Consulta c[], int n);
void mostrarConsultas(struct Consulta c[], int n);
void menuConsultas(struct Consulta c[], int n);

#endif
