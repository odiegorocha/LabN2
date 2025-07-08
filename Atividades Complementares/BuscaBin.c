#include <stdio.h>

int buscaBinaria(int lista[], int inicio, int fim, int alvo) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista[meio] == alvo) return meio;
        else if (alvo < lista[meio]) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

int main() {
    int lista[] = {2, 5, 7, 10, 14, 18, 21, 29, 31, 34, 39, 41, 45, 48, 52};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int alvo;

    printf("Digite o número: ");
    scanf("%d", &alvo);

    printf("Lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    int indice = buscaBinaria(lista, 0, tamanho - 1, alvo);

    if (indice != -1) {
        printf("Número %d encontrado no índice %d.\n", alvo, indice);
    } else {
        printf("Número %d não encontrado.\n", alvo);
    }

    return 0;
}
