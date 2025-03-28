#ifndef QUEUE_H
#define QUEUE_H

#include "../common.h"

typedef struct queue_type* Queue;

Queue CreateQueue();

Status DestroyQueue(Queue q);

Bool QueueEmpty(Queue q);
int QueueLength(Queue q);

Status Enqueue(Queue q, ElemType e);
Status Dequeue(Queue q, ElemType *e);

void QueueTraverse(Queue q, void (* visit)(ElemType e));

#endif