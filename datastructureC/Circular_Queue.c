#include "Circular_Queue.h"
#include <stdlib.h>
#include <stdio.h>

void QueInit(Queue* qp){
    qp->frount =0; //q배열의 인덱스 
    qp->re =0; // 원형의 첫 인덱스는 0
}
int QEmpty(Queue* qp){
    if(qp->re  == qp->frount ) return 1;
    else 0;
}

void Enqueue(Queue* qp, data data){
    if(((qp->re)%MAX_LEN) +1 == qp->frount){
        printf("Queue is full");
        exit(-1);
    }else{
        qp->qudata[(++qp->re)%MAX_LEN] = data;
    }
}
data Dequeue(Queue* qp){
    if(QEmpty(qp)){
        printf("Queue is Empty");
        exit(-1);
    }
    data remove = qp->qudata[++(qp->frount)%MAX_LEN];
    return remove;
    
}
data peek(Queue* qp){
    if(QEmpty(qp)){
        printf("Queue is empty");
        exit(-1);
    }
    return qp->qudata[qp->re];
}
int NextPost(int pos){
    if(pos == MAX_LEN -1)
    return 0;
    else pos+1;
    //원형회전을 생각하면 이게 맞긴함 
    //내꺼는 계속 늘어나면서 11 12 %MAX_LEN이지만 이건 진짜 1 -2> 로 바뀌는 거자나
    
}