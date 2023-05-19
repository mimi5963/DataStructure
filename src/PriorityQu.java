public class PriorityQu {
    public static void main(String[] args){

    }
}

class Pqueue<T>{
    MyHeap<T> pqel;
    Pqueue(){
        this.pqel = new MHeap<>();
    }

    boolean PqisEmpty(){ return pqel.HEmpty();}
    void PEnqueue(T data){pqel.HInsert(data);}

    T PDequeue(){return pqel.HDelete();}

}
