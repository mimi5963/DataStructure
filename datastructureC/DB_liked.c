#include<stdio.h>
#include<stdlib.h>
#include"DB_linked.h"


void Listinit(List* plist){
    plist->head = (node*)malloc(sizeof(node));
    plist->head->pre = NULL;
    plist->head->next = plist->tail;
    

    plist->tail = (node*)malloc(sizeof(node));
    plist->tail->pre=plist->head;
    plist->tail->next =NULL;
    plist->size =0;
     
}
void Linsert(List* plist, Ldata data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    
    newnode->next = plist->tail->pre->next; //초기에는 head->next인 tail
    newnode->pre = plist->tail->pre; //초기에는 tail->pre인 head
    plist->tail->pre->next = newnode; //초기에는 head->next가 newnode 
    plist->tail->pre = newnode; //최근 이전노드를 newnode로 두기
    
    
    (plist->size)++;
}

int Lfirst(List* plist,Ldata* data){
    if(plist->head->next == plist->tail) return 0;

    plist->cur = plist->head->next;
    *data = plist->cur->data;
    return 1;
}
int LNext(List* plist,Ldata* data){
    if(plist->cur->next == plist->tail) return 0;
    plist->cur = plist->cur->next;
    *data =plist->cur->data;
    return 1;
}
int LPrivious(List* plist, Ldata* data){
    if(plist->cur->pre == plist->head) return 0;
    plist->cur = plist->cur->pre;
    *data =plist->cur->data;
    return 1;
}
Ldata LRemove(List* plist){
    node* Rnode = plist->cur;
    Ldata Rdata = Rnode->data;

    
    plist->cur->pre->next = plist->cur->next;
    plist->cur->next->pre = plist->cur->pre;
    plist->cur = plist->cur->pre; //이거 빼먹을뻔! 
    free(Rnode);
    (plist->size) --;
    return Rdata;
}
int Lsize(List* plist){

    return plist->size;
}