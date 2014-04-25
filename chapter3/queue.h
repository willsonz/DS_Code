#ifndef _QUEUE_H
# define _QUEUE_H

# include <stdio.h>
# include <stdlib.h>
# include "basic.h"
# include "linklist.h"

// -------队列的链式存储结构-------
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;     // 队头指针
    QueuePtr rear;      // 队尾指针
} LinkQueue;

// -------基本操作函数原型说明------
Status InitQueue( LinkQueue &Q );
    // 构造一个空队列Q

Status DestroyQueue( LinkQueue &Q );
    // 销毁队列Q,Q不再存在

Status ClearQueue( LinkQueue &Q );
    // 将Q清为空队列

Status QueueEmpty( LinkQueue Q );
    // 若队列Q为空队列则返回TURE，否则返回FALSE

int QueueLength( LinkQueue Q );
    // 饭回队列Q的元素个数,即为队列的长度

Status GetHead( LinkQueue Q, QElemType &e );
    // 若队列非空,则用e饭回Q的队首元素,并返回OK，否则返回ERROR

Status enQueue( LinkQueue &Q, QElemType e );
    // 插入元素e为Q新的队尾元素

Status DeQueue( LinkQueue &Q, QElemType &e );
    // 若队列非空,则删除Q的队首元素，用e返回其值，并返回OK;
    // 否则返回ERROR

Status QueueTraverse( LinkQueue Q, visit() );
    //
