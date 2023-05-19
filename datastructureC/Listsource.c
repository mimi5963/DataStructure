#include<stdio.h>
#include "Listheader.h"
#include<stdlib.h>

void Linit(List* plist){
plist->numofdata =0;
plist->cur = -1;
}
void Linsert(List* plist, Ldata data){
  if(plist->numofdata>= MAX_LEN) 
  {
    fprintf(stderr,"꽉차서 안대유");
    exit(0);
  }
    plist->arr[(plist->numofdata)++] =data;

}
int Lfirst(List* plist, Ldata* data){
    if(plist->numofdata == 0){
        fprintf(stderr,"암것두 업슈");
        return false;
    }
    plist->cur=0;
    *data = plist->arr[plist->cur];

    return true;
}
int Lnext(List* plist, Ldata* data){
    if(plist->cur >= (plist->numofdata)-1)
    {
        fprintf(stderr,"너무 갔슈");
        return false;
    }
    *data = plist->arr[++(plist->cur)];
    return true;
}
Ldata Lremove(List* plist){
    int rpos = plist->cur;
    Ldata rdata= plist->arr[rpos];
    int i;
    for(i = rpos; i<(plist->numofdata)-1;i++){
        plist->arr[i] = plist->arr[i+1];
    }
    
    (plist->numofdata)--;
    (plist->cur)--;
    return rdata;
}
int size(List* plist){
    return plist->numofdata;
}

void Lclear(List* plist){
    plist->cur = (plist->numofdata)-1; 
    for(int i = (plist->numofdata)-1; i>=0;i--){
        Lremove(plist);
    }
    
}