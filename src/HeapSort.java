import java.util.Arrays;

public class HeapSort {
    public static void main(String[] args){
    Integer[] arr = new Integer[]{3,4,2,1};
    HeapSort.<Integer>HSort(arr);
    System.out.println(Arrays.toString(arr));
    }
    public static <T> void HSort(T[] arr){
        MyHeap<T> myH = new MHeap<>();
        int i;

        for(i =0 ;i<arr.length;i++){
            myH.HInsert(arr[i]);
        }
        for(i=0; i<arr.length;i++){
            arr[i] = myH.HDelete();
        }
    }
}
