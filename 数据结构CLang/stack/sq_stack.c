// 栈， 顺序存储（动态数组实现）
// 下面的实现还有一些缺点
// 比如，存储空间只会变大，不会紧缩
//  与申请和释放空间无关的函数，没有时刻检验Stack指针是否为NULL
//     这个是假设由用户保证，比如StackEmpty函数就没有检验
//  与释放和申请空间有关的语句，之前必须确认指针的有效性 
//  这是为了练习和有效性考虑
#include <stdlib.h>
#include "stack.h"

#define STACK_INIT_SIZE 5 // 栈的初始化大小
#define STACKINCREMENT 2 // 栈的增

struct stack_type
{
    /* data */
    ElemType *base, *top; // 栈底和栈顶
    int stack_size; //栈的容量大小
};

Stack CreateStack()
{
    // 创建栈
    Stack st = malloc(sizeof(struct stack_type));
    if(!st) exit(OVERFLOW);

    st->base = malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if(!st->base) exit(OVERFLOW);
    st->top = st->base;
    st->stack_size = STACK_INIT_SIZE;
    return st;
}

Status DestroyStack(Stack st)
{
    // 销毁栈
    if (st)
    {
        if (st->base)
            free(st->base);
        free(st);
        return OK;
    }
    return ERROR;
}

Status ClearStack(Stack st)
{
    // 清空栈
    if (st && st->base)
    {
        st->top = st->base; // 重置栈顶指针
        return OK;
    }
    return ERROR;
}

Bool StackEmpty(Stack st)
{
    // 判断栈是否为空
    return st->top == st->base;
}



Bool StackFull(Stack st)
{
    // 判断是否栈满
    return (st->top - st->base) >= st->stack_size;
}

int StackLength(Stack st)
{
    return st->top - st->base;
}

Status Push(Stack st, ElemType e)
{
    if(StackFull(st)){
        st->base = realloc(st->base, sizeof(ElemType) * (st->stack_size + STACKINCREMENT));
        if(!st->base) exit(OVERFLOW);

        st->top = st->base + st->stack_size;
        st->stack_size = st->stack_size + STACKINCREMENT;
    }
    *st->top++ = e;
    st->stack_size++;
    return OK;
}

Status Pop(Stack st, ElemType* e)
{
    if(StackEmpty(st)) return ERROR;
    *e = *--st->top;
    st->stack_size--;
    return OK;
}

Status GetTop(Stack st, ElemType* e)
{
    if(StackEmpty(st)) return ERROR;
    *e = *(st->top - 1);
    return OK;
}

Status StackTraverse(Stack st, Status (* visit)(ElemType e))
{
    for(ElemType* p = st->base; p != st->top; p++){
        visit(*p);
    }
}
