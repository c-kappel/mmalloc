#include <iostream>
#pragma once

struct Block{
    size_t size;
    int free; // 1 free, 0 occupied
    Block* next;
};

Block* findFreeInitializedMem(size_t size);

void* allocate(size_t size);

void free(void* ptr);