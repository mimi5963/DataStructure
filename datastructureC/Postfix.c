#include "Postfix.h"
#include <stdlib.h>
#include "CStack.h"
#include <string.h>
#include <ctype.h>

int PrecOP(char op1, char op2){
    int op1_n = GetOp(op1);
    int op2_n = GetOp(op2);
    if(op1_n == -1 || op2_n == -1){
        printf("에러");
        exit(-1);
    }
    if(op1_n > op2_n) return 1;
    else if(op1 < op2_n) return -1;
    else return 0;
}
int GetOp(char op){
    switch (op)
    {
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
void ConvertRPN(char exp[]){
    Stack stack;
    StackInit(&stack);
    int lens = len(exp);
    char temp[] = (char*)malloc(lens+1);
    memset(temp,0,sizeof(char)*lens+1); //미리 0으로 초기화 해둠
    int Tempindex =0;

    for(int i=0; i<lens; i++){
        char curChar = exp[i];
        if(isdigit(curChar)){
            temp[Tempindex++] = curChar;
        }
        else if(curChar == '(')
        {
            push(&stack,curChar);
        }
        else if(curChar == ')')
        {
            while(!itEmpty(&stack)){
                char c = pop(&stack);
                if(c == '(') break;
                temp[Tempindex++] = c;                
            }
        }
        else{
            while(!itEmpty(&stack) && PrecOP(peek(&stack),curChar)!= -1){
                temp[Tempindex++] = pop(&stack);
            }
            pust(&stack,curChar);
        }
    }
    while(!itEmpty(&stack)){
        temp[Tempindex++] = pop(&stack);
    }
    strcpy(exp,temp);
    free(temp);

}