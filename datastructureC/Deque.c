#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

void DequeInit(Deque* pq1){
    pq1->head = NULL;
    pq1->tail = NULL;
   
}
int DQisEmpty(Deque* pq1){
    if(pq1 -> head =NULL) return 1;
    else return 0;
}

void DQAddFirst(Deque* pq1,data data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    
    newnode -> next = pq1->head;
    
    if(DQisEmpty(pq1)){
        pq1->tail = newnode;
    }else{
        pq1->head->pre=newnode;
    }

    newnode->pre = NULL;
    pq1->head = newnode;
    
}
void DQAddLast(Deque* pq1,data data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode->next = NULL;
    newnode -> pre = pq1->tail;
    if(DQisEmpty(pq1)){
        pq1->head = newnode;
    }else{
        pq1->tail->next = newnode;
    }
   newnode->next = NULL;
    pq1->tail = newnode;
}

data DQRemoveFirst(Deque* pq1){
    if(DQisEmpty(pq1)){
        exit(-1);
    }
    node* renode = pq1->head;
    data Data = renode->data;

    
    pq1->head = pq1->head->next;
    free(renode);
    
    if(pq1->head == NULL)
    pq1->tail == NULL;
    else 
    pq1->head->pre=NULL;

    return Data;

}
data DQRemoveLast(Deque* pq1){
    if(DQisEmpty){
        exit(-1);
    }
     node* renode = pq1->tail;
    data Data = renode->data;

    
    pq1->tail = pq1->tail->pre;
    free(renode);

    if(pq1->tail == NULL)
    pq1->head = NULL;
    else 
    pq1->tail->next=NULL;

    return Data;
}

data DQgetFirst(Deque* pq1){
if(DQisEmpty){
    exit(-1);
}
return pq1->head->data;
}
data DQfetLast(Deque* pq1){
if(DQisEmpty){
    exit(-1);
}
return pq1->head->data;
}