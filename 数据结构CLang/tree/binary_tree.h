#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../common.h"

typedef struct bst_type* BinaryTree;

// 创建二叉树, 按先序输入，#表示NULL结点
BinaryTree CreateBST(BinaryTree bt);

// 先序遍历
Status PreOrderTraverse(BinaryTree bt, Status (* visit)(ElemType data));

#endif