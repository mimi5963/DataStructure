#include"LinkedQ.h"
#include<stdio.h>
#include<stdlib.h>

void QueInint(Que* pq){
    pq->f = NULL;
    pq->r = NULL;
    pq->size =0;
}
int Qempty(Que* pq){
if(pq->f == NULL ) return 1; //dqu 연산시 마지막 노드 삭제하면 pq->f ==null이지만, r은 모름..! 그래서 
                            //empty는 f로 판단하는게 좋다.
else return 0;
}

void Enqu(Que* pq, data data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data =data;
    newnode->next = NULL;
    if(pq->r==NULL){
        pq->f = newnode;
        pq->r = newnode;
    }else{
        pq->r->next = newnode;
        pq->r = newnode;
    }
    (pq->size)++;
}
data Dqu(Que* pq){
    if(Qempty(pq)){
        printf("빈 큐 \n");
        exit(-1);
    }
    node* remove = pq->f;
    data rdata = pq->f->data;
     
    pq->f = pq->f->next;
    free(remove);
    (pq->size)--;
    return rdata;
}
data qpeek(Que* pq){
    if(Qempty(pq)){
        printf("빈 큐 \n");
        exit(-1);
    }
    return pq->f->data;
}
int size(Que* pq){
    return pq->size;
}