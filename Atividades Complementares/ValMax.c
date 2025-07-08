#include <stdio.h>

int main() {
    short s = -1;
    for (int i = 0; i < 32; i++) {
        if (s + 1 > s)
            s++;
        else
            break;
    }
    printf("Máximo short: %d\n", s);

    long l = -1;
    for (int i = 0; i < 32; i++) {
        if (l + 1 > l)
            l++;
        else
            break;
    }
    printf("Máximo long: %ld\n", l);

    long long ll = -1;
    for (int i = 0; i < 32; i++) {
        if (ll + 1 > ll)
            ll++;
        else
            break;
    }
    printf("Máximo long long: %lld\n", ll);

    unsigned long ul = 0;
    for (int i = 0; i < 32; i++) {
        if (ul + 1 > ul)
            ul++;
        else
            break;
    }
    printf("Máximo unsigned long: %lu\n", ul);

    return 0;
}
