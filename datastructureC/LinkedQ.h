#ifndef __Linked_Q
#define __Linked_Q

typedef int data;

typedef struct _node
{
    data data;
    struct _node* next;
}node;

typedef  struct _LinkedQ{
    node* f;
    node* r;
    int size;
}LinkedQ;

typedef LinkedQ Que;

void QueInint(Que* pq);
int Qempty(Que* pq);

void Enqu(Que* pq, data data);
data Dqu(Que* pq);
data qpeek(Que* pq);
int size(Que* pq);



#endif