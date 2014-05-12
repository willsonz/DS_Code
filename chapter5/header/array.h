/**********************************
 * 数组结构头文件
 *
 *********************************/

#ifndef _ARRAY_H
# define _ARRAY_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "basic.h"

//--------数组顺序存储表示----------
#define MAX_ARRAY_DIM   8       // 数组维数最大值

typedef int ElemType;

typedef struct {
    ElemType *base;     // 数组元素基址
    int dim;            // 维数
    int *bounds;        // 维界基址
    int *constants;     // 数组映像函数常量基址
} Array;

//--------基本操作函数原型-----------
Status InitArray(Array &A, int dim, ...);
Status DestroyArray(Array &A);
Status Locate(Array A, va_list ap, int &off);
Status Value(Array A, ElemType &e, ...);
Status Assign(Array &A, ElemType e, ...);

#endif
