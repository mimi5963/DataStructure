#include<stdio.h>
#include<stdlib.h>



int main(){

    return 1;
}

void Merge(int arr[], int start, int mid, int end){

    int leftStart = start; //왼쪽 처음
    int RightStart = mid+1;//오른쪽 처음
    int i;

    int * sortArr = (int*)malloc(sizeof(int)*(end+1));
    int sortIdx = start;

    //왼쪽과 오른쪽을 중간으로 나누고 각 요소를 하나씩 비교하는 과정
    while(leftStart <=mid && RightStart <= end){
        if(arr[leftStart] <= arr[RightStart])
           //오름차순이므로 leftStart가 작을 경우에 먼저 옴 
            sortArr[sortIdx] = arr[leftStart++];
        
         else sortArr[sortIdx] = arr[RightStart++];
         sortIdx++;
    }
    //왼쪽 오른쪽 정렬 후에 남은 요소 복사
    if(leftStart>mid) // leftStart가 >mid보다 크면서 while문 종료 왼쪽은 다 돌았다는 의미
    {
        for(i=RightStart;i<=end;){
            sortArr[sortIdx++] = arr[i++];
        }
    }else{
        for(i=leftStart;i<=mid;)
        sortArr[sortIdx++] = arr[i++];

    }
    //정렬완료된 sortArr을 원래 arr에 복사
    for(int i=start;i<=end;i++){
        arr[i] = sortArr[i];
    }
    free(sortArr);

}

void mergeSort(int arr[],int start,int end){
    int mid;

    if(start<end){ 
    //총 배열의 요소가 1개가 될때 까지 쪼갤것 
    //끝이 시작보다 크다면 계속 쪼개고 작거나 같아지면 중지
    mid = (start+end)/2;

    mergeSort(arr,start,mid); //끝을 줄여가면서  왼쪽부터 처리
    mergeSort(arr,mid+1,end); //시작을 늘려가면서 오른쪽 처리
    
    Merge(arr,start,mid,end); 
    //mergeSort가 호출되는 동안 스택에 쌓였다가, 한번씩 시행
    //12345678이라고 한다면
    //1234 5678 -> 1234 -> 12 -> 1 1이되면 그냥 return이므로 Merge발생x 
                       //->12 -> 2 2가되면 그냥 return Merge발생 x  
                       // 12 (start 0,end 1 mid 0)에서 Merge 하고 return 
                //->1234 -> 34 -> 3
                       //-> 34 -> 4
                       //-> 34(start 2, end 3 mid 2)에서 Merge 하고 return 
                //->1234 (start 0 , mid 1, end 3)에서 Merge하고 return 
                //반대과정 반복후 
                //처음 12345678(start 0, mid 3, end 7)에서 Merge하고 
                //최종 mergeSort종료         
    }
}