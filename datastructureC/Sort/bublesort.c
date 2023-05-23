#include<stdio.h>


int main(){

    int arr[] = {4,100,2,5,9,10};


    bubbleSort(arr,len(arr));


}

int bubbleSort(int arr[],int n){

    int i,j;
    int temp;

    for( i=0; i<n-1; i++){
        for( j=0; j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}