#include "PostCal.h" // 후위 계산
#include "Postfix.h" //중위 -> 후위 변환
#include <string.h>
#include <stdlib.h>
#include "infixCa.h"

int InfixExp(char exp[]){
    
    int len = strlen(exp);
    int result=0;
    char* postFix = (char*)malloc(len+1); //널문자 포함 +1
    strcpy(postFix,exp);
    ConvertRPN(postFix);
    result = SolRPN(postFix);
    free(postFix);
    return result;

}