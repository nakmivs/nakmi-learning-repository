#include <stdio.h>
#include <assert.h>
#include "queue.h"

void visitElemType(ElemType e)
{
    printf("%d ", e);
}

int main()
{
    Queue q = CreateQueue();

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    
    int x;
    Dequeue(q, &x);
    printf("x: %d \n", x);

    QueueTraverse(q, visitElemType);
    DestroyQueue(q);
    return 0;
}