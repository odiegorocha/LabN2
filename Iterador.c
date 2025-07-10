#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double *data;
    int capacity;
    int size;
    int current;
} Iterator;

Iterator *createIterator(int capacity) {
    Iterator *it = malloc(sizeof(Iterator));
    it->data = malloc(sizeof(double) * capacity);
    it->capacity = capacity;
    it->size = 0;
    it->current = 0;
    return it;
}

void add(Iterator *it, double value) {
    if (it->size < it->capacity)
        it->data[it->size++] = value;
}

bool hasNext(Iterator *it) {
    return it->current < it->size;
}

double next(Iterator *it) {
    return hasNext(it) ? it->data[it->current++] : 0.0;
}

int size(Iterator *it) {
    return it->size;
}

void seek(Iterator *it, int index) {
    if (index >= 0 && index < it->size)
        it->current = index;
}

void iterate(Iterator *it, void (*func)(double *)) {
    for (int i = 0; i < it->size; i++)
        func(&it->data[i]);
}

int cmp(const void *a, const void *b) {
    double da = *(double *)a;
    double db = *(double *)b;
    return (da > db) - (da < db);
}

double media(Iterator *it) {
    double sum = 0;
    for (int i = 0; i < it->size; i++)
        sum += it->data[i];
    return sum / it->size;
}

double mediana(Iterator *it) {
    double *copy = malloc(sizeof(double) * it->size);
    for (int i = 0; i < it->size; i++)
        copy[i] = it->data[i];
    qsort(copy, it->size, sizeof(double), cmp);
    double m;
    if (it->size % 2 == 0)
        m = (copy[it->size/2 - 1] + copy[it->size/2]) / 2.0;
    else
        m = copy[it->size/2];
    free(copy);
    return m;
}

void ordenar(Iterator *it) {
    qsort(it->data, it->size, sizeof(double), cmp);
}

int main() {
    int n = 1000;
    Iterator *it = createIterator(n);
    for (int i = 0; i < n; i++)
        add(it, rand() % 10000 / 10.0);

    printf("Tamanho: %d\n", size(it));
    printf("Media: %.2f\n", media(it));
    printf("Mediana: %.2f\n", mediana(it));
    ordenar(it);
    seek(it, 0);
    while (hasNext(it)) {
        double val = next(it);
        break;
    }

    free(it->data);
    free(it);
    return 0;
}
