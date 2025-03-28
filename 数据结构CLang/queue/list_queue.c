// 队列， 链表实现
#include <stdlib.h>
#include "queue.h"

typedef struct QNode{
    ElemType data;
    struct QNode* next;
} QNode;

struct queue_type
{
    /* data */
    QNode *front, *rear;
};

Queue CreateQueue()
{
    // 创建队列
    Queue q = malloc(sizeof(struct queue_type));
    if(!q) exit(OVERFLOW);
    q->front = q->rear = NULL;
    return q;
}

Status DestroyQueue(Queue q)
{
    if(q){
        // q不是NULL时
        QNode* n = q->front;
        while (n)
        {
            /* code */
            q->front = q->front->next;
            free(n);
            n = q->front;
        }
        q->rear = q->front; // 重置 尾结点指针
        return OK;
    }
    return ERROR;
}

Bool QueueEmpty(Queue q)
{
    return q->front == NULL;
}

int QueueLength(Queue q)
{
    int len = 0;
    QNode* p = q->front;
    while (p)
    {
        /* code */
        len++;
        p = p->next;
    }
    return len;
}

Status Enqueue(Queue q, ElemType e)
{
    if(!q) return ERROR;
    QNode* new_node = malloc(sizeof(QNode));
    if(!new_node) exit(OVERFLOW);
    new_node->data = e;
    new_node->next = NULL;
    if(q->rear){
        // 如果尾指针不是NULL
        q->rear->next = new_node;
        q->rear = new_node;
    }else{
        q->front = q->rear = new_node;
    }

}
Status Dequeue(Queue q, ElemType *e)
{   // 出队
    // 链表队列，注意一种情况，如果出队的是最后一个结点，则尾指针也要重置
    if(!q || !q->front) return ERROR;
    QNode* p = q->front;
    *e = p->data;

    q->front = p->next;
    if(p == q->rear) q->rear = NULL;

    free(p);
    return OK;
}

void QueueTraverse(Queue q, void (* visit)(ElemType e))
{
    QNode* p = q->front;
    while (p)
    {
        /* code */
        visit(p->data);
        p = p->next;
    }
}