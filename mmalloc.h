#include <iostream>
#pragma once

struct Block{
    size_t size;
    int free; // 0 free, 1 occupied
    Block* next;
};

Block* findFreeInitializedMemory();

void* allocate();

void* free();