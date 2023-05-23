#include"Heap.h";
#include<stdio.h>

int main(){



}

void HeapSort(int arr[]){
    Heap h;
    int i;
    HeapInit(&h,Comparator);
    for(i=0; i<sizeof(arr)/sizeof(int);i++){
        HInsert(&h,arr[i]);
    }
    for(i=0; i<sizeof(arr)/sizeof(int);i++){
        arr[i] = HDelete(&h);
    }

}

int Comparator(int data1, int data2){
    return data2 - data1;
}