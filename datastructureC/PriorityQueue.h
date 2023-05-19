#ifndef __PRIORITY_QUEUE_H
#define __PRIORITY_QUEUE_H

#include "Heap.h"

typedef Heap PQueue;
typedef Hdata PQdata;

void PQueueInit(PQueue* ppq, GetPriority pc);
int PQisEmpty(PQueue* ppq);

void PEnqueue(PQueue * ppq, PQdata data);
PQdata PDqueue(PQueue* ppq);

#endif