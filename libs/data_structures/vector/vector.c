#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "vector.h"

// 14.2

vector createVector(size_t  capacity) {
    vector v = { (int*)malloc(sizeof(int) * capacity), capacity, capacity };

    if (!(v.data)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}