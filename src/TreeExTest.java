import com.sun.source.tree.Tree;

import java.util.TreeMap;
import java.util.TreeSet;
import java.util.function.Consumer;

public class TreeExTest {
    public static void main(String[] args) {
        MTree<Integer> m1 = MTree.getInstance();
        MTree<Integer> m2 = MTree.getInstance();
        MTree<Integer> m3 = MTree.getInstance();
        MTree<Integer> m4 = MTree.getInstance();

        MTree<Integer> m5 = MTree.getInstance();
        MTree<Integer> m6 = MTree.getInstance();
        MTree<Integer> m7 = MTree.getInstance();
        MTree<Integer> m8 = MTree.getInstance();

        m1.SetData(1);
        m2.SetData(2);
        m3.SetData(3);
        m4.SetData(4);
        m5.SetData(5);
        m6.SetData(6);
        m7.SetData(7);
        m8.SetData(8);
        m1.MakeLeftSubTree(m2);
        m1.MakeRightSubTree(m3);
        m2.MakeLeftSubTree(m4);

        m4.MakeLeftSubTree(m5);
        m4.MakeRightSubTree(m6);

        m3.MakeRightSubTree(m7);
        m7.MakeLeftSubTree(m8);

        Consumer<Integer> t = (x) -> {System.out.println(x+"");};

        MTree.PreorderTraverse(m1,t);
        System.out.println();
        MTree.InorderTraverse(m3,t);
        System.out.println();
        MTree.PostoerderTraverse(m2,t);

        MTree<Integer> m11 = MTree.getInstance();
        MTree<Integer> m22 = MTree.getInstance();
        m11.SetData(11);
        m22.SetData(22);

        m11.MakeLeftSubTree(m22);
        m2.MakeLeftSubTree(m11);
        System.out.println();
        MTree.PreorderTraverse(m1,t);

        //내부적으로 root만 가지고 쫙 이어지는 트리 만드는거 아닌이상.. 자바에선 free가 없어서
        //main에서 instance 가리키고 있는 이상 내부적으로 연결 끊어봐야 변수가 가리키는게 남아있어서.. 아예 사라지는게 어렵네
        //따라서 여기까지만..이래서 C로하나보눈구나.. 얻은게 있다.!

    }



}

class MTree<T>{
    //root는 Mtree와 연결. 각자의 data가짐
    private Tnode<T> root;
    private static class Tnode<T>{
        T data;
        Tnode<T> left;
        Tnode<T> right;
        Tnode(){
            left = null;
            right = null;
        }
    }
   private MTree(){
        root = new Tnode<>();
    }
    public static <T> MTree<T> getInstance(){
        return new MTree();
    }
    //대외적 이용
    public T Getdata(){
        return GetNodedata(this.root);
    }
    public void SetData(T data){
       SetNodedata(this.root,data);
    }
   public Tnode<T> GetLeftSubTree(){
        return GetLeftNode(this.root);
   }
    public void MakeLeftSubTree(MTree<T> bt){
        if(this.root.left != null){
            DeleteNode(this.root.left);
        }
        MakeLeftSubNode(this.root,bt.root);
    }
   public Tnode<T> GetRightSubTree(){
        return GetRightNode(this.root);
   }
    public void MakeRightSubTree(MTree<T> bt){
        if(this.root.right != null){
            DeleteNode(this.root.right);
        }
        MakeRightSubNode(this.root,bt.root);
    }

    public static  <T> void InorderTraverse(MTree<T> bt, Consumer<T> c){
        InorderTraverseNode(bt.root,c);
    }
    public  static <T> void PreorderTraverse(MTree<T> bt, Consumer<T> c){
        PreorderTraverseNode(bt.root,c);
    }

    public static <T> void PostoerderTraverse(MTree<T> bt, Consumer<T> c){
        PostorderTraverseNode(bt.root,c);
    }

   public static <T> void DeleteTree(MTree<T> bt){
       DeleteNode(bt.root);
       bt.root = null;
   }

    private static <T> void DeleteNode(Tnode<T> current) {
        if(current == null) return;
        DeleteNode(GetLeftNode(current));
        DeleteNode(GetRightNode(current));
        current.right=null;
        current.left =null;
    }


    //내부 노드 이용 (따로 떼어두는 이유는 내부 함수들 때문인듯?)
    //static인 이유는 인스턴스 생성시마다 굳이 달라지는 부분 없음! 내부적 문제이므로
    private static <T> void PostorderTraverseNode(Tnode<T> current, Consumer<T> c) {
        if(current == null) return;
        PostorderTraverseNode(GetLeftNode(current),c);
        PostorderTraverseNode(GetRightNode(current),c);
        c.accept(current.data);

    }
    private static <T> void PreorderTraverseNode(Tnode<T> current, Consumer<T> c) {
        if(current == null) return;
        c.accept(current.data);
        PreorderTraverseNode(GetLeftNode(current),c);
        PreorderTraverseNode(GetRightNode(current),c);
    }
   private static <T> void InorderTraverseNode(Tnode<T> current, Consumer<T> c){
       if(current == null) return;
       InorderTraverseNode(GetLeftNode(current),c);
       c.accept(current.data);
       InorderTraverseNode(GetRightNode(current),c);
   }
    private static <T>void SetNodedata(Tnode<T> current ,T data){
        current.data = data;
    }
    private static <T> T GetNodedata(Tnode<T> current){return current.data;}
   private static <T> Tnode<T> GetLeftNode(Tnode<T> current){
        return current.left;
    }
   private static <T> Tnode<T> GetRightNode(Tnode<T> current){
        return current.right;
    }

   private  static <T> void MakeLeftSubNode(Tnode<T> main, Tnode<T> sub){
        main.left =sub;
   }
   private static <T> void MakeRightSubNode(Tnode<T> main, Tnode<T> sub){
        main.right = sub;
   }


}
