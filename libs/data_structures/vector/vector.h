//
// Created by Stepan on 14.04.2023.
//

#ifndef VECTORLAB_VECTOR_H
#define VECTORLAB_VECTOR_H

#endif //VECTORLAB_VECTOR_H

#include <stdio.h>
#include <stdbool.h>

#define SIZE_MAX 500000

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

bool isEmpty(vector *v);

bool isFull(vector *v);

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);