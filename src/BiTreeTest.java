import java.util.function.Consumer;

public class BiTreeTest {
  public static void main(String[] args){
      MyTree<Integer> b1 = new BiTree<>();
      MyTree<Integer> b2 = new BiTree<>();
      MyTree<Integer> b3 = new BiTree<>();
      MyTree<Integer> b4 = new BiTree<>();
      Consumer t = (x) -> System.out.println(x);

      b1.SetData(1);
      b2.SetData(2);
      b3.SetData(3);
      b4.SetData(4);
      b1.MakeLeftSubTree(b2);
      b2.MakeLeftSubTree(b4);
      b1.MakeRightSubTree(b3);

      BiTree.InorderTraverse(b1,t);
      System.out.println();



      MyTree<Integer> a = new BiTree<>();
      MyTree<Integer> s = new BiTree<>();
      MyTree<Integer> k = new BiTree<>();

      a.SetData(200);
      s.SetData(300);
      k.SetData(400);
      a.MakeLeftSubTree(s);
      a.MakeRightSubTree(k);

      b1.MakeLeftSubTree(a);
      System.out.println();
      BiTree.InorderTraverse(b1,t);
  }
}
class BiTree<T> implements MyTree<T>{
    Tnode<T> root=null;
    private static class Tnode<T> implements TreeData{
        T data;
        MyTree<T> left;
        MyTree<T> right;
        Tnode(){
            left = null;
            right = null;
        }
    }
    BiTree(){
        this.root = new Tnode<>();
    }
    @Override
    public T GetData() {
        return this.root.data;
    }

    @Override
    public void SetData(T data) {
        this.root.data = data;
    }

    @Override
    public MyTree<T> GetLeftSubTree() {
        return this.root.left;
    }

    @Override
    public MyTree<T> GetRightSubTree() {
        return this.root.right;
    }

    @Override
    public void MakeLeftSubTree(MyTree<T> sub) {
        if(this.root.left != null){
            BiTree.DeleteBiTree(this.GetLeftSubTree());
        }
        this.root.left = sub;
    }

    @Override
    public void MakeRightSubTree(MyTree<T> sub) {
        if(this.root.right != null)
            BiTree.DeleteBiTree(this.GetRightSubTree());
        this.root.right = sub;
    }

    @Override
    public void DeleteTree() {
        DeleteBiTree(this);
    }
    public static <T extends MyTree<?>> void DeleteBiTree(T bt){

        if(bt == null || ((BiTree)bt).root == null) return;
        DeleteBiTree(bt.GetLeftSubTree());
        DeleteBiTree(bt.GetRightSubTree());
        ((BiTree)bt).root =null;
    }

    static  <T extends MyTree<?> > void  InorderTraverse(T bt, Consumer t){
        if(bt ==null || ((BiTree)bt).root ==null) return;
        InorderTraverse(bt.GetLeftSubTree(),t);
        t.accept(bt.GetData());
        InorderTraverse(bt.GetRightSubTree(),t);
    }
    static  <T extends MyTree<?> > void  PreorderTraverse(T bt, Consumer t){
        if(bt ==null || ((BiTree)bt).root ==null) return;
        t.accept(bt.GetData());
        PreorderTraverse(bt.GetLeftSubTree(),t);
        PreorderTraverse(bt.GetRightSubTree(),t);
    }
    static  <T extends MyTree<?> > void  PostorderTraverse(T bt, Consumer t){
        if(bt ==null || ((BiTree)bt).root ==null) return;
        PostorderTraverse(bt.GetLeftSubTree(),t);
        PostorderTraverse(bt.GetRightSubTree(),t);
        t.accept(bt.GetData());
    }
}
