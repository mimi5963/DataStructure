#include <string.h>
#include <ctype.h>
#include "CStack.h"
#include "PostCal.h"
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