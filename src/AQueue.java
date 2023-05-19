public class AQueue {
    public static void main(String[] args){
        MyAQueue Mqp = new MyAQueue();
        Mqp.Enqueue(1);
        Mqp.Enqueue(2);
        Mqp.Enqueue(3);
        System.out.print(Mqp.peek());
        System.out.print(Mqp.Dequeue());
        System.out.print(Mqp.Dequeue());
        System.out.print(Mqp.Dequeue());
        //System.out.print(Mqp.Dequeue());
        Mqp.Enqueue(3);
        Mqp.Enqueue(3);
        Mqp.Enqueue(3);
        Mqp.Enqueue(3);


    }
}

class MyAQueue{
    private final int MAX_LEN =100;
    Object[] arr =new Object[MAX_LEN];
    private int frount;
    private  int Rear;

    MyAQueue(){
        frount = 0;
        Rear = 0;
    }
    void Enqueue(Object data){
        if(Rear +1 == frount){
            System.out.print("Queue is full");

        }
        Rear = ++Rear%MAX_LEN;
        arr[Rear] = data;
    }
    Object Dequeue(){
        if(isEmpty()){
            System.out.print("삭제할 데이터 없음");
        }
        frount  = ++frount%MAX_LEN;
        return arr[frount];
    }

    boolean isEmpty(){
        if(Rear == frount) return true;
        else return false;
    }

    Object peek(){
        if(isEmpty()){
            System.out.print("빈 큐");
        }
        return arr[Rear];
    }


}
