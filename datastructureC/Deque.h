#ifndef _DQUE_H
#define _DQUE_H


typedef int data;

typedef struct _node{
    data data;
    struct _node* next;
    struct _node* pre;
   
}node;

typedef struct _Dque{
    node* head;
    node* tail;
    int size;
}Dque;

typedef Dque Deque;

void DequeInit(Deque* pq1);
int DQisEmpty(Deque* pq1);

void DQAddFirst(Deque* pq1,data data);
void DQAddLast(Deque* pq1,data data);

data DQRemoveFirst(Deque* pq1);
data DQRemoveLast(Deque* pq1);

data DQgetFirst(Deque* pq1);
data DQfetLast(Deque* pq1);

#endif