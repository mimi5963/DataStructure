#include<stdio.h>
#include<stdlib.h>
#include"Circular_LinkedList.h"

void Linsert(List* plist,Ldata data){
    Node* newnode =(Node*)malloc(sizeof(Node));
    newnode->data = data;
    if(plist->tail == NULL){
        newnode->next= newnode;
        plist->tail = newnode;
    }else{
    newnode->next = plist->tail->next;
    plist->tail->next = newnode;
    plist->tail = newnode;
    }
    (plist->size)++;
}
void Linit(List* plist){
    plist->size =0;
    plist->cur = NULL;
    plist->before= NULL;
    plist->tail =NULL;

}
void LinsertFirst(List* plist,Ldata data){
    Node* newnode =(Node*)malloc(sizeof(Node));
    newnode->data = data;
    if(plist->tail == NULL){ //여기는 한 방향 연결리스트와 다름
        newnode->next= newnode;
        plist->tail = newnode;
    }else{
    newnode->next = plist->tail->next;
    plist->tail->next = newnode;
    }
    (plist->size)++;
}

int LFirst(List* plist,Ldata* data){
    if(plist->tail ==NULL) return 0;

    plist->cur = plist->tail->next; //첫번째 
    plist->before = plist->tail; //끝
    *data = plist->cur->data;
    return 1;
}
int LNext(List* plist,Ldata* data){
    if(plist->tail ==NULL) return 0; //무한 반복 가능
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *data = plist->cur->data;
    return 1;
}
Ldata LRemove(List* plist){
    Node* Rnode = plist->cur;
    Ldata Rdata = Rnode->data;

    if(Rnode == plist->tail){ //삭제 대상이 tail임 
        if(plist->tail == plist->tail->next) // 노드가 1개일 경우
        {
            plist->tail = NULL;
        }else{
            plist->tail = plist->before; //그 외의 경우  
        }
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(Rnode);

    (plist->size)--;
    return Rdata;
}
int Lcount(List* plist){
    return plist->size;
}
