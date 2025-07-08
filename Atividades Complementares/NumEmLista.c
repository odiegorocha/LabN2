#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lista[50];
    int numero, i, indice = -1, indice_maior = 0;

    srand(time(NULL));
    for (i = 0; i < 50; i++) {
        lista[i] = rand() % 100;
    }

    printf("Digite um número: ");
    scanf("%d", &numero);

    printf("Lista gerada:\n");
    for (i = 0; i < 50; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    for (i = 0; i < 50; i++) {
        if (lista[i] == numero) {
            indice = i;
            break;
        }
    }

    for (i = 1; i < 50; i++) {
        if (lista[i] > lista[indice_maior]) {
            indice_maior = i;
        }
    }

    if (indice != -1) {
        printf("Índice do número %d: %d\n", numero, indice);
    } else {
        printf("Número %d não encontrado: -1.\n", numero);
    }

    printf("Índice do maior valor (%d): %d\n", lista[indice_maior], indice_maior);

    return 0;
}
