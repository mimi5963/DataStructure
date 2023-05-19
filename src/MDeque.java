public class MDeque {

    public static void main(String[] args){

    }

}

class MyDequeue<T>{

    private Node<T> head;
    private Node<T> tail;

    MyDequeue(){
        head =null;
        tail = null;
    }

    boolean isEmpty(){
        if(head == null) return true;
        return false;
    }

    void addFrount(T data){
        Node<T> newnode = new Node<>();
        newnode.data =data;
        newnode.next = head;
        newnode.pre = null;

        if(isEmpty()){
            tail = newnode;
        }else
            head.pre = newnode;


        head = newnode;
    }
    void addLast(T data){
        Node<T> newnode = new Node<>();
        newnode.data = data;
        newnode.pre = tail;
        newnode.next = null;

        if(isEmpty()){
            head = newnode;
        }else{
            tail.next = newnode;
        }
        tail = newnode;
    }

    T removeFrount(){
        if(isEmpty()){
            System.out.print("빈큐");
            System.exit(-1);
        }
        T redata = head.data;
        head = head.next;


        if(head == null) tail =null;
        else   head.pre = null;

        return redata;
    }

    T removeLast(){
        if(isEmpty()){
            System.out.print("빈큐");
            System.exit(-1);
        }
        T rdata = tail.data;
        tail = tail.pre;
        if(tail==null) head =null;
        else
            tail.next = null;

        return rdata;
    }

    T getFrount(){
        if(isEmpty()){
            System.out.print("빈큐");
            System.exit(-1);
        }
        return head.data;
    }
    T getLast(){
        if(isEmpty()){
            System.out.print("빈큐");
            System.exit(-1);
        }
        return tail.data;
    }


    private class Node<T>{
        T data;
        Node<T> next;
        Node<T> pre;
    }
}