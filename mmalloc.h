#include <iostream>
#pragma once

struct Block{
    size_t size;
    int free; // 0 free, 1 occupied
    Block* next;
};

Block* findFreeInitializedMem(size_t size);

void* allocate(size_t size);

void free(void* ptr);