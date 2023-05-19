#include<stdio.h>
#include<stdlib.h>
#include"DB_LinkedList.h"

void Listinit(List* plist){
    plist->head = NULL;
    plist->cur =NULL;
    plist->size =0;
}
void Linsert(List* plist, Ldata data){
    //맨 앞에 데이터 추가 양 끝은 null
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    newnode->next = plist->head; //처음에는 null, 다음부터는 있음
    if(plist->head != NULL){
        plist->head->pre = newnode;
    }
    newnode->pre = NULL;
    plist->head = newnode;
    (plist->size)++;
}

int Lfirst(List* plist,Ldata* data){
if(plist->head == NULL)
return 0;
plist->cur = plist->head;
*data =  plist->cur->data;
return 1;
}
int LNext(List* plist,Ldata* data){
    if(plist->cur->next == NULL)
    return 0;

    plist->cur = plist->cur->next;
    *data = plist->cur->data;
    return 1;
}
int Lprevious(List* plist,Ldata* data){
    if(plist->cur->pre == NULL) return 0;

     plist->cur = plist->cur->pre;
    *data = plist->cur->data;
    return 1;
}

int Lsize(List* plist){
    return plist->size;
}