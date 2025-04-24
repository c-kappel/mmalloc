#include "mmalloc.h"
#include "unistd.h"
#include <iostream>

Block* head = (Block*)sbrk(0);

Block* findFreeInitializedMem(){
    Block* bottomInitializedMem = head;
    while(bottomInitializedMem->free == 1){ // occupied
        bottomInitializedMem = bottomInitializedMem->next;
    }
    if(bottomInitializedMem == nullptr){
        return NULL;
    }
    else{
        
    }
    
}

void* allocate(size_t size){
    if(size == 0){
        return NULL;
    }
    void* top = sbrk(0);
}

int main(){

}