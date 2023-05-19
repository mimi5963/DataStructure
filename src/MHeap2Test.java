import java.sql.Wrapper;
import java.util.Comparator;

public class MHeap2Test {
    public static void main(String[] args){
        MyHeap<Character> mh = new MHeap<>(new Desc<>());
        mh.HInsert('A');
        mh.HInsert('B');
        mh.HInsert('C');
        System.out.printf("%c \n",mh.HDelete());
        mh.HInsert('A');
        mh.HInsert('B');
        mh.HInsert('C');
        System.out.printf("%c \n",mh.HDelete());

        while(!mh.HEmpty()){
            System.out.printf("%c \n",mh.HDelete());
        }
    }
}

class MHeap<T> implements MyHeap<T>{
    private static final int MAX_LEN =100;
    T[] data;
    int numofdata;
    Comparator<T> comp;
    MHeap(){
     this.numofdata=0;
     data = getDataArr();
     comp = new Asc<>();
    }
    MHeap(Comparator<T> comp){
        this();
        this.comp = comp;
    }
    private T[] getDataArr(){
        Object[] temp = new Object[100];
        return (T[])temp;
    }
    @Override
    public boolean HEmpty() {
        if(this.numofdata == 0 )return true;
        return false;
    }

    @Override
    public void HInsert(T data) {
        int lastIdx = this.numofdata +1;

        while(lastIdx != 1){
            if(this.comp.compare(data,this.data[GetParentIdx(lastIdx)])<=0)break;
            this.data[lastIdx] = this.data[GetParentIdx(lastIdx)];
            lastIdx = GetParentIdx(lastIdx);
        }
        this.data[lastIdx] = data;
        this.numofdata +=1 ;
    }

    @Override
    public T HDelete() {
        T Rdata = this.data[1];
        T lastdata = this.data[numofdata];
        int parentidx =1;
        int childidx;

        while((childidx = GetTopPriorityChildIdx(parentidx)) != 0){
            if(this.comp.compare(lastdata,this.data[childidx])<0){
                this.data[parentidx] = this.data[childidx];
                parentidx =childidx;
            }else break;
        }
        this.data[parentidx] = lastdata;
        this.numofdata -=1;
        return Rdata;
    }

    private int GetLeftChildIdx(int idx){ return idx*2;}
    private int GetRightChildIdx(int idx){return idx*2+1;}
    private int GetParentIdx(int idx){return idx/2;}

    private int GetTopPriorityChildIdx(int Parent){
        if(GetLeftChildIdx(Parent) > this.numofdata)return 0;
        else if(GetLeftChildIdx(Parent) == this.numofdata) return GetLeftChildIdx(Parent);

        if(comp.compare(this.data[GetLeftChildIdx(Parent)],this.data[GetRightChildIdx(Parent)])<0){
            return GetRightChildIdx(Parent);
        }
        else return GetLeftChildIdx(Parent);
    }
   private static class Asc<T> implements Comparator<T>{

        @Override
        public int compare(T o1, T o2) {
            if(o1 instanceof Character && o2 instanceof Character)
                return (char)o2 - (char)o1;
            return (Integer) o2 -(Integer) o1;
        }
    }

}

class Desc<T> implements Comparator<T>{

    @Override
    public int compare(T o1, T o2) {
        if(o1 instanceof Character && o2 instanceof Character)
            return (char)o1 - (char)o2;
        return (Integer) o1 -(Integer) o2;
    }
}
