import java.util.Stack;
import java.util.function.Consumer;

public class ExpresstionTreeTest {

    public static void main(String[] args) {
        String exp = "123*+45/-";
        BiTree<Integer> Exptree = ExpresstionTree.MaKeExpTree(exp.toCharArray());
        System.out.println("전위표기");
        ExpresstionTree.ShowPrefixType(Exptree);
        System.out.println();
        System.out.println("중위표기");
        ExpresstionTree.ShowInfixType(Exptree);
        System.out.println();
        System.out.println("후위표기");
        ExpresstionTree.ShowPostfixType(Exptree);
        System.out.println();

        System.out.println(ExpresstionTree.EvaluateExpTree(Exptree));
        ExpresstionTree.ShowInfix2(Exptree);
        System.out.println();
        ExpresstionTree.ShowInfix3(Exptree);
    }
}

class ExpresstionTree {
    static BiTree<Integer> MaKeExpTree(char[] exp){
        Stack<BiTree> st = new Stack<>();
        int len = exp.length;
        BiTree<Integer> Tree;

        for(int i=0; i<len;i++){
            Tree = new BiTree<>();
            if(exp[i]>='0'&& exp[i] <='9'){
                Tree.SetData(exp[i]-'0');
            }else{
                Tree.MakeRightSubTree(st.pop());
                Tree.MakeLeftSubTree(st.pop());
                Tree.SetData((int)exp[i]);
            }
            st.push(Tree);
        }
        return st.pop();
    }
   static int EvaluateExpTree(BiTree<Integer> btn){
        int op1,op2;
        if(btn.GetLeftSubTree() ==null && btn.GetRightSubTree() == null){
            return btn.GetData();
        }
        op1 = EvaluateExpTree((BiTree<Integer>) btn.GetLeftSubTree());
        op2 = EvaluateExpTree((BiTree<Integer>) btn.GetRightSubTree());

        if(btn.GetData() == '+'){
            return op1+op2;
        }else if(btn.GetData() == '-'){
            return op1-op2;
        }else if(btn.GetData()=='*'){
            return op1*op2;
        }else if(btn.GetData() == '/')
            return op1/op2;

        return 0;
    }

   static void ShowPrefixType(BiTree<Integer> bt){
        BiTree.PreorderTraverse(bt,t);
    }
    static void ShowInfixType(BiTree<Integer> bt){
        BiTree.InorderTraverse(bt,t);
    }
    static void ShowPostfixType(BiTree<Integer> bt){
        BiTree.PostorderTraverse(bt,t);
    }

    static Consumer<Integer> t = (x) -> {
        if(x>=0 && x<=9){
            System.out.printf("%d ",x);
        }else{
            System.out.printf("%c ",x);
        }
    };

    static void ShowInfix2(BiTree<Integer> btn){
        if(btn == null || btn.root == null) return;

        if(btn.GetLeftSubTree() != null || btn.GetRightSubTree() !=null)
            t.accept((int)'(');

        ShowInfix2((BiTree) btn.GetLeftSubTree());
        t.accept(btn.GetData());
        ShowInfix2((BiTree)btn.GetRightSubTree());

        if(btn.GetLeftSubTree() != null || btn.GetRightSubTree() !=null)
            t.accept((int)')');
    }
    static void ShowInfix3(BiTree<Integer> btn){
        if(btn == null || btn.root == null) return;

        if(isNumber(btn))
            t.accept((int)'(');

        ShowInfix2((BiTree) btn.GetLeftSubTree());
        t.accept(btn.GetData());
        ShowInfix2((BiTree)btn.GetRightSubTree());

        if(isNumber(btn))
            t.accept((int)')');
    }

    private static boolean isNumber(BiTree<Integer> btn) {
        int dataL = btn.GetLeftSubTree().GetData();
        int dataR = btn.GetRightSubTree().GetData();
        if(dataL>=0 && dataL<=9 && dataR>=0 && dataR<=9)return true;
        return false;
    }
}