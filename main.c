#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    assert(isEmpty(&v));

    pushBack(&v, 1);
    assert(v.data[0] == 1 && v.capacity == 1 && v.size == 1);

    reserve(&v, 0);
    pushBack(&v, 7);
    assert(v.data[0] == 7 && v.capacity == 1 && v.size == 1);

    reserve(&v, 0);
    pushBack(&v, 13);
    assert(v.data[0] == 13 && v.capacity == 1 && v.size == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(0);
    assert(isFull(&v));

    pushBack(&v, 1);
    assert(v.data[0] == 1 && v.capacity == 1 && v.size == 1);

    pushBack(&v, 28);
    assert(v.data[1] == 28 && v.capacity == 2 && v.size == 2);

    pushBack(&v, 24);
    pushBack(&v, 123450);
    assert(v.data[3] == 123450 && v.capacity == 4 && v.size == 4);

    pushBack(&v, -123450);
    assert(v.data[4] == -123450 && v.capacity == 8 && v.size == 5);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    pushBack(&v, -700);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_nonEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    assert(&v.data[0] == atVector(&v, 0));

    pushBack(&v, 44);
    assert(v.size == 2);

    assert(&v.data[1] == atVector(&v, 1));

    pushBack(&v, 404);
    pushBack(&v, 702);
    assert(v.size == 4);

    assert(&v.data[2] == atVector(&v, 2));

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 12);
    pushBack(&v, 14);
    pushBack(&v, 16);

    assert(v.size == 4);
    assert(&v.data[3] == atVector(&v, 3));

    pushBack(&v, 16);
    assert(&v.data[4] == atVector(&v, 4));

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 12);
    pushBack(&v, 14);
    pushBack(&v, 16);

    assert(v.size == 4);
    assert(&v.data[3] == back(&v));

    pushBack(&v, 16);
    assert(&v.data[4] == back(&v));

    popBack(&v);
    assert(&v.data[3] == back(&v));

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 12);
    pushBack(&v, 14);
    pushBack(&v, 16);

    assert(v.size == 4);
    assert(&v.data[0] == front(&v));

    pushBack(&v, 16);
    assert(&v.data[0] == front(&v));

    popBack(&v);
    assert(&v.data[0] == front(&v));

    reserve(&v, 2);
    assert(&v.data[0] == front(&v));

    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_nonEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    vector v = createVector(SIZE_MAX);
    test();

    return 0;
}