#ifndef _BASIC_H
#define _BASIC_H

// 定义基本的常量及类型

// 函数结果状态代码
# define TRUE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASIBLE -1
# define OVERFLOW -2

typedef int Status;
    // Status 是函数的类型，其值是函数结果状态代码
// typedef int bool;
    // bool 是布尔类型，其值是函数结果状态代码
    // C++ 已内建bool类型，此处注释
typedef float ElemType;
    // ElemType 是列表元素类型，其值为float型数据

#endif
