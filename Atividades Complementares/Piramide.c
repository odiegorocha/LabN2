#include <stdio.h>

int main() {
    int linhas = 5;
    for (int i = 0; i < linhas; i++) {

        for (int j = 0; j < linhas - i - 1; j++) {
            printf(" ");
        }

        for (int k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
