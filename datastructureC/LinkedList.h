#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#define false 0
#define true 1

typedef int Ldata;

typedef struct _node{
    Ldata data;
    struct _node* next;

}node;

typedef struct _LinkedList
{
    node* head;
    node* tail;
    int length;
    int cur;

}LinkedList;

typedef LinkedList List;

void Linit(List* plist);
void Linsert(List* plist, Ldata data);
void Lclear(List* plist);
int Lfirst(List* plist, Ldata* data);
int Lnext(List* plist, Ldata* data);
Ldata Lremove(List* plist);
int size(List* plist);

#endif