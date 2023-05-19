#include "CStack.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include"ExpresstionTree.h"
BTreeNode* MakeExpTree(char exp[]){
    Stack st;
    int len = strlen(exp);
    StackInit(&st);
    BTreeNode* node;

    for(int i=0; i<len ;i++){
        node = MakeBTreeNode();
        if(isdigit(exp[i])){
         SetData(node,exp[i]-'0');
        }else{
            MakeLeftSubTree(node,pop(&st));
            MakeRightSubTree(node,pop(&st));
            SetData(node,exp[i]);

        }
        push(&st,node);
    }
    
    return pop(&st);
}

int EvaluateExpTree(BTreeNode* btn){
    int op1,op2;
    if(btn->left == NULL && btn->right == NULL){
        return btn->data;
    }
    op1 = EvaluateExpTree(GetLeftSubTree(btn));
    op2 = EvaluateExpTree(GetRightSubTree(btn));

    switch (btn->data)
    {
        case '+':  return op1+op2;
        case '-':  return op1-op2;
        case '*':  return op1*op2;
        case '/':  return op1/op2;
    }
    return 0;

}

void ShowPrefixType(BTreeNode* btn){
   PreorderTraverse(btn,showdata);
}
void ShowInfixType(BTreeNode* btn){
    InorderTraverse(btn,showdata);
}
void ShowPostfixType(BTreeNode* btn){
    PostorderTraverse(btn,showdata);
}

void showdata(int data){
    if(0<=data && data>=9){
        printf("%d ",data);
    }else {
        printf("%c ",data);
    }
}

void ShowInfix1(BTreeNode* btn){
    if(btn == NULL) return;

    if(btn->left != NULL || btn->right !=NULL)
    printf("( ");

    ShowInfix1(GetLeftSubTree(btn));
    showdata(btn->data);
    ShowInfix1(GetRightSubTree(btn));
    
    if(btn->left != NULL || btn->right !=NULL)
    printf(" )");
}
void ShowInfix2(BTreeNode* btn){
     if(btn == NULL) return;

    if(isdigit(btn->left->data)  && isdigit(btn->right->data) ) //혹은 */일때만
    printf("( ");

    ShowInfix1(GetLeftSubTree(btn));
    showdata(btn->data);
    ShowInfix1(GetRightSubTree(btn));
    
   if(isdigit(btn->left->data)  && isdigit(btn->right->data) )
    printf("( ");
}