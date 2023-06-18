public class DEF {

    public static void main(String[] args){
        int n=3;
        hanoi(n,'A','B','C');

    }
    public static void hanoi(int n, char start , char by, char end){
        if(n==1){
            System.out.printf("%d원반은 %c에서 %c로 옮긴다.",n,start,end);
        }else{
            hanoi(n-1,start,end,by);
            


        }


    }


}
