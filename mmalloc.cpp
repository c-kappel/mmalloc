#include "mmalloc.h"
#include "unistd.h"
#include <iostream>

Block* head = nullptr;
Block* tail = nullptr;

Block* findFreeInitializedMem(size_t size){
    Block* currentBlock = head;
    while(currentBlock != nullptr){ 
        if(currentBlock->free == 1 && currentBlock->size >= size){
            currentBlock->free = 0;
            return currentBlock;
        }
        currentBlock = currentBlock->next;
    }
    return nullptr;
}


void* allocate(size_t size){;
    if(size == 0){
        return NULL;
    }
    if(head == nullptr){ //first allocation
        head = (Block*)sbrk(sizeof(Block) + size);
        head->free = 0;
        head->size = sizeof(Block) + size;
        head->next = nullptr;
        tail = head;
        return (void*)(head+1);
    }
    Block* availableMemory = findFreeInitializedMem(size);
    if(availableMemory == nullptr){ // new space
        Block* newAllocatedMemory = (Block*)sbrk(sizeof(Block) + size);
        tail->next = newAllocatedMemory;
        tail = newAllocatedMemory;
        tail->free = 0;
        tail->size = sizeof(Block) + size;
        tail->next = nullptr;
        return (void*)(tail+1);
    }
    return (void*)(availableMemory+1);
}

void free(void* ptr){
    if(ptr == nullptr){
        return;
    }
    Block* blockPortion = (Block*)(ptr)-1;
    blockPortion->free = 1;
}

int main(){
    //code
}
