import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.function.BiFunction;

public class SimpleHeapTest {

    public static void main(String[] args){

    MyHeap<Character> h = new SimpleHeap<>();
    h.HInsert('A');
    h.HInsert('B');
    h.HInsert('C');
    System.out.printf("%c \n",h.HDelete());
    h.HInsert('A');
    h.HInsert('B');
    h.HInsert('C');
    System.out.printf("%c \n",h.HDelete());

    while(!h.HEmpty()){
        System.out.printf("%c \n",h.HDelete());
    }
    }

}

class SimpleHeap<T> implements MyHeap<T>{
    private final int MAX_LEN = 100;
    private Helem<T>[] ElemArr = new Helem[MAX_LEN];
    private int numofdata;
    SimpleHeap(){this.numofdata =0;}

    @Override
    public boolean HEmpty() {
        if(this.numofdata == 0) return true;
        else return false;
    }

    @Override
    public void HInsert(T data) {
        System.out.println("go to SimpleHeapHInsert  you should enter data Priority");
        SimpleHeapHInsert(data,new Scanner(System.in).nextInt());
    }
    void SimpleHeapHInsert(T data, int priority){
        int lastIndex = this.numofdata +1;
        Helem<T> newdata = new Helem<>(data,priority);

        while(lastIndex != 1){
            if(priority < this.ElemArr[GetParentIdx(lastIndex)].GetPriority()){
                this.ElemArr[lastIndex] = this.ElemArr[GetParentIdx(lastIndex)];
                lastIndex = GetParentIdx(lastIndex);
            }else break;
        }
        this.ElemArr[lastIndex] = newdata;
        this.numofdata +=1;
    }
    @Override
    public T HDelete() {
        T DelData = this.ElemArr[1].Getdata();
        Helem<T> lastElem = this.ElemArr[this.numofdata];

        int Parentidx = 1;
        int child;
        while((child = GetTopPriorityChild(Parentidx)) != 0){
         if(lastElem.GetPriority() <= this.ElemArr[child].GetPriority())
             break;
         this.ElemArr[Parentidx] = this.ElemArr[child];
         Parentidx = child;
        }
        this.ElemArr[Parentidx] = lastElem;
        this.numofdata --;
        return DelData;

    }

    private int GetParentIdx(int idx) {return idx/2;}
    private int GetLeftChildIdx(int idx) {return idx*2;}
    private int GetRightChildIdx(int idx){return idx*2+1;}

    private int GetTopPriorityChild(int ParentIdx){
        if(GetLeftChildIdx(ParentIdx) > this.numofdata)
            return 0;
        else if(GetLeftChildIdx(ParentIdx) == this.numofdata){
            return GetLeftChildIdx(ParentIdx);
        }
        if(this.ElemArr[GetLeftChildIdx(ParentIdx)].GetPriority()
                >this.ElemArr[GetRightChildIdx(ParentIdx)].GetPriority()){
            return GetRightChildIdx(ParentIdx);
        }else
            return GetLeftChildIdx(ParentIdx);
    }


    private static class Helem<T> {
        private T data;
        private int Priority;
        public void Setdata(T data){ this.data = data;}
        public T Getdata(){return this.data;}
        public void SetPriority(int pr){this.Priority = pr;}
        public int GetPriority(){return this.Priority;}

        Helem(T data, int pr){
            this.data = data;
            this.Priority = pr;
        }
        Helem(){}

    }
}



