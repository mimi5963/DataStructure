import java.util.Arrays;

public class EasySort {


    public static void main (String[] args){
        int[] Bubblearr = new int[] {100,20,3,40,205,89,220,2};
        int[] Seletionarr = new int[] {100,20,3,40,205,89,220,2};
        int[] Insertionarr = new int[] {100,20,3,40,205,89,220,2};
        BubbleSort(Bubblearr);
        SelectionSort(Seletionarr);
        InsertionSort(Insertionarr);

        System.out.println(Arrays.toString(Bubblearr));
        System.out.println(Arrays.toString(Seletionarr));
        System.out.println(Arrays.toString(Insertionarr));

    }
    public static void BubbleSort(int[] arr){
        int i,j;

        for(i=0; i<arr.length-1;i++){
            for(j=0; j<arr.length-1-i;j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    public static void SelectionSort(int[] arr){
        int i,j;
        int selectIdx;

        for(i=0; i<arr.length-1;i++){
            selectIdx = i;
            for(j=i+1; j<arr.length;j++){
                if(arr[selectIdx] > arr[j]) selectIdx =j;
            }
            int temp = arr[i];
            arr[i] =arr[selectIdx];
            arr[selectIdx] = temp;
        }
    }
    public static void InsertionSort(int[] arr){
        int i,j;
        int InsertionVal;
        for(i=1;i<arr.length;i++){
            InsertionVal = arr[i];
            for(j=i-1; j>=0 ;j--){
                if(arr[j] > InsertionVal)
                    arr[j+1] = arr[j];
                else break;
            }
            arr[j+1] =InsertionVal;
        }
    }
}
