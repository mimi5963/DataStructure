#include <stdio.h>
#include <stdlib.h>
#include "LinkedListDummy.h"

void ListInit(List* plist){
    plist->head = (Node*)malloc(sizeof(Node)); //더미노드 추가
    plist->head->next = NULL; 
    plist->before= NULL;
    plist->cur =NULL;
    plist->size =0;
}
void LFinsert(List* plist, Ldata data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    
     newnode->next = plist->head->next; 
     plist->head->next = newnode;
     (plist->size)++;

}
void LSInsert(List* plist,Ldata data){

}
void Linsert(List* plist, Ldata data){
    if(plist->comp == NULL)
    LFinsert(plist,data);
    else
    LSInsert(plist,data);
}

int Lfrist(List* plist, Ldata* data){
    if(plist->head->next =NULL){
        printf("조회할 데이터가 없습니다.\n");
        return 0;
    }
    plist->before = plist->head;
    plist->cur = plist->head->next;
    *data = plist->cur->data;

    return 1;

}
int LNext(List* plist, Ldata* data){
    if(plist->cur->next == NULL){
        printf("더 이상 조회할 데이터가 없습니다.\n");
        return 0;
    }
    plist->before = plist->cur;
    plist->cur= plist->cur->next;

    *data = plist->cur->data;
    return 1;
}

Ldata LRemove(List* plist){
    Node* RemoveNode = plist->cur;
    Ldata Rdata = RemoveNode->data;

    plist->before->next = RemoveNode->next; //삭제는 보통 조회와 같이 이루어짐
    plist->cur = plist->before; //삭제 후 현 위치는 before과 같음
    free(RemoveNode);
    (plist->size)--;
    
    return Rdata;

}
int Lcount(List* plist){
 return plist->size;
}

void SetSortRule(List * plist, int(*comp)(Ldata d1,Ldata d2)){


}