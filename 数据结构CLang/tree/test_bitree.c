#include <stdio.h>
#include "binary_tree.h"

Status visitData(ElemType data)
{
    printf("%c ", data);
    return OK;
}

int main()
{
    BinaryTree bt = NULL;
    bt = CreateBST(bt);
    PreOrderTraverse(bt, visitData);
}