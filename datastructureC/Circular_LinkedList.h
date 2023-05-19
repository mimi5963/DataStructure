#ifndef Circular_LinkedList
#define Circular_LinkedList

#define false 0
#define true 1

typedef int Ldata;

typedef struct _node{
    Ldata data;
    struct _node* next;
}Node;

typedef struct _Circle{
    Node* tail;
    Node* before;
    Node* cur;
    int size;

}Circle;

typedef Circle List;

void Linsert(List* plist,Ldata data);
void Linit(List* plist);
void LinsertFirst(List* plist,Ldata data);

int LFirst(List* plist,Ldata* data);
int LNext(List* plist,Ldata* data);
Ldata LRemove(List* plist);
int Lcount(List* plist);



#endif