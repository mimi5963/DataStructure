public class ThEx {

    public static void main(String[] args){
        Thread t1 = new Thread(new Th1());
        Thread t2 = new th2("Th2!");

        t1.start();
        t2.run();
        t2.start();
        System.out.println("hi from main");
        System.out.println(2/0);
    }
}

class Th1 implements Runnable{

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() +" hi!");
    }
}
class th2 extends Thread{
    th2(String name){
        super(name);
    }
    public void run(){
        if(Thread.currentThread() != this){
            System.out.println("hey!");
        }else{
            System.out.println(Thread.currentThread().getName()+"hi");
        }
    }
}
