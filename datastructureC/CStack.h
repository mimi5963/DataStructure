#include"Circular_LinkedList.h"

typedef int Data;

typedef struct _CStakc{
    List* plist; //LinkedList로 구현하기 전 일단 각 스택별 List를 가지고 있어야함
}CStack;

typedef CStack Stack;

void StackInit(Stack* st);
int itEmpty(Stack* st);

void push(Stack* st, Data data);
Data pop(Stack* st);
Data peek(Stack* st);