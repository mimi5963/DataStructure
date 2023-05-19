#include "PriorityQueue.h"
#include "Heap.h"

void PQueueInit(PQueue* ppq, GetPriority pc){
    HeapInit(ppq,pc);
}
int PQisEmpty(PQueue* ppq){
    return HisEmpty(ppq);
}

void PEnqueue(PQueue * ppq, PQdata data){
    HInsert(ppq,data);
}
PQdata PDqueue(PQueue* ppq){
    return HDelete(ppq);
}