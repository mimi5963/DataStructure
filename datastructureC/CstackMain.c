#include"CStack.h"
#include<stdio.h>
#include<stdlib.h>

void ConvertRPN(char exp[])
{
    Stack stack;
    int len = strlen(exp);
    char* convExp = (char*)malloc(len+1);

    int i=0;
    int idx=0;
    char curChar;
    char popOp;

    memset(convExp,0,sizeof(char)*len+1);
    StackInit(&stack);

    for(i=0; i<len;i++){
        curChar = exp[i];
        if(isdigit(curChar)){
            convExp[idx++] = curChar;
        }else{
            switch (curChar)
            { case '(' :
                push(&stack,curChar);
                break;
              case ')' :
                while(!itEmpty(&stack)){
                    char temp = pop(&stack);
                    if(temp == '(') break;
                    convExp[idx++] = temp;
                }
                break;

                case '+':case '-':
                case'/': case '*':
                while(!itEmpty(&stack) && PrecOPpeek(&stack,curChar) >=0){
                        convExp[idx++] = pop(&stack);
                }
                push(&stack,curChar);
                break;
            }

        }
    }
    
    while(!itEmpty(&stack))
        convExp[idx++] = pop(&stack);

        strcpy(exp,convExp);
        free(convExp);
}

int main(){
    int result;
    char exp[] = "3-2+4";
    ConvertRPN(exp);
    int result=0;
    result=SolRPN(exp);
    printf("%d result",result);
    return 0;
}

int GetOp(char op){
    switch(op){
        case '*':
        case '/':
        return 2;
        case '+':
        case '-':
        return 1;
        case '(':
        return 0;
    }
    return -1;
}

int PrecOP(char op1, char op2){
    int op1number = GetOp(op1);
    int op2number = GetOp(op2);

    if(op1number > op2number) return 1;
    else if(op1number<op2number) return -1;
    else return 0;
}
int SolRPN(char exp[]){
    Stack stack;
    StackInit(&stack);
    
    for(int i=0; i<len(exp);i++){
        if(isdigit(exp[i]))push(&stack,exp[i]);
        else{
            int backNumber = pop(&stack) -'0';
            int frontNumber = pop(&stack) -'0';
            switch (exp[i])
            {
            case '*':
            push(&stack,frontNumber*backNumber);
            break;
            case '/':
            push(&stack,frontNumber/backNumber);
            break;
            case '+':
            push(&stack,frontNumber+backNumber);
            break;
            case '-':
            push(&stack,frontNumber-backNumber);
            break;
            } 
        }
    }
    return pop(&stack);

}