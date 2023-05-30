#include<stdio.h>

int ISearch(int ar[], int first, int last, int target){

    int mid;
    if(first > last) return -1;
    mid = ((double)(target-ar[first])/(ar[last]-ar[first])*(last-first)) + first;

    if(ar[mid] == target) return mid;
    else if(target < ar[mid])
        return ISearch(ar,first,mid-1,target);
    else return ISearch(ar,mid+1,last,target);
}

int main(void){


return 1;
}