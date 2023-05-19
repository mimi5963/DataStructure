#ifndef __HEAP_H
#define __HEAP_H

#define MAX_LEN 100

typedef char Hdata;
typedef int GetPriority(Hdata d1, Hdata d2);


typedef struct _UHeap{
    GetPriority* comp;
    Hdata HeapArr[MAX_LEN];
    int numofdata;
}Heap;

void HeapInit(Heap* hp, GetPriority comp);
int HisEmpty(Heap* hp);
void HInsert(Heap* hp, Hdata data);
Hdata HDelete(Heap* hp);


#endif