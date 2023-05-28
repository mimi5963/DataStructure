import java.util.Arrays;

public class QuickSort {

    public static void main (String[] args){
        int[] arr = new int[] {1,2,3,4,5,6,7,8,9};
        quickSort(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
    static void swap(int[] arr ,int idx1, int idx2 ){
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    static int Partition(int[] arr, int start, int end){
        int pivot = arr[start];
        int low = start+1;
        int high = end;

        while(low <= high){

            while(low <= end && pivot >= arr[low])//low <= end //같을때도 이동 그래야 빠져나감
                low++;
            while(high >=(start+1) && pivot <= arr[high]) //start+1 빠져나갈때 pivot까지가고 끝 범위는 start+1까지
                high--;

            if(low <= high) swap(arr,low,high);

        }
        swap(arr,start,high);

        return high;
    }

    static void quickSort(int arr[] ,int start,int end){
        if(start <= end){
            int pivot = Partition(arr,start,end);
            quickSort(arr,start,pivot-1); //반쪽이 바꿀게 없다면 0 pivot==0
            quickSort(arr,pivot+1,end); //큰 반쪽이 바꿀게 없다면 pivot==end
        }


    }
}
