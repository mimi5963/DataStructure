#ifndef __EXPRESSTION_H
#define __EXPRESSTION_H
#include "BTree.h"

BTreeNode* MakeExpTree(char exp[]);

int EvaluateExpTree(BTreeNode* btn);

void ShowPrefixType(BTreeNode* btn);
void ShowInfixType(BTreeNode* btn);
void ShowPostfixType(BTreeNode* btn);




#endif