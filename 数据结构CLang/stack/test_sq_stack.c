#include <stdio.h>
#include <assert.h>
#include "stack.h"

void printElem(ElemType e)
{
    printf("%d ", e);
}

int main()
{
    Stack s = CreateStack();
    assert(StackLength(s) == 0);
    for(int i = 0; i < 7; i++){
        Push(s, i);
    }
    int x;
    Pop(s, &x);
    printf("%d \n", x);
    GetTop(s, &x);
    assert(x == 5);
}