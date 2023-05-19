#include<stdio.h>
#include "CStack.h"
#include<stdlib.h>

void StackInit(Stack* st){
    Linit(st->plist);
}
int isEmpty(Stack* st){
    if(st->plist->tail == NULL) return 1;
    return 0;
}

void push(Stack* st, Data data){
    LinsertFirst(st->plist,data);
}
Data pop(Stack* st){
    Data data;
    if(isEmpty){
        exit(-1);
    }
    LFirst(st->plist,&data);
    LRemove(st->plist);
    return data;
}
Data peek(Stack* st){
    Data data;
    LFirst(st->plist,&data);
    return data;
}