
#ifndef _St_Array
#define _St_Array
#define MAX_DATA 100

typedef int Sdata;

typedef struct _Stack{
    Sdata arr[MAX_DATA];
    int index;
}StackArray;

typedef StackArray Stack;

void StackInit(Stack* st);
int isEmpty(Stack* st);

void push(Stack* st, Sdata data);
Sdata pop(Stack* st);
Sdata peek(Stack* st);
int size(Stack* st);

#endif