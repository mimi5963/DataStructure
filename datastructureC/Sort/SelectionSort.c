#include<stdio.h>


int main(){

    int arr[] = {1,200,30,50,60};

    selectionSort(arr,sizeof(arr)/sizeof(int));


}

void selectionSort(int arr[],int len){
    int i,j;
    int temp;
    int maxIdx =0;
    for( i=0; i<len-1; i++){
        maxIdx =i;
        for( j=i+1;j<len; j++){
            if(arr[j] < arr[maxIdx]){
                maxIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;

    }

}