#include "mmalloc.h"
#include "unistd.h"
#include <iostream>

Block* head = nullptr;
Block* tail = nullptr;

Block* findFreeInitializedMem(size_t size){
    Block* currentBlock = head;
    while(currentBlock != nullptr){ 
        if(currentBlock->free == 0 && currentBlock->size >= size){
            currentBlock->free = 1;
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
        head->free = 1;
        head->size = sizeof(Block) + size;
        head->next = nullptr;
        tail = head;
        return head;
    }
    Block* avaliableMemory = findFreeInitializedMem(sizeof(Block) + size);
    if(avaliableMemory == nullptr){ // new space
        Block* newAllocatedMemory = (Block*)sbrk(sizeof(Block) + size);
        tail->next = newAllocatedMemory;
        tail = newAllocatedMemory;
        tail->free = 1;
        tail->size = sizeof(Block) + size;
        tail->next = nullptr;
        return tail;
    }
    return avaliableMemory;
}

void free(Block* ptr){
    if(ptr == nullptr){
        return;
    }
    ptr->free = 0;
}



int main(){

}