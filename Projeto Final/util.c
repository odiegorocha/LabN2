#include <stdlib.h>
#include <string.h>
#include "util.h"

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
    if (mes == 2) return 28;
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) return 30;
    else return 31;
}

int calcularDiferencaDias(char data1[], char data2[]) {
    int d1 = extrairDia(data1);
    int m1 = extrairMes(data1);
    int a1 = extrairAno(data1);
    int d2 = extrairDia(data2);
    int m2 = extrairMes(data2);
    int a2 = extrairAno(data2);
    if (a1 == a2 && m1 == m2) return d2 - d1;

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
