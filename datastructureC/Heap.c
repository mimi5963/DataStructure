#include "Heap.h"


void HeapInit(Heap* hp, GetPriority comp){

    hp->numofdata == 0;
    hp->comp = comp;

}
int HisEmpty(Heap* hp){

    if(hp->numofdata ==0) return 1;
    else return 0;

}
void HInsert(Heap* hp, Hdata data){
    int lastIndex = hp->numofdata +1;
   
    while(lastIndex != 1){
        if(hp->comp(data,hp->HeapArr[GetParentIndex(lastIndex)]) > 0){
        hp->HeapArr[lastIndex] = hp->HeapArr[GetParentIndex(lastIndex)];
        lastIndex = GetParentIndex(lastIndex);
        }
        else break;
    }
    hp->HeapArr[lastIndex] = data;
    hp->numofdata += 1;

}
Hdata HDelete(Heap* hp){
    Hdata Ddata = hp->HeapArr[1];
    Hdata lastdata = hp->HeapArr[hp->numofdata];

    int Parentidx = 1;
    int Childidx;

    while( Childidx = GetTopPriorityChildIndex(hp,Parentidx)){
        if(hp->comp(lastdata,hp->HeapArr[Childidx])>=0)
        break;

        hp->HeapArr[Parentidx] = hp->HeapArr[Childidx];
        Parentidx = Childidx;
    }
    hp->HeapArr[Parentidx] = lastdata;
    hp->numofdata -=1;
    return Ddata;

}

int GetLeftChildIndex(int idx){ return idx*2;}
int GetRightChildIndex(int idx){ return idx*2+1;}
int GetParentIndex(int idx){return idx/2;}

int GetTopPriorityChildIndex(Heap* hp, int idx){

    if(GetLeftChildIndex(idx) > hp->numofdata)
    return 0;
    else if(GetLeftChildIndex(idx) == hp->numofdata)
    return GetLeftChildIndex(idx);

    if(hp->comp(hp->HeapArr[GetLeftChildIndex(idx)],hp->HeapArr[GetRightChildIndex(idx)])<0)
     return GetRightChildIndex(idx);
     else return GetLeftChildIndex(idx);

}

