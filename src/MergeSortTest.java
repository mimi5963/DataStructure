import java.util.Arrays;

public class MergeSortTest {

    public static void main(String[] args){
        Integer[] arr = new Integer[] {3,4,2,1,7,5,6};
        MergeSort(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
    public static <T> void MergeSort(T[] arr,int start, int end){
        int mid;
        if(start<end){
            mid = (start+end)/2;

            MergeSort(arr,start,mid);
            MergeSort(arr,mid+1,end);

            Merge(arr,start,mid,end);
        }
    }

    private static <T> void Merge(T[] arr, int start, int mid, int end) {
        int LeftStart = start;
        int RightStart = mid+1;
        T[] temp = GetTArr(arr.length);
        int tempIdx=start;
        int i;
        while(LeftStart <= mid && RightStart <= end){
            if(comp(arr[LeftStart],arr[RightStart]) <0){
                temp[tempIdx] = arr[LeftStart++];
            }else
                temp[tempIdx] = arr[RightStart++];

            tempIdx++;
        }
        if(LeftStart > mid){
            for(i=RightStart; i<= end;)
                temp[tempIdx++] = arr[i++];

        }else {
            for(i=LeftStart; i<= mid;)
                temp[tempIdx++] = arr[i++];
        }
//        for(i=start;i<=end;i++){
//            arr[i] =temp[i];
//        }
        System.arraycopy(temp,start,arr,start,end-start+1);
    }

    private static <T> T[] GetTArr(int length) {
        return (T[])new Object[length];
    }
    private static<T> int comp(T o1, T o2){
        return ((Integer) o1).compareTo((Integer) o2);
    }
}
