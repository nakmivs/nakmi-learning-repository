#include <stdlib.h>
#include "binary_tree.h"


typedef struct bst_type {
    struct bst_type* left;
    struct bst_type* right;
    ElemType data;
}*BiNode; // 递归定义，二叉树的左右子树也是二叉树


BinaryTree CreateBST(BinaryTree bt)
{
    // 先序创建二叉树
    // # 表示NULL叶子结点
    // 递归形式
    ElemType ch;
    scanf("%c ",&ch);
    if(ch == '#') {
        bt = NULL;
    }else{
        bt = malloc(sizeof(struct bst_type));
        bt->data = ch;
        bt->left = CreateBST(bt->left);
        bt->right = CreateBST(bt->right);
    }
    return bt; // 返回 根结点
}

Status PreOrderTraverse(BinaryTree bt, Status (* visit)(ElemType data))
{
    // 递归形式的先序遍历
    if(bt){
        visit(bt->data);
        PreOrderTraverse(bt->left, visit);
        PreOrderTraverse(bt->right, visit);
    }

    return OK;
}