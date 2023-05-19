#ifndef __Cir_queue_h
#define __Cir_queue_h

#define MAX_LEN 100
typedef int data;

typedef struct _Cqueue{
    int frount;
    int re;
    data qudata[MAX_LEN];
}Cqueue;

typedef Cqueue Queue;

void QueInit(Queue* qp);
int QEmpty(Queue* qp);

void Enqueue(Queue* qp, data data);
data Dequeue(Queue* qp);
data peek(Queue* qp);

#endif