#ifndef __DUMMY_LINKED_LIST
#define __DUMMY_LINKED_LIST 

#define false 0
#define true  1
typedef int Ldata;

typedef struct _node{
    Ldata data;
    struct _node* next;
    
}Node;

typedef struct _List{
    int size;
    Node* head;
    Node* cur;
    Node* before;
    int(*comp)(Ldata d1, Ldata d2);    
}LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void Linsert(List* plist, Ldata data);

int Lfrist(List* plist, Ldata* data);
int LNext(List* plist, Ldata* data);

Ldata LRemove(List* plist);
int Lcount(List* plist);

void SetSortRule(List * plist, int(*comp)(Ldata d1,Ldata d2));
#endif