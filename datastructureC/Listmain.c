#include<stdio.h>
#include<stdlib.h>
#include"Listheader.h"

int main(){
   // ArrayList 생성 및 초기화
    List plist;
    Ldata data;
    List* plist2 = (List*)malloc(sizeof(List));
    Linit(&plist);
    Linit(plist2);
    Linsert(plist2 ,3);
    Linsert(plist2 ,4);
    Linsert(plist2 ,5);
    Linsert(&plist,6);
    Linsert(&plist,7);
    Linsert(&plist,8);

    if(Lfirst(&plist,data)){
        printf("plist1 [%d ",data);
        while(Lnext(&plist,data)){
        printf("%d ",data);
    }
        printf("]\n");
    }
    
    if(Lfirst(plist2,data)){
        printf("plist1 [%d ",data);
        while(Lnext(plist2,data)){
        printf("%d ",data);
    }
        printf("]\n");
    }
    return 0;
}