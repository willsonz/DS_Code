#ifndef _SMATRIX_H
# define _SMATRIX_H

# include <stdio.h>
# include <stdlib.h>
# include "basic.h"

//------------triple of SparseMatrix--------------
# define MAXSIZE 12500

typedef struct {
    int i, j;
    ElemType e;
} Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int     mu, nu, tu;
} TSMatrix;

//----------Functions ProtoType------------------
Status CreateSMatrix(TSMatrix &M);
void DestroySMatrix(TSMatrix &M);
void CopySMatrix(TSMatrix M, TSMarix &T);
Status TransposeSMatrix(TSMatrix M, TSMatrix &T);




#endif
