#include <stdio.h>

int main() {
    int numero, original, reverso = 0;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    original = numero;

    while (numero > 0) {
        int digito = numero % 10;
        reverso = reverso * 10 + digito;
        numero = numero / 10;
    }

    if (original == reverso) {
        printf("O número é um palíndromo.\n");
    } else {
        printf("O número não é um palíndromo.\n");
    }

    return 0;
}
