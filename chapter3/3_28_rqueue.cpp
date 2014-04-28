#include <stdio.h>
#include <stdlib.h>
#include "basic.h"

// 元素结构
typedef struct {
    ElemType data;
    ElemType *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr rear;
    int length;
} rQueue;

// 操作函数
Status InitRQueue(rQueue &Q)
{
    Q.rear = (QueuePtr)molloc(sizeof(QNode));

    if (!Q.rear)
        exit(OVERFLOW);

    Q.rear->next = Q.rear;
    Q.length = 0;

    return OK;
}

Statu enRQueue(rQueue &Q, ElemType e)
{
    QueuePtr ptr;

    ptr = (QueuePtr)molloc(sizeof(QNode));
    if (!ptr)
        exit(OVERFLOW);

    ptr->data = e;
    ptr->next = Q.rear->next;
    Q.rear = ptr;

    Q.length += 1;

    return OK;
}

Status deRQueue(rQueue &Q, ElemType &e)
{
    if (!Q.length)
        return ERROR;

    QueuePtr ptr;

    ptr = Q.rear->next;     // 头结点

    e = ptr->next->data;
    ptr->next = ptr->next->next;

    if (Q.length == 1)
        Q.rear = ptr;

    free(p->next);

    Q.length -= 1;

    return OK;
}

