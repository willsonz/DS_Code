// 队列链式实现
//
#include <stdio.h>
#include <stdlib.h>
#include "header/queue.h"

Status InitQueue( LinkQueue &Q )
{
    // 构造一个空队列Q
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));

    if( !Q.front )
        exit(OVERFLOW);

    Q.front->next = NULL;

    return OK;
}

Status DestroyQueue( LinkQueue &Q )
{
    // 销毁队列Q,Q不再存在
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }

    return OK;
}

Status ClearQueue( LinkQueue &Q )
{
    // 将Q清为空队列
    DestroyQueue(Q);

    InitQueue(Q);

    return OK;
}

Status QueueEmpty( LinkQueue Q )
{
    // 若队列Q为空队列则返回TURE，否则返回FALSE
    return (Q.front == Q.rear) ? TRUE : FALSE;
}

int QueueLength( LinkQueue Q )
{
    // 饭回队列Q的元素个数,即为队列的长度
    int i;      // 计数器
    QueuePtr p;

    p = Q.front->next;
    i = 0;

    while (p) {
        p = p->next;
        i++;
    }

    return i;
}

Status GetHead( LinkQueue Q, QElemType &e )
{
    // 若队列非空,则用e饭回Q的队首元素,并返回OK，否则返回ERROR
    if (QueueEmpty(Q))
        return ERROR;
    else
        e = Q.front->next->data;

    return OK;
}

Status enQueue( LinkQueue &Q, QElemType e )
{
    // 插入元素e为Q新的队尾元素
    QElemPtr p;

    p = (QueuePtr)molloc(sizeof(QElemType));
    if(p)
        exit(OVERFLOW);

    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    p = NULL;

    return OK;
}

Status DeQueue( LinkQueue &Q, QElemType &e )
{
    // 若队列非空,则删除Q的队首元素，用e返回其值，并返回OK;
    // 否则返回ERROR
    if (QueueEmpty(Q))
        return ERROR;

    Queueptr p;

    p = Q.front->next;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;

    e = p->data;
    free(p);

    return OK;
}

Status QueueTraverse( LinkQueue Q, visit() );
    //
