// smatrix.cpp - 三元组稀疏矩阵基本操作

#include <stdio.h>
#include <stdlib.h>

typedef int ELemType;
#include "./header/smatrix.h"

// 基本操作函数定义
Status CreateSMatrix(TSMatrix &M)
{
    // 创建稀疏矩阵
    int i, m, n;
    ElemType e;
    Status k;

    printf("输入:行数，列数，非零元素个数");
    scanf(" %d%d%d", &M.mu, &M.nu, &M.tu);
}
void DestroySMatrix(TSMatrix &M);
void CopySMatrix(TSMatrix M, TSMarix &T);
Status TransposeSMatrix(TSMatrix M, TSMatrix &T);
