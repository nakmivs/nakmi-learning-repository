#ifndef STACK_H
#define STACK_H

#include "../common.h"

typedef struct stack_type* Stack;

// 初始化栈
Stack CreateStack();
// 销毁栈 
Status DestroyStack(Stack st);
// 设置为空栈
Status ClearStack(Stack st);

// 压入栈
Status Push(Stack st, ElemType e);
// 弹出栈，获得元素
Status Pop(Stack st, ElemType* e);
// 获得栈顶元素
Status GetTop(Stack st, ElemType* e);

// 求栈的元素个数
int StackLength(Stack st);

// 判断栈是否为空
Bool StackEmpty(Stack st);
Bool StackFull(Stack st);

// 遍历栈的元素
Status StackTraverse(Stack st, Status (* visit)(ElemType e));

#endif