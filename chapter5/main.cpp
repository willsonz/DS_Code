//---------------测试------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "array.h"

int main(void)
{
    Array A;

    if (InitArray(A, 2, 2, 2))
        printf("Array A inited\n");
    else
        printf("Array A not init!\n");

    return 0;
}
