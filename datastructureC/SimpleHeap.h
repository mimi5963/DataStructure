#ifndef __SIMPLE_HEAP_H
#define __SIMPLE_HEAP_

#define MAX_LEN 100
typedef char Hdata;
typedef int Priority;

typedef struct _Helem{
    Hdata data;
    Priority pr;
}helem;

typedef struct _Sheep{
    int numofdata;
    helem helemarr[MAX_LEN];
}Heap;

void HeapInit(Heap* hp);
int HisEmpty(Heap* hp);
void HInsert(Heap* hp, Hdata data,Priority pr);
Hdata HDelete(Heap* hp);

#endif