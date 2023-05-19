#ifndef _DB_liked_dummy
#define _DB_liked_dummy
typedef int Ldata;

typedef struct _node{
    Ldata data;
    struct _node* next;
    struct _node* pre;
}node;

typedef struct db_linked_list_d{
    node* head;
    node* tail;
    node* cur;
    int size;
}dblist_d;

typedef dblist_d List;

void Listinit(List* plist);
void Linsert(List* plist, Ldata data);

int Lfirst(List* plist,Ldata* data);
int LNext(List* plist,Ldata* data);
int LPrivious(List* plist, Ldata* data);
Ldata LRemove(List* plist);
int Lsize(List* plist);



#endif