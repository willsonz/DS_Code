//------------数组顺序结构基本算法描述---------------
#include <stdio.h>
#include <stdlib.h>
#include "./header/array.h"

Status InitArray(Array &A, int dim, ...)
{
    // 若维数dim和各维度长度合法,则构造相应数组A,并返回OK
    if (dim < 1 || dim > MAX_ARRAY_DIM)
        return ERROR;

    va_list ap;     // 依次指向每个无名参数
    int elemtotal;   // A的元素总数
    int i;

    A.dim = dim;
    A.bounds = (int *)malloc(dim * sizeof(int));

    if (!A.bounds)
        exit(OVERFLOW);
    else
        elemtotal = 1;

    // 长度合法,则存入A.biunds
    va_start(ap, dim);
    for (i = 0; i < dim; i++) {
        A.bounds[i] = va_arg(ap, int);

        if (A.bounds[i] < 0)
            return UNDERFLOW;

        elemtotal *= A.bounds[i];
    }
    va_end(ap);

    A.base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if (!A.base)
        exit(OVERFLOW);

    // 求映像函数的常数ci,并存入A.constants[i-1]
    A.constants = (int *)malloc(dim * sizeof(int));
    if (!A.constants)
        exit(OVERFLOW);

    A.constants[dim-1] = 1;
    for (i = dim-2; i > 0; i--)
        A.constants[i] = A.bounds[i+1] * A.constants[i+1];

    return OK;
}

Status DestroyArray(Array &A)
{
    if (!A.base)
        return ERROR;
    free(A.base);
    A.base = NULL;

    if (!A.bounds)
        return ERROR;
    free(A.bounds);
    A.bounds = NULL;

    if (!A.constants)
        return ERROR;
    free(A.constants);
    A.constants = NULL;

    return OK;
}

Status Locate(Array &A, va_list ap, int &off)
{
    // 若ap指示的各下标指合法,则求出该元素在A的相对地址off
    int i, ind;
    off = 0;

    for (i = 0; i < A.dim; i++) {
        ind = va_arg(ap, int);

        if (ind < 0 || ind >= A.bounds[i])
            return ERROR;

        off += A.constants[i] * ind;
    }

    return OK;
}

Status Value(Array A, ElemType &e, ...)
{
    // 若A是n维数组,e为元素变量,随后是n个下标值。
    // 若各下标不超界,则e赋值为所指定的A的元素值,并返回OK
    va_list ap;
    Status result;
    int off;

    va_start(ap, e);
    if ((result = Locate(A, ap, off)) < 0)
        return result;
    e = *(A.base + off);

    return OK;
}

Status Assign(Array &A, ElemType e, ...)
{
    va_list ap;
    Status result;
    int off;

    if ((result = Locate(A, ap, off)) <= 0)
        return result;
    *(A.base + off) = e;

    return OK;
}

