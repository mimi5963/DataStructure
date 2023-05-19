import java.util.function.Consumer;

public interface MyTree<T> extends TreeData {
    T GetData();
    void SetData(T data);
    MyTree<T> GetLeftSubTree();
    MyTree<T> GetRightSubTree();
    void MakeLeftSubTree(MyTree<T> sub);
    void MakeRightSubTree(MyTree<T> sub);
    void DeleteTree();
}

interface TreeData{

}
