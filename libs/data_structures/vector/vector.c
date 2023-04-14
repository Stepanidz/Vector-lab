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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return *(v->data + i);
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        v->capacity++;
    } else if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }
    *(v->data + v->size++) = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Empty vector");
        exit(1);
    }
    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int* back(vector *v) {
    return v->data + v->size - 1;
}

int* front(vector *v) {
    return v->data;
}