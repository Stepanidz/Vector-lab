//
// Created by Stepan on 14.04.2023.
//
#include <malloc.h>
#include "vector.h"


vector createVector(size_t n) {
    int *data = (int*) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "Wrong value: capacity");
        exit(1);
    }
    return (vector) {
            data,
            0,
            n
    };
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) v->data = NULL;
    v->data = (int*) realloc(v->data ,sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "Wrong value: newCapacity = %llu", newCapacity);
        exit(1);
    }
    v->capacity = newCapacity;
    if (newCapacity < v->size) v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}