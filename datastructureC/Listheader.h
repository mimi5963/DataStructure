#ifndef __ARRAY_LIST_H
#define __ARRAY_LIST_H

#define false 0
#define true 1
#define MAX_LEN 100

typedef int Ldata;

typedef struct _List
{
  Ldata arr[MAX_LEN];
  int numofdata;
  int cur;
}ArrayList;

typedef ArrayList List;

void Linit(List* plist);
void Linsert(List* plist, Ldata data);
void Lclear(List* plist);
int Lfirst(List* plist, Ldata* data);
int Lnext(List* plist, Ldata* data);
Ldata Lremove(List* plist);
int size(List* plist);


#endif